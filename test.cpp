#include "histogram.h"
#include "svg.h"
#include <cassert>

void test_positive()
{
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
}

void test_negative()
{
    double min = 0;
    double max = 0;
    find_minmax({-1, -2, -3}, min, max);
    assert(min == -3);
    assert(max == -1);
}

void test_equal()
{
    double min = 0;
    double max = 0;
    find_minmax({1, 1, 1}, min, max);
    assert(min == 1);
    assert(max == 1);
}

void test_single()
{
    double min = 0;
    double max = 0;
    find_minmax({1}, min, max);
    assert(min == 1);
    assert(max == 1);
}

void test_empty()
{
    double min = 0;
    double max = 0;
    find_minmax({}, min, max);
    assert(min == 0);
    assert(max == 0);
}

 void test_dz1()
 {
     double font_size=8;
     bool flag=true;
     check_size(font_size, flag);
     assert(flag=true);
 }

 void test_dz2()
 {
     double font_size=1;
     bool flag=true;
     check_size(font_size, flag);
     assert(flag=true);
 }

int main()
{
   test_positive();
   test_negative();
   test_equal();
   test_single();
   test_empty();
   test_dz1();
   test_dz2();
}
