#include <gtest/gtest.h>
#include "figure.h"
#include "triangle.h"
#include "square.h"
#include "rectangle.h"
#include "array.h"

TEST(Triangle, EmptyConstructor) {
    Triangle t;
    EXPECT_DOUBLE_EQ(t.ploshad(), 0.0);
    EXPECT_EQ(t.center(), std::make_pair(0.0, 0.0));
}

TEST(Triangle, VectorConstructor) {
    std::vector<double> x = {0.0, 10.0, 0.0};
    std::vector<double> y = {0.0, 0.0, 10.0};
    Triangle t(x, y);
    EXPECT_DOUBLE_EQ(t.ploshad(), 50.0);
    EXPECT_NEAR(t.center().first, 3.33333, 0.00001);
    EXPECT_NEAR(t.center().second, 3.33333, 0.00001);
}


TEST(Triangle, AssignmentOperator) {
    std::vector<double> x1 = {0.0, 10.0, 0.0};
    std::vector<double> y1 = {0.0, 0.0, 10.0};
    Triangle t1(x1, y1);
    
    std::vector<double> x2 = {0.0, 5.0, 0.0};
    std::vector<double> y2 = {0.0, 0.0, 5.0};
    Triangle t2(x2, y2);

    t2 = t1;

    EXPECT_DOUBLE_EQ(t2.ploshad(), 50.0);
    EXPECT_NEAR(t2.center().first, 3.33333, 0.00001);
    EXPECT_NEAR(t2.center().second, 3.33333, 0.00001);
}

TEST(Square, EmptyConstructor) {
    Square s;
    EXPECT_DOUBLE_EQ(s.ploshad(), 0.0);
    EXPECT_EQ(s.center(), std::make_pair(0.0, 0.0));
}

TEST(Square, VectorConstructor) {
    std::vector<double> x = {0.0, 10.0, 10.0, 0.0};
    std::vector<double> y = {0.0, 0.0, 10.0, 10.0};
    Square s(x, y);
    EXPECT_DOUBLE_EQ(s.ploshad(), 100.0);
    EXPECT_EQ(s.center(), std::make_pair(5.0, 5.0));
}

TEST(Rectangle, EmptyConstructor) {
    Rectangle r;
    EXPECT_DOUBLE_EQ(r.ploshad(), 0.0);
    EXPECT_EQ(r.center(), std::make_pair(0.0, 0.0));
}

TEST(Rectangle, VectorConstructor) {
    std::vector<double> x = {0.0, 10.0, 10.0, 0.0};
    std::vector<double> y = {0.0, 0.0, 5.0, 5.0};
    Rectangle r(x, y);
    EXPECT_DOUBLE_EQ(r.ploshad(), 50.0);
    EXPECT_EQ(r.center(), std::make_pair(5.0, 2.5));
}

TEST(Array, EmptyConstructor) {
    Array a;
    EXPECT_EQ(a.get_size(), 10);
    for (size_t i = 0; i < a.get_size(); ++i) {
        EXPECT_EQ(a[i], nullptr);
    }
}

TEST(Array, SizeConstructor) {
    Array a(15);
    EXPECT_EQ(a.get_size(), 15);
    for (size_t i = 0; i < a.get_size(); ++i) {
        EXPECT_EQ(a[i], nullptr);
    }
}
