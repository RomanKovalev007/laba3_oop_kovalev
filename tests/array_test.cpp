#include <gtest/gtest.h>
#include "../include/octagon.h"
#include "../include/triangle.h"
#include "../include/square.h"
#include "../include/array.h"

TEST(ArrayTest, DefaultConstructor) {
    Array arr;
    EXPECT_EQ(arr.getSize(), 0);
    EXPECT_EQ(arr.getCapacity(), 0);
    EXPECT_TRUE(arr.isEmpty());
}

TEST(ArrayTest, CapacityConstructor) {
    Array arr(10);
    EXPECT_EQ(arr.getSize(), 0);
    EXPECT_EQ(arr.getCapacity(), 10);
    EXPECT_TRUE(arr.isEmpty());
}

TEST(ArrayTest, PushAndSize) {
    Array arr;
    Figure* fig1 = new Octagon();
    Figure* fig2 = new Triangle();
    
    arr.push(fig1);
    arr.push(fig2);
    
    EXPECT_EQ(arr.getSize(), 2);
    EXPECT_FALSE(arr.isEmpty());
}

TEST(ArrayTest, ResizeOnPush) {
    Array arr(2);
    Figure* fig1 = new Octagon();
    Figure* fig2 = new Triangle();
    Figure* fig3 = new Square();
    
    arr.push(fig1);
    arr.push(fig2);
    EXPECT_EQ(arr.getCapacity(), 2);
    
    arr.push(fig3);
    EXPECT_GE(arr.getCapacity(), 3);
}

TEST(ArrayTest, AccessOperator) {
    Array arr;
    Figure* fig1 = new Octagon();
    Figure* fig2 = new Triangle();
    arr.push(fig1);
    arr.push(fig2);
    
    EXPECT_EQ(arr[0], fig1);
    EXPECT_EQ(arr[1], fig2);

    EXPECT_THROW(arr[2], std::out_of_range);
}


TEST(ArrayTest, RemoveElement) {
    Array arr;
    Figure* fig1 = new Octagon();
    Figure* fig2 = new Triangle();
    Figure* fig3 = new Square();

    arr.push(fig1);
    arr.push(fig2);
    arr.push(fig3);
    
    EXPECT_EQ(arr.getSize(), 3);
    arr.remove(1);
    EXPECT_EQ(arr.getSize(), 2);
    EXPECT_EQ(arr[0], fig1);
    EXPECT_EQ(arr[1], fig3);
}

TEST(ArrayTest, CopyConstructor) {
    Array arr1;
    Figure* fig1 = new Octagon();
    Figure* fig2 = new Triangle();
    arr1.push(fig1);
    arr1.push(fig2);
    
    Array arr2(arr1);
    EXPECT_EQ(arr2.getSize(), arr1.getSize());
    EXPECT_EQ(*arr2[0], *arr1[0]);
    EXPECT_EQ(*arr2[1], *arr1[1]);

}

TEST(ArrayTest, MoveConstructor) {
    Array arr1;
    Figure* fig1 = new Octagon();
    Figure* fig2 = new Triangle();
    arr1.push(fig1);
    arr1.push(fig2);
    
    Array arr2(std::move(arr1));
    EXPECT_EQ(arr2.getSize(), 2);
    EXPECT_EQ(arr1.getSize(), 0);
    EXPECT_EQ(arr1.getCapacity(), 0);

}

TEST(ArrayTest, CopyOperator) {
    Array arr1;
    Figure* fig1 = new Octagon();
    arr1.push(fig1);
    
    Array arr2;
    arr2 = arr1;
    
    EXPECT_EQ(arr2.getSize(), arr1.getSize());
    EXPECT_EQ(*arr2[0],*arr1[0]);
}

TEST(ArrayTest, MoveOperator) {
    Array arr1;    
    Figure* fig1 = new Octagon();
    Figure* fig2 = new Triangle();
    arr1.push(fig1);
    arr1.push(fig2);
    
    Array arr2;
    arr2 = std::move(arr1);
    
    EXPECT_EQ(arr2.getSize(), 2);
    EXPECT_EQ(arr1.getSize(), 0);
}

TEST(ArrayTest, TotalArea) {
    Array arr;
    const Point points1[4] = {{0, 0}, {0, 3}, {3, 0}, {3, 3}};
    Figure* fig1 = new Square(points1);
    const Point points2[3] = {{0, 0}, {0, 4}, {4, 0}};
    Figure* fig2 = new Triangle(points2);
    arr.push(fig1);
    arr.push(fig2);
    
    double total = arr.totalArea();
    EXPECT_EQ(total, 17.0);
}