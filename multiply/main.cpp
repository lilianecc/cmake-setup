#include "multiply.h"
#include "addition.h"
#include "arh.h"
#include "bitstruct.h"
#include "bitTesting.h"
#include <bitset>
#include "multiply.h"
#include "msgTest.h"
#include "singletonTest.h"
#include "rMsgStruct.h"
#include "chronoTest.h"
#include <cmath>
int localVale = 12345;
int foo(char c)
{
    std::cout << localVale << std::endl;
    return (int)c;
}
void bar()
{
    std::cout << localVale << std::endl;
};
// int (*func_ptr)(char)=&foo;
int main()
{

    BitTesting bitTesting; // check varForBitTesting value
    configurationIDUnion ConfigUnion;
    ConfigUnion.raw = 0xA01;
    std::string test;
    halfhalfUnion storetest;
    storetest.halfhalf.char1 = 0x55;
    storetest.halfhalf.char2 = 0x53;
    halfhalfUnion storetestRaw;
    storetestRaw.raw = ((storetest.raw & 0xFF00) >> 8)|((storetest.raw & 0x00FF) <<8);
    Multiply testClass;
    uint16_t blcok = testClass.mapWithStruct[5].block;
    testClass.throwawayArea();
    bitTesting.testStructArrInput(Multiply::staticArr);
    std::cout << testClass.varForBitTesting << std::endl;
    testClass.varForBitTesting = 888;
    testClass.message13R001.raw[0] = 1;
    std::cout << testClass.message13R001.raw[0] << std::endl;
    // call bittesting again to see the value
    bitTesting.getXValueFromBitTesting();
    // testing static variable for multiple class to use
    //  bitTesting.setmultiplystaticlocal(1234567);
    //  int  xvalueInmain=bitTesting.getlocalValueinBitTesting();
    //  testClass.setLocalyWithCallBack(1234, &bar, localVale);
    Multiply::Instructions tempEnum = Multiply::NO_INSTRUVTION;
    if (tempEnum == Multiply::NO_INSTRUVTION)
        std::cout << "success" << std::endl;
    testClass.inputcharForSwitch("download");
    testClass.testOnBitShift();
    //  testClass.calculateDecimalWithSignBit(65190);
    //  testClass.calculateDecimalWithSignBit(328);

    // testing _byteswap_ushort, if you have 16 bits all different things, need to completely reverse it
    all16union INSUnion;
    INSUnion.raw = 0xBE8F;
    // INSUnion.allINS.bit7 = 1;  // for 10000001000000000 raw becomes 129 because of swap
    // INSUnion.allINS.bit10 = 1; // for 1000000100100000
    uint16_t wordINS = 2048;
    all16union aNewINSUnion;

    aNewINSUnion.raw = bitTesting.reverseAllBits(wordINS >> 8) | bitTesting.reverseAllBits(wordINS << 8);
    // bytewswap doesnt work, every bits need to be swap

    // this test 11 bits different, 4 bits reserve
    somebitsdiffUnion SOMEBitsUnion;
    SOMEBitsUnion.someBits.altitude = 1;
    SOMEBitsUnion.someBits.bit10 = 1;
    SOMEBitsUnion.someBits.notused = 2;
    SOMEBitsUnion.raw = (16384);
    uint16_t tempPtr;
    tempPtr = SOMEBitsUnion.raw;
    // testing subaddress move
    subAddUnion subADDUnion;
    subADDUnion.SubADD.subaddress = 18;
    subADDUnion.SubADD.reserve = 1234;
    subAddUnion newSubADDUnion;
    uint16_t bitsComeInFromAC = 18 << 11 | 1234; // this uses the subadd first, then reserve later
    // hence we need to switch
    newSubADDUnion.raw = (bitsComeInFromAC & 0x07FF) >> 5 | (bitsComeInFromAC & 0xF800) << 11;
    // testing LAR
    uint16_t larRaw = 0x4A80;
    LARUnion larUnion;
    larUnion.lar.MSN = 5;
    larUnion.lar.IZ = 1;
    larUnion.lar.scale = 1;

    larUnion.raw = ((larRaw & 0x8000) >> 15) | ((larRaw & 0x4000) >> 13) | ((larRaw & 0x2000) >> 11) | ((larRaw & 0x1000) >> 9) | ((larRaw & 0x0E00) >> 5) | (larRaw & 0x0180) | ((larRaw & 0x0040) << 3) | ((larRaw & 0x0020) << 5) | ((larRaw & 0x0010) << 7) | ((larRaw & 0x0008) << 9) | ((larRaw & 0x0004) << 11) | ((larRaw & 0x0002) << 13) | ((larRaw & 0x0001) << 15);
    // testClass.multiplier(3, 4);
    //  int result = addition(1, 2);
    //  int *testPtr = testClass.testPtr(1);
    //  unsigned short arr[30] = {0};
    //  unsigned short *arrPtr;
    PlatformID platformID;
    PlatformID revPlatformIDraw;
    platformID.platformBytes[0] = 0x46;
    platformID.platformBytes[1] = 45;
    revPlatformIDraw.raw[0] = 17965; // this will be -F instead of F-
    revPlatformIDraw.raw[0] = _byteswap_ushort(revPlatformIDraw.raw[0]);
    std::cout << platformID.platformBytes[0] << std::endl;
    uint16_t *msgPtr;
    uint16_t msgByRef[5] = {0};
    //  testClass.GetMsgByPtr(msgPtr);
    testClass.GetMsgByPtr(msgByRef);

    testClass.multipleStrComp();
    testClass.functionToReturnStruct();
    // printAllChrono();

    //**** test singleton
    // singletonTest &s1 = singletonTest::getInstance();
    // singletonTest &s2 = singletonTest::getInstance();
    // s1.multiplier(3, 4);
    // std::cout << "testing class member value: " << s2.getLocalValue() << std::endl;

    enum fail_bit_mask
    {
        ALL_PASS = 0x0001,
        ONE_FAIL = 0x0002,
        ALL_FAIL = 0x0003
    };
    uint32_t interfaceFail;
    uint32_t temp = interfaceFail |= ALL_FAIL;
    std::cout << temp << std::endl;

    //**** test on bit shift and message
    // msgCreateAndShift();

    // test checksum

    unsigned short *msgInshort = (unsigned short *)malloc(31); // use uint16_t is better
    uint16_t TMsg[30][30] = {{0}, {0}};
    TMsg[0][0] = 1057;
    TMsg[0][1] = 10;
    TMsg[0][2] = 20;
    TMsg[0][3] = 16711;
    TMsg[0][12] = 12345;
    TMsg[0][29] = 100;
    uint16_t *TMsg1 = TMsg[0];
    uint16_t checksumRet = bitTesting.checksum(TMsg1, 30);
    std::copy(TMsg1, TMsg1 + 30, msgInshort + 1);

    // std::cout << "main finished!" << 12345 << std::endl;
    // std::cout << "addition result: " << result << std::endl;

    T1Msgs t1msg;
    T2Msgs t2msg;
    // t1msg.raw[0]=tempRaw;
    std::copy(TMsg1, TMsg1 + 4, t1msg.raw);
    uint16_t *tempArr;
    tempArr = t1msg.raw;
    std::cout << t1msg.raw[2] << std::endl;

    std::vector<uint16_t *> testVectorArrPtr;
    testVectorArrPtr.push_back(t1msg.raw);
    testVectorArrPtr.push_back(t2msg.raw);
    int i = 1;
    for (uint16_t *ptr : testVectorArrPtr)
    {
        std::copy(ptr, ptr + 5, TMsg[i]);
        i++;
    };

    // enum UAIMsgWordCount
    // {
    //     T1 = 30,
    //     T2 = 30
    // };
    // char input = 'T1';
    // enum UAIMsgWordCount testWordCount = static_cast<UAIMsgWordCount>(input);
    // std::cout << testWordCount << std::endl;
    // uint16_t msgWithCommandWord[31] = {0};
    // msgWithCommandWord[0] = tempBits;
    // std::copy(TMsg1, TMsg1 + 30, msgWithCommandWord + 1);

    // testing bit shift to create double and sign change
    rMsgsData msg1;
    rMsgsData msgNegative;
    msg1.velocityMSB = 1200;
    msgNegative.velocityMSB = -1200;
    double combineV = (msg1.velocityMSB << 16) + (msg1.velocityLSB);
    int32_t combineVelocityInt32 = (msg1.velocityMSB << 16) + (msg1.velocityLSB);
    uint32_t combineVN = (msgNegative.velocityMSB << 16) + (msgNegative.velocityLSB);
    int32_t combineVelocityNInt32 = (msgNegative.velocityMSB << 16) + (msgNegative.velocityLSB);
    bool sameOr = (combineVelocityNInt32 == (int32_t)(combineVN));
    std::cout << ((combineVelocityNInt32 == (int32_t)(combineVN)) ? "same" : "no") << std::endl;

    return 0;
}
