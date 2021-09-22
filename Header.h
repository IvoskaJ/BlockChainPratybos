#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <bitset>
#include <iomanip>
#include <iterator>
#include <functional>

using namespace std;

unsigned int convertStringToUnsignedInt(string input) {
	const unsigned int init = 17;
	const unsigned int magic = 5;
	 unsigned int stringConvertedToInt=0;
    for (int z = 0; z<init; z++){
        stringConvertedToInt=stringConvertedToInt+init;
            for(int j = 0; j<63; j++){
                for (int i = 0; i < input.size(); i++) {
                    stringConvertedToInt = stringConvertedToInt ^ (input[i]);
                    stringConvertedToInt = stringConvertedToInt * magic;
                    stringConvertedToInt = stringConvertedToInt ^ input.size();
                }
                stringConvertedToInt=stringConvertedToInt*init;
            }
    }
	return stringConvertedToInt;
}

string toHash(unsigned int input) {
    bitset<256> bs(input);
    bs=bs.flip();
    bs=bs>>5;
    bs=bs.flip();
    bs=bs<<7;
    bs=bs.flip();
    hash<bitset<256>> n;
	string temp;
	temp=to_string(n(bs));

	return temp;
}

string giveOutPut(string input) {
	string output;
	string out;
	stringstream ss;
    output = toHash(convertStringToUnsignedInt(input));
    for (const auto &item : output) {
        ss << hex << int(item);
    }
    out = ss.str();
    out.resize(32);
	return out;
}
