#ifndef LIBRARY_MANAGEMENT_SYSTEM_MANAGE_PATRON_H
#define LIBRARY_MANAGEMENT_SYSTEM_MANAGE_PATRON_H

#endif //LIBRARY_MANAGEMENT_SYSTEM_MANAGE_PATRON_H

#include <string>

struct PatronInfo{
    int patron_id{};
    std::string patron_name;
    std::string patron_email;
    int patron_phone;
    std::string patron_book; // borrowed book by patron.
};

void PatronMenu();
void CreatePatron();
void ReadPatron();
void UpdatePatron();
void DeletePatron();
void SearchPatron();
void SearchPatronRecord();