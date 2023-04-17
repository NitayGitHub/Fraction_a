#include "doctest.h"
#include "sources/Fraction.hpp"
#include <iostream>
using namespace std;
using namespace ariel;



TEST_CASE("Initialize 0 in denominator") {
    CHECK_THROWS(Fraction(1,0));
}

TEST_CASE("Check boolean operators"){
    Fraction f1(1,2);
    Fraction f2(128,256);
    Fraction f3(4,5);

    CHECK(f1 == f2);
    CHECK(f3 > f1);
    CHECK(f3 >= f1);
    CHECK(f1 < f3);
    CHECK(f1 <= f3);
}

TEST_CASE("Check math operators"){
    Fraction half(1,2);
    Fraction f4(277, 40);

    CHECK(half + 13.867 == 14.367);
    CHECK(13.867 - half == 13.367);
    CHECK(half * 13.85 == f4);
    CHECK(13.85 / half == 27.7);
}

TEST_CASE("Check boolean operators with floats and fractions"){
    Fraction f1(15,2);

    CHECK(7.5 == f1);
    CHECK(f1 > 7);
    CHECK(f1 >= 7.5);
    CHECK(f1 < 9);
    CHECK(f1 <= 8);
    CHECK(f1 - 7.5 == 0);
}

TEST_CASE("Check unary operators"){
    Fraction f1(1,2);

    CHECK(++f1 == 1.5);
    CHECK(--f1 == 0.5);
    CHECK(f1++ == 1.5);
    CHECK(f1-- == 0.5);
}

