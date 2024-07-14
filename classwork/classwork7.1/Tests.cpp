#include "Rectangle.h"
#include "UnitTests.h"

int main() {
    UnitTests testSuite;

    // Test cases for Rectangle class
    testSuite.addTest("TestRectangleArea",
                      []() {
                          Rectangle rectangle(3.0, 4.0);
                          ASSERT_EQ(rectangle.getArea(), 12.0);
                      });

    testSuite.addTest("TestRectangleAreaZero",
                      []() {
                          Rectangle rectangle(0.0, 4.0);
                          ASSERT_EQ(rectangle.getArea(), 0.0);
                      });

    testSuite.addTest("TestRectangleAreaNegative",
                      []() {
                          Rectangle rectangle(-3.0, 4.0);
                          ASSERT_EQ(rectangle.getArea(), -12.0);
                      });

    testSuite.addTest("TestRectangleCanBePlacedInsideTrue",
                      []() {
                          Rectangle rect1(2.0, 3.0);
                          Rectangle rect2(5.0, 6.0);
                          ASSERT_EQ(rect1.canBePlacedInside(rect2), true);
                      });

    testSuite.addTest("TestRectangleCanBePlacedInsideFalse",
                      []() {
                          Rectangle rect1(5.0, 6.0);
                          Rectangle rect2(2.0, 3.0);
                          ASSERT_EQ(rect1.canBePlacedInside(rect2), false);
                      });

    testSuite.addTest("TestRectangleBiggerSideWidth",
                      []() {
                          Rectangle rectangle(3.0, 4.0);
                          ASSERT_EQ(rectangle.getBiggerSide(), 4.0);
                      });

    testSuite.addTest("TestRectangleBiggerSideHeight",
                      []() {
                          Rectangle rectangle(4.0, 3.0);
                          ASSERT_EQ(rectangle.getBiggerSide(), 4.0);
                      });

    testSuite.addTest("TestRectangleBiggerSideEqual",
                      []() {
                          Rectangle rectangle(3.0, 3.0);
                          ASSERT_EQ(rectangle.getBiggerSide(), 3.0);
                      });

    testSuite.run();

    return 0;
}
