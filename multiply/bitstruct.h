#ifndef BITSTRUCT_H
#define BITSTRUCT_H
#include<iostream>

struct Bitstruct
{
    unsigned char remoteAddress : 5;
    unsigned char rOrT : 1;
    unsigned char subAddress : 5;
    unsigned char wordCount : 5;
};
typedef union bitsetConverter
{
    Bitstruct bitstruct;
    uint16_t bitInt16;
} bitsetConverter;

#endif