#include "singletonTest.h"

singletonTest::singletonTest(){
    localValue=123;
};
void singletonTest::multiplier(int a, int b)
{
    int result = a * b;
    localValue = a;
}

int singletonTest::getLocalValue() { return localValue; }