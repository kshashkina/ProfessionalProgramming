#include <iostream>
#include <cmath>
#include "Triangle.h"
#include "Color.h"
#include "UnitTests.h"

int main() {
    UnitTests testSuite;

    testSuite.addTest("TestArea_3_4_5",
                      []() {
                          Triangle triangle(3, 4, 5);
                          double s = (3 + 4 + 5) / 2.0;
                          double expected = std::sqrt(s * (s - 3) * (s - 4) * (s - 5));
                          ASSERT_EQ(triangle.area(), expected);
    });

    testSuite.addTest("TestArea_1_1_1",
                      []() {
                          Triangle triangle(1, 1, 1);
                          double s = (1 + 1 + 1) / 2.0;
                          double expected = std::sqrt(s * (s - 1) * (s - 1) * (s - 1));
                          ASSERT_EQ(triangle.area(), expected);
    });

    testSuite.addTest("TestArea_5_12_13",
                      []() {
                          Triangle triangle(5, 12, 13);
                          double s = (5 + 12 + 13) / 2.0;
                          double expected = std::sqrt(s * (s - 5) * (s - 12) * (s - 13));
                          ASSERT_EQ(triangle.area(), expected);
    });

    testSuite.addTest("TestNegativeSide",
                      []() {
                          Triangle triangle(-3, 4, 5);
                          ASSERT_EQ(triangle.area(), -1);
    });

    testSuite.addTest("TestZeroSide",
                      []() {
                          Triangle triangle(0, 4, 5);
                          ASSERT_EQ(triangle.area(), -1);
    });

    testSuite.addTest("TestInvalidTriangle",
                      []() {
                          Triangle triangle(1, 2, 3);
                          ASSERT_EQ(triangle.area(), -1);
    });

    testSuite.addTest("TestColor_100_50_25",
                      []() {
                            Color color(100, 50, 25);
                            Color magic = color.magicColor();
                            auto [r, g, b] = magic.getRGB();
                            ASSERT_EQ(r, 49);  // (100 / 2) - 1 = 49
                            ASSERT_EQ(g, 98);  // (50 * 2) - 2 = 98
                            ASSERT_EQ(b, 25);  // Unchanged
    });

    testSuite.addTest("TestColor_0_0_0",
                      []() {
                            Color color(0, 0, 0);
                            Color magic = color.magicColor();
                            auto [r, g, b] = magic.getRGB();
                            ASSERT_EQ(r, 0);   // (0 / 2) - 1 = -1, clamped to 0
                            ASSERT_EQ(g, 0);   // (0 * 2) - 2 = -2, clamped to 0
                            ASSERT_EQ(b, 0);   // Unchanged
    });

    testSuite.addTest("TestColor_255_255_255",
                      []() {
                            Color color(255, 255, 255);
                            Color magic = color.magicColor();
                            auto [r, g, b] = magic.getRGB();
                            ASSERT_EQ(r, 126); // (255 / 2) - 1 = 126
                            ASSERT_EQ(g, 255); // (255 * 2) - 2 = 508, clamped to 255
                            ASSERT_EQ(b, 255); // Unchanged
    });

    testSuite.addTest("TestColor_1_1_1", []() {
                            Color color(1, 1, 1);
                            Color magic = color.magicColor();
                            auto [r, g, b] = magic.getRGB();
                            ASSERT_EQ(r, 0);   // (1 / 2) - 1 = -1, clamped to 0
                            ASSERT_EQ(g, 0);   // (1 * 2) - 2 = 0
                            ASSERT_EQ(b, 1);   // Unchanged
    });

    testSuite.addTest("TestColor_2_2_2", []() {
                            Color color(2, 2, 2);
                            Color magic = color.magicColor();
                            auto [r, g, b] = magic.getRGB();
                            ASSERT_EQ(r, 0);   // (2 / 2) - 1 = 0
                            ASSERT_EQ(g, 2);   // (2 * 2) - 2 = 2
                            ASSERT_EQ(b, 2);   // Unchanged
    });

    testSuite.run();
}
