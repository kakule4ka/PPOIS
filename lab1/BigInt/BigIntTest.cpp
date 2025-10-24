#include <gtest/gtest.h>
#include "BigInt.h"
#include <sstream>

class BigIntTest : public ::testing::Test {
protected:
    BigInt zero = BigInt(0);
    BigInt pos_small = BigInt(42);
    BigInt neg_small = BigInt(-73);
    BigInt pos_medium = BigInt("12345678901234567890"); // 3 words
    BigInt neg_medium = BigInt("-98765432109876543210");
    BigInt pos_large = BigInt("123456789012345678901234567890"); // 4 words
    BigInt neg_large = BigInt("-999999999999999999999999999999");
    BigInt max_single = BigInt("999999999");
    BigInt min_double = BigInt("1000000000");
};

static std::string to_str(const BigInt& v) {
    std::stringstream ss;
    ss << v;
    return ss.str();
}

// Конструкторы
TEST_F(BigIntTest, Constructors) {
    BigInt d;
    EXPECT_EQ(to_str(d), "0");
    EXPECT_EQ(to_str(BigInt(123)), "123");
    EXPECT_EQ(to_str(BigInt(-9999)), "-9999");
    EXPECT_EQ(to_str(BigInt("0")), "0");
    EXPECT_EQ(to_str(BigInt("-0")), "0");
    EXPECT_EQ(to_str(BigInt("12345678901234567890")), "12345678901234567890");

    BigInt copy(pos_large);
    EXPECT_EQ(to_str(copy), to_str(pos_large));
}

// Присваивание
TEST_F(BigIntTest, Assignment) {
    BigInt a;
    a = pos_medium;
    EXPECT_EQ(to_str(a), to_str(pos_medium));

    a = neg_medium;
    EXPECT_EQ(to_str(a), to_str(neg_medium));

    a = a; // Self-assign
    EXPECT_EQ(to_str(a), to_str(neg_medium));
}

// Унарные операторы
TEST_F(BigIntTest, Unary) {
    EXPECT_EQ(to_str(+pos_small), "42");
    EXPECT_EQ(to_str(-pos_small), "-42");
    EXPECT_EQ(to_str(-zero), "0");
    EXPECT_EQ(to_str(-neg_small), "73");
}

// Сравнения
TEST_F(BigIntTest, ComparisonsBigInt) {
    EXPECT_TRUE(pos_small > neg_small);
    EXPECT_TRUE(neg_large < neg_medium);
    EXPECT_TRUE(pos_large >= pos_medium);
    EXPECT_TRUE(pos_small <= pos_small);
    EXPECT_TRUE(zero == BigInt(0));
    EXPECT_TRUE(pos_large != neg_large);
}

TEST_F(BigIntTest, ComparisonsInt) {
    EXPECT_TRUE(pos_small > 0);
    EXPECT_TRUE(neg_small < 0);
    EXPECT_TRUE(pos_small == 42);
    EXPECT_TRUE(neg_small == -73);
    EXPECT_TRUE(zero == 0);
}

// Арифметика BigInt
TEST_F(BigIntTest, AddSubBigInt) {
    EXPECT_EQ(to_str(pos_small + pos_medium), "12345678901234567932");
    EXPECT_EQ(to_str(pos_medium - pos_small), "12345678901234567848");
    EXPECT_EQ(to_str(neg_small + pos_medium), "12345678901234567817");
    EXPECT_EQ(to_str(zero - pos_small), "-42");
}

TEST_F(BigIntTest, MulBigInt) {
    // Простые случаи
    BigInt a(123);
    BigInt b(456);
    EXPECT_EQ(to_str(a * b), "56088");
    
    // Коммутативность
    EXPECT_EQ(to_str(pos_small * pos_medium), to_str(pos_medium * pos_small));
    
    // Умножение на ноль
    EXPECT_EQ(to_str(zero * pos_large), "0");
    EXPECT_EQ(to_str(pos_large * zero), "0");
    
    // Умножение отрицательных
    BigInt neg_result = neg_small * pos_medium;
    EXPECT_TRUE(neg_result < zero);
    
    // Большие числа
    BigInt huge1("123456789012345678901234567890");
    BigInt huge2("2");
    EXPECT_EQ(to_str(huge1 * huge2), "246913578024691357802469135780");
}

TEST_F(BigIntTest, DivBigInt) {
    EXPECT_EQ(to_str((pos_medium * BigInt(2)) / pos_medium), "2");
    EXPECT_EQ(to_str(neg_medium / BigInt(2)), "-49382716054938271605");
    EXPECT_THROW(pos_medium / zero, std::invalid_argument);
    
    // Деление больших чисел
    BigInt huge("123456789012345678901234567890");
    EXPECT_EQ(to_str(huge / BigInt(10)), "12345678901234567890123456789");
}

// Составные присваивания с BigInt
TEST_F(BigIntTest, CompoundBigInt) {
    BigInt t = pos_small;
    t += pos_medium;
    EXPECT_EQ(to_str(t), "12345678901234567932");

    t = pos_medium;
    t -= pos_small;
    EXPECT_EQ(to_str(t), "12345678901234567848");

    t = pos_small;
    t *= pos_medium;
    EXPECT_EQ(to_str(t), to_str(pos_small * pos_medium));

    t = pos_medium;
    t /= pos_small;
    EXPECT_EQ(to_str(t), to_str(pos_medium / pos_small));
}

// Арифметика с int
TEST_F(BigIntTest, ArithmeticInt) {
    EXPECT_EQ(to_str(pos_small + 1), "43");
    EXPECT_EQ(to_str(1 + pos_small), "43");
    EXPECT_EQ(to_str(neg_small + 100), "27");
    EXPECT_EQ(to_str(100 + neg_small), "27");

    EXPECT_EQ(to_str(pos_small - 1), "41");
    EXPECT_EQ(to_str(1 - pos_small), "-41");
    EXPECT_EQ(to_str(neg_small - 100), "-173");

    EXPECT_EQ(to_str(pos_small * 3), "126");
    EXPECT_EQ(to_str(3 * pos_small), "126");
    EXPECT_EQ(to_str(neg_small * 2), "-146");
    
    EXPECT_EQ(to_str(pos_medium / 2), "6172839450617283945");
    EXPECT_EQ(to_str(BigInt(1000) / pos_small), "23");
    EXPECT_EQ(to_str(neg_medium / 10), "-9876543210987654321");
}

TEST_F(BigIntTest, CompoundInt) {
    BigInt t = pos_medium;
    t += 10;
    EXPECT_EQ(to_str(t), "12345678901234567900");

    t = pos_medium;
    t -= 1000;
    EXPECT_EQ(to_str(t), "12345678901234566890");

    t = pos_small;
    t *= 10;
    EXPECT_EQ(to_str(t), "420");

    t = pos_medium;
    t /= 3;
    EXPECT_EQ(to_str(t), "4115226300411522630");
}

// Инкремент/декремент
TEST_F(BigIntTest, IncrementDecrement) {
    BigInt t = pos_small;

    EXPECT_EQ(to_str(++t), "43");
    EXPECT_EQ(to_str(t++), "43");
    EXPECT_EQ(to_str(t), "44");

    EXPECT_EQ(to_str(--t), "43");
    EXPECT_EQ(to_str(t--), "43");
    EXPECT_EQ(to_str(t), "42");
    
    // С отрицательными числами
    BigInt n = neg_small;
    EXPECT_EQ(to_str(++n), "-72");
    EXPECT_EQ(to_str(--n), "-73");
}

// Ввод/вывод
TEST_F(BigIntTest, IO) {
    std::stringstream ss;
    ss << pos_medium;
    EXPECT_EQ(ss.str(), "12345678901234567890");

    ss.str("");
    ss << neg_medium;
    EXPECT_EQ(ss.str(), "-98765432109876543210");

    BigInt a;
    ss.str("123456");
    ss >> a;
    EXPECT_EQ(to_str(a), "123456");

    ss.clear();
    ss.str("-0");
    ss >> a;
    EXPECT_EQ(to_str(a), "0");

    ss.clear();
    ss.str("12x34");
    ss >> a;
    EXPECT_TRUE(ss.fail());
}

// Граничные случаи
TEST_F(BigIntTest, Boundaries) {
    EXPECT_EQ(to_str(max_single + BigInt(1)), "1000000000");
    EXPECT_EQ(to_str(min_double - BigInt(1)), "999999999");

    EXPECT_EQ(to_str(max_single * BigInt(2)), "1999999998");
    EXPECT_EQ(to_str(min_double * BigInt(2)), "2000000000");
    
    // Переход через base при сложении
    BigInt carry_test("999999999999999999");
    EXPECT_EQ(to_str(carry_test + BigInt(1)), "1000000000000000000");
}

// Цепочки операций
TEST_F(BigIntTest, Chained) {
    BigInt r = (pos_small + pos_medium) * BigInt(2) - (neg_small / BigInt(3));
    EXPECT_EQ(to_str(r), to_str((BigInt(42) + pos_medium) * BigInt(2) - (BigInt(-73) / BigInt(3))));
    
    // Сложные цепочки
    BigInt complex = (pos_medium * neg_small) / pos_small + (neg_medium - pos_large);
    EXPECT_TRUE(complex < zero);
}

// Исключения
TEST_F(BigIntTest, Exceptions) {
    EXPECT_THROW(BigInt(""), std::invalid_argument);
    EXPECT_THROW(BigInt("abc"), std::invalid_argument);
    EXPECT_THROW(BigInt("12a34"), std::invalid_argument);
    EXPECT_THROW(BigInt("--1"), std::invalid_argument);
    EXPECT_THROW(pos_small / zero, std::invalid_argument);
    EXPECT_THROW(zero / zero, std::invalid_argument);
}

// Тесты преобразования типов
TEST_F(BigIntTest, Conversion) {
    EXPECT_EQ(static_cast<int>(BigInt(123)), 123);
    EXPECT_EQ(static_cast<int>(BigInt(-456)), -456);
    EXPECT_EQ(static_cast<int>(zero), 0);
    
    EXPECT_EQ(static_cast<long long>(BigInt(1234567890)), 1234567890LL);
    EXPECT_EQ(static_cast<long long>(BigInt(-1234567890)), -1234567890LL);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
