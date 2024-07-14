#pragma once

#include <memory>

class MegaData {
public:
    static constexpr size_t SMALL_ARRAY_SIZE = 1024;
    static constexpr size_t BIG_ARRAY_SIZE = 1024 * 1024;

    MegaData();
    void reset();

    bool operator==(const MegaData& other) const;

    std::unique_ptr<float[]> smallArray;
    std::unique_ptr<double[]> bigArray;
};
