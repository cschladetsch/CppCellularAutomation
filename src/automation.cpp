#include "automation.hpp"
#include <algorithm>

// ? Move function definitions here
CellState::CellState(unsigned val) : value_(val % 16) {}
unsigned CellState::value() const { return value_; }
void CellState::set_value(unsigned val) { value_ = val % 16; }
void CellState::randomize() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<unsigned> dis(0, 15);
    value_ = dis(gen);
}

// ? AutomatonGrid Implementations
AutomatonGrid::AutomatonGrid(size_t w, size_t h, RuleFunction rule)
    : width_(w), height_(h), rule_(rule), grid_(w * h, CellState(0)) {}

std::pair<size_t, size_t> AutomatonGrid::dimensions() const { return {width_, height_}; }
void AutomatonGrid::set(size_t x, size_t y, CellState state) { grid_[y * width_ + x] = state; }
CellState AutomatonGrid::at(size_t x, size_t y) const { return grid_[y * width_ + x]; }

std::vector<CellState> AutomatonGrid::get_neighborhood(size_t x, size_t y) const {
    std::vector<CellState> neighbors;
    for (int dy = -1; dy <= 1; ++dy) {
        for (int dx = -1; dx <= 1; ++dx) {
            size_t nx = (x + dx + width_) % width_;
            size_t ny = (y + dy + height_) % height_;
            neighbors.push_back(grid_[ny * width_ + nx]);
        }
    }
    return neighbors;
}

void AutomatonGrid::evolve() {
    std::vector<CellState> new_grid = grid_;
    for (size_t y = 0; y < height_; ++y) {
        for (size_t x = 0; x < width_; ++x) {
            auto neighbors = get_neighborhood(x, y);
            new_grid[y * width_ + x] = rule_(neighbors);
        }
    }
    grid_ = std::move(new_grid);
}

#include "automation.hpp"

// ✅ Define the missing `rules` functions
namespace rules {
    CellState game_of_life_rule(std::span<const CellState> neighborhood) {
        int live_neighbors = std::count_if(neighborhood.begin(), neighborhood.end(),
            [](const CellState& cell) { return cell.value() > 0; });

        bool is_alive = neighborhood[4].value() > 0;

        if (is_alive) {
            return CellState((live_neighbors == 2 || live_neighbors == 3) ? 1 : 0);
        } else {
            return CellState(live_neighbors == 3 ? 1 : 0);
        }
    }

    CellState cyclic_rule(std::span<const CellState> neighborhood) {
        unsigned next_state = (neighborhood[4].value() + 1) % 16;
        bool should_change = std::any_of(neighborhood.begin(), neighborhood.end(),
            [next_state](const CellState& cell) { return cell.value() == next_state; });

        return CellState(should_change ? next_state : neighborhood[4].value());
    }

    CellState majority_rule(std::span<const CellState> neighborhood) {
        std::vector<int> count(16, 0);
        for (const auto& cell : neighborhood) {
            count[cell.value()]++;
        }
        int max_state = std::distance(count.begin(), std::max_element(count.begin(), count.end()));
        return CellState(max_state);
    }

    CellState xor_rule(std::span<const CellState> neighborhood) {
        unsigned new_state = 0;
        for (const auto& cell : neighborhood) {
            new_state ^= cell.value();
        }
        return CellState(new_state % 16);
    }
}

