#ifndef RMSGSTRUCT_H
#define RMSGSTRUCT_H
#include <iostream>

// class rMsgStruct
//{
struct CommandWordstruct
{
    uint16_t remoteAddress : 5;
    uint16_t rOrT : 1;
    uint16_t subAddress : 5;
    uint16_t wordCount : 5;
    // Bitstruct ():remoteAddress(12){}
};
union CommandWordUnion
{
    CommandWordstruct cmdWord;
    uint16_t CWint;
};
struct rMsgs
{
    uint16_t id;          // word 1
    uint16_t code;        // word 2
    uint16_t anotherID;   // word 3
    uint16_t velocityMSB; // word 4
    uint16_t velocityLSB; // word 5
};
// union RMSGS
// {
//     CommandWordstruct commandWord;
//     rMsgs RMSGS;
// };
union RMsgs
{
    uint16_t raw[31]; //={0};
    CommandWordstruct commandWord;
    rMsgs RMSGS;
};

union PlatformID
{
    uint8_t platformBytes[16];
    uint16_t platformWords[8];
};
//};

#endif