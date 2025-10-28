#include <gtest/gtest.h>
#include <cmath>

#include "vector.h"
#include "figure.h"
#include "rectangle.h"
#include "square.h"
#include "triangle.h"

using namespace figure;
using namespace vector;

TEST(PointTest, ConstructorAndEquality) {
    Point p1(1.0, 2.0);
    Point p2(1.0, 2.0);
    Point p3(1.5, 2.0);
    
    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
    EXPECT_TRUE(p1 != p3);
}

TEST(PointTest, DistanceCalculation) {
    Point p1(0, 0);
    Point p2(3, 4);
    
    EXPECT_DOUBLE_EQ(Distance(p1, p2), 5.0);
}

TEST(PointTest, StreamOperators) {
    Point p1(2.5, 3.7);
    std::stringstream ss;
    ss << p1;
    EXPECT_EQ(ss.str(), "(2.5, 3.7)");
    
    Point p2;
    std::stringstream ss2("1.5 2.5");
    ss2 >> p2.x >> p2.y;
    EXPECT_DOUBLE_EQ(p2.x, 1.5);
    EXPECT_DOUBLE_EQ(p2.y, 2.5);
}

TEST(RectangleTest, CenterAndArea) {
    Rectangle r(Point(0,0), Point(0,4), Point(6,4), Point(6,0));
    EXPECT_DOUBLE_EQ(r.Center().x, 3.0);
    EXPECT_DOUBLE_EQ(r.Center().y, 2.0);
    EXPECT_DOUBLE_EQ(r.Area(), 24.0);
    EXPECT_DOUBLE_EQ(static_cast<double>(r), 24.0);
}

TEST(RectangleTest, EqualityAndAssignment) {
    Rectangle r1(Point(0,0), Point(0,2), Point(3,2), Point(3,0));
    Rectangle r2 = r1;
    Rectangle r3;
    r3 = r1;
    EXPECT_TRUE(r1 == r2);
    EXPECT_TRUE(r1 == r3);
    EXPECT_FALSE(r1 != r2);
}

TEST(SquareTest, CenterAndArea) {
    Square s(Point(0,0), Point(0,5), Point(5,5), Point(5,0));
    EXPECT_DOUBLE_EQ(s.Center().x, 2.5);
    EXPECT_DOUBLE_EQ(s.Center().y, 2.5);
    EXPECT_DOUBLE_EQ(s.Area(), 25.0);
    EXPECT_DOUBLE_EQ(static_cast<double>(s), 25.0);
}

TEST(SquareTest, EqualityAndCopy) {
    Square s1(Point(0,0), Point(0,2), Point(2,2), Point(2,0));
    Square s2 = s1;
    EXPECT_TRUE(s1 == s2);
}

TEST(TriangleTest, CenterAndArea) {
    Triangle t(Point(0,0), Point(2,0), Point(1, std::sqrt(3.0)));
    EXPECT_NEAR(t.Center().x, 1.0, EPS);
    EXPECT_NEAR(t.Center().y, std::sqrt(3.0)/3, EPS);
    double expected = std::sqrt(3.0);
    EXPECT_NEAR(t.Area(), expected, EPS);
    EXPECT_NEAR(static_cast<double>(t), expected, EPS);
}

TEST(TriangleTest, EqualityAndAssignment) {
    Triangle t1(Point(0,0), Point(1,0), Point(0,1));
    Triangle t2;
    t2 = t1;
    EXPECT_TRUE(t1 == t2);
}

TEST(VectorTest, PushBackAndAccess) {
    Vector v;
    Rectangle* r = new Rectangle();
    Square* s = new Square();
    v.PushBack(r);
    v.PushBack(s);
    EXPECT_EQ(v.Size(), 2);
    EXPECT_EQ(v[0], r);
    EXPECT_EQ(v[1], s);
}

TEST(VectorTest, EraseAndClear) {
    Vector v;
    v.PushBack(new Rectangle());
    v.PushBack(new Square());
    v.Erase(0);
    EXPECT_EQ(v.Size(), 1);
    v.Clear();
    EXPECT_TRUE(v.IsEmpty());
}

TEST(VectorTest, OutOfRange) {
    Vector v;
    EXPECT_THROW(v[0], std::out_of_range);
    EXPECT_THROW(v.Erase(0), std::out_of_range);
}

TEST(PolymorphismTest, VirtualMethodsAndTotalArea) {
    Vector v;
    v.PushBack(new Rectangle(Point(0,0), Point(0,2), Point(3,2), Point(3,0))); // area = 6
    v.PushBack(new Square(Point(0,0), Point(0,2), Point(2,2), Point(2,0)));   // area = 4
    v.PushBack(new Triangle(Point(-2,0), Point(2,0), Point(0, 2 * std::sqrt(3))));             // area = 6

    double total = 0.0;
    for (size_t i = 0; i < v.Size(); ++i) {
        total += static_cast<double>(*v[i]);
        EXPECT_GT(v[i]->Area(), 0.0);
        Point c = v[i]->Center();
        EXPECT_FALSE(std::isnan(c.x) || std::isnan(c.y));
    }
    EXPECT_NEAR(total, 10 + 4 * std::sqrt(3), 1e-9);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}