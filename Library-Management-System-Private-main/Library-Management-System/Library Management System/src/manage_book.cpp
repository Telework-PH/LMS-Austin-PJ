#include "C:\Users\twph.coders\Desktop\Library-Management-System-Private-main\Library-Management-System\Library Management System\include\global.h"
#include "C:\Users\twph.coders\Desktop\Library-Management-System-Private-main\Library-Management-System\Library Management System\include\admin.h"
#include "C:\Users\twph.coders\Desktop\Library-Management-System-Private-main\Library-Management-System\Library Management System\include\manage_book.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>

BookInfo book;
std::string book_record = R"(C:\Users\twph.coders\Desktop\Library-Management-System-Private-main\Library-Management-System\Library Management System\data\book_record.csv)";

void ApplicationMenu(){
    system("cls");
    int choose;
    while(true){
        std::cout << "\t\t\t\t\t==================================================\n";
        std::cout << "\t\t\t\t\t|| [1] Create Book Record \n";
        std::cout << "\t\t\t\t\t|| [2] Read Book Record \n";
        std::cout << "\t\t\t\t\t|| [3] Update Book Record \n";
        std::cout << "\t\t\t\t\t|| [4] Delete Book Record \n";
        std::cout << "\t\t\t\t\t|| [5] Search Book Record \n";
        std::cout << "\t\t\t\t\t|| [6] Back \n";
        std::cout << "\t\t\t\t\t|| [7] Exit \n";
        std::cout << "\t\t\t\t\t|| [>] ";
        while (!(std::cin >> choose)) IntegerOnly();

        switch (choose) {
            case 1:
                system("cls");
                CreateBookRecord();
                std::cout << "\n\n";
                continue;
            case 2:
                system("cls");
                ReadBookRecord();
                std::cout << "\n\n";
                continue;
            case 3:
                system("cls");
                ReadBookRecord();
                UpdateBookRecord();
                std::cout << "\n\n";
                continue;
            case 4:
                system("cls");
                ReadBookRecord();
                DeleteBookRecord();
                std::cout << "\n\n";
                continue;
            case 5:
                system("cls");
                SearchBookRecord();
                std::cout << "\n\n";
                continue;
            case 6:
                system("cls");
                AdminInterface();
            case 7:
                exit(0);
            default:
                system("cls");
        }
    }
}
void CreateBookRecord(){
    system("cls");
    std::fstream fout;
    fout.open(book_record, std::ios::out | std::ios::app);
    std::cout << "\t\t\t\t\t==================================================\n";
    std::cout << "\t\t\t\t\t|| ADD NEW BOOK...\n";
    std::cout << "\t\t\t\t\t|| Book Name >> Author >> Genre >> Year Release\n";
    std::cout << "\t\t\t\t\t|| ID: ";
    while (!(std::cin >> book.book_id)) IntegerOnly();
    std::cin.ignore();
    std::cout << "\t\t\t\t\t|| Book Name: ";
    getline(std::cin, book.book_name);
    std::cout << "\t\t\t\t\t|| Author: ";
    getline(std::cin, book.book_author);
    std::cout << "\t\t\t\t\t|| Year: ";
    while (!(std::cin >> book.book_release)) IntegerOnly();
    std::cout << "\t\t\t\t\t|| Available: ";
    std::cin >> book.book_availability;

    fout << book.book_id << ","
         << book.book_name << ","
         << book.book_author << ","
         << book.book_release << ","
         << book.book_availability
         << "\n";
}
void ReadBookRecord(){
    system("cls");
    std::ifstream file(book_record);
    if (!file.is_open()) {
        std::cout << "\t\t\t\t\tError opening file." << std::endl;
        return;
    }

    std::vector<BookInfo> book_info;

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string data;

        if (std::getline(ss, data, ',')) {
            // Trim leading/trailing whitespaces from data
            data.erase(data.find_last_not_of(" \n\r\t") + 1);
            data.erase(0, data.find_first_not_of(" \n\r\t"));

            try {
                book.book_id = std::stoi(data);
            } catch (const std::invalid_argument& e) {
                std::cout << "\t\t\t\t\tError converting id to integer: " << e.what() << std::endl;
                continue; // Skip this line and move to the next one
            }
        }

        if (std::getline(ss, book.book_name, ',')) {
            // Trim leading/trailing spaces from name
            book.book_name.erase(0, book.book_name.find_first_not_of(" "));
            book.book_name.erase(book.book_name.find_last_not_of(" ") + 1);
        }
        if (std::getline(ss, book.book_author, ',')) {
            // Trim leading/trailing spaces from name
            book.book_author.erase(0, book.book_author.find_first_not_of(" "));
            book.book_author.erase(book.book_author.find_last_not_of(" ") + 1);
        }

        if (std::getline(ss, data)) {
            // Trim leading/trailing whitespaces from data
            data.erase(data.find_last_not_of(" \n\r\t") + 1);
            data.erase(0, data.find_first_not_of(" \n\r\t"));

            try {
                book.book_release = std::stoi(data);
            } catch (const std::invalid_argument& e) {
                std::cout << "\t\t\t\t\tError converting grade to integer: " << e.what() << std::endl;
                continue; // Skip this line and move to the next one
            }
        }

        book_info.push_back(book);
    }

    file.close();

    // Print data in the desired format
    for (const auto& books : book_info) {
        std::cout << "\t\t\t\t\t==================================================\n";
        //std::cout << "\t\t\t\t\t|| AVAILABLE: || " << books.book_availability << "\n";
        std::cout << "\t\t\t\t\t|| ID:        || " << books.book_id << "\n";
        std::cout << "\t\t\t\t\t|| TITLE:     || " << books.book_name << "\n";
        std::cout << "\t\t\t\t\t|| AUTHOR:    || " << books.book_author << "\n";
        std::cout << "\t\t\t\t\t|| YEAR:      || " << books.book_release << "\n";
    }
    std::cout << "\t\t\t\t\t==================================================\n";
}
void UpdateBookRecord() {

    std::ifstream inFile(book_record);
    std::ofstream tempFile("temp_book.csv");

    if (!inFile || !tempFile) {
        std::cerr << "Error opening files." << std::endl;
        return;
    }

    int updateBook;
    std::cout << "\t\t\t\t\t|| UPDATE A BOOK...\n";
    std::cout << "\t\t\t\t\t|| ID: "; std::cin >> updateBook;

    std::string line;
    int lineNum = -1;
    while (std::getline(inFile, line)) {
        lineNum++;
        if (lineNum != updateBook) {
            tempFile << line << std::endl;
        } else {
            BookInfo updatedBook;
            updatedBook.book_id = updateBook;

            std::cin.ignore();
            std::cout << "\t\t\t\t\t|| Book Name: ";
            getline(std::cin, updatedBook.book_name);
            std::cout << "\t\t\t\t\t|| Author: ";
            getline(std::cin, updatedBook.book_author);
            std::cout << "\t\t\t\t\t|| Year: ";
            std::cin >> updatedBook.book_release;

            tempFile << updatedBook.book_id << ","
                     << updatedBook.book_name << ","
                     << updatedBook.book_author << ","
                     << updatedBook.book_release
                     << std::endl;
        }
    }
    inFile.close();
    tempFile.close();

    // Remove the original file
    std::remove(book_record.c_str());

    // Rename the temporary file to the original file name
    std::rename("temp_book.csv", book_record.c_str());
    std::cout << "\t\t\t\t\t|| Book record updated successfully!\n";
}
void DeleteBookRecord(){
    std::cout << "\n\n";

    std::ifstream inFile(book_record);
    std::ofstream tempFile("temp_book.csv");

    if (!inFile || !tempFile) {
        std::cerr << "\t\t\t\t\tError opening files." << std::endl;
        return;
    }

    int lineToDelete;
    std::cout << "\t\t\t\t\t==================================================\n";
    std::cout << "\t\t\t\t\t|| Delete a record...\n";
    std::cout << "\t\t\t\t\t|| ID: ";
    while (!(std::cin >> lineToDelete)) IntegerOnly();

    std::string line;
    int lineNum = -1; // Starts at line 2. Line 1 is for header.
    while (std::getline(inFile, line)) {
        lineNum++;
        if (lineNum != lineToDelete) {
            tempFile << line << std::endl;
        }
    }

    inFile.close();
    tempFile.close();

    // Remove the original file
    std::remove(book_record.c_str());

    // Rename the temporary file to the original file name
    std::rename("temp_book.csv", book_record.c_str());

}
void SearchBook(){
    system("cls");
    std::ifstream file(book_record);

    if (!file.is_open()) {
        std::cout << "\t\t\t\t\tError opening file!" << std::endl;
        return;
    }

    std::string book_to_find;
    std::cin.ignore();
    std::cout << "\t\t\t\t\tSearch: ";
    getline(std::cin, book_to_find);

    bool book_found = false;
    std::string line;
    std::string lowerTitleToFind = toLower(book_to_find);
    std::vector<std::string> found_lines;

    while (std::getline(file, line)) {
        std::string lowerLine = toLower(line);
        size_t found = lowerLine.find(lowerTitleToFind);
        if (found != std::string::npos) {
            book_found = true;
            found_lines.push_back(line);
        }
    }

    file.close();

    if (!book_found) {
        // Your code for the condition in the if statement goes here
        std::cout << "\t\t\t\t\tBook not found!" << std::endl;
    } else {
        std::cout << "\t\t\t\t\tSearch result!" << std::endl;
        // Print all lines of data found with the title
        for (const std::string& found_line : found_lines) {
            std::cout << "\t\t\t\t\t>>> " << found_line << std::endl;
        }
    }
}
void SearchBookRecord(){
    system("cls");
    while (true) {
        int choose;
        std::cout << "\t\t\t\t\t==================================================\n";
        std::cout << "\t\t\t\t\t|| Search Book \n";
        std::cout << "\t\t\t\t\t|| [1] Search \n";
        std::cout << "\t\t\t\t\t|| [2] Back \n";
        std::cout << "\t\t\t\t\t|| [3] Exit \n";
        std::cout << "\t\t\t\t\t|| [>] ";
        while (!(std::cin >> choose)) IntegerOnly();
        switch (choose) {
            case 1:
                system("cls");
                SearchBook();
                continue;
            case 2:
                system("cls");
                ApplicationMenu();
                continue;
            case 3:
                exit(0);
            default:
                continue;
        }
    }
}