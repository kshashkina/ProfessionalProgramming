#include <array>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <memory>

class MegaData {
public:
    static constexpr size_t SMALL_ARRAY_SIZE = 1024;
    static constexpr size_t BIG_ARRAY_SIZE = 1024 * 1024;

    MegaData() : smallArray(std::make_unique<float[]>(SMALL_ARRAY_SIZE)),
                 bigArray(std::make_unique<double[]>(BIG_ARRAY_SIZE)) {
        std::fill(smallArray.get(), smallArray.get() + SMALL_ARRAY_SIZE, 42.0f);
        std::fill(bigArray.get(), bigArray.get() + BIG_ARRAY_SIZE, 42.0);
    }

    void reset() {
        std::fill(smallArray.get(), smallArray.get() + SMALL_ARRAY_SIZE, 42.0f);
        std::fill(bigArray.get(), bigArray.get() + BIG_ARRAY_SIZE, 42.0);
    }

    bool operator==(const MegaData& other) const {
        return std::equal(smallArray.get(), smallArray.get() + SMALL_ARRAY_SIZE, other.smallArray.get()) &&
               std::equal(bigArray.get(), bigArray.get() + BIG_ARRAY_SIZE, other.bigArray.get());
    }

    std::unique_ptr<float[]> smallArray;
    std::unique_ptr<double[]> bigArray;
};