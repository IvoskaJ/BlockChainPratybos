#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <cmath>
#include <random>

using namespace std;


int extendInput(int& inputVal) {
	inputVal = rand() * (sqrt(pow(inputVal, 8)));
	return inputVal;
}

string convertInputToInteger(string &input) {
	int inputVal=0;
	for (int i = 0; i < input.length(); i++) {
		inputVal = inputVal + input.at(i);
	}

	extendInput(inputVal);

	input = to_string(inputVal);

	return input;
}

string hashFunction(string input) {
	string output;
	stringstream thingy;
	convertInputToInteger(input);



	for (const auto& item : input) {
		thingy << hex << int(item);
	}
	output = thingy.str();
	
	return output;
}