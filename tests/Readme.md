# Tests

Unit tests for the cellular automaton implementation.

## Test Files

- `test_automation.cpp` - Tests for:
  - CellState operations
  - AutomatonGrid functionality
  - Rule implementations

## Running Tests

From build directory:
```bash
# Run all tests
ctest

# Run tests with detailed output
./tests/automaton_tests

# List available tests
./tests/automaton_tests --list-tests

# Run specific test cases
./tests/automaton_tests "[cell]"  # runs only cell-related tests
```
