# Introduction to Google C++ Unit Testing

Source: https://medium.com/@rvarago/introduction-to-google-c-unit-testing-3d564c30f3b0


## Installation (install  into source directory, eg: /usr/src/gtest)
`sudo apt install libgtest-dev`


## Compile with cmake and make (install does not exist)
```
cd /usr/src/gtest
sudo CMakeLists.txt
sudo make
```

## Copy the generated binaries into your lib directory (for example: /usr/lib)
```
cd lib/
sudo cp libgtest.a libgtest_main.a /usr/lib
```

## Example, simple add and sub calculator

``` cpp
// calc.hpp
#ifndef CALC_HPP
#define CALC_HPP

int add(int op1, int op2);
int sub(int op1, int op2);

#endif
```

``` cpp
// calc.cpp
#include "calc.hpp"

int add(int op1, int op2) {
    return op1 + op2;
}

int sub(int op1, int op2) {
    return op1 - op2;
}
```

``` cpp
// calc_test.cpp
#include <gtest/gtest.h>
#include "calc.hpp"

TEST(CalcTest, Add) {
    ASSERT_EQ(2, add(1, 1));
    ASSERT_EQ(5, add(3, 2));
    ASSERT_EQ(10, add(7, 3));
}

TEST(CalcTest, Sub) {
    ASSERT_EQ(3, sub(5, 2));
    ASSERT_EQ(-10, sub(5, 15));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

## There are some new stuff from GoogleTest here:

    You must include the header file gtest/gtest.h (look at /usr/include/gtest for more information)
    The TEST macro is responsible for the creation of the test cases, where the first parameter is the test suite name and the second parameter is the specific test case name, which will be visible in the display information during execution
    The ASSERT_EQ, member of ASSERT_* group of macros, defines the equality test for GoogleTest and, based on this information, the framework verifies the success or failure of the tests and logs these information, aborting the test case when the test failed. You can use EXPECT_EQ if you want to continue the test case execution in the presence of a failure
    You can prepare the GoogleTest by calling testing::InitGoogleTest and passing a pointer to argc and the argv array (which is a pointer too)
    Then, you start GoogleTest by invoking RUN_ALL_TESTS
    

## Compilation

To compile the example, type the following command:
g++ -o calc_test calc_test.cpp calc.cpp -lgtest -lpthread
    
Note that you must link the code against the GoogleTest (gtest) and the POSIX Thread (pthread) libs.

## Some link

[googletest](https://github.com/google/googletest#Assertions)

