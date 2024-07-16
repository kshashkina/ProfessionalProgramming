#include "MegaDataPool.h"
#include <iostream>
#include <thread>
#include <cassert>
#include <mutex>
#include <print>

std::mutex io_mutex;

void usePool(int threadID) {
    try {
        MegaData* data = acquireFromPool();

        {
            std::lock_guard<std::mutex> lock(io_mutex);
            std::println("Thread {} acquired an object.", threadID);
        }

        // Modify the object
        data->smallArray[0] = static_cast<float>(threadID);
        data->bigArray[0] = static_cast<double>(threadID);

        // Verify the modification
        assert(data->smallArray[0] == static_cast<float>(threadID));
        assert(data->bigArray[0] == static_cast<double>(threadID));

        {
            std::lock_guard<std::mutex> lock(io_mutex);
            std::println("Thread {} modified the object", threadID);
        }

        // Reset and release the object
        releaseToPool(data);

        {
            std::lock_guard<std::mutex> lock(io_mutex);
            std::println("Thread {} released the object.", threadID);
        }
    } catch (const std::exception& e) {
        std::lock_guard<std::mutex> lock(io_mutex);
        std::println("Thread {} encountered an error: {}", threadID, e.what());
    }
}

int main() {
    std::thread t1(usePool, 1);
    std::thread t2(usePool, 2);

    t1.join();
    t2.join();

    {
        std::lock_guard<std::mutex> lock(io_mutex);
        std::println("All done!");
    }

    return 0;
}
