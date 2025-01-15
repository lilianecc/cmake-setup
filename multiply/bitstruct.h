#ifndef BITSTRUCT_H
#define BITSTRUCT_H
#include <iostream>
struct Bitstruct
{
    uint16_t remoteAddress : 5;
    uint16_t rOrT : 1;
    uint16_t subAddress : 5;
    uint16_t wordCount : 5;
};
struct RevBitStruct
{
    uint16_t wordCount : 5;
    uint16_t subAddress : 5;
    uint16_t rOrT : 1;
    uint16_t remoteAddress : 5;
};
typedef union bitsetConverter
{
    Bitstruct bitstruct;
    uint16_t bitInt16;
} bitsetConverter;

typedef union revBitConverter
{
    RevBitStruct revBitStruct;
    uint16_t revbitInt;
};
#endif