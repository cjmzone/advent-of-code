#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    std::string firstDigit = "";
    std::string lastDigit = "";
    std::string strNumber = "";
    std::string lines;
    std::ifstream m_file;

    int index = 0;
    int value1 = 0;
    int value2 = 0;
    int total = 0;
    int lineCount = 0;

    vector<pair<string, pair<size_t, int>>> foundPositions;
    std::vector<std::string> fileLines;
    vector<string> first;

    map<string, int> keys = {
        {"one", 1}, {"two", 2}, {"three", 3},
        {"four", 4}, {"five", 5}, {"six", 6},
        {"seven", 7}, {"eight", 8}, {"nine", 9}
    };

    // begin 
    m_file.open("keys.txt");
    while (m_file >> lines){
        fileLines.push_back(lines);
    }
    m_file.close();

    // look for digits and strings
    for (const auto& entry : keys) {
        const string& key = entry.first;
        for (int i = 0; i < fileLines.size(); i++) {
            size_t position = fileLines[i].find(key);
            for(int j = 0; j < fileLines[i].length(); j++){
                if (isdigit(fileLines[i][j]) == entry.second){
                    firstDigit = fileLines[i][j];
                    // cout << "Found at " << fileLines[i][j] << endl;
                    foundPositions.push_back(make_pair(firstDigit, make_pair(j, i)));
                }
            }
            while (position != string::npos) {
                foundPositions.push_back(make_pair(key, make_pair(position, i)));
                position = fileLines[i].find(key, position + key.length());
            }
        }
    }

    // BubbleSort the found positions 
    for (int i = 0; i < foundPositions.size() - 1; ++i) {
        for (int j = 0; j < foundPositions.size() - i - 1; ++j) {
            // Compare based on the line index
            if (foundPositions[j].second.second > foundPositions[j + 1].second.second ||
                (foundPositions[j].second.second == foundPositions[j + 1].second.second &&
                 foundPositions[j].second.first > foundPositions[j + 1].second.first)) {
                // Swap
                swap(foundPositions[j], foundPositions[j + 1]);
            }
        }
    }

    for (int i = 0; i < foundPositions.size(); i++) {
        if (foundPositions[i].second.second == index) {
            first.push_back(foundPositions[i].first);
        } else {
            if (!first.empty()) {
                string f = first.front();
                string l = first.back();
                // math logic 
                if(f.length() > 1){
                    auto it = keys.find(f);
                    if(it!=keys.end()){
                        value1 = it->second;
                    }
                } else {
                    value1 = stoi(f);
                }
                if(l.length() > 1){
                    auto it = keys.find(l);
                    if(it!=keys.end()){
                        value2 = it->second;
                    }
                } else {
                    value2 = stoi(l);
                }
                string result = to_string(value1) + to_string(value2);
                int lineSum = stoi(result);
                // cout <<"line sum: " << lineSum << endl;
                
                total += lineSum;
                // cout << total << endl;
                lineCount++;
                first.clear();
            }
            index = foundPositions[i].second.second;
            first.push_back(foundPositions[i].first);  // Add the first element for the new index
        }
    }
    
    if (!first.empty()) {
        string f = first.front();
        string l = first.back();
        // math logic 
        if (f.length() > 1) {
            auto it = keys.find(f);
            if (it != keys.end()) {
                value1 = it->second;
            }
        } else {
            value1 = stoi(f);
        }
        if (l.length() > 1) {
            auto it = keys.find(l);
            if (it != keys.end()) {
                value2 = it->second;
            }
        } else {
            value2 = stoi(l);
        }
        string result = to_string(value1) + to_string(value2);
        int lineSum = stoi(result);
        total += lineSum;
    }

    std::cout << "Total: " << total << endl;
    std::cout << "Total lines counted: " << lineCount << endl;

    return 0;
}
