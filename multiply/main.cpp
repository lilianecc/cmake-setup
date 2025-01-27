#include "multiply.h"
#include "addition.h"
#include "arh.h"
#include "bitstruct.h"
#include "bitTesting.h"
#include <bitset>
int main()
{
    // Multiply testClass;
    // testClass.multiplier(3, 4);
    // int result = addition(1, 2);
    // int *testPtr = testClass.testPtr(1);
    // unsigned short arr[30] = {0};
    // unsigned short *arrPtr;
    BitTesting bitTesting;
    unionHasStructInstruct unionhasSoManyStruct;
    
    // tes  t on msg
    unsigned char *msg = (unsigned char *)malloc(62);
    unsigned short *msgInshort = (unsigned short *)malloc(31); // use uint16_t is better
    int remoteAdd = 29;
    int rOrT = 0;
    int msgNum = 1;
    int wordCount = 30;
    // use shift and mask
    // uint16_t tempMsgNum = (msgNum & 0x1F) << 5;
    // uint16_t tempWordCount = wordCount & 0x1F;
    uint16_t tempBits = (remoteAdd << 11) | rOrT << 10 | (msgNum & 0x1F) << 5 | wordCount & 0x1F;
    msg[0] = tempBits >> 8;
    msg[1] = tempBits & 0xFF;
    // command word should be msg[1] and msg[2] since each index contains 8 bits
    msgInshort[0] = tempBits; // 59454 for 29,0, 1, 30
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
    std::cout << "gonna print the same as tempBits: " << revConv.revbitInt << std::endl;//still 59454
    //test bit representation
    std::string airplane="F-35A     ";
    for(char c:airplane){
        std::bitset<8> bitRep(c);
        std::cout<<bitRep<<","<<std::endl;
    };
    TMsgs Tmsgs;
    //Tmsgs.raw[]={0};
    memset(Tmsgs.raw,0 , sizeof(Tmsgs));//cant use memset to initialize to other number, like 2
    structInsideStruct tempStruct;
    // tempStruct={
    //     123,
    //     {1234}
    // };
    //test checksum
    uint16_t TMsg[30][30] = {{0}, {0}};
    TMsg[0][0] = 1057;
    TMsg[0][1] = 0;
    TMsg[0][2] = 0;
    TMsg[0][3] = 16711;
    TMsg[0][29] = 0;
    uint16_t *TMsg1 = TMsg[0];
    uint16_t checksumRet = bitTesting.checksum(TMsg1, 30);
    std::copy(TMsg1, TMsg1 + 30, msgInshort + 1);
    // testClass.Get_Msg(msgNum, arr);
    // std::cout << "main finished!" << 12345 << std::endl;
    // std::cout << "addition result: " << result << std::endl;


    T1Msgs t1msg;
    T2Msgs t2msg;
    //need to update msg based on input msg number


    return 0;
}
