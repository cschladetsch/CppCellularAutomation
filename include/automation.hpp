#pragma once

#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <concepts>
#include <random>
#include <span>
#include <functional>
#include <bitset>
#include <array>
#include <cmath>

class CellState {
    std::bitset<4> state;  // Allows for 16 different states

public:
    CellState() : state(0) {}
    explicit CellState(unsigned val) : state(val % 16) {}

    auto operator<=>(const CellState&) const = default;
    
    unsigned value() const { return state.to_ulong(); }
    void set_value(unsigned val) { state = val % 16; }
    
    void randomize() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<> dis(0, 15);
        state = dis(gen);
    }
};

class AutomatonGrid {
public:
    using RuleFunction = std::function<CellState(std::span<const CellState>)>;

private:
    std::vector<CellState> grid;
    size_t width;
    size_t height;
    RuleFunction rule;

public:
    AutomatonGrid(size_t w, size_t h, RuleFunction r) 
        : grid(w * h), width(w), height(h), rule(std::move(r)) {}

    void randomize() {
        for (auto& cell : grid) {
            cell.randomize();
        }
    }

    CellState at(size_t x, size_t y) const {
        return grid[y * width + x];
    }

    void set(size_t x, size_t y, CellState state) {
        grid[y * width + x] = state;
    }

    std::vector<CellState> get_neighborhood(size_t x, size_t y) const {
        std::vector<CellState> neighbors;
        neighbors.reserve(9);

        for (int dy = -1; dy <= 1; ++dy) {
            for (int dx = -1; dx <= 1; ++dx) {
                size_t nx = (x + width + dx) % width;
                size_t ny = (y + height + dy) % height;
                neighbors.push_back(at(nx, ny));
            }
        }
        return neighbors;
    }

    void evolve() {
        auto new_grid = grid;
        
        for (size_t y = 0; y < height; ++y) {
            for (size_t x = 0; x < width; ++x) {
                auto neighbors = get_neighborhood(x, y);
                new_grid[y * width + x] = rule(std::span(neighbors));
            }
        }
        
        grid = std::move(new_grid);
    }

    struct Dimensions {
        size_t width;
        size_t height;
    };

    Dimensions dimensions() const {
        return {width, height};
    }
};

// Predefined rules namespace
namespace rules {

// Inspired by Belousov-Zhabotinsky reaction
inline CellState cyclic_rule(std::span<const CellState> neighbors) {
    auto center = neighbors[4];
    
    // Count states in various phases
    std::array<int, 16> phase_counts{};
    for (const auto& cell : neighbors) {
        phase_counts[cell.value()]++;
    }
    
    // Calculate phase differences and interactions
    unsigned current = center.value();
    unsigned next_phase = (current + 1) % 16;
    unsigned prev_phase = (current + 15) % 16;
    
    // Complex interaction rules based on neighbor counts
    if (phase_counts[next_phase] >= 3) {
        return CellState(next_phase);  // Activation
    } else if (phase_counts[prev_phase] > phase_counts[current]) {
        return CellState(prev_phase);  // Inhibition
    } else if (phase_counts[current] <= 2) {
        return CellState((current + 2) % 16);  // Jump states if isolated
    }
    
    return center;
}

// Neural-like activation patterns
inline CellState majority_rule(std::span<const CellState> neighbors) {
    auto center = neighbors[4];
    std::array<int, 16> activations{};
    
    // Calculate weighted influences
    for (size_t i = 0; i < neighbors.size(); ++i) {
        if (i == 4) continue;  // Skip center
        
        unsigned val = neighbors[i].value();
        // Distance-based weight
        double weight = (i % 2 == 0) ? 1.0 : 0.707; // Diagonal neighbors have less influence
        activations[val] += static_cast<int>(weight * 100);
    }
    
    // Find the highest and second highest activations
    unsigned max_idx = 0, second_idx = 0;
    for (size_t i = 1; i < 16; ++i) {
        if (activations[i] > activations[max_idx]) {
            second_idx = max_idx;
            max_idx = i;
        } else if (activations[i] > activations[second_idx]) {
            second_idx = i;
        }
    }
    
    // Complex state transition rules
    if (activations[max_idx] > 250) {
        return CellState(max_idx);  // Strong activation
    } else if (activations[max_idx] > 150) {
        // Blend states for moderate activation
        return CellState((max_idx + second_idx) / 2);
    } else if (center.value() == max_idx) {
        // State persistence with slight drift
        return CellState((center.value() + 1) % 16);
    }
    
    return center;
}

// Reaction-diffusion inspired patterns
inline CellState xor_rule(std::span<const CellState> neighbors) {
    auto center = neighbors[4];
    unsigned sum = 0;
    unsigned xor_val = 0;
    
    // Calculate both sum and XOR of neighbors
    for (size_t i = 0; i < neighbors.size(); ++i) {
        if (i != 4) {
            sum += neighbors[i].value();
            xor_val ^= neighbors[i].value();
        }
    }
    
    // Average concentration
    unsigned avg = sum / 8;
    
    // Complex transition rules combining diffusion and reaction
    if (std::abs(static_cast<int>(center.value()) - static_cast<int>(avg)) > 4) {
        // Large gradient - move toward average
        return CellState((center.value() + avg) / 2);
    } else if (xor_val > 8) {
        // High activity - state jump
        return CellState((center.value() + 4) % 16);
    } else if (xor_val < 3) {
        // Low activity - gradual change
        return CellState((center.value() + xor_val + 1) % 16);
    }
    
    return CellState(xor_val);
}

} // namespace rules
