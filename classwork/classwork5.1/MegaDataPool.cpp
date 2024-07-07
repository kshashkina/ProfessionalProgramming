#include "MegaData.cpp"

class MegaDataPool {
public:
    MegaDataPool(size_t poolSize) : poolSize(poolSize), usedCount(0) {
        pool.reserve(poolSize);
        for (size_t i = 0; i < poolSize; ++i) {
            pool.emplace_back();
        }
        availableIndices.reserve(poolSize);
        for (size_t i = 0; i < poolSize; ++i) {
            availableIndices.push_back(i);
        }
    }

    MegaData* acquire() {
        if (usedCount == poolSize) {
            throw std::out_of_range("No available objects in the pool");
        }
        size_t index = availableIndices.back();
        availableIndices.pop_back();
        ++usedCount;
        return &pool[index];
    }

    void release(MegaData* obj) {
        auto it = std::find(pool.begin(), pool.end(), *obj);
        if (it == pool.end()) {
            throw std::invalid_argument("Object does not belong to the pool");
        }
        size_t index = std::distance(pool.begin(), it);
        availableIndices.push_back(index);
        --usedCount;
        obj->reset();
    }

    size_t size() const {
        return poolSize;
    }

    size_t usedSize() const {
        return usedCount;
    }

private:
    const size_t poolSize;
    size_t usedCount;
    std::vector<MegaData> pool;
    std::vector<size_t> availableIndices;
};