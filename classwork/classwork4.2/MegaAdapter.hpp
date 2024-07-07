#pragma once

#include <memory>
#include "LegacyCalculator.hpp"
#include "ModernCalculators.hpp"

class MegaAdapter : public BaseMegaCalculator {
public:
    MegaAdapter(std::unique_ptr<LegacyCalculator> legacyCalculator)
            : legacyCalculator(std::move(legacyCalculator)) {}

    double getPrice() const override {
        // Adapt the legacy calculator's two-part price calculation into a single price for the new interface
        return legacyCalculator->calculatePricePart1() + legacyCalculator->calculatePricePart2();
    }

    double getMinimalValue() const override {
        // Adapt the minimal value calculation from the legacy calculator
        return legacyCalculator->getOurTheMostAndMinimalValue();
    }

    std::string getReport() const override {
        // Adapt the document representation from the legacy calculator
        return legacyCalculator->getSomeDocumentRepresentation();
    }

private:
    std::unique_ptr<LegacyCalculator> legacyCalculator;
};
