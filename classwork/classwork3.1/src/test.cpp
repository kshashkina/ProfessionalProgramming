#include <print>
#include "Helpers.hpp"
#include "UnitTests.hpp"

int main() {
    UnitTests testSuite;

    testSuite.addTest("RepeatString_test1",
                      [](){
                          // Build:
                          std::vector<int> vec = {0, 2, 1};
                          std::string str = "home";

                          // Operate:
                          auto result = repeatString(vec, str);

                          // Check:
                          ASSERT_EQ(result, "homehome")
                      });

    testSuite.addTest("RepeatString_test2_EmptyVector",
                      [](){
                          // Build:
                          std::vector<int> vec = {};
                          std::string str = "home";

                          // Operate:
                          auto result = repeatString(vec, str);

                          // Check:
                          ASSERT_EQ(result, "")
                      });

    testSuite.addTest("RepeatString_test3_SingleElement",
                      [](){
                          // Build:
                          std::vector<int> vec = {3};
                          std::string str = "home";

                          // Operate:
                          auto result = repeatString(vec, str);

                          // Check:
                          ASSERT_EQ(result, "homehomehome")
                      });

    testSuite.addTest("RepeatString_test4_AllZeros",
                      [](){
                          // Build:
                          std::vector<int> vec = {0, 0, 0};
                          std::string str = "home";

                          // Operate:
                          auto result = repeatString(vec, str);

                          // Check:
                          ASSERT_EQ(result, "")
                      });

    testSuite.addTest("RepeatString_test5_NegativeAndPositive",
                      [](){
                          // Build:
                          std::vector<int> vec = {-1, 5, 3};
                          std::string str = "home";

                          // Operate:
                          auto result = repeatString(vec, str);

                          // Check:
                          ASSERT_EQ(result, "homehomehomehomehome")
                      });

    testSuite.run();
}
