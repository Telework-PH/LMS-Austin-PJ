#include "C:\Users\twph.coders\Desktop\Library-Management-System-Private-main\Library-Management-System\Library Management System\include\global.h"
#include "C:\Users\twph.coders\Desktop\Library-Management-System-Private-main\Library-Management-System\Library Management System\include\admin.h"
#include "C:\Users\twph.coders\Desktop\Library-Management-System-Private-main\Library-Management-System\Library Management System\include\manage_patron.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>

PatronInfo patron;
std::string patron_record = R"(C:\Users\twph.coders\Desktop\Library-Management-System-Private-main\Library-Management-System\Library Management System\data\patron_record.csv)";

void PatronMenu(){
    system("cls");
    int choose;
    while(true){
        std::cout << "\t\t\t\t\t|| [1] Create Patron \n";
        std::cout << "\t\t\t\t\t|| [2] Read Patron \n";
        std::cout << "\t\t\t\t\t|| [3] Update Patron \n";
        std::cout << "\t\t\t\t\t|| [4] Delete Patron \n";
        std::cout << "\t\t\t\t\t|| [5] Search Patron \n";
        std::cout << "\t\t\t\t\t|| [6] Back \n";
        std::cout << "\t\t\t\t\t|| [7] Exit \n";
        std::cout << "\t\t\t\t\t|| [>] ";
        while (!(std::cin >> choose)) IntegerOnly();

        switch (choose) {
            case 1:
                system("cls");
                CreatePatron();
                std::cout << "\n\n";
                continue;
            case 2:
                system("cls");
                ReadPatron();
                std::cout << "\n\n";
                continue;
            case 3:
                system("cls");
                UpdatePatron();
                std::cout << "\n\n";
                continue;
            case 4:
                system("cls");
                DeletePatron();
                std::cout << "\n\n";
                continue;
            case 5:
                system("cls");
                SearchPatronRecord();
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

void CreatePatron(){
    system("cls");
    std::fstream fout;
    fout.open(patron_record, std::ios::out | std::ios::app);
    std::cout << "\t\t\t\t\t|| ADD NEW BOOK...\n";
    std::cout << "\t\t\t\t\t|| Book Name >> Author >> Genre >> Year Release\n";
    std::cout << "\t\t\t\t\t|| ID: ";
    while (!(std::cin >> patron.patron_id)) IntegerOnly();
    std::cin.ignore();
    std::cout << "\t\t\t\t\t|| Name: ";
    getline(std::cin, patron.patron_name);
    std::cout << "\t\t\t\t\t|| Email: ";
    getline(std::cin, patron.patron_email);
    std::cout << "\t\t\t\t\t|| Phone: ";
    while (!(std::cin >> patron.patron_phone)) IntegerOnly();

    fout << patron.patron_id << ","
         << patron.patron_name << ","
         << patron.patron_email << ","
         << patron.patron_phone
         << "\n";
}

void ReadPatron(){
    system("cls");
    std::ifstream file(patron_record);
    if (!file.is_open()) {
        std::cout << "\t\t\t\t\tError opening file." << std::endl;
        return;
    }

    std::vector<PatronInfo> patron_info;

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string data;

        if (std::getline(ss, data, ',')) {
            // Trim leading/trailing whitespaces from data
            data.erase(data.find_last_not_of(" \n\r\t") + 1);
            data.erase(0, data.find_first_not_of(" \n\r\t"));

            try {
                patron.patron_id = std::stoi(data);
            } catch (const std::invalid_argument& e) {
                std::cout << "\t\t\t\t\tError converting id to integer: " << e.what() << std::endl;
                continue; // Skip this line and move to the next one
            }
        }

        if (std::getline(ss, patron.patron_name, ',')) {
            // Trim leading/trailing spaces from name
            patron.patron_name.erase(0, patron.patron_name.find_first_not_of(" "));
            patron.patron_name.erase(patron.patron_name.find_last_not_of(" ") + 1);
        }
        if (std::getline(ss, patron.patron_email, ',')) {
            // Trim leading/trailing spaces from name
            patron.patron_email.erase(0, patron.patron_email.find_first_not_of(" "));
            patron.patron_email.erase(patron.patron_email.find_last_not_of(" ") + 1);
        }

        if (std::getline(ss, data)) {
            // Trim leading/trailing whitespaces from data
            data.erase(data.find_last_not_of(" \n\r\t") + 1);
            data.erase(0, data.find_first_not_of(" \n\r\t"));

            try {
                patron.patron_phone = std::stoi(data);
            } catch (const std::invalid_argument& e) {
                std::cout << "\t\t\t\t\tError converting grade to integer: " << e.what() << std::endl;
                continue; // Skip this line and move to the next one
            }
        }

        patron_info.push_back(patron);
    }

    file.close();

    // Print data in the desired format
    for (const auto& patrons : patron_info) {
        std::cout << "\t\t\t\t\t==================================================\n";
        std::cout << "\t\t\t\t\t|| ID:       || " << patrons.patron_id << "\n";
        std::cout << "\t\t\t\t\t|| NAME:     || " << patrons.patron_name << "\n";
        std::cout << "\t\t\t\t\t|| EMAIL:    || " << patrons.patron_email << "\n";
        std::cout << "\t\t\t\t\t|| PHONE:    || " << patrons.patron_phone << "\n";
    }
    std::cout << "\t\t\t\t\t==================================================\n";
}

void UpdatePatron() {
    system("cls");
    ReadPatron();

    std::ifstream inFile(patron_record);
    std::ofstream tempFile("temp_book.csv");

    if (!inFile || !tempFile) {
        std::cerr << "Error opening files." << std::endl;
        return;
    }

    int updatePatron;
    std::cout << "\t\t\t\t\t|| UPDATE A PATRON...\n";
    std::cout << "\t\t\t\t\t|| ID: "; std::cin >> updatePatron;

    std::string line;
    int lineNum = -1;
    while (std::getline(inFile, line)) {
        lineNum++;
        if (lineNum != updatePatron) {
            tempFile << line << std::endl;
        } else {
            PatronInfo updatedPatron;
            updatedPatron.patron_id = updatePatron;

            std::cin.ignore();
            std::cout << "\t\t\t\t\t|| Name: ";
            getline(std::cin, updatedPatron.patron_name);
            std::cout << "\t\t\t\t\t|| Email: ";
            getline(std::cin, updatedPatron.patron_email);
            std::cout << "\t\t\t\t\t|| Phone: ";
            std::cin >> updatedPatron.patron_phone;

            tempFile << updatedPatron.patron_id << ","
                     << updatedPatron.patron_name << ","
                     << updatedPatron.patron_email << ","
                     << updatedPatron.patron_phone
                     << std::endl;
        }
    }

    inFile.close();
    tempFile.close();

    // Remove the original file
    std::remove(patron_record.c_str());

    // Rename the temporary file to the original file name
    std::rename("temp_book.csv", patron_record.c_str());

    std::cout << "\t\t\t\t\t|| Book record updated successfully!\n";
}

void DeletePatron(){
    system("cls");
    ReadPatron();
    std::cout << "\n\n";

    std::ifstream inFile(patron_record);
    std::ofstream tempFile("temp_patron.csv");

    if (!inFile || !tempFile) {
        std::cerr << "\t\t\t\t\tError opening files." << std::endl;
        return;
    }

    int lineToDelete;
    std::cout << "\t\t\t\t\t|| Delete a record...\n";
    std::cout << "\t\t\t\t\t|| ID: ";
    while (!(std::cin >> lineToDelete)) IntegerOnly();

    std::string line;
    int lineNum = -1;
    while (std::getline(inFile, line)) {
        lineNum++;
        if (lineNum != lineToDelete) {
            tempFile << line << std::endl;
        }
    }

    inFile.close();
    tempFile.close();

    // Remove the original file
    std::remove(patron_record.c_str());

    // Rename the temporary file to the original file name
    std::rename("temp_patron.csv", patron_record.c_str());
}

void SearchPatron(){
    system("cls");
    std::ifstream file(patron_record);

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
        std::cout << "\t\t\t\t\tPatron not found!" << std::endl;
        // ...do something...
    } else {
        std::cout << "\t\t\t\t\tSearch result!" << std::endl;
        // Print all lines of data found with the title
        for (const std::string& found_line : found_lines) {
            std::cout << "\t\t\t\t\t>>> " << found_line << std::endl;
        }
        // ...do something else...
    }
}

void SearchPatronRecord(){
    system("cls");
    while (true) {
        int choose;
        std::cout << "\t\t\t\t\t==================================================\n";
        std::cout << "\t\t\t\t\t|| Search Patron \n";
        std::cout << "\t\t\t\t\t|| [1] Search \n";
        std::cout << "\t\t\t\t\t|| [2] Back \n";
        std::cout << "\t\t\t\t\t|| [3] Exit \n";
        std::cout << "\t\t\t\t\t|| [>] ";
        while (!(std::cin >> choose)) IntegerOnly();
        switch (choose) {
            case 1:
                system("cls");
                SearchPatron();
                break;
            case 2:
                system("cls");
                PatronMenu();
                break;
            case 3:
                exit(0);
            default:
                continue;
        }
    }
}