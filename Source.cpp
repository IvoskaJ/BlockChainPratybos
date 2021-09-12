#include "Header.h"

int main() {
	string input;
	string output;

	cin >> input;

	output = hashFunction(input);

	
	cout << output;


	return EXIT_SUCCESS;
}