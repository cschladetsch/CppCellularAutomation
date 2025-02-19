# Advanced Cellular Automaton Simulator

## Overview

This project is an **Advanced Cellular Automaton Simulator**, capable of running various rule-based cellular automata such as:
- **BZ-Inspired (Spiral patterns)**
- **Neural-Like (Wave patterns)**
- **Reaction-Diffusion (Spotted patterns)**
- **Conway's Game of Life (with Glider Initialization)**

The simulation runs directly in the **terminal**, displaying color-coded ASCII representations.

## Demo

![image](/resources/CellularAutoation-1.gif)


## Features
* **Multiple Cellular Automaton Rules** (including Game of Life)  
* **Real-time Terminal Visualization** with ASCII symbols  
* **Configurable Grid Size**  
* **Glider Initialization for Game of Life**  
* **Unit Tests with Catch2 Framework**  

## Installation

### **Prerequisites**
- **C++23 compiler** (GCC 13+, Clang 16+, MSVC 2022+)  
- **CMake 3.28+**  
- **GNU Make** or equivalent build system  

### **Build Instructions**

```sh
git clone https://github.com/cschladetsch/cellular-automaton.git  
cd cellular-automaton  
mkdir build && cd build  
cmake ..  
make  
```

### **Run the Simulator**
```sh
./automaton  
```
You will be prompted to **select a rule** from the available automaton types.  
Press **Ctrl+C** to exit.

## Usage

When prompted, select a rule:  
```
Available Rules:
1. BZ-Inspired (Spiral patterns)
2. Neural-Like (Wave patterns)
3. Reaction-Diffusion (Spotted patterns)
4. Conway's Game of Life (with Glider)
Select rule (1-4): 
```
- If you select **Game of Life (4)**, the grid initializes with a **glider**, which will move across the screen.  
- Other rules produce **different evolving patterns**.

## Project Structure

```
include/
    automation.hpp       # Core automaton logic
    test_rang.hpp        # Terminal color handling

src/
    main.cpp             # Entry point
    automation.cpp       # Automaton logic implementation

tests/
    test_automation.cpp  # Unit tests for automaton logic
    test_rang.cpp        # Tests for terminal color handling

CMakeLists.txt           # Build system configuration
Readme.md                # Project documentation
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

## Installation

### **Prerequisites**
- **C++23 compiler** (GCC 13+, Clang 16+, MSVC 2022+)  
- **CMake 3.28+**  
- **GNU Make** or equivalent build system  

### **Build Instructions**

```sh
git clone https://github.com/your-repo/cellular-automaton.git  
cd cellular-automaton  
mkdir build && cd build  
cmake ..  
make  
```

### **Run the Simulator**
```sh
./automaton  
```
You will be prompted to **select a rule** from the available automaton types.  
Press **Ctrl+C** to exit.

## Usage

When prompted, select a rule:  
```
Available Rules:
1. BZ-Inspired (Spiral patterns)
2. Neural-Like (Wave patterns)
3. Reaction-Diffusion (Spotted patterns)
4. Conway's Game of Life (with Glider)
Select rule (1-4): 
```
- If you select **Game of Life (4)**, the grid initializes with a **glider**, which will move across the screen.  
- Other rules produce **different evolving patterns**.

## Project Structure

```
include/
    automation.hpp       # Core automaton logic
    test_rang.hpp        # Terminal color handling

src/
    main.cpp             # Entry point
    automation.cpp       # Automaton logic implementation

tests/
    test_automation.cpp  # Unit tests for automaton logic
    test_rang.cpp        # Tests for terminal color handling

CMakeLists.txt           # Build system configuration
Readme.md                # Project documentation
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
