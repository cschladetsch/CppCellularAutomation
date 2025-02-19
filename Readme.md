# Advanced Cellular Automaton Simulator  

## Overview  

This project is an **Advanced Cellular Automaton Simulator**, featuring various rule-based evolution methods such as BZ-Inspired, Neural-Like, and Reaction-Diffusion models. The simulation is rendered directly in the console with color-coded ASCII representations.  

## Demo

![demo](/resources/CellularAutoation-1.gif)

## Features  

- **Rule-Based Cellular Automata**  
  - BZ-Inspired (Spiral patterns)  
  - Neural-Like (Wave patterns)  
  - Reaction-Diffusion (Spotted patterns)  
- **Dynamic Visualization**  
  - Runs in the terminal with real-time updates  
  - Uses ANSI escape sequences for smooth rendering  
- **Customizable Simulation Grid**  
  - Adjustable size and initial conditions  
  - Multiple color-coded states for visualization  
- **Unit Testing**  
  - Catch2 framework for testing automaton logic  

## Installation  

### Prerequisites  

- A **C++23** compiler (GCC 13+, Clang 16+, MSVC 2022+)  
- **CMake 3.20+**  
- **GNU Make** or equivalent build system  

### Build Instructions  

```sh
git clone ssh://github.com/cschladetsch/cellular-automaton.git  
cd cellular-automaton  
mkdir build && cd build  
cmake ..  
make  
```

### Running the Simulator  

After building, run the executable:  

```sh
./automaton  
```

You will be prompted to select a rule. Press `Ctrl+C` to exit.  

## Project Structure  

```
ÃÄÄ include/
³   ÃÄÄ automation.hpp      # Core automaton logic
³   ÃÄÄ rang.hpp            # Terminal color handling (auto-downloaded)
³   ÃÄÄ catch.hpp           # Unit testing framework (auto-downloaded)
³
ÃÄÄ src/
³   ÃÄÄ main.cpp            # Entry point
³
ÃÄÄ tests/
³   ÃÄÄ test_automation.cpp # Unit tests for automaton logic
³   ÃÄÄ test_rang.cpp       # Tests for color output
³
ÃÄÄ CMakeLists.txt          # Build system
ÃÄÄ Readme.md               # Documentation
```

## Testing  

To run unit tests:  

```sh
ctest --output-on-failure  
```

Alternatively, run:  

```sh
./automaton_tests  
```

## Dependencies  

- **rang.hpp** - Color and styling library (auto-downloaded)  
- **Catch2** - Unit testing framework (auto-downloaded)  

## License  

This project is licensed under the MIT License.  
