#include "formula.h"

#include "FormulaAST.h"

#include <algorithm>
#include <cassert>
#include <cctype>
#include <sstream>

using namespace std::literals;

std::ostream& operator<<(std::ostream& output, FormulaError fe) {
    // Ещё не сделал
}

namespace {
class Formula : public FormulaInterface {
// Методы тоже ещё не реализовал
public:
    explicit Formula(std::string expression);

    Value Evaluate(const SheetInterface& sheet) const override;

    std::string GetExpression() const override;

    std::vector<Position> GetReferencedCells() const override;

private:
    FormulaAST ast_;
};
}  // namespace

std::unique_ptr<FormulaInterface> ParseFormula(std::string expression) {
    return std::make_unique<Formula>(std::move(expression));
}