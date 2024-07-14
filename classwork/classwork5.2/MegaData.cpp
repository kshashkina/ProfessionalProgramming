#include "MegaData.h"
#include <algorithm>

MegaData::MegaData() : smallArray(std::make_unique<float[]>(SMALL_ARRAY_SIZE)),
                       bigArray(std::make_unique<double[]>(BIG_ARRAY_SIZE)) {
    std::fill(smallArray.get(), smallArray.get() + SMALL_ARRAY_SIZE, 42.0f);
    std::fill(bigArray.get(), bigArray.get() + BIG_ARRAY_SIZE, 42.0);
}

void MegaData::reset() {
    std::fill(smallArray.get(), smallArray.get() + SMALL_ARRAY_SIZE, 42.0f);
    std::fill(bigArray.get(), bigArray.get() + BIG_ARRAY_SIZE, 42.0);
}

bool MegaData::operator==(const MegaData& other) const {
    return std::equal(smallArray.get(), smallArray.get() + SMALL_ARRAY_SIZE, other.smallArray.get()) &&
           std::equal(bigArray.get(), bigArray.get() + BIG_ARRAY_SIZE, other.bigArray.get());
}
