#ifndef MULTIPLY_H
#define MULTIPLY_H
#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include "bitstruct.h"
#include "arh.h"
#include "rMsgStruct.h"
// forward declaration
//  class BitTesting;
class Multiply
{
public:
    Multiply();
    // BitTesting* BitTestingClassPtr;
    void multiplier(int a, int b);
    int result;
    int *testPtr(int a);
    bool Get_Msg(unsigned int msgNum, unsigned short words[30]);
    void GetMsgByPtr(uint16_t *msgPtr);
    void commandWord();
    void testOnBitShift();
    void throwawayArea();
    void calculateDecimalWithSignBit(int num);
    void inputcharForSwitch(std::string input);
    int getXValue();
    void setLocalXValue(int input);
    int setLocalyWithCallBack(int input, void (*unc_ptr)(), int &passIn);
    unsigned char reverseBits(uint8_t bits);
    uint16_t reverseWholeWord(uint16_t word);
    uint16_t GetWord(int n);
    struct SomeData
    {
        int ID;
        std::string name;
        double height;
    };
    SomeData functionToReturnStruct();
    void multipleStrComp();
    enum Instructions
    {
        NO_INSTRUVTION = 0,
        STARTINSTRUCTION = 1
    };
    static int localX;
    static message13R001Union message13R001;
    int varForBitTesting = 666;
    struct Person
    {
        std::string name;
        int id;
    };
    static Person staticArr[10];
    void testSharedPtrFunc(std::shared_ptr<ARH> ptrVale, std::shared_ptr<ARH> &ptrRef);
    struct BlockRecord
    {
        uint16_t block;
        uint16_t record;
    };
    static std::map<int, BlockRecord> mapWithStruct;

protected:
    mixDatatype rMsgsArr[4];
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