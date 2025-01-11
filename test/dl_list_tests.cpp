#include <gtest/gtest.h>
#include "../dl_list.cpp"

#include <iostream>

TEST(ListDL, empty) {
    // Arrange
    ListDL<int> container;

    // Act (empty for this test)

    // Assert
    ASSERT_EQ(container.size(), 0);
}


TEST(ListDL, filled) {
    // Arrange
    ListDL<int> container;

    // Act (empty for this test)
    for (int i = 0; i <= 9; i++) {
        container.push_back(i);
    }

    // Assert
    ASSERT_EQ(container.size(), 10);
}

TEST(ListDL, append) {
    // Arrange
    ListDL<int> container;
    
    // Act (empty for this test)

    container.append(1);

    container.append(15);

    // Assert
    ASSERT_EQ(container[0], 15);
    ASSERT_EQ(container.size(), 2);
}

TEST(ListDL, push_back) {
    // Arrange
    ListDL<int> container;
    
    // Act (empty for this test)

    container.push_back(1);

    container.push_back(15);

    // Assert
    ASSERT_EQ(container[1], 15);
    ASSERT_EQ(container.size(), 2);
}

TEST(ListDL, erase_first) {
    // Arrange
    ListDL<int> container;
    
    // Act (empty for this test)

    for (int i = 0; i <= 9; i++) {
        container.push_back(i);
    }
    container.erase(0);

    // Assert
    ASSERT_EQ(container[0], 1);
    ASSERT_EQ(container.size(), 9);
}

TEST(ListDL, erase_last) {
    // Arrange
    ListDL<int> container;
    
    // Act (empty for this test)

    for (int i = 0; i <= 9; i++) {
        container.push_back(i);
    }
    container.erase(9);

    // Assert
    ASSERT_THROW(container[9], std::out_of_range);
    ASSERT_EQ(container.size(), 9);
}

TEST(ListDL, erase_middle) {
    // Arrange
    ListDL<int> container;
    
    // Act (empty for this test)

    for (int i = 0; i <= 9; i++) {
        container.push_back(i);
    }
    container.erase(3);

    // Assert
    ASSERT_EQ(container[3], 4);
    ASSERT_EQ(container.size(), 9);
}

TEST(ListDL, insert_middle) {
    // Arrange
    ListDL<int> container;
    
    // Act (empty for this test)

    for (int i = 0; i <= 8; i++) {
        container.push_back(i);
    }
    container.insert(20, 3);

    // Assert
    ASSERT_EQ(container[3], 20);
    ASSERT_EQ(container.size(), 10);
}

TEST(ListDL, size) {
    // Arrange
    ListDL<int> container;
    
    // Act (empty for this test)

    for (int i = 0; i <= 9; i++) {
        container.push_back(i);
    }

    // Assert
    ASSERT_EQ(container.size(), 10);
}

TEST(ListDL, insert_out_of_range) {
    // Arrange
    ListDL<int> container;
    
    // Act (empty for this test)

    for (int i = 0; i <= 9; i++) {
        container.push_back(i);
    }

    // Assert
    ASSERT_THROW(container.insert(20, 11);, std::out_of_range);
    ASSERT_EQ(container.size(), 10);
}