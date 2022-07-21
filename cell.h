#pragma once

#include "common.h"
#include "formula.h"

class Cell : public CellInterface {
public:
    Cell(SheetInterface& sheet, Position pos);
    ~Cell();

    void Set(std::string text) override;

    std::vector<Position> GetReferencedCells() const override;
    Value GetValue() const override;
    std::string GetText() const override;

private:
    class Impl;
    class EmptyImpl;
    class TextImpl;
    class FormulaImpl;

    SheetInterface& sheet_;
    Position pos_;
    std::set<Position> depend_on_this_cell_;
    std::unique_ptr<Impl> impl_;
    std::string text_;

    bool IsCyclicalDependenceCaused(const std::vector<Position>& unverified_positions, std::set<Position>& verified_positions) const;
    void ClearCache(std::set<Position>& verified_positions);
    void BindCells(const std::vector<Position>& unverified_positions);
};