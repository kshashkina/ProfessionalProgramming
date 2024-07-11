package org.example;

import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;

public class MegaDataPool {
    private final int poolSize;
    private int usedCount;
    private final List<MegaData> pool;
    private final List<Integer> availableIndices;

    public MegaDataPool(int poolSize) {
        this.poolSize = poolSize;
        this.usedCount = 0;
        this.pool = new ArrayList<>(poolSize);
        this.availableIndices = new ArrayList<>(poolSize);
        for (int i = 0; i < poolSize; i++) {
            pool.add(new MegaData());
            availableIndices.add(i);
        }
    }

    public MegaData acquire() {
        if (usedCount == poolSize) {
            throw new NoSuchElementException("No available objects in the pool");
        }
        int index = availableIndices.remove(availableIndices.size() - 1);
        usedCount++;
        return pool.get(index);
    }

    public void release(MegaData obj) {
        int index = pool.indexOf(obj);
        if (index == -1) {
            throw new IllegalArgumentException("Object does not belong to the pool");
        }
        availableIndices.add(index);
        usedCount--;
        obj.reset();
    }

    public int size() {
        return poolSize;
    }

    public int usedSize() {
        return usedCount;
    }
}

