#include "UnitTests.h"
#include "MegaDataPool.cpp"

int main() {
    UnitTests testSuite;

    testSuite.addTest("TestMegaDataInitialization",
                      []() {
                          MegaData data;
                          for (size_t i = 0; i < MegaData::SMALL_ARRAY_SIZE; ++i) {
                              ASSERT_EQ(data.smallArray[i], 42.0f);
                          }
                          for (size_t i = 0; i < MegaData::BIG_ARRAY_SIZE; ++i) {
                              ASSERT_EQ(data.bigArray[i], 42.0);
                          }
                      });

    testSuite.addTest("TestMegaDataReset",
                      []() {
                          MegaData data;
                          data.smallArray[0] = 0.0f;
                          data.bigArray[0] = 0.0;
                          data.reset();
                          ASSERT_EQ(data.smallArray[0], 42.0f);
                          ASSERT_EQ(data.bigArray[0], 42.0);
                      });

    testSuite.addTest("TestMegaDataPoolAcquireRelease",
                      []() {
                          MegaDataPool pool(2);
                          ASSERT_EQ(pool.size(), 2);
                          ASSERT_EQ(pool.usedSize(), 0);

                          MegaData* data1 = pool.acquire();
                          ASSERT_EQ(pool.usedSize(), 1);

                          MegaData* data2 = pool.acquire();
                          ASSERT_EQ(pool.usedSize(), 2);

                          pool.release(data1);
                          ASSERT_EQ(pool.usedSize(), 1);

                          pool.release(data2);
                          ASSERT_EQ(pool.usedSize(), 0);
                      });

    testSuite.addTest("TestMegaDataPoolExhaustion",
                      []() {
                          MegaDataPool pool(1);
                          MegaData* data1 = pool.acquire();
                          ASSERT_NEQ(data1, nullptr);
                          ASSERT_THROW(pool.acquire(), std::out_of_range);


                          pool.release(data1);
                      });

    testSuite.run();

    return 0;
}
