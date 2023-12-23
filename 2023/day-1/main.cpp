#include <iostream>
#include <fstream>
#include <vector>
#include <string>


int main(){
    std::vector<std::string> fileLines;
    std::string lines;
    std::string firstDigit = "";
    std::string lastDigit = "";
    std::string strNumber = "";
    int num = 0;
    int total = 0;
    std::ifstream m_file;

    m_file.open("keys.txt");

    while (m_file >> lines){
        fileLines.push_back(lines);
    }

    m_file.close();
    
    for(int i = 0; i < fileLines.size(); i++) {
        for(int j = fileLines[i].length() - 1; j >= 0; j--){
            strNumber = "";
            if (isdigit(fileLines[i][j])) {
                firstDigit = fileLines[i][j];
            }
        }
        for(int k = 0; k < fileLines[i].length(); k++){
                if (isdigit(fileLines[i][k])) {
                    lastDigit = fileLines[i][k];
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