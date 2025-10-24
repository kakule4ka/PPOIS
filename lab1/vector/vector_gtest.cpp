#include <gtest/gtest.h>
#include "vector.h"
#include <sstream>
#include <cmath>

class vector_gtest : public ::testing::Test {
protected:
    static constexpr double EPS = 1e-10;
    void SetUp() override {
        v_zero = vector();
        v_a = vector(1.0, 2.0, 3.0);
        v_b = vector(-1.0, 4.0, 0.5);
        v_c = vector({0.0, 0.0, 1.0});
    }

    vector v_zero, v_a, v_b, v_c;
};

TEST_F(vector_gtest, DefaultConstructor) {
    EXPECT_NEAR(v_zero.size(), 0.0, EPS);
}

TEST_F(vector_gtest, ThreeComponentConstructorAndSize) {
    EXPECT_NEAR(v_a.size(), std::sqrt(14.0), EPS);
}

TEST_F(vector_gtest, InitializerListConstructorAndAssignment) {
    vector tmp = {0.0, 0.0, 1.0};
    EXPECT_TRUE(tmp == v_c);
    v_zero = {2.5, -1.5, 4.0};
    EXPECT_NEAR(v_zero.size(), std::sqrt(2.5*2.5 + (-1.5)*(-1.5) + 4.0*4.0), EPS);
}

TEST_F(vector_gtest, Swap) {
    vector a = v_a;
    vector b = v_b;
    a.swap(b);
    EXPECT_TRUE(a == v_b);
    EXPECT_TRUE(b == v_a);
}

TEST_F(vector_gtest, AdditionSubtractionAndAssignments) {
    vector sum = v_a + v_b;
    vector expected_sum(0.0, 6.0, 3.5);
    EXPECT_TRUE(sum == expected_sum);
    vector diff = v_a - v_b;
    vector expected_diff(2.0, -2.0, 2.5);
    EXPECT_TRUE(diff == expected_diff);
    vector t = v_a;
    t += v_b;
    EXPECT_TRUE(t == expected_sum);
    t = v_a;
    t -= v_b;
    EXPECT_TRUE(t == expected_diff);
}

TEST_F(vector_gtest, ScalarMultiplicationAndAssignment) {
    vector mul = v_a * 2.5;
    EXPECT_NEAR(mul.size(), std::sqrt(2.5*2.5 + 5.0*5.0 + 7.5*7.5), EPS);
    vector t = v_a;
    t *= -1.0;
    EXPECT_TRUE(t == vector(-1.0, -2.0, -3.0));
}

TEST_F(vector_gtest, ScalarDivisionAndAssignment) {
    vector div = v_a / 2.0;
    EXPECT_TRUE(div == vector(0.5, 1.0, 1.5));
    vector t = v_a;
    t /= 2.0;
    EXPECT_TRUE(t == div);
    EXPECT_THROW(v_a / 0.0, std::invalid_argument);
    EXPECT_THROW(v_a /= 0.0, std::invalid_argument);
}

TEST_F(vector_gtest, ElementwiseDivisionByVectorAndAssignment) {
    vector el = v_a / v_b;
    EXPECT_NEAR(el.size(), std::sqrt((-1.0)*(-1.0) + 0.5*0.5 + 6.0*6.0), EPS);
    vector has_zero = vector(1.0, 2.0, 0.0);
    EXPECT_THROW(v_a / has_zero, std::invalid_argument);
    vector t = v_a;
    EXPECT_THROW(t /= has_zero, std::invalid_argument);
}

TEST_F(vector_gtest, DotProduct) {
    double dot = v_a * v_b;
    EXPECT_NEAR(dot, 8.5, EPS);
    EXPECT_NEAR((v_zero * v_a), 0.0, EPS);
}

TEST_F(vector_gtest, CrossProductAndAssignment) {
    vector cross = v_a % v_b;
    vector expected(-11.0, -3.5, 6.0);
    EXPECT_TRUE(cross == expected);
    vector t = v_a;
    t %= v_b;
    EXPECT_TRUE(t == expected);
    EXPECT_TRUE((v_a % v_a) == vector(0.0, 0.0, 0.0));
}

TEST_F(vector_gtest, CosineBetweenVectors) {
    double cosab = v_a ^ v_b;
    double expected = (v_a * v_b) / (v_a.size() * v_b.size());
    EXPECT_NEAR(cosab, expected, 1e-12);
    EXPECT_THROW(v_zero ^ v_a, std::invalid_argument);
    EXPECT_THROW(v_a ^ v_zero, std::invalid_argument);
}

TEST_F(vector_gtest, EqualityInequality) {
    vector copy = v_a;
    EXPECT_TRUE(copy == v_a);
    EXPECT_FALSE(copy != v_a);
    EXPECT_TRUE(v_a != v_b);
}

TEST_F(vector_gtest, ComparisonsByLength) {
    EXPECT_TRUE(v_a < vector(10.0,10.0,10.0));
    EXPECT_TRUE(v_a <= vector(1.0,2.0,3.0));
    EXPECT_TRUE(vector(0.1,0.0,0.0) < vector(0.2,0.0,0.0));
    EXPECT_TRUE(vector(0.2,0.0,0.0) > vector(0.1,0.0,0.0));
    EXPECT_TRUE(vector(0.2,0.0,0.0) >= vector(0.2,0.0,0.0));
    EXPECT_TRUE(vector(0.2,0.0,0.0) <= vector(0.2,0.0,0.0));
}

TEST_F(vector_gtest, IOOperatorsValidAndInvalid) {
    std::stringstream out;
    out << v_a;
    std::string s = out.str();
    EXPECT_NE(s.find("1"), std::string::npos);
    EXPECT_NE(s.find("3"), std::string::npos);
    std::stringstream in("{1, 2, 3}");
    vector parsed;
    in >> parsed;
    EXPECT_TRUE(parsed == v_a);
    std::stringstream in2("1 2 3");
    vector parsed2;
    in2 >> parsed2;
    EXPECT_TRUE(in2.fail());
}

TEST_F(vector_gtest, SelfAssignmentAndChainedOperations) {
    vector s = v_a;
    s = s;
    EXPECT_TRUE(s == v_a);
    vector tmp = (v_a + v_b) * 2.0;
    vector expected = vector(0.0, 12.0, 7.0);
    EXPECT_TRUE(tmp == expected);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


