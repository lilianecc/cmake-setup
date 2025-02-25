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
int main()
{
    Multiply testClass;
    // testClass.multiplier(3, 4);
    //  int result = addition(1, 2);
    //  int *testPtr = testClass.testPtr(1);
    //  unsigned short arr[30] = {0};
    //  unsigned short *arrPtr;
    PlatformID platformID;
    
    uint16_t *msgPtr;
    uint16_t msgByRef[5] = {0};
  //  testClass.GetMsgByPtr(msgPtr);
    testClass.GetMsgByPtr(msgByRef);
    testClass.multipleStrComp();
    testClass.functionToReturnStruct();
    printAllChrono();

    //**** test singleton
    singletonTest &s1 = singletonTest::getInstance();
    singletonTest &s2 = singletonTest::getInstance();
    s1.multiplier(3, 4);
    std::cout << "testing class member value: " << s2.getLocalValue() << std::endl;

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
    BitTesting bitTesting;
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
    rMsgs msg1;
    rMsgs msgNegative;
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
