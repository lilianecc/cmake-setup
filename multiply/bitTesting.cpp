#include "bitstruct.h"
#include <iostream>
#include "bitTesting.h"
#include <cstring>
// testing DPRAM stuff
Multiply multiplyClass;

BitTesting::BitTesting()
{
    //bitTestingAccessMultiplyX = multiplycas.getXValue();
}

int BitTesting::getXValueFromBitTesting() { return bitTestingAccessMultiplyX; };
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
uint16_t *BitTesting::PickMsg(uint16_t msgNum) {

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
