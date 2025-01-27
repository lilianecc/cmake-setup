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
    unionHasStructInstruct(){
        soManystruct.bitstructWord.remoteAddress=12;
    };
    ~unionHasStructInstruct(){};
};
#endif