#include "automation.hpp"
#include "rang.hpp"
#include <chrono>
#include <thread>
#include <iostream>
#include <iomanip>

using namespace std::chrono_literals;

class AutomatonVisualizer {
    static constexpr size_t GRID_SIZE = 60;    // Smaller width
    static constexpr size_t GRID_HEIGHT = 30;  // Smaller height

public:
    void run() {
        std::cout << rang::style::bold << rang::fg::cyan 
                  << "Advanced Cellular Automaton Simulator\n" 
                  << rang::style::reset << std::endl;

        auto rule = select_rule();
        AutomatonGrid grid(GRID_SIZE, GRID_HEIGHT, rule);
        initialize_pattern(grid);

        // Clear screen and save cursor position
        std::cout << "\033[2J\033[H\033[s";
        
        while (true) {
            // Restore cursor position
            std::cout << "\033[u";
            display_grid(grid);
            grid.evolve();
            std::this_thread::sleep_for(100ms);
            std::cout.flush();
        }
    }

private:
    static void initialize_pattern(AutomatonGrid& grid) {
        auto [width, height] = grid.dimensions();
        double center_x = width / 2.0;
        double center_y = height / 2.0;
        
        for (size_t y = 0; y < height; ++y) {
            for (size_t x = 0; x < width; ++x) {
                double dx = x - center_x;
                double dy = y - center_y;
                double distance = std::sqrt(dx*dx + dy*dy);
                double angle = std::atan2(dy, dx);
                
                unsigned state = static_cast<unsigned>(
                    (distance + angle * 3) * 1.5
                ) % 16;
                
                grid.set(x, y, CellState(state));
            }
        }
    }

    static AutomatonGrid::RuleFunction select_rule() {
        std::cout << "Available Rules:\n"
                  << "1. BZ-Inspired (Creates spiral patterns)\n"
                  << "2. Neural-Like (Creates wave patterns)\n"
                  << "3. Reaction-Diffusion (Creates spotted patterns)\n"
                  << "Select rule (1-3): ";
                  
        int choice;
        std::cin >> choice;
        
        switch (choice) {
            case 1: return rules::cyclic_rule;
            case 2: return rules::majority_rule;
            case 3: return rules::xor_rule;
            default: return rules::cyclic_rule;
        }
    }

    static void display_grid(const AutomatonGrid& grid) {
        static const std::array<rang::fg, 16> colors = {
            rang::fg::blue,   rang::fg::green,  rang::fg::cyan,   rang::fg::red,
            rang::fg::magenta,rang::fg::yellow, rang::fg::blue,   rang::fg::green,
            rang::fg::cyan,   rang::fg::red,    rang::fg::magenta,rang::fg::yellow,
            rang::fg::blue,   rang::fg::green,  rang::fg::cyan,   rang::fg::red
        };

        // Simple ASCII characters
        static const std::array<const char*, 16> symbols = {
            ".", "o", "O", "#", "@", "*", "+", "=",
            "-", "|", "/", "\\", ":", ";", "x", "X"
        };

        auto [width, height] = grid.dimensions();
        std::string buffer;
        buffer.reserve(width * height * 3);

        for (size_t y = 0; y < height; ++y) {
            for (size_t x = 0; x < width; ++x) {
                auto state = grid.at(x, y);
                std::cout << colors[state.value()]
                         << symbols[state.value()]
                         << ' '  // Add space for better aspect ratio
                         << rang::fg::reset;
            }
            std::cout << '\n';
        }
        
        std::cout << "Press Ctrl+C to exit";
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
