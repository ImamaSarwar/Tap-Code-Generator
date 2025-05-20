#pragma once
#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
using namespace std;

class tapCodeDecipher
{
private:
    char polybiusSquareCapital[5][5] = {
            {'A', 'B', 'C', 'D', 'E'},
            {'F', 'G', 'H', 'I', 'J'},
            {'L', 'M', 'N', 'O', 'P'},
            {'Q', 'R', 'S', 'T', 'U'},
            {'V', 'W', 'X', 'Y', 'Z'}
    };
    char polybiusSquareSmall[5][5] = {
            {'a', 'b', 'c', 'd', 'e'},
            {'f', 'g', 'h', 'i', 'j'},
            {'l', 'm', 'n', 'o', 'p'},
            {'q', 'r', 's', 't', 'u'},
            {'v', 'w', 'x', 'y', 'z'}
    };
public:
    char* convertToTapCode(char* input);
    char* convertToString(const char* input);
};
#endif
