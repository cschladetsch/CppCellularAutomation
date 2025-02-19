#pragma once

#include <vector>
#include <span>
#include <random>

// ? Declare CellState first before `rules::`
class CellState {
    unsigned value_;
public:
    explicit CellState(unsigned val = 0);
    unsigned value() const;
    void set_value(unsigned val);
    void randomize();
};

// ? Now declare `rules` after `CellState`
namespace rules {
    CellState game_of_life_rule(std::span<const CellState> neighborhood);
    CellState cyclic_rule(std::span<const CellState> neighborhood);
    CellState majority_rule(std::span<const CellState> neighborhood);
    CellState xor_rule(std::span<const CellState> neighborhood);
}

// ? Declare AutomatonGrid class
class AutomatonGrid {
public:
    using RuleFunction = CellState (*)(std::span<const CellState>);

private:
    std::vector<CellState> grid_;
    size_t width_, height_;
    RuleFunction rule_;

public:
    AutomatonGrid(size_t w, size_t h, RuleFunction rule);
    std::pair<size_t, size_t> dimensions() const;
    void set(size_t x, size_t y, CellState state);
    CellState at(size_t x, size_t y) const;
    std::vector<CellState> get_neighborhood(size_t x, size_t y) const;
    void evolve();
};
