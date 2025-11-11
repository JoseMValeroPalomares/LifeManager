cmake_minimum_required(VERSION 4.0)
project(LifeManager)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(LifeManager
        include/Entreno.h
        include/Gasto.h
        include/GestorEntrenos.h
        include/GestorGastos.h
        include/GestorTareas.h
        include/Shell.h
        include/Tarea.h
        src/Entreno.cpp
        src/Gasto.cpp
        src/GestorEntrenos.cpp
        src/GestorGastos.cpp
        src/GestorTareas.cpp
        src/main.cpp
        src/Shell.cpp
        src/Tarea.cpp
        include/Gestor.h)
