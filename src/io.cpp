#include <iostream>
#include <fstream> 
#include <string>

int openFile(char *fileName) {

    std::fstream myFile;
    myFile.open(fileName, std::ios::in); // read
    if (myFile.is_open()){
        std::cout << "File is open" << std::endl;
        std::string line;
        while(getline(myFile,line)) {
            std::cout << line << std::endl;
        }
    } else {
        std::cout << "File not open" << std::endl;
    }

    return 0;
}