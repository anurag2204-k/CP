#include <iostream>
#include <fstream>
#include <string>

bool compareFiles(const std::string& file1, const std::string& file2, std::ofstream& resultFile) {
    std::ifstream f1(file1);
    std::ifstream f2(file2);

    if (!f1.is_open() || !f2.is_open()) {
        resultFile << "Error opening files!" << std::endl;
        return false;
    }

    std::string line1, line2;
    int lineNumber = 1;
    bool areIdentical = true;

    while (std::getline(f1, line1) && std::getline(f2, line2)) {
        if (line1 != line2) {
            resultFile << "Difference found at line " << lineNumber << ":\n";
            resultFile << "Answer file: " << line1 << "\n";
            resultFile << "Output file: " << line2 << "\n";
            areIdentical = false;
        }
        lineNumber++;
    }

    return areIdentical;
}
void test_main(){
    std::string answerFile = "answer.txt";
    std::string outputFile = "output.txt";
    std::ofstream resultFile("testresult");
    
    if (!resultFile.is_open()) {
        std::cerr << "Error opening result file!" << std::endl;
        return;
    }
    
    if (compareFiles(answerFile, outputFile, resultFile)) {
        resultFile << "Files are identical." << std::endl;
    } else {
        resultFile << "Files are different." << std::endl;
    }
    
    resultFile.close();
}

