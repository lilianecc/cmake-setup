#include "multiply.h"
#include "rMsgStruct.h"
#include <stdexcept>
#include <exception>
#include <algorithm>
#include <queue>
using namespace std;
// Multiply temp;
// Multiply::Multiply()
// {
// }
Multiply::Multiply() {};
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
        int a = strncmp(platform,content.c_str(),3);
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
Multiply::SomeData Multiply::functionToReturnStruct()
{
    SomeData student;
    // RMsgs msg1;
    // msg1.RMSGS.id = 1;
    // msg1.RMSGS.code = 123;
    // testingMap[1] = msg1.raw + 1;
    // uint16_t *temparr;

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
    int remoteAdd = 29;
    int rOrT = 1;
    int msgNum = 1;
    int wordCount = 30;
    uint16_t msgWithCommandWord[21] = {0};
    uint16_t msg2WithCW[31] = {0};
    uint16_t revBits = (wordCount << 11) | msgNum << 6 | rOrT << 5 | remoteAdd & 0x1F;
    uint16_t commandword = (remoteAdd << 11) | rOrT << 10 | (msgNum & 0x1F) << 5 | wordCount & 0x1F;
    CommandWordUnion notreversedUnion;
    notreversedUnion.CWint = commandword;

    CommandWordUnion reversedUnion;
    reversedUnion.CWint = revBits;

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
    return student;
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
void Multiply::GetMsgByPtr(uint16_t* msgPtr){
    platformNum[0]=123;
    platformNum[1]=234;
    platformNum[3]=2323;
    std::copy(platformNum, platformNum+5, msgPtr);
};

int Multiply::getXValue() { return localX; };