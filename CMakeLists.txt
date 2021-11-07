cmake_minimum_required(VERSION 3.20)
project(Podstawy_Programowania_1 C)

set(CMAKE_C_STANDARD 11)

include_directories("1. Wprowadzanie i wyswietlanie danych")
include_directories("2. Instrukcje wakunkowe, wyboru switch .. case")
include_directories("3. Petle, instrukcje iteracyjne")

add_executable(Podstawy_Programowania_1
        "3. Petle, instrukcje iteracyjne/1.Wyswietlanie_liczb_w_petli.c")
