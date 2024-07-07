package org.example;


public class MegaData {
    public static final int SMALL_ARRAY_SIZE = 1024;
    public static final int BIG_ARRAY_SIZE = 1024 * 1024;

    public final float[] smallArray;
    public final double[] bigArray;

    public MegaData() {
        smallArray = new float[SMALL_ARRAY_SIZE];
        bigArray = new double[BIG_ARRAY_SIZE];
        for (int i = 0; i < SMALL_ARRAY_SIZE; i++) {
            smallArray[i] = 42.0f;
        }
        for (int i = 0; i < BIG_ARRAY_SIZE; i++) {
            bigArray[i] = 42.0;
        }
    }

    public void reset() {
        for (int i = 0; i < SMALL_ARRAY_SIZE; i++) {
            smallArray[i] = 42.0f;
        }
        for (int i = 0; i < BIG_ARRAY_SIZE; i++) {
            bigArray[i] = 42.0;
        }
    }

}