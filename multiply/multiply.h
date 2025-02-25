#ifndef MULTIPLY_H
#define MULTIPLY_H
#include <iostream>
#include <gtest/gtest.h>

class Multiply
{
public:
    Multiply();

    void multiplier(int a, int b);
    int result;
    int *testPtr(int a);
    bool Get_Msg(unsigned int msgNum, unsigned short words[30]);
    void GetMsgByPtr(uint16_t *msgPtr);
    int getXValue();
    struct SomeData
    {
        int ID;
        std::string name;
        double height;
    };
    SomeData functionToReturnStruct();
    void multipleStrComp();

protected:
    int localX;
    char platform[5];
    uint16_t platformNum[5];
    int y;
    int PMsg[3][2][3];
    int doubleBufferIdx[30];
    std::map<int, uint16_t *> testingMap;
    FRIEND_TEST(MultiplyTests, PrivateVarTest);
};
// using extern didn't work
// extern Multiply multiplycas;
#endif