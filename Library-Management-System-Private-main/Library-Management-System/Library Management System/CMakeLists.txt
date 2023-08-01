cmake_minimum_required(VERSION 3.25)
project(Library_Management_System)

set(CMAKE_CXX_STANDARD 23)

add_executable(Library_Management_System main.cpp include/manage_book.h include/admin.h src/admin.cpp src/manage_book.cpp src/manage_patron.cpp include/manage_patron.h src/manage_checkout_return.cpp include/manage_checkout_return.h include/global.h)



