#include "Header.h"

int main() {
	bool programExit = false;
	do {
		string input;
		string output;

		getline(cin, input);
		output = giveOutPut(input);

		cout << output << endl;
	} while (programExit == false);


	return EXIT_SUCCESS;
}
