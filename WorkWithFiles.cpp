
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void grade10(const char* path) {
    std::ifstream file(path);
    if (!file) {
        std::cout << "Không thể mở tệp tin." << std::endl;
        return;
    }

    std::vector<std::string> students;

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name, grade;
        std::getline(iss, name, ',');
        std::getline(iss, grade, ',');
        if (grade == "10") {
            students.push_back(name);
        }
    }

    file.close();

    if (students.empty()) {
        std::cout << "Không có sinh viên nào có điểm THCS4 là 10." << std::endl;
        return;
    }

    std::cout << "Các sinh viên có điểm THCS4 là 10:" << std::endl;
    for (const std::string& student : students) {
        std::cout << student << std::endl;
    }
}

int main() {
    const char* path = "1.csv";
    grade10(path);
    return 0;
}

