#include "readfiles.h"

#pragma optimize(-O3)

int main() {
    char decision;
    bool decisionMade = false;
    cout << "a -- if you would like to type in the input by hand" << endl;
    cout << "b -- if you would like the input to come from a file" << endl;
    cout << "c -- if you would like to run a collision analyis" << endl;
    cout << "d -- if you would like to measure how long it takes to hash konstitucija.txt" << endl;
    cout << "e -- if you would like to compare the ammount of time it takes to hash a large file with random strings, with the written hash, sha256 and md5" << endl;
    cout << "f -- if you want the program to close" << endl;
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
            doCollisionAnalysis();
            decisionMade = true;

        }
        else if ((decision == 'd') || (decision == 'D')){
            hashKonstitucija();
            decisionMade = true;

        }
        else if ((decision == 'e') || (decision == 'E')){
            compareToShaAndMd5();
            decisionMade = true;
        }
        else if ((decision == 'f') || (decision  == 'F')){
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
