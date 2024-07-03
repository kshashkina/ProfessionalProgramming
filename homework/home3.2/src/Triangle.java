package org.example;

public class Triangle {
    private double a, b, c;

    public Triangle(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public double area() {
        if (a <= 0 || b <= 0 || c <= 0) {
            return -1; // Indicate invalid triangle
        }
        if (a + b <= c || a + c <= b || b + c <= a) {
            return -1; // Indicate invalid triangle
        }

        double s = (a + b + c) / 2.0;
        return Math.sqrt(s * (s - a) * (s - b) * (s - c));
    }

    public double getHeight(char side) {
        double area = area();
        if (area == -1) {
            return -1; // Invalid triangle
        }

        switch (side) {
            case 'a':
                return (2 * area) / a;
            case 'b':
                return (2 * area) / b;
            case 'c':
                return (2 * area) / c;
            default:
                throw new IllegalArgumentException("Invalid side: " + side);
        }
    }
}
