cmake_minimum_required(VERSION 3.24)
project(LogIn_and_SignUp_system)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_PREFIX_PATH "C:/Qt/6.5.0/mingw_64/lib/cmake")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6Widgets REQUIRED)

add_executable(LogIn_and_SignUp_system main.cpp)

target_link_libraries(LogIn_and_SignUp_system Qt6::Widgets)


