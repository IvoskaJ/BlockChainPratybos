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
            handInput();
            decisionMade = true;
        }
        else if((decision == 'b') || (decision == 'B')){
            useFiles();
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
