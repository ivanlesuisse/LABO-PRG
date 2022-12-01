cmake_minimum_required(VERSION 3.23)
project(LABO_PRG)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LABO_PRG
        dictionnaire_anglais.txt
        dictionnaire_francais.txt
        fonctions.cpp
        fonctions.h
        main.cpp)
