#pragma once

#include "MegaData.h"
#include <vector>
#include <mutex>

class MegaDataPool {
public:
    static MegaDataPool& instance(size_t poolSize = 10);
    MegaData* acquire();
    void release(MegaData* obj);
    size_t size() const;
    size_t usedSize() const;

private:
    MegaDataPool(size_t poolSize);

    const size_t poolSize;
    size_t usedCount;
    std::vector<MegaData> pool;
    std::vector<size_t> availableIndices;
    std::mutex mutex_;
};

// Helper functions
MegaData* acquireFromPool();
void releaseToPool(MegaData* obj);
size_t poolSize();
size_t usedPoolSize();
