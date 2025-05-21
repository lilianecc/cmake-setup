#ifndef BITTESTING_H
#define BITTESTING_H
#include <iostream>
#include "multiply.h"
#include "arh.h"
class BitTesting
{
public:
    BitTesting();
    uint16_t checksum(const uint16_t *msg, const size_t length);
    void DPRAMTest();
    uint16_t *PickMsg(uint16_t msgNum);
    int getXValueFromBitTesting();
    void funCallBack();
    void setmultiplystaticlocal(int input);
    int getlocalValueinBitTesting();
    void thisFunctionShowBracketDiff();
    void testStructArrInput(Multiply::Person *input);
    static int bitTestingStaticValue;
    int referenceVarInMultiply;
    unsigned char reverseAllBits(uint8_t byteIn);
    

private:
    std::shared_ptr<ARH> testSharedPtr;

    char *dpramBytes = nullptr;
    int bitTestinglocalVal = 3;
    int localValueinBitTesting;
    int bitTestingAccessMultiplyX;
    enum
    {
        DPRAM_OFFSET = 0x0003FFFF,          // decimal: 262143
        MSG_R_QUEUE_PTR_OFFSET = 0X0003FF34 //

    };
};

#endif