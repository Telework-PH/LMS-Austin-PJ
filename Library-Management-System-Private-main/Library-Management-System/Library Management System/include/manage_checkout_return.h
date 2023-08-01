#ifndef LIBRARY_MANAGEMENT_SYSTEM_MANAGE_CHECKOUT_RETURN_H
#define LIBRARY_MANAGEMENT_SYSTEM_MANAGE_CHECKOUT_RETURN_H

#endif //LIBRARY_MANAGEMENT_SYSTEM_MANAGE_CHECKOUT_RETURN_H

void CheckOutReturnMenu();
std::string getCurrentDate();
void CheckOutBook();
void ReturnBook();
void DisplayCheckOut();

struct CheckoutInfo{
    int patron_id{};
    std::string patron_name;
    int book_id{};
    std::string book_name;
    std::string date_borrow;
    std::string date_due;
    float penalty;
};