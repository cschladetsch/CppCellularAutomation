#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "automation.hpp"
#include <random>

TEST_CASE("CellState basic operations", "[cell]") {
    CellState cell;
    
    SECTION("Default construction") {
        REQUIRE(cell.value() == 0);
    }
    
    SECTION("Value construction") {
        CellState cell2(5);
        REQUIRE(cell2.value() == 5);
        
        CellState cell3(20);  // Should wrap to 4
        REQUIRE(cell3.value() == 4);
    }
    
    SECTION("Value wrapping") {
        cell.set_value(25);  // Should wrap to 9
        REQUIRE(cell.value() == 9);
    }
    
    SECTION("Randomization") {
        std::vector<CellState> states(100);
        for (auto& state : states) {
            state.randomize();
        }
        
        // Check that we get some variety (not a perfect test but good enough)
        auto different_values = std::count_if(states.begin(), states.end(),
            [first_val = states[0].value()](const auto& state) {
                return state.value() != first_val;
            });
            
        REQUIRE(different_values > 0);
    }
}

TEST_CASE("AutomatonGrid operations", "[grid]") {
    AutomatonGrid grid(10, 10, rules::cyclic_rule);
    
    SECTION("Grid dimensions") {
        auto [width, height] = grid.dimensions();
        REQUIRE(width == 10);
        REQUIRE(height == 10);
    }
    
    SECTION("Cell access") {
        grid.set(5, 5, CellState(7));
        REQUIRE(grid.at(5, 5).value() == 7);
    }
    
    SECTION("Neighborhood") {
        // Set up a specific pattern
        grid.set(1, 1, CellState(1));
        grid.set(1, 2, CellState(2));
        grid.set(2, 1, CellState(3));
        
        auto neighbors = grid.get_neighborhood(1, 1);
        REQUIRE(neighbors.size() == 9);
        REQUIRE(neighbors[4].value() == 1);  // Center cell
    }
    
    SECTION("Evolution with cyclic rule") {
        // Set up a pattern that should evolve
        grid.set(1, 1, CellState(1));
        grid.set(1, 2, CellState(2));
        grid.set(2, 1, CellState(2));
        
        grid.evolve();
        
        // Center cell should evolve based on rules
        REQUIRE(grid.at(1, 1).value() != 1);  // Should have changed
    }
}

TEST_CASE("Rule implementations", "[rules]") {
    SECTION("Cyclic rule") {
        std::vector<CellState> neighbors(9, CellState(0));
        neighbors[4] = CellState(1);  // Center cell
        neighbors[1] = CellState(2);  // Two neighbors in next state
        neighbors[7] = CellState(2);
        
        auto result = rules::cyclic_rule(std::span(neighbors));
        REQUIRE(result.value() != neighbors[4].value());  // Should change state
    }
    
    SECTION("Majority rule") {
        std::vector<CellState> neighbors{
            CellState(1), CellState(1), CellState(1),
            CellState(2), CellState(2), CellState(3),
            CellState(3), CellState(3), CellState(3)
        };
        
        auto result = rules::majority_rule(std::span(neighbors));
        REQUIRE(result.value() == 3);  // Most common value
    }
    
    SECTION("XOR rule") {
        std::vector<CellState> neighbors(9, CellState(1));
        
        auto result = rules::xor_rule(std::span(neighbors));
        REQUIRE(result.value() != 0);  // Should produce some non-zero value
    }
}
