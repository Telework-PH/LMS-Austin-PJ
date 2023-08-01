#include "C:\Users\twph.coders\Desktop\Library-Management-System-Private-main\Library-Management-System\Library Management System\include\global.h"
#include "C:\Users\twph.coders\Desktop\Library-Management-System-Private-main\Library-Management-System\Library Management System\include\admin.h"
#include "C:\Users\twph.coders\Desktop\Library-Management-System-Private-main\Library-Management-System\Library Management System\include\manage_checkout_return.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
std::string checkout_record = R"(C:\Users\twph.coders\Desktop\Library-Management-System-Private-main\Library-Management-System\Library Management System\data\checkout_record.csv)";
void CheckOutReturnMenu(){
    int choose;
    while(true){
        std::cout << "\t\t\t\t\t|| [1] Check-Out a Book \n";
        std::cout << "\t\t\t\t\t|| [2] Return a Book \n";
        std::cout << "\t\t\t\t\t|| [3] Display all Check-Out Books \n";
        std::cout << "\t\t\t\t\t|| [4] Back  \n";
        std::cout << "\t\t\t\t\t|| [5] Exit  \n";
        std::cout << "\t\t\t\t\t|| [>] ";
        while (!(std::cin >> choose)) IntegerOnly();

        switch (choose) {
            case 1:
                system("cls");
                CheckOutBook();
                std::cout << "\n\n";
                continue;
            case 2:
                system("cls");
                ReturnBook();
                std::cout << "\n\n";
                continue;
            case 3:
                system("cls");
                DisplayCheckOut();
                std::cout << "\n\n";
                continue;
            case 4:
                system("cls");
                AdminInterface();
            case 5:
                exit(0);
            default:
                system("cls");
                continue;
        }
    }
}

std::string getCurrentDate() {
    time_t now = time(0);
    char* date = ctime(&now);
    std::string currentDate(date);
    currentDate.erase(currentDate.find_last_not_of(" \n\r\t") + 1);
    return currentDate;
}
void CheckOutBook() {
    CheckoutInfo checkout;
    std::fstream fout;
    fout.open("checkout_record.csv", std::ios::out | std::ios::app);
    std::cout << "\t\t\t\t\t|| CHECKOUT BOOK...\n";
    std::cout << "\t\t\t\t\t|| Enter Book ID to Checkout: ";
    int book_id;
    std::cin >> book_id;
    // Check if the book with the given ID exists in the record
    bool book_found = false;
    std::ifstream file(checkout_record);
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string data;
        std::getline(ss, data, ',');
        try {
            int id = std::stoi(data);
            if (id == book_id) {
                book_found = true;
                break;
            }
        } catch (const std::invalid_argument& e) {
            continue;
        }
    }
    file.close();
    if (!book_found) {
        std::cout << "\t\t\t\t\t|| Book not found with ID: " << book_id << std::endl;
        return;
    }
    // Check if the book is already checked out
    std::ifstream checkoutFile("book_record.csv");
    while (std::getline(checkoutFile, line)) {
        std::stringstream ss(line);
        std::string data;
        std::getline(ss, data, ',');
        try {
            int id = std::stoi(data);
            if (id == book_id) {
                std::cout << "\t\t\t\t\t|| Book with ID " << book_id << " is already checked out." << std::endl;
                checkoutFile.close();
                return;
            }
        } catch (const std::invalid_argument& e) {
            continue;
        }
    }
    checkoutFile.close();
    CheckoutInfo checkouts;
    checkout.book_id = book_id;
    checkout.date_borrow = getCurrentDate();
    // Set due date to 14 days from checkout date
    time_t now = time(0);
    now += 14 * 24 * 60 * 60; // 14 days in seconds
    char* due_date = ctime(&now);
    checkout.date_borrow = std::string(due_date);
    checkout.date_borrow.erase(checkout.date_borrow.find_last_not_of(" \n\r\t") + 1);
    fout << checkout.book_id << ","
         << checkout.date_borrow << ","
         << checkout.date_due << "\n";
    fout.close();
    std::cout << "\t\t\t\t\t|| Book checked out successfully!\n";
}

void ReturnBook(){

}

void DisplayCheckOut(){

}

