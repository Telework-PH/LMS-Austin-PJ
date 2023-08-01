#ifndef LIBRARY_MANAGEMENT_SYSTEM_MANAGE_BOOK_H
#define LIBRARY_MANAGEMENT_SYSTEM_MANAGE_BOOK_H

#endif //LIBRARY_MANAGEMENT_SYSTEM_MANAGE_BOOK_H

void helloManageBook();

#include <string>

struct BookInfo {
    int book_id{};
    std::string book_name;
    std::string book_author;
    int book_release{};
    std::string book_availability;
};
std::string toLower(const std::string& str);
void ApplicationMenu();
void CreateBookRecord();
void ReadBookRecord();
void UpdateBookRecord();
void DeleteBookRecord();
void SearchBook();
void SearchBookRecord();