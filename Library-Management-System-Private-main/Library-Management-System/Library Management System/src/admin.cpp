#include "C:\Users\twph.coders\Desktop\Library-Management-System-Private-main\Library-Management-System\Library Management System\include\global.h"
#include "C:\Users\twph.coders\Desktop\Library-Management-System-Private-main\Library-Management-System\Library Management System\include\admin.h"
#include "C:\Users\twph.coders\Desktop\Library-Management-System-Private-main\Library-Management-System\Library Management System\include\manage_book.h"
#include "C:\Users\twph.coders\Desktop\Library-Management-System-Private-main\Library-Management-System\Library Management System\include\manage_patron.h"
#include "C:\Users\twph.coders\Desktop\Library-Management-System-Private-main\Library-Management-System\Library Management System\include\manage_checkout_return.h"
#include <iostream>
#include <string>

void IntegerOnly() {
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout << "\t\t\t\t\t|| [>] ";
}

// Function to convert a string to lowercase
std::string toLower(const std::string& str){
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

void AdminInterface(){
    while (true) {
        int admin_choice;
        std::cout << "\t\t\t\t\t==================================================\n";
        std::cout << "\t\t\t\t\t|| [1] Manage Books \n";
        std::cout << "\t\t\t\t\t|| [2] Manage Patrons \n";
        std::cout << "\t\t\t\t\t|| [3] Manage Check-outs and Returns \n";
        std::cout << "\t\t\t\t\t|| [4] Exit \n";
        std::cout << "\t\t\t\t\t|| [>] ";
        while (!(std::cin >> admin_choice)) IntegerOnly();

        switch (admin_choice) {
            case 1:
                system("cls");
                std::cout << "\t\t\t\t\t==================================================\n";
                std::cout << "\t\t\t\t\t||\t\t   Book Manager   \t\t||\n";
                std::cout << "\t\t\t\t\t==================================================\n";
                ApplicationMenu();
                break;
            case 2:
                system("cls");
                std::cout << "\t\t\t\t\t==================================================\n";
                std::cout << "\t\t\t\t\t||\t\t   Patron Manager   \t\t||\n";
                std::cout << "\t\t\t\t\t==================================================\n";
                PatronMenu();
                break;
            case 3:
                system("cls");
                std::cout << "\t\t\t\t\t==================================================\n";
                std::cout << "\t\t\t\t\t||\t   Check-Outs and Return Manager   \t||\n";
                std::cout << "\t\t\t\t\t==================================================\n";
                CheckOutReturnMenu();
                break;
            case 4:
                exit(0);
            default:
                system("cls");
                continue;
        }
    }
}