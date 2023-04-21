#include <gtest/gtest.h>

TEST(MyLibraryTest, Test1) {
EXPECT_EQ(1 + 1, 2);
}

TEST(MyLibraryTest, Test2) {
EXPECT_TRUE(false);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}