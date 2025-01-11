#include <gtest/gtest.h>
#include "dl_list.cpp"

template <typename T>
class DlListTest : public ::testing::Test{
    protected:
    ListDL<T>* container;

    void SetUp() override {
        container = new ListDL()
    };

    void TearDown() override {
        delete container;
    }

}