cmake_minimum_required(VERSION 3.28)
project(Projeto C)

set(CMAKE_C_STANDARD 11)

add_executable(Projeto main.c
        lista.c
        lista.h
        arvore.c
        arvore.h
        lista_dupla.c
        lista_dupla.h)
