#include "rMsgStruct.h"
#include "multiplyhelper.h"
#include <queue>
#include <map>
void bitShift()
{
    std::map<int, uint16_t *> testingMap;
    // test on configurationID
    ConfigID configrationID;
    uint16_t disable = 1;
    uint16_t reserved = 7;
    uint16_t configuration = 2050;
    configrationID.disable = 1;
    configrationID.reserved = 7;
    configrationID.configuration = 2050;
    ConfigIDUnion configUnion;
    configUnion.configID = configrationID;
    uint16_t testbits = disable << 15 | reserved << 12 | configuration; // original setup
    // using raw to interpret the values
    ConfigIDUnion usingRawUnion;
    usingRawUnion.raw = (testbits & 0x8000) >> 15 | (testbits & 0x7000) >> 11 | (testbits & 0x0FFF) << 4; // 32815

    // just sawp bytes and ?
    ConfigIDUnion configUnionByteSwap;
    configUnionByteSwap.raw = _byteswap_ushort(testbits); // doesnt work
    uint16_t msgWithCommandWord[21] = {0};
    uint16_t msg2WithCW[31] = {0};
    uint16_t revBits = (30 << 11) | 1 << 6 | 1 << 5 | 29 & 0x1F;
    msgWithCommandWord[0] = revBits;
    msgWithCommandWord[1] = 0x421; // pretend to be ID
    msgWithCommandWord[4] = 1200;  // pretend velocity
    uint16_t msgWithoutCW[30] = {0};
    std::copy(msgWithCommandWord + 1, msgWithCommandWord + 30, msgWithoutCW);

    testingMap[3] = msgWithoutCW;
    testingMap[2] = msg2WithCW + 1;
    // std::copy(testingMap[3],testingMap[3]+30,msgWithoutCW);
    std::cout << msgWithoutCW[3] << std::endl;

    // using vector of struct
    struct MSGWithID
    {
        uint16_t ID;
        uint16_t arr[30] = {0};
    };
    std::queue<MSGWithID> msgs;
    MSGWithID firstMsg;
    firstMsg.ID = 1;
    std::copy(msgWithCommandWord + 1, msgWithCommandWord + 21, firstMsg.arr);
    MSGWithID secondMsg;
    secondMsg.ID = 2;
    std::copy(msg2WithCW + 1, msg2WithCW + 30, secondMsg.arr);
    msgs.push(firstMsg);
    msgs.push(secondMsg);
    MSGWithID temp;
    temp = msgs.front();
    // msgs.pop();
    msgs = {}; // same as pop
}