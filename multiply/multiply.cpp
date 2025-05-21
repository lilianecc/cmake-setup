#include "multiply.h"
#include "rMsgStruct.h"
#include "multiplyhelper.h"
#include <stdexcept>
#include <exception>
#include <algorithm>
#include <queue>
#include <bitset>
#include <cmath>
#include <iostream>
#include <array>
#include <vector>
using namespace std;

// Multiply::Multiply()
// {
// }
std::map<int, Multiply::BlockRecord> Multiply::mapWithStruct = {
    {5, Multiply::BlockRecord{2, 3}}, {15, Multiply::BlockRecord{12, 13}}

};
Multiply::Multiply()
{
    rMsgsArr[4] = {};
};
int Multiply::localX = 0;
message13R001Union Multiply::message13R001 = {};
Multiply::Person Multiply::staticArr[10] = {};
void Multiply::multiplier(int a, int b)
{
    result = a * b;
    int *temp = testPtr(a);
    localX = a;
}

void Multiply::multipleStrComp()
{
    platform[0] = 'A';
    platform[1] = 'B';
    platform[2] = 'C';
    platformNum[0] = 'A';
    platformNum[1] = 'B';
    platformNum[2] = 'C';
    string acceptableOnes[3] = {"ACC", "ABC", "AEC"};

    string platformStr(platform);
    std::cout << platformStr << std::endl;

    for (string content : acceptableOnes)
    {
        int a = strncmp(platform, content.c_str(), 3);
        if (a == 0)
        {
            std::cout << "found" << std::endl;
            break;
        }
        else
        {
            std::cout << "not found" << std::endl;
        }
    };
    bool temp = platformStr.compare(acceptableOnes[0]);
};
void Multiply::commandWord()
{
    CommandWordUnion useForTest;
    useForTest.CWint = 27229;
    int remoteAdd = 29;
    int rOrT = 1;
    int msgNum = 1;
    int wordCount = 30;

    uint16_t revBits = (wordCount << 11) | msgNum << 6 | rOrT << 5 | remoteAdd & 0x1F;
    uint16_t commandwordRaw = (remoteAdd << 11) | rOrT << 10 | (msgNum & 0x1F) << 5 | wordCount & 0x1F;
    CommandWordUnion notreversedUnion;
    notreversedUnion.CWint = commandwordRaw;
    // reverse
    CommandWordUnion reversedUnion;
    reversedUnion.CWint = revBits;
    //**testing convert word to byte right away
    CommandWordBytesUnion cmdBytes;
    uint8_t tempfirstByte = (uint8_t)commandwordRaw;
    uint8_t temp2ndByte = (uint8_t)(commandwordRaw >> 8);
    cmdBytes.rawBytes[0] = tempfirstByte;
    cmdBytes.rawBytes[1] = temp2ndByte;
};

Multiply::SomeData Multiply::functionToReturnStruct()
{
    SomeData student;
    RMsgs msg1;
    msg1.RMSGS.id = 1;
    msg1.RMSGS.code = 123;
    testingMap[1] = msg1.raw + 1;
    uint16_t *temparr;

    // std::copy(msg1.raw, msg1.raw + 6, temparr);           // different ways to copy array to another
    // std::copy(testingMap[1], testingMap[1] + 6, temparr); // 2nd way of copying
    // msg1.RMSGS.id = 321;                                  // this will change the map value automatically since the value is a pointer

    // // find key 1
    // auto it = testingMap.find(1);
    // if (it != testingMap.end())
    // {
    //     std::cout << "found key 1" << std::endl;
    // }

    // if the array are different , map doesnt work!!!
    return student;
};

void Multiply::testOnBitShift()
{
    bitShift(); // test move content into a helper file
};
void Multiply::testSharedPtrFunc(std::shared_ptr<ARH> ptrVale, std::shared_ptr<ARH> &ptrRef)
{
    // ptrVale->data = 123;
    ptrRef->data2 = 345;
};

int *Multiply::testPtr(int a)
{
    uint32_t data = 0;
    uint32_t anotherData = 169;
    uint32_t addr = 0;
    uint32_t *src;
    src = &anotherData;
    // *((uint32_t *)(addr))=anotherData;
    cout << "data: " << data << endl;
    cout << "src: " << src << endl;
    cout << "*src: " << *src << endl;
    cout << "addr: " << addr << endl;

    uint32_t T_msg[30][2][30] = {0};
    src = &T_msg[1][0][0];
    src[0] = (uint32_t)0x0421;
    cout << "src[0]: " << src[0] << " , " << "T_msg[1][0][0]: " << T_msg[1][0][0] << endl;
    src[3] = (uint32_t)0x4147;
    cout << "src[3]: " << src[3] << " , " << "T_msg[1][0][3]: " << T_msg[1][0][3] << endl;
    if (a > 100)
    {
        throw std::string("test");
    }
    int buffIdx = doubleBufferIdx[a];
    std::cout << "test end!" << std::endl;
    return &PMsg[a][buffIdx][0];
};

bool Multiply::Get_Msg(unsigned int msgNum, unsigned short words[30])
{
    char *dest_msg_ptr = (char *)&words[0];
    std::cout << "test end!" << std::endl;
    return true;
};
void Multiply::GetMsgByPtr(uint16_t *msgPtr)
{
    platformNum[0] = 123;
    platformNum[1] = 234;
    platformNum[3] = 2323;
    std::copy(platformNum, platformNum + 5, msgPtr);
};
uint16_t Multiply::GetWord(int n)
{
    //<insert range check here probably>;
    //  (((uint16_t)byteArray[n * 2]) << 8) | byteArray[n * 2 + 1];
    return 1;
};
int Multiply::getXValue() { return localX; };
void Multiply::throwawayArea()
{
    struct gpsKeyData
    {
        uint16_t num;
        std::vector<vector<int>> data;
    };
    gpsKeyData gpsKey;
    gpsKey.num = 4;
    int msgKey[4][8];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            msgKey[i][j] = j + i;
        }
    };
    int msgKey1[8];
    std::copy(msgKey[0], msgKey[0] + 8, msgKey1);

    for (int i = 0; i < 2; i++)
    {
        vector<int> tempKey;
        for (int j = 0; j < 8; j++)
        {
            tempKey.push_back(msgKey[i][j]);
        }
        gpsKey.data.push_back(tempKey);
    }
    for (int i = 2; i < 4; i++)
    {
        vector<int> tempKey;
        for (int j = 0; j < 8; j++)
        {
            tempKey.push_back(msgKey[i][j]);
        }
        gpsKey.data.push_back(tempKey);
    }
    // uint16_t arm = 65190;
    // int32_t int32Arm = (int32_t)arm;
    // std::bitset<16> bitform(int32Arm);
    // std::bitset<32> bitform32(int32Arm);

    // double result = (double)(int32Arm * std::pow(2, -7));
    // int32_t temp = int32Arm;
    // int base = 1;
    // int dec_value = 0;
    // while (temp)
    // {
    //     int last_digit = temp % 10;
    //     temp = temp / 10;
    //     dec_value += last_digit * base;
    //     base = base * 2;
    // }
    // std::cout << dec_value << std::endl;
    uint16_t words[5] = {123, 10, 20, 30, 40};
    std::cout << words[0] << std::endl;              // prints out 123,
    std::cout << &words[0] << std::endl;             // prints out the pointer of the array 0x70f446
    std::cout << (uint32_t *)words[0] << std::endl;  // prints out 0x7b, it's 123 into pointer?
    std::cout << (uint32_t *)&words[0] << std::endl; // casting the pointer to 32 bit pointer so still 0x70f446
    std::cout << (uint32_t)words[0] << std::endl;    // casting 123 to 32 bit, still 123
    // std::cout << (uint32_t)&words[0] << std::endl;
};
void Multiply::calculateDecimalWithSignBit(int num)
{

    // uint32_t num32 = 2147483647;
    uint16_t newNum = (num & 0x7fff); // & num >> 1;
    int32_t newNumIn32 = (int16_t)(num);
    int16_t result = (newNum * std::pow(2, -7));
    int16_t resultIn32 = (newNumIn32 * std::pow(2, -7));
    // if ((num&0x8000)>0)
    // {
    //     result = -result;
    // };
    result = ((num & 0x8000) != 0) ? -result : result;
};

unsigned char Multiply::reverseBits(uint8_t b)
{
    b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
    b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
    b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
    return b;
}
uint16_t Multiply::reverseWholeWord(uint16_t word)
{
    return reverseBits(word >> 8) | reverseBits(word) << 8;
};
void Multiply::setLocalXValue(int input)
{
    localX = input;
}

void Multiply::inputcharForSwitch(string input)
{
    if (input == "download")
    {
        std::cout << "download" << std::endl;
    }
    else if (input == "upload")
        std::cout << "upload" << std::endl;
};
int Multiply::setLocalyWithCallBack(int input, void (*unc_ptr)(), int &passIn)
{
    y = input;
    passIn = 54321;
    char c = 'a';
    // y = func_ptr(c);

    unc_ptr();
    return y;
};