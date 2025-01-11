#include <gtest/gtest.h>
#include "../seqContainer.cpp"

#include <iostream>

TEST(seqContainer, empty) {
    // Arrange
    seqContainer<int> container(10);

    // Act (empty for this test)

    // Assert
    ASSERT_EQ(container.size(), 0);
    ASSERT_EQ(container.capacity(), 10);
}

TEST(seqContainer, filled_no_reserve) {
    // Arrange
    seqContainer<int> container(10);
    for (int i = 0; i <= 9; i++) {
        container.push_back(i);
    }

    // Act (empty for this test)

    // Assert
    ASSERT_EQ(container.size(), 10);
    ASSERT_EQ(container.capacity(), 10);
}

TEST(seqContainer, filled_with_reserve) {
    // Arrange
    seqContainer<int> container(10, true);

    // Act (empty for this test)
    for (int i = 0; i <= 9; i++) {
        container.push_back(i);
    }

    // Assert
    ASSERT_EQ(container.size(), 10);
    ASSERT_EQ(container.capacity(), 20);
}

TEST(seqContainer, append) {
    // Arrange
    seqContainer<int> container(10);
    
    // Act (empty for this test)

    container.append(1);

    container.append(15);

    // Assert
    ASSERT_EQ(container[0], 15);
    ASSERT_EQ(container.size(), 2);
}

TEST(seqContainer, push_back) {
    // Arrange
    seqContainer<int> container(10);
    
    // Act (empty for this test)

    container.push_back(1);

    container.push_back(15);

    // Assert
    ASSERT_EQ(container[1], 15);
    ASSERT_EQ(container.size(), 2);
}

TEST(seqContainer, erase_first) {
    // Arrange
    seqContainer<int> container(10);
    
    // Act (empty for this test)

    for (int i = 0; i <= 9; i++) {
        container.push_back(i);
    }
    container.erase(0);

    // Assert
    ASSERT_EQ(container[0], 1);
    ASSERT_EQ(container.size(), 9);
}

TEST(seqContainer, erase_last) {
    // Arrange
    seqContainer<int> container(10);
    
    // Act (empty for this test)

    for (int i = 0; i <= 9; i++) {
        container.push_back(i);
    }
    container.erase(9);

    // Assert
    ASSERT_THROW(container[9], std::out_of_range);
    ASSERT_EQ(container.size(), 9);
}

TEST(seqContainer, erase_middle) {
    // Arrange
    seqContainer<int> container(10);
    
    // Act (empty for this test)

    for (int i = 0; i <= 9; i++) {
        container.push_back(i);
    }
    container.erase(3);

    // Assert
    ASSERT_EQ(container[3], 4);
    ASSERT_EQ(container.size(), 9);
}

TEST(seqContainer, insert_middle) {
    // Arrange
    seqContainer<int> container(10);
    
    // Act (empty for this test)

    for (int i = 0; i <= 8; i++) {
        container.push_back(i);
    }
    container.insert(20, 3);

    // Assert
    ASSERT_EQ(container[3], 20);
    ASSERT_EQ(container.size(), 10);
}

TEST(seqContainer, size) {
    // Arrange
    seqContainer<int> container(10);
    
    // Act (empty for this test)

    for (int i = 0; i <= 9; i++) {
        container.push_back(i);
    }

    // Assert
    ASSERT_EQ(container.size(), 10);
}