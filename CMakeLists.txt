cmake_minimum_required(VERSION 3.24)
project(agenda)

set(CMAKE_CXX_STANDARD 17)

add_executable(agenda fichier.c fichier.h main.c timer.c application.c application.h)
