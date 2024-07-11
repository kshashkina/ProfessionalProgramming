import java.io.*;
import java.util.*;

class Color {
    int r, g, b;

    public Color(int r, int g, int b) {
        if (!isValidColorValue(r) || !isValidColorValue(g) || !isValidColorValue(b)) {
            throw new IllegalArgumentException("Invalid color value. Each component must be in the range [0, 255].");
        }
        this.r = r;
        this.g = g;
        this.b = b;
    }

    private boolean isValidColorValue(int value) {
        return value >= 0 && value <= 255;
    }

    public boolean equals(Color other) {
        return this.r == other.r && this.g == other.g && this.b == other.b;
    }

    @Override
    public String toString() {
        return r + "," + g + "," + b;
    }
}
