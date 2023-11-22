#include <iostream>
#include <fstream>
#include <sstream>

// Định nghĩa cấu trúc cho sinh viên
struct SinhVien
{
    int stt;
    std::string ho;
    std::string ten;
    std::string ngaySinh;
    int daiSo;
    int thcs4;
    int thcs1;
};

// Hàm kiểm tra điểm THCS4 bằng 10 và in ra họ tên của sinh viên
void prafel10(const std::string &inputPath, const std::string &outputPath)
{
    std::ifstream inputFile(inputPath);
    if (!inputFile.is_open())
    {
        std::cout << "Khong mo duoc file dau vao." << std::endl;
        return;
    }

    std::ofstream outputFile(outputPath);
    if (!outputFile.is_open())
    {
        std::cout << "Khong tao duoc file dau ra." << std::endl;
        inputFile.close();
        return;
    }

    int count = 0;
    std::string line;

    // Đọc từng dòng trong file đầu vào
    while (std::getline(inputFile, line))
    {
        SinhVien sv;

        // Sử dụng stringstream để đọc từng trường thông tin từ dòng
        std::istringstream iss(line);
        char comma;

        iss >> sv.stt >> comma;
        std::getline(iss, sv.ho, ',');
        std::getline(iss, sv.ten, ',');
        std::getline(iss, sv.ngaySinh, ',');
        iss >> sv.daiSo >> comma >> sv.thcs4 >> comma >> sv.thcs1;

        // Kiểm tra điểm THCS4 bằng 10
        if (sv.thcs4 == 10)
        {
            // In ra họ tên của sinh viên
            std::cout << sv.ho << " " << sv.ten << std::endl;

            // Ghi thông tin vào file đầu ra
            outputFile << sv.ho << " " << sv.ten << std::endl;
            count++;
        }
    }

    inputFile.close();
    outputFile.close();

    // Kiểm tra nếu không có sinh viên nào có điểm THCS4 bằng 10
    if (count == 0)
    {
        std::cout << "Khong co sinh vien nao co diem THCS4 bang 10." << std::endl;
    }
    else
    {
        std::cout << "\nDa luu du lieu vao file 1.csv.";
    }
}

int main()
{
    std::string inputPath = "./BANGDIEM.txt";
    std::string outputPath = "./1.csv";
    prafel10(inputPath, outputPath);

    return 0;
}
