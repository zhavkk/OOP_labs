#include <gtest/gtest.h>
#include "calculations.h"
#include "array.h"
#include "rectangle.h"
#include "square.h"
#include "triangle.h"

TEST(Triangle, empty_constructor)
{
    Triangle<double> t;
    std::pair<double, double> dot = {0, 0};
    std::pair<double, double> time = middle<Triangle<double>, double>(t);
    double surface = surf<Triangle<double>, double>(t);
    EXPECT_EQ(time, dot);
    EXPECT_EQ(0, surface);
}

TEST(Triangle, vect_const)
{
    std::vector<double> x{1, 2, 3};
    std::vector<double> y{1, 2, 3};
    std::vector<std::pair<double, double>> three(3);
    for (int i = 0; i < 3; ++i)
    {
        three[i].first = x[i];
        three[i].second = y[i];
    }
    Triangle<double> t(three);

    std::pair<double, double> dot = {2, 2};
    std::pair<double, double> time = middle<Triangle<double>, double>(t);
    EXPECT_EQ(time, dot);
}

TEST(Rectangle, empty)
{
    Rectangle<double> r;
    std::pair<double, double> dot = {0, 0};
    std::pair<double, double> time = middle<Rectangle<double>, double>(r);
    double surface = surf<Rectangle<double>, double>(r);
    EXPECT_NEAR(time.first, dot.first, 1e-6);
    EXPECT_NEAR(time.second, dot.second, 1e-6);
    EXPECT_NEAR(0, surface, 1e-6);
}

TEST(Rectangle, vect_const)
{
    std::vector<double> x{1, 2, 3, 1};
    std::vector<double> y{1, 2, 3, 1};
    std::vector<std::pair<double, double>> four(4);
    for (int i = 0; i < 4; ++i)
    {
        four[i].first = x[i];
        four[i].second = y[i];
    }
    Rectangle<double> r(four);

    std::pair<double, double> dot = {1.75, 1.75};  
    std::pair<double, double> time = middle<Rectangle<double>, double>(r);
    EXPECT_NEAR(time.first, dot.first, 1e-6);
    EXPECT_NEAR(time.second, dot.second, 1e-6);
}

TEST(Square, empty)
{
    Square<double> s;
    std::pair<double, double> dot = {0, 0};
    std::pair<double, double> time = middle<Square<double>, double>(s);
    double surface = surf<Square<double>, double>(s);
    EXPECT_NEAR(time.first, dot.first, 1e-6);
    EXPECT_NEAR(time.second, dot.second, 1e-6);
    EXPECT_NEAR(0, surface, 1e-6);
}

TEST(Square, vect_const)
{
    std::vector<double> x{1, 2, 3, 1};
    std::vector<double> y{1, 2, 3, 1};
    std::vector<std::pair<double, double>> four(4);
    for (int i = 0; i < 4; ++i)
    {
        four[i].first = x[i];
        four[i].second = y[i];
    }
    Square<double> s(four);

    std::pair<double, double> dot = {1.75, 1.75};  
    std::pair<double, double> time = middle<Square<double>, double>(s);
    EXPECT_NEAR(time.first, dot.first, 1e-6);
    EXPECT_NEAR(time.second, dot.second, 1e-6);
}

TEST(Array, common_surf)
{
    Array<Triangle<double>> a(2);
    Triangle<double> *t1 = new Triangle<double>();
    Triangle<double> *t2 = new Triangle<double>();
    a[0] = *t1;
    a[1] = *t2;
    EXPECT_EQ(a.common_surf(), 0.0);
}
