#include "automation.hpp"
#include <vector>
#include <numeric>

namespace rules {

    // Conway's Game of Life Rule
    CellState game_of_life_rule(std::span<const CellState> neighborhood) {
        int live_neighbors = std::count_if(neighborhood.begin(), neighborhood.end(),
            [](const CellState& cell) { return cell.value() > 0; });

        bool is_alive = neighborhood[4].value() > 0;  // Center cell

        if (is_alive) {
            return CellState((live_neighbors == 3 || live_neighbors == 2) ? 1 : 0);
        } else {
            return CellState(live_neighbors == 3 ? 1 : 0);
        }
    }

    // Cyclic rule (example from previous implementation)
    CellState cyclic_rule(std::span<const CellState> neighborhood) {
        unsigned next_state = (neighborhood[4].value() + 1) % 16;
        bool should_change = std::any_of(neighborhood.begin(), neighborhood.end(),
            [next_state](const CellState& cell) { return cell.value() == next_state; });

        return CellState(should_change ? next_state : neighborhood[4].value());
    }

    // Majority rule (example for more complex cellular automata)
    CellState majority_rule(std::span<const CellState> neighborhood) {
        std::vector<int> count(16, 0);
        for (const auto& cell : neighborhood) {
            count[cell.value()]++;
        }
        int max_state = std::distance(count.begin(), std::max_element(count.begin(), count.end()));
        return CellState(max_state);
    }

    // XOR rule (example pattern)
    CellState xor_rule(std::span<const CellState> neighborhood) {
        unsigned new_state = 0;
        for (const auto& cell : neighborhood) {
            new_state ^= cell.value();
        }
        return CellState(new_state % 16);
    }

}

void AutomatonGrid::evolve() {
    std::vector<CellState> new_grid = grid_;  // Copy current grid

    for (size_t y = 0; y < height_; ++y) {
        for (size_t x = 0; x < width_; ++x) {
            auto neighbors = get_neighborhood(x, y);
            new_grid[y * width_ + x] = rule_(neighbors);
        }
    }

    grid_ = std::move(new_grid);  // Apply updated grid state
}
