#include "automation.hpp"
#include "rang.hpp"
#include <chrono>
#include <thread>
#include <iostream>
#include <iomanip>

using namespace std::chrono_literals;  

// Remove: using namespace rules;

class AutomatonVisualizer {
    static constexpr size_t GRID_SIZE = 60;
    static constexpr size_t GRID_HEIGHT = 30;

public:
    void run() {
        std::cout << rang::style::bold << rang::fg::cyan 
                  << "Advanced Cellular Automaton Simulator" 
                  << rang::style::reset << std::endl;

        auto rule = select_rule();
        AutomatonGrid grid(GRID_SIZE, GRID_HEIGHT, rule);

        // ? Fix: Use `rules::` explicitly
        if (rule == rules::game_of_life_rule) {
            initialize_glider(grid);
        }

        std::cout << "[2J[H[s";

        while (true) {
            std::cout << "[u";
            display_grid(grid);
            grid.evolve();
            std::this_thread::sleep_for(100ms);
            std::cout.flush();
        }
    }

private:
    static void initialize_glider(AutomatonGrid& grid) {
        size_t width, height;
        std::tie(width, height) = grid.dimensions();

        if (width < 5 || height < 5) return;

        std::vector<std::pair<size_t, size_t>> glider = {
            {1, 0}, {2, 1}, {0, 2}, {1, 2}, {2, 2}
        };

        for (const auto& [x, y] : glider) {
            grid.set(x, y, CellState(1));
        }
    }

    static AutomatonGrid::RuleFunction select_rule() {
        std::cout << "Available Rules:\n"
                  << "1. BZ-Inspired (Spiral patterns)\n"
                  << "2. Neural-Like (Wave patterns)\n"
                  << "3. Reaction-Diffusion (Spotted patterns)\n"
                  << "4. Conway's Game of Life (with Glider)\n"
                  << "Select rule (1-4): ";

        int choice;
        std::cin >> choice;

        // ? Fix: Explicitly reference `rules::`
        switch (choice) {
            case 1: return &rules::cyclic_rule;
            case 2: return &rules::majority_rule;
            case 3: return &rules::xor_rule;
            case 4: return &rules::game_of_life_rule;
            default: return &rules::cyclic_rule;
        }
    }

    static void display_grid(const AutomatonGrid& grid) {
        auto [width, height] = grid.dimensions();

        for (size_t y = 0; y < height; ++y) {
            for (size_t x = 0; x < width; ++x) {
                char symbol = grid.at(x, y).value() > 0 ? '#' : '.';
                std::cout << symbol << ' ';
            }
        }
    }
};

int main() {
    try {
        AutomatonVisualizer visualizer;
        visualizer.run();
    } catch (const std::exception& e) {
        std::cerr << rang::fg::red
                  << "Error: " << e.what()
                  << rang::fg::reset << std::endl;
        return 1;
    }
    return 0;
}

