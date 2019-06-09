#include "BubbleSort.hpp"
#include <vector>
#include <stdexcept>
#include <gtest/gtest.h>

TEST(BubbleSortTest, NullTest) {
    std::vector<size_t> arr;
    EXPECT_NO_THROW(BubbleSort(arr));
}

int main(int argc, char **argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}