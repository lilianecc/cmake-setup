#include "msgTest.h"
#include <bitset>
#include <iostream>
#include "bitstruct.h"
#include "string.h"
void msgCreateAndShift()
{
    unsigned char *msg = (unsigned char *)malloc(62);
    unsigned short *msgInshort = (unsigned short *)malloc(31); // use uint16_t is better
    int remoteAdd = 29;
    int rOrT = 0;
    int msgNum = 1;
    int wordCount = 30;
    // use shift and mask
    // uint16_t tempMsgNum = (msgNum & 0x1F) << 5;
    // uint16_t tempWordCount = wordCount & 0x1F;
    uint16_t tempBits = (remoteAdd << 11) | rOrT << 10 | (msgNum & 0x1F) << 5 | wordCount & 0x1F; // can use decimal to shift, code knows how
    msg[0] = tempBits >> 8;
    msg[1] = tempBits & 0xFF;
    // command word should be msg[1] and msg[2] since each index contains 8 bits
    msgInshort[0] = tempBits; // 59454 for 29,0, 1, 30
    //word count has 5 bits so only shift to left 11 bits, just think of padding 11 zero to the right
    uint16_t revBits = (wordCount << 11) | msgNum << 6 | rOrT << 5 | remoteAdd & 0x1F;
    // test union
    bitsetConverter converter;
    Bitstruct bitTemp;
    bitTemp.remoteAddress = 29;
    bitTemp.rOrT = 0;
    bitTemp.subAddress = 1;
    bitTemp.wordCount = 30;
    converter.bitstruct = bitTemp;
    std::cout << "bit int 16: " << converter.bitInt16 << std::endl; // shows up as 59454
    // use the int to get bitstruct
    bitsetConverter converterRev;
    converterRev.bitInt16 = 61533;
    std::cout << converterRev.bitstruct.subAddress << std::endl; // 29,0,1,30
    // reverse the struct
    revBitConverter revConv;
    RevBitStruct revBitStruct;
    revBitStruct.RevRemoteAddress = 29;
    revBitStruct.RevROrT = 0;
    revBitStruct.RevSubAddress = 1;
    revBitStruct.RevWordCount = 30;
    revConv.revBitStruct = revBitStruct;
    std::cout << "gonna print the same as tempBits: " << revConv.revbitInt << std::endl; // still 59454
    // test bit representation
    std::string airplane = "F-35A     ";
    for (char c : airplane)
    {
        std::bitset<8> bitRep(c);
        std::cout << bitRep << "," << std::endl;
    };
    TMsgs Tmsgs;
    // Tmsgs.raw[]={0};
    memset(Tmsgs.raw, 0, sizeof(Tmsgs)); // cant use memset to initialize to other number, like 2
    structInsideStruct tempStruct;
};