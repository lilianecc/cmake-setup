#include "multiply.h"
#include <stdexcept>
#include <exception>
using namespace std;
// Multiply temp;
// Multiply::Multiply()
// {
// }
Multiply::Multiply(){};
void Multiply::multiplier(int a, int b)
{
    result = a * b;
    int *temp = testPtr(a);
    localX = a;
}

int *Multiply::testPtr(int a)
{
    uint32_t data = 0;
    uint32_t anotherData = 169;
    uint32_t addr = 0;
    uint32_t *src;
    src = &anotherData;
    // *((uint32_t *)(addr))=anotherData;
    cout << "data: " << data << endl;
    cout << "src: " << src << endl;
    cout << "*src: " << *src << endl;
    cout << "addr: " << addr << endl;

    uint32_t T_msg[30][2][30] = {0};
    src = &T_msg[1][0][0];
    src[0] = (uint32_t)0x0421;
    cout << "src[0]: " << src[0] << " , " << "T_msg[1][0][0]: " << T_msg[1][0][0] << endl;
    src[3] = (uint32_t)0x4147;
    cout << "src[3]: " << src[3] << " , " << "T_msg[1][0][3]: " << T_msg[1][0][3] << endl;
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

int Multiply::getXValue() { return localX; };