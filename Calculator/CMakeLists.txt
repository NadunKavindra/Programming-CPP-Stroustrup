cmake_minimum_required(VERSION 3.21)
project(Calculator)

set(CMAKE_CXX_STANDARD 14)

add_executable(Calculator Calculator.cpp Token.hpp TokenStream.cpp TokenStream.hpp SymbolTable.cpp SymbolTable.hpp main.cpp Calculator.hpp)
