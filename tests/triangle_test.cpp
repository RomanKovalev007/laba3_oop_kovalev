#include <gtest/gtest.h>
#include "../include/triangle.h"


TEST(TriangleTest, DefaultConstructor) {
    Triangle  sq;
    EXPECT_NO_THROW(sq.area());
}

TEST(TriangleTest, ValidTriangleCreation) {
    Point points[3] = {{0,4}, {4,0}, {0,0}};
    EXPECT_NO_THROW(Triangle tr(points));
}

TEST(TriangleTest, InvalidTriangleCreation) {
    Point invalidPoints[3] = {{0,0}, {1,0}, {2,0}};
    EXPECT_THROW(Triangle tr(invalidPoints), std::invalid_argument);
}

TEST(TriangleTest, CopyConstructor) {
    Point points[3] = {{0,4}, {4,0}, {0,0}};
    const Triangle* tr = new Triangle(points);
    Triangle copy(*tr);
    EXPECT_TRUE(copy == *tr);
}

TEST(TriangleTest, MoveConstructor) {
    Point points[3] = {{0,4}, {4,0}, {0,0}};
    const Triangle* tr = new Triangle(points);
    Triangle moved(std::move(*tr));
    EXPECT_TRUE(moved == *tr);
}

TEST(TriangleTest, AssignmentOperator) {
    Point points[3] = {{0,4}, {4,0}, {0,0}};
    const Triangle* tr = new Triangle(points);
    Triangle  copy;
    copy = *tr;
    EXPECT_TRUE(copy == *tr);
}

TEST(TriangleTest, MoveAssignment) {
    Point points[3] = {{0,4}, {4,0}, {0,0}};
    const Triangle* tr = new Triangle(points);
    Triangle moved;
    moved = std::move(*tr);
    EXPECT_TRUE(moved == *tr);
}

TEST(TriangleTest, AreaCalculation) {
    Point points[3] = {{0,4}, {4,0}, {0,0}};
    const Triangle* tr = new Triangle(points);
    double area = tr->area();
    EXPECT_EQ(area, 8.0);
}

TEST(TriangleTest, GeometricCenter) {
    Point points[3] = {{0,3}, {3,0}, {0,0}};
    const Triangle* tr = new Triangle(points);
    Point center = tr->gcenter();
    EXPECT_EQ(center.x, 1.0);
    EXPECT_EQ(center.y, 1.0);
}

TEST(TriangleTest, EqualityOperator) {
    Point points[3] = {{0,4}, {4,0}, {0,0}};
    const Triangle* tr = new Triangle(points);
    Triangle copy(*tr);
    EXPECT_TRUE(copy == *tr);
}