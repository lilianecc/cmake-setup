#ifndef MULTIPLY_H
#define MULTIPLY_H
#include <iostream>

class Multiply
{
public:
    // Multiply();
    void multiplier(int a, int b);
    int result;
    int *testPtr(int a);
    bool Get_Msg(unsigned int msgNum, unsigned short words[30]);
private:
    int x;
    int y;
    int PMsg[3][2][3];
    int doubleBufferIdx[30];
};

#endif