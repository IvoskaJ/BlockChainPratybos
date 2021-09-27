#include "header.h"
#include "sha256.h"
#include "sha256.cpp"
#include "md5.h"
#include "md5.cpp"
#include <fstream>
#include <vector>
#include <exception>
#include <chrono>

using namespace std::chrono;


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

void readFileForCollisionAnalysis(string fileName, vector<string> &vectorOfRandomStrings){
    string temp;
    ifstream fd(fileName);
    for(int i=0; i<25000; i++){
    fd >> temp;
    vectorOfRandomStrings.push_back(temp);
    }
    fd.close();
}

string  gen_random(int len) {
        string s;
        static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

        for (int i = 0; i < len; ++i) {
            s+= alphanum[rand() % (sizeof(alphanum) - 1)];
             }

     return s;
}

void fileGenerator(int stringLength){
    ofstream fr(to_string(stringLength) + "symbols.txt");
        for (int j=0; j<25000; j++){
            fr << gen_random(stringLength) << endl;
        }
    fr.close();
}

void generateFiles(){
    int stringLength = 10;
    for (int i = 0; i<3; i++){
        fileGenerator(stringLength);
        stringLength = stringLength * 10;
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

void doCollisionAnalysis(){
        generateFiles();
        int symbolLength = 10;
        for(int i =0; i<3; i++){
        string fileName = (to_string(symbolLength) + "symbols.txt");
        vector<string> vectorOfStrings;
        readFileForCollisionAnalysis(fileName, vectorOfStrings);
        vector<string> vectorOfHashes;
        int ammountOfCollisions = 0;
        for(int j = 0; j<vectorOfStrings.size(); j++){
            vectorOfHashes.push_back(giveOutPut(vectorOfStrings[j]));
        }
        ofstream fr(to_string(symbolLength) + "hashedSymbols.txt");
        for(int j=0; j<vectorOfHashes.size(); j++){
            fr << vectorOfHashes[j] << endl;
        }
        vectorOfStrings.clear();
        for(int j = 0; j<vectorOfHashes.size(); j++){
            for(int z =0; z<vectorOfHashes.size(); z++){
                if(j==z) {z++;}
                if(vectorOfHashes[j]==vectorOfHashes[z]){
                    ammountOfCollisions++;
                }
            }
        }
        cout << ammountOfCollisions  << " collisions occured in " << fileName << endl;
        vectorOfHashes.clear();
        symbolLength=symbolLength*10;
        }

}

void hashKonstitucija(){
    string konstitucija;
    readfile("konstitucija.txt", konstitucija);
    auto start = high_resolution_clock::now();
    giveOutPut(konstitucija);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start) * 1.0 / 1000000;

    cout << "time taken to hash konstitucija.txt with the written hash function " << duration.count() << endl;
}

void compareToShaAndMd5(){
    generateFiles();
    string input;
    readfile("1000symbols.txt", input);
    auto start = high_resolution_clock::now();
    giveOutPut(input);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start) * 1.0 / 1000000;
    cout << "time taken to hash 1000symbols.txt with the written hash function " << duration.count() << endl;
    string temp;
    start = high_resolution_clock::now();
    sha256(input);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start) * 1.0 / 1000000;
    cout << "time taken to hash 1000symbols.txt with sha256 " << duration.count() << endl;
    start = high_resolution_clock::now();
    md5(input);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start) * 1.0 / 1000000;
    cout << "time taken to hash 1000symbols.txt with md5 " << duration.count() << endl;
}
