#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <cmath>
#include <random>

using namespace std;

unsigned int hashFunction(string input) {
	const unsigned int init = 17;
	const unsigned int magic = 7753;
	 unsigned int hash;
	for (int i = 0; i < input.length(); i++){
		hash = hash ^ (input[i]);
		hash = hash * magic;
		hash = hash ^ (input.length());
	}
	return hash;
}

string toHex(unsigned int input) {
	string hexHash;
	stringstream hexstream;
	hexstream << hex << input;
	hexHash = hexstream.str();
	return hexHash;
}


string giveOutPut(string input) {
	string output;
	stringstream thingy;
	output = toHex(hashFunction(toHex(hashFunction(input))));


	return output;
}