#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "C:\Users\twph.coders\Desktop\Library-Management-System-Private-main\Library-Management-System\Library Management System\include\global.h"
#include "C:\Users\twph.coders\Desktop\Library-Management-System-Private-main\Library-Management-System\Library Management System\include\admin.h"
// User struct is at the global.h

std::vector<User> readCSV(const std::string& filename) {
    std::vector<User> users;
    std::ifstream file(filename);

    if (!file) {
        std::cout << "\t\t\t\t\t|| Error opening file: " << filename << std::endl;
        return users; // Return an empty vector if the file cannot be opened
    }

    std::string line;
    while (std::getline(file, line)) {
        User user;
        size_t comma_pos = line.find(',');
        if (comma_pos != std::string::npos) {
            user.username = line.substr(0, comma_pos);
            user.password = line.substr(comma_pos + 1);
            users.push_back(user);
        }
    }

    file.close();
    return users;
}

int main() {
    std::string file_name = R"(C:\Users\twph.coders\Desktop\Library-Management-System-Private-main\Library-Management-System\Library Management System\data\user_record.csv)";
    std::vector<User> users = readCSV(file_name);

    bool login_success = false;
    std::cout << "\t\t\t\t\t==================================================\n";
    std::cout << "\t\t\t\t\t||\t   LIBRARY MANAGEMENT SYSTEM\n";
    std::cout << "\t\t\t\t\t==================================================\n";
    std::string user_name, user_pass;
    wrong:
    std::cout << "\t\t\t\t\t|| Enter username: ";
    std::cin >> user_name;
    std::cout << "\t\t\t\t\t|| Enter password: ";
    std::cin >> user_pass;

    bool success = false;
    for (const User& user : users) {
        if (user_name == user.username && user_pass == user.password) {
            success = true;
            break;
        }
    }

    if (success) {
        system("cls");
        AdminInterface();
    } else {
        std::cout << "\t\t\t\t\t|| Login failed. Invalid username or password." << std::endl;
        goto wrong;
    }

    return 0;
}

