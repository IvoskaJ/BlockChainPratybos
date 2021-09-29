#include "header.h"
#include "sha256.h"
#include "sha256.cpp"
#include "md5.h"
#include "md5.cpp"
#include <fstream>
#include <vector>
#include <exception>
#include <chrono>
#include <algorithm>
#include <numeric>

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
        for (int j=0; j<50000; j++){
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
        int amountOfCollisions = 0;
        for(int i =0; i<3; i++){
        string fileName = (to_string(symbolLength) + "symbols.txt");
        vector<string> vector1;
        vector<string> vector2;
        string temp;
        ifstream fd(fileName);
        for(int j = 0; j<25000; j++){
            fd >> temp;
            vector1.push_back(temp);
            fd >> temp;
            vector2.push_back(temp);
        }
        for(int j=0; j<vector1.size(); j++){
            temp = giveOutPut(vector1[i]);
            vector1.at(j) = temp;
            temp = giveOutPut(vector2[i]);
            vector2.at(j) = temp;
        }
        for(int j=0; j<vector1.size(); j++){
            if(vector1[j] == vector2[j]){
                amountOfCollisions++;
            }
            vector1.clear();
            vector2.clear();
        }
        cout << amountOfCollisions  << " collisions occured in " << fileName << endl;
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

double average(vector<int> const& v){
    int sum=0;
    double a;
    for (int i=0; i<v.size(); i++){
        sum=sum+v.at(i);
    }
    a = (sum / v.size());
    return a;
}

void findPercentileOfMatchingHex(){
        ofstream fr("fileForCheckingHashes.txt");
        for (int j=0; j<100000; j++){
            string s = gen_random(1000);
            s.at(0)='a';
            fr << s << endl;
            s.at(0)='b';
            fr << s << endl;
        }
        fr.close();
        vector<string> hashesThatStartWithA;
        vector<string> hashesThatStartWithB;
        string temp;
        ifstream fd("fileForCheckingHashes.txt");
        for(int i=0; i<100000; i++){
            fd >> temp;
            hashesThatStartWithA.push_back(temp);
            fd >> temp;
            hashesThatStartWithB.push_back(temp);
        }
        fd.close();
        for(int i = 0; i<100000; i++){
            temp = giveOutPut(hashesThatStartWithA[i]);
            hashesThatStartWithA.at(i) = temp;
            temp = giveOutPut(hashesThatStartWithB[i]);
            hashesThatStartWithB.at(i) = temp;
        }
        int amountOfMatches=0;
        string temp2;
        vector<int> totalAmountOfMatches;
        for (int i = 0; i<100000; i++){
            int amountOfMatchesInOnePair=0;
            temp = hashesThatStartWithA[i];
            temp2 = hashesThatStartWithB[i];
            for(int j =0; j<64; j++){
                if(temp.at(j)==temp2.at(j)){
                    amountOfMatches++;
                    amountOfMatchesInOnePair++;
                }
            }
            totalAmountOfMatches.push_back(amountOfMatchesInOnePair);
        }
        hashesThatStartWithA.clear();
        hashesThatStartWithB.clear();

        double percentageOfMatchingHex = (amountOfMatches * 100 / 6400000);
        cout << "percentile of matching hex: " << percentageOfMatchingHex << "% " << endl;
        auto it = max_element(totalAmountOfMatches.begin(), totalAmountOfMatches.end());
        cout << "max amount of matches in single pair: " << *it << endl;
        it = min_element(totalAmountOfMatches.begin(), totalAmountOfMatches.end());
        cout << "min amount of matches in single pair: " << *it << endl;
        double avg = average(totalAmountOfMatches);
        cout << "average amount of matches in single pair: " << avg << endl;
        totalAmountOfMatches.clear();
}

void findPercentileOfMatchingBinary(){
        ifstream fd("fileForCheckingHashes.txt");
        string temp;
        vector<string> hashesThatStartWithA;
        vector<string> hashesThatStartWithB;
        for (int i=0; i<100000; i++){
            fd >> temp;
            hashesThatStartWithA.push_back(temp);
            fd >> temp;
            hashesThatStartWithB.push_back(temp);
        }
        for(int i =0; i<100000; i++){
            temp = returnedHexedBits(convertStringToUnsignedInt(hashesThatStartWithA[i]));
            hashesThatStartWithA.at(i) = temp;
            temp = returnedHexedBits(convertStringToUnsignedInt(hashesThatStartWithB[i]));
            hashesThatStartWithB.at(i) = temp;
        }
        int amountOfMatches = 0;
        string temp2;
        vector<int> totalAmountOfMatches;
        for (int i = 0; i<100000; i++){
            int amountOfMatchesInOnePair=0;
            temp = hashesThatStartWithA[i];
            temp2 = hashesThatStartWithB[i];
            for(int j =0; j<256; j++){
                if(temp.at(j)==temp2.at(j)){
                    amountOfMatches++;
                    amountOfMatchesInOnePair++;
                }
            }
            totalAmountOfMatches.push_back(amountOfMatchesInOnePair);
        }
        hashesThatStartWithA.clear();
        hashesThatStartWithB.clear();

        double percentageOfMatchingBinary = (amountOfMatches * 100 / 25600000);
        cout << "percentile of matching binary: " << percentageOfMatchingBinary << "% " << endl;
        auto it = max_element(totalAmountOfMatches.begin(), totalAmountOfMatches.end());
        cout << "max amount of matches in single pair: " << *it << endl;
        it = min_element(totalAmountOfMatches.begin(), totalAmountOfMatches.end());
        cout << "min amount of matches in single pair: " << *it << endl;
        double avg = average(totalAmountOfMatches);
        cout << "average amount of matches in single pair: " << avg << endl;
        totalAmountOfMatches.clear();
}
