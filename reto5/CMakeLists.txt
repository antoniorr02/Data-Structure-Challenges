cmake_minimum_required(VERSION 3.21)
project(reto5)

set(CMAKE_CXX_STANDARD 14)
set(BASE_FOLDER estudiante)

include_directories(${BASE_FOLDER}/include)

if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/src/ejercicio40.cpp)
    add_executable(ejercicio40
            ${BASE_FOLDER}/src/ejercicio40.cpp estudiante/src/ejercicio40.cpp)
endif()

if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/src/ejercicio41.cpp)
    add_executable(ejercicio41
            ${BASE_FOLDER}/src/ejercicio41.cpp estudiante/src/ejercicio41.cpp)
endif()

if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/src/ejercicio38.cpp)
    add_executable(ejercicio38
            ${BASE_FOLDER}/src/ejercicio38.cpp estudiante/src/ejercicio38.cpp)
endif()

if (EXISTS ${CMAKE_SOURCE_DIR}/${BASE_FOLDER}/src/Ejercicio3_ExamenEnero2021.cpp)
    add_executable(Ejercicio3_ExamenEnero2021
            ${BASE_FOLDER}/src/Ejercicio3_ExamenEnero2021.cpp estudiante/src/Ejercicio3_ExamenEnero2021.cpp)
endif()