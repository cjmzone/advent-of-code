#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

int main(){
    std::vector<std::string> keys;
    std::string lines;
    std::string firstDigit = "";
    std::string lastDigit = "";
    std::string strNumber = "";
    int num = 0;
    int total = 0;
    std::ifstream fileIn;

    fileIn.open("keys.txt");

    while (fileIn >> lines){
        keys.push_back(lines);
    }
    fileIn.close();
    
    for(int i = 0; i < keys.size(); i++) {
        for(int j = keys[i].length() - 1; j >= 0; j--){
            strNumber = "";
            if (isdigit(keys[i][j])) {
                firstDigit = keys[i][j];
            }
        }
        for(int k = 0; k < keys[i].length(); k++){
                if (isdigit(keys[i][k])) {
                    lastDigit = keys[i][k];
                }
            }
            strNumber = firstDigit + lastDigit;
            num = stoi(strNumber);
            total += num;

        std::cout << "Line " << i + 1 << ": " << strNumber << std::endl;
    }
    std::cout << "Total: " << total << std::endl;
    return 0;
}