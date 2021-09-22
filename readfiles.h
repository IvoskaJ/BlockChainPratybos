#include "header.h"
#include <fstream>

void readfile(string fileName, string &fileData){
    ifstream fd(fileName);
    getline(fd, fileData, '\0');
    fd.close();
}
