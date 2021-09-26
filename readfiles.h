#include "header.h"
#include <fstream>
#include <exception>

void readfile(string fileName, string &fileData){
    try{
    ifstream fd(fileName);
    if(!fd){
            cerr << "file not found, the application will now close." << endl;
            throw;
    }
    getline(fd, fileData, '\0');
    fd.close();
    } catch(exception &e){
    }
}

bool handInput(){
        cin.ignore();
        bool programExit = false;
        do {
            cout << "type in any input." << endl;
            char thingy;
            string input;
            getline(cin, input, '\n');
            cout << input << endl;
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
        return true;
}

bool useFiles(){
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
        return true;
}
