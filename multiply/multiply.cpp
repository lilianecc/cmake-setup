#include "multiply.h"
#include <stdexcept>
#include <exception>
// Multiply temp;
// Multiply::Multiply()
// {
// }
void Multiply::multiplier(int a, int b)
{
    result = a * b;
}

int *Multiply::testPtr(int a)
{
    if (a > 100)
    {
        throw std::string("test");
    }
    int buffIdx = doubleBufferIdx[a];
    std::cout << "test end!" << std::endl;
    return &PMsg[a][buffIdx][0];
};

bool Multiply::Get_Msg(unsigned int msgNum, unsigned short words[30])
{
    char *dest_msg_ptr = (char *)&words[0];
    std::cout << "test end!" << std::endl;
    return true;
};