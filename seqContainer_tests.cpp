#include <gtest/gtest.h>
#include "seqContainer.cpp"

template <typename T>
class seqContainerTest : public ::testing::Test {
    protected:
    seqContainer<T>* container;

    void SetUp() override {
        container = new seqContainer<T>(10);
    }

    void TearDown() override {
        delete container;
    }
};

TEST_F(seqContainerTest<int>, IntInitialization) {
    EXPECT_EQ(container->capacity(), 10);
    EXPECT_EQ(container->size(), 0);
}