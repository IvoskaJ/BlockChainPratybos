#include "readfiles.h"

int main() {
    char decision;
    bool decisionMade = false;
    cout << "a -- if you would like to type in the input by hand" << endl;
    cout << "b -- if you would like the input to come from a file" << endl;
    cout << "c -- if you want the program to close" << endl;
    do{
    cin >> decision;
        if ((decision == 'a') || (decision == 'A')){
                cin.ignore();
            	bool programExit = false;
                do {
                    cout << "type in any input." << endl;
                    char thingy;
                    string input;
                    getline(cin, input, '\n');
                    cout << giveOutPut(input) << endl;
                    cout << "would you like to continue -- type y for yes, n for no, typing n will also close the program." << endl;
                    bool correctInput;
                        do{
                        cin >> thingy;
                        correctInput = false;
                        if ((thingy  == 'y') || (thingy == 'Y')){
                            correctInput = true;
                        }
                        else if ((thingy == 'n') || (thingy == 'N')){
                            correctInput = true;
                            return EXIT_SUCCESS;
                        }
                        else {
                            cout << "incorrect input, please retry" << endl;
                        }
                        cin.ignore();
                        }  while (correctInput == false);
                } while (programExit==false);
                decisionMade == true;
        }
        else if((decision == 'b') || (decision == 'B')){
                cin.ignore();
            	bool programExit = false;
                do {
                    string input;
                    string fileName;
                    char thingy;
                    cout << "type in the name of the file, which you would like to hash" << endl;
                    cin >> fileName;
                    readfile(fileName, input);
                    cout << giveOutPut(input) << endl;
                    cout << "would you like to continue -- type y for yes, n for no, typing n will also close the program." << endl;
                    bool correctInput = false;
                        do{
                        cin >> thingy;
                        correctInput = false;
                        if ((thingy  == 'y') || (thingy == 'Y')){
                            correctInput = true;
                        }
                        else if ((thingy == 'n') || (thingy == 'N')){
                            correctInput = true;
                            return EXIT_SUCCESS;
                        }
                        else {
                            cout << "incorrect input, please retry" << endl;
                        }
                        cin.ignore();
                        }  while (correctInput == false);
                } while (programExit==false);
                decisionMade == true;
        }
        else if ((decision == 'c') || (decision == 'C')){
            decisionMade == true;
            return EXIT_SUCCESS;
        }
        else{
            cout << "incorrect input, please retry" << endl;
            decisionMade = false;
        }
        cin.ignore();
    } while (decisionMade == false);

	return EXIT_SUCCESS;
}
