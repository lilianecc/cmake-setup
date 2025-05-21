#ifndef BITSTRUCT_H
#define BITSTRUCT_H
#include <iostream>
struct Bitstruct
{
    uint16_t remoteAddress : 5;
    uint16_t rOrT : 1;
    uint16_t subAddress : 5;
    uint16_t wordCount : 5;
    // Bitstruct ():remoteAddress(12){}
};
struct RevBitStruct
{
    uint16_t RevWordCount : 5;
    uint16_t RevSubAddress : 5;
    uint16_t RevROrT : 1;
    uint16_t RevRemoteAddress : 5;
};
struct structInsideStruct
{
    // void setBitstruct(Bitstruct &bitstru) { this->bitstructWord = bitstru; };
    uint16_t word : 1;
    Bitstruct bitstructWord = {.remoteAddress = 12};
};

typedef union bitsetConverter
{
    Bitstruct bitstruct;
    uint16_t bitInt16;

} bitsetConverter;

union revBitConverter
{
    RevBitStruct revBitStruct;
    uint16_t revbitInt;
};
union combine
{
    bitsetConverter bitsetConv;
    RevBitStruct revbitstruct;
    uint16_t raw16[5];
};
union TMsgs
{
    uint16_t raw[5]; //={0};
    Bitstruct Bitstruct;
};
union T1Msgs
{
    uint16_t raw[5]; //={0};
    Bitstruct Bitstruct;
};
union T2Msgs
{
    uint16_t raw[5]; //={0};
    Bitstruct Bitstruct;
};
union unionHasStructInstruct
{
    structInsideStruct soManystruct;
    uint16_t aSeriesNum;
    unionHasStructInstruct()
    {
        soManystruct.bitstructWord.remoteAddress = 12;
    };
    ~unionHasStructInstruct() {};
};
// mimic file struct
struct message13R001Struct
{
    uint16_t ID;
    uint16_t name;
    uint16_t latitude;
    uint16_t logitutde;
    uint16_t setting;
    uint16_t radius;
    uint16_t reserve;
};
union message13R001Union
{
    message13R001Struct data;
    uint16_t raw[7];
};
union message13R001Union1
{
    message13R001Struct data;
    uint16_t raw[7];
};
struct mdtFile003struct // not necessary
{
    message13R001Union rec[5];
};
union mdtFile003Union
{
    mdtFile003struct Fstruct;
    uint16_t raw[5][5][5] = {0};
};
union testFile003withoutunion
{
    message13R001Union rec[5];
    uint16_t raw[5][5][5] = {0};
};
struct file003
{
    uint16_t recordNum = 0;
    uint16_t blockNum = 0;
    mdtFile003Union fileData;
};
struct file003WithoutMiddle
{
    uint16_t recordNum = 0;
    uint16_t blockNum = 0;
    testFile003withoutunion fileData;
};
struct twomessage
{
    message13R001Union msg13R1;
    message13R001Union1 msg13R2;
};
struct combinetwomsg
{
    twomessage rec[4];
};
union file005
{
    combinetwomsg Fstruct;
    uint16_t Raw[4][1][1];
};
struct arrayofmsg
{
    mdtFile003struct blk[8];
};
union file022
{
    arrayofmsg Fstruct;
    uint16_t raw[5][5][5] = {0};
};
#endif