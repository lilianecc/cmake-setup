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
struct Store
{
    uint16_t storeType : 11;
    uint16_t storeVar : 5;
};
union StoreUnion
{
    Store store;
    uint16_t raw;
};
struct HalfHalf
{
    uint16_t char1 : 8;
    uint16_t char2 : 8;
};
union halfhalfUnion
{
    HalfHalf halfhalf;
    uint16_t raw;
};
union CommandWordBytesUnion
{
    CommandWordstruct cmdWord;
    uint8_t rawBytes[2];
};
struct mixDatatype
{
    bool run;
    uint16_t ID;
    uint16_t something;
};
struct rMsgsData
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
    rMsgsData RMSGS;
};

union PlatformID
{
    uint8_t platformBytes[16];
    uint16_t raw[8] = {0};
};
struct ConfigID
{
    uint16_t disable : 1;
    uint16_t reserved : 3;
    uint16_t configuration : 12;
};
union ConfigIDUnion
{
    ConfigID configID;
    uint16_t raw;
};
struct all16diff
{
    uint16_t INS : 1;
    uint16_t restart : 1;
    uint16_t MA : 1;
    uint16_t reserved : 1;
    uint16_t altitude : 1;
    uint16_t bit5 : 1;
    uint16_t bit6 : 1;
    uint16_t bit7 : 1;
    uint16_t bit8 : 1;
    uint16_t bit9 : 1;
    uint16_t bit10 : 1;
    uint16_t bit11 : 1;
    uint16_t bit12 : 1;
    uint16_t bit13 : 1;
    uint16_t bit14 : 1;
    uint16_t bit15 : 1;
};
union all16union
{
    all16diff allINS = {0};
    uint16_t raw;
};
struct somebitsdiff
{
    uint16_t INS : 1;
    uint16_t restart : 1;
    uint16_t MA : 1;
    uint16_t reserved : 1;
    uint16_t altitude : 1;
    uint16_t bit5 : 1;
    uint16_t bit6 : 1;
    uint16_t bit7 : 1;
    uint16_t bit8 : 1;
    uint16_t bit9 : 1;
    uint16_t bit10 : 1;
    uint16_t bit11 : 1;
    uint16_t notused : 4;
};
union somebitsdiffUnion
{
    somebitsdiff someBits = {0};
    uint16_t raw;
};
struct subAdd
{
    uint16_t subaddress : 5;
    uint16_t reserve : 11;
};
union subAddUnion
{
    subAdd SubADD;
    uint16_t raw;
};
struct MomentInv
{
    uint16_t INS : 1;
    uint16_t offset : 1;
    uint16_t reserved : 2;
    uint16_t unused : 12;
};
union MomentInvUnion
{
    MomentInv momentInv;
    uint16_t raw[2];
};
struct LAR
{
    uint16_t IR : 1;
    uint16_t IZ : 1;
    uint16_t LAR : 1;
    uint16_t curr : 1;
    uint16_t MSN : 3;
    uint16_t scale : 2;
    uint16_t AH : 1;
    uint16_t AL : 1;
    uint16_t SH : 1;
    uint16_t SL : 1;
    uint16_t FP : 1;
    uint16_t Ground : 1;
    uint16_t reserve : 1;
};
union LARUnion
{
    LAR lar = {0};
    uint16_t raw;
};
struct configurationID
{
    uint16_t r0 : 1;
    uint16_t r1 : 1;
    uint16_t r2 : 1;
    uint16_t r3 : 1;
    uint16_t h1 : 4;
    uint16_t h2 : 4;
    uint16_t h3 : 4;
};
union configurationIDUnion
{
    configurationID ConfigID;
    uint16_t raw;
};
//};

#endif