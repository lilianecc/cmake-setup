#include "multiply.h"
#include "addition.h"
#include "arh.h"
#include "bitstruct.h"
int main()
{
    // Multiply testClass;
    // testClass.multiplier(3, 4);
    // int result = addition(1, 2);
    // int *testPtr = testClass.testPtr(1);
    // unsigned short arr[30] = {0};
    // unsigned short *arrPtr;

    // test on msg
    unsigned char *msg = (unsigned char *)malloc(62);
    unsigned short *msgInshort = (unsigned short *)malloc(31); // use uint16_t is better
    int remoteAdd = 1;
    int rOrT = 1;
    int msgNum = 22;
    int wordCount = 30;
    // use shift and mask
    // uint16_t tempMsgNum = (msgNum & 0x1F) << 5;
    // uint16_t tempWordCount = wordCount & 0x1F;
    uint16_t tempBits = (remoteAdd << 11) | rOrT << 10 | (msgNum & 0x1F) << 5 | wordCount & 0x1F;
    msg[0] = tempBits >> 8;
    msg[1] = tempBits & 0xFF;
    // command word should be msg[1] and msg[2] since each index contains 8 bits
    msgInshort[0] = tempBits; //3806 for 1,1, 22, 30
    // test union
    bitsetConverter converter;
    Bitstruct bitTemp;
    bitTemp.remoteAddress = 1;
    bitTemp.rOrT = 1;
    bitTemp.subAddress = 22;
    bitTemp.wordCount = 30;
    converter.bitstruct = bitTemp;
    std::cout << "bit int 16: " << converter.bitInt16 << std::endl;//shows up as 5665
    // reverse the union
    bitsetConverter converterRev;
    converterRev.bitInt16 = 3806;
    std::cout << converterRev.bitstruct.subAddress << std::endl;//30, 0, 14, 0
    
    // testClass.Get_Msg(msgNum, arr);
    // std::cout << "main finished!" << 12345 << std::endl;
    // std::cout << "addition result: " << result << std::endl;
  
    return 0;
}
