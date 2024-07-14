#include "MegaDataPool.h"
#include <stdexcept>
#include <algorithm>

MegaDataPool& MegaDataPool::instance(size_t poolSize) {
    static MegaDataPool instance(poolSize);
    return instance;
}

MegaDataPool::MegaDataPool(size_t poolSize) : poolSize(poolSize), usedCount(0) {
    pool.reserve(poolSize);
    for (size_t i = 0; i < poolSize; ++i) {
        pool.emplace_back();
    }
    availableIndices.reserve(poolSize);
    for (size_t i = 0; i < poolSize; ++i) {
        availableIndices.push_back(i);
    }
}

MegaData* MegaDataPool::acquire() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (usedCount == poolSize) {
        throw std::out_of_range("No available objects in the pool");
    }
    size_t index = availableIndices.back();
    availableIndices.pop_back();
    ++usedCount;
    return &pool[index];
}

void MegaDataPool::release(MegaData* obj) {
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = std::find(pool.begin(), pool.end(), *obj);
    if (it == pool.end()) {
        throw std::invalid_argument("Object does not belong to the pool");
    }
    size_t index = std::distance(pool.begin(), it);
    availableIndices.push_back(index);
    --usedCount;
    obj->reset();
}

size_t MegaDataPool::size() const {
    return poolSize;
}

size_t MegaDataPool::usedSize() const {
    return usedCount;
}

// Helper functions
MegaData* acquireFromPool() {
    return MegaDataPool::instance().acquire();
}

void releaseToPool(MegaData* obj) {
    MegaDataPool::instance().release(obj);
}

size_t poolSize() {
    return MegaDataPool::instance().size();
}

size_t usedPoolSize() {
    return MegaDataPool::instance().usedSize();
}
