#include <gtest/gtest.h>
#include "../include/octagon.h"

TEST(OctagonTest, DefaultConstructor) {
    Octagon oct;
    EXPECT_NO_THROW(oct.area());
}

TEST(OctagonTest, ValidOctagonCreation) {
    Point points1[8] = {{2,0}, {4,0}, {6,2}, {6,4}, {4,6}, {2,6}, {0,4}, {0,2}};
    Point points2[8] = {{2,0}, {4,0}, {6,2}, {6,4}, {4,4}, {2,6}, {0,4}, {0,2}};
    EXPECT_NO_THROW(Octagon oct(points1));
    EXPECT_NO_THROW(Octagon oct(points2));
}

TEST(OctagonTest, InvalidOctagonCreation) {
    Point invalidPoints1[8] = {{0,0}, {1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}, {7,0}};
    EXPECT_THROW(Octagon oct(invalidPoints1), std::invalid_argument);
}

TEST(OctagonTest, CopyConstructor) {
    Point points[8] = {{2,0}, {4,0}, {6,2}, {6,4}, {4,6}, {2,6}, {0,4}, {0,2}};
    Octagon oct(points);
    Octagon copy(oct);
    EXPECT_TRUE(copy == oct);
}

TEST(OctagonTest, MoveConstructor) {
    Point points[8] = {{2,0}, {4,0}, {6,2}, {6,4}, {4,6}, {2,6}, {0,4}, {0,2}};
    Octagon oct(points);
    Octagon original(oct);
    Octagon moved(std::move(oct));
    EXPECT_TRUE(moved == original);
}

TEST(OctagonTest, AssignmentOperator) {
    Point points[8] = {{2,0}, {4,0}, {6,2}, {6,4}, {4,6}, {2,6}, {0,4}, {0,2}};
    Octagon oct(points);
    Octagon copy;
    copy = oct;
    EXPECT_TRUE(copy == oct);
}

TEST(OctagonTest, MoveAssignment) {
    Point points[8] = {{2,0}, {4,0}, {6,2}, {6,4}, {4,6}, {2,6}, {0,4}, {0,2}};
    Octagon oct(points);
    Octagon original(oct);
    Octagon moved;
    moved = std::move(oct);
    
    EXPECT_TRUE(moved == original);
}

TEST(OctagonTest, AreaCalculation) {
    Point points1[8] = {{2,0}, {4,0}, {6,2}, {6,4}, {4,6}, {2,6}, {0,4}, {0,2}};
    Point points2[8] = {{2,0}, {4,0}, {6,2}, {6,4}, {4,4}, {2,6}, {0,4}, {0,2}};

    const Octagon* oct1 = new Octagon(points1);
    const Octagon* oct2 = new Octagon(points2);
    double area1 = oct1->area();
    double area2 = oct2->area();
    EXPECT_EQ(area1, 28.0);
    EXPECT_EQ(area2, 24.0);
}

TEST(OctagonTest, GeometricCenter) {
    Point points[8] = {{2,0}, {4,0}, {6,2}, {6,4}, {4,6}, {2,6}, {0,4}, {0,2}};
    const Octagon* oct = new Octagon(points);
    Point center = oct->gcenter();
    EXPECT_EQ(center.x, 3.0);
    EXPECT_EQ(center.y, 3.0);
}

TEST(OctagonTest, EqualityOperator) {
    Point points[8] = {{2,0}, {4,0}, {6,2}, {6,4}, {4,6}, {2,6}, {0,4}, {0,2}};
    const Octagon* oct = new Octagon(points);
    Octagon copy(*oct);
    EXPECT_TRUE(copy == *oct);
}