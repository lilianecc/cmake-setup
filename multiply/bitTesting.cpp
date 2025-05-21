#include "bitstruct.h"
#include <iostream>
#include "bitTesting.h"
#include <cstring>
// testing DPRAM stuff
Multiply multiplyClass;
int bitTestingStaticValue = 10;
BitTesting::BitTesting()
{
    // bitTestingAccessMultiplyX = multiplycas.getXValue();
    referenceVarInMultiply = multiplyClass.varForBitTesting;
    multiplyClass.varForBitTesting = 777;
    testSharedPtr = std::make_shared<ARH>();
   
}
void BitTesting::testStructArrInput(Multiply::Person *input)
{
    input[0].id = 123;
};
void funCallBack() { std::cout << "fun call back" << std::endl; };
unsigned char BitTesting::reverseAllBits(uint8_t byteIn)
{
    byteIn = (byteIn & 0xF0) >> 4 | (byteIn & 0x0F) << 4;
    byteIn = (byteIn & 0xCC) >> 2 | (byteIn & 0x33) << 2;
    byteIn = (byteIn & 0xAA) >> 1 | (byteIn & 0x55) << 1;
    return byteIn;
};
int BitTesting::getXValueFromBitTesting()
{
    multiplyClass.testSharedPtrFunc(testSharedPtr, testSharedPtr);
    uint16_t subA = testSharedPtr->data;
    uint16_t subB = testSharedPtr->data2;
    std::cout << "construction end" << std::endl;
    // multiplyClass.setLocalyWithCallBack(1111, &funCallBack, bitTestinglocalVal);
    bitTestingAccessMultiplyX = multiplyClass.message13R001.raw[0];
    return bitTestingAccessMultiplyX;
};
int BitTesting::getlocalValueinBitTesting() { return localValueinBitTesting; };
void BitTesting::setmultiplystaticlocal(int input)
{
    // multiplyClass.setLocalXValue(input);
    Multiply::localX = input;
    localValueinBitTesting = multiplyClass.localX;
};
void BitTesting::thisFunctionShowBracketDiff()
{
    uint16_t msg1R28 = 0x0A01;                                                                                      // 2561
    uint16_t aftersawp = (msg1R28 & 0x8000 >> 15) | (msg1R28 & 0x7000 >> 11) | (msg1R28 & 0x0FFF << 4);             // 2561
    uint16_t swapwithmiddleBracket = (msg1R28 & 0x8000) >> 15 | (msg1R28 & 0x7000) >> 11 | (msg1R28 & 0x0FFF) << 4; // 40976
    uint16_t swapNoBracket = msg1R28 & 0x8000 >> 15 | msg1R28 & 0x7000 >> 11 | msg1R28 & 0x0FFF << 4;               // 2561
    uint16_t thirdpart = (msg1R28 & 0x0FFF) << 4;
    // we can see that middlebracket is the correct one
};
void BitTesting::DPRAMTest()
{
    int DPRAM_SIZE = (DPRAM_OFFSET + 1) * 4; // 1048576
    dpramBytes = new char[DPRAM_SIZE];       // 0x0000023edf9b1040
    std::memset(dpramBytes, 0, DPRAM_SIZE);

    int base_addr = (uint64_t)(dpramBytes); //(uint_32)dpramBytes
    uint32_t IO_BASE_addr = base_addr;
    uint32_t *MSG_r_READ_PTR;
    MSG_r_READ_PTR = (uint32_t *)(IO_BASE_addr + MSG_R_QUEUE_PTR_OFFSET * 4);

    uint8_t test = 0b111; // this is 7, because 2^2+2^1+2^0=7
    std::cout << "test:" << test << std::endl;
    test = 0b111 << 2;     // this means add 2 0 to the right -->11100-->2^4+2^3+2^2+2^1+2^0
    test &= ~(0b111 << 2); // AND and NOT, ^ is XOR,
    std::cout << test << std::endl;
    std::cout << "here" << std::endl;
}
uint16_t *BitTesting::PickMsg(uint16_t msgNum)
{
    uint16_t *tempMsg;
    return tempMsg;
};
uint16_t BitTesting::checksum(const uint16_t *msg, const size_t length)
{
    if (!msg || (0 == length))
    {
        return 0;
    }

    auto cyclicRightShift = [](const uint16_t value, size_t uShiftAmount) -> uint16_t
    {
        uShiftAmount = uShiftAmount % (sizeof(uint16_t) * 8); // sizeof(uint16_t)=2

        return (value >> uShiftAmount) | (value << ((sizeof(uint16_t) * 8) - uShiftAmount));
    };

    auto cyclicLeftShift = [](const uint16_t value, size_t uShiftAmount) -> uint16_t
    {
        uShiftAmount = uShiftAmount % (sizeof(uint16_t) * 8);

        return (value << uShiftAmount) | (value >> ((sizeof(uint16_t) * 8) - uShiftAmount));
    };

    uint16_t checksum = 0;

    for (size_t uWordIdx = 0; uWordIdx < length; ++uWordIdx)
    {
        checksum ^= cyclicRightShift(msg[uWordIdx], uWordIdx);
    }

    return cyclicLeftShift(checksum, length);
}
