#include <gtest/gtest.h>
#include "../include/square.h"


TEST(SquareTest, DefaultConstructor) {
    Square  sq;
    EXPECT_NO_THROW(sq.area());
}

TEST(SquareTest, ValidSquareCreation) {
    Point points[4] = {{0,4}, {4,0}, {0,0}, {4,4}};
    EXPECT_NO_THROW(Square sq(points));
}

TEST(SquareTest, InvalidSquareCreation) {
    Point invalidPoints1[4] = {{0,0}, {1,0}, {2,0}, {3,0}};
    Point invalidPoints2[4] = {{0,4}, {4,0}, {0,0}, {5,4}};
    Point invalidPoints3[4] = {{0,0}, {3,0}, {3,2}, {2,0}};
    EXPECT_THROW(Square sq(invalidPoints1), std::invalid_argument);
    EXPECT_THROW(Square sq(invalidPoints2), std::invalid_argument);
}

TEST(SquareTest, CopyConstructor) {
    Point points[4] = {{0,4}, {4,0}, {0,0}, {4,4}};
    const Square* sq = new Square(points);
    Square copy(*sq);
    EXPECT_TRUE(copy == *sq);
}

TEST(SquareTest, MoveConstructor) {
    Point points[4] = {{0,4}, {4,0}, {0,0}, {4,4}};
    const Square* sq = new Square(points);
    Square moved(std::move(*sq));
    EXPECT_TRUE(moved == *sq);
}

TEST(SquareTest, AssignmentOperator) {
    Point points[4] = {{0,4}, {4,0}, {0,0}, {4,4}};
    const Square* sq = new Square(points);
    Square  copy;
    copy = *sq;
    EXPECT_TRUE(copy == *sq);
}

TEST(SquareTest, MoveAssignment) {
    Point points[4] = {{0,4}, {4,0}, {0,0}, {4,4}};
    const Square* sq = new Square(points);
    Square moved;
    moved = std::move(*sq);
    EXPECT_TRUE(moved == *sq);
}

TEST(SquareTest, AreaCalculation) {
    Point points[4] = {{0,4}, {4,0}, {0,0}, {4,4}};
    const Square* sq = new Square(points);
    double area = sq->area();
    EXPECT_EQ(area, 16.0);
}

TEST(SquareTest, GeometricCenter) {
    Point points[4] = {{0,4}, {4,0}, {0,0}, {4,4}};
    const Square* sq = new Square(points);
    Point center = sq->gcenter();
    EXPECT_EQ(center.x, 2.0);
    EXPECT_EQ(center.y, 2.0);
}

TEST(SquareTest, EqualityOperator) {
    Point points[4] = {{0,4}, {4,0}, {0,0}, {4,4}};
    const Square* sq = new Square(points);
    Square copy(*sq);
    EXPECT_TRUE(copy == *sq);
}