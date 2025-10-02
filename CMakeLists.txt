cmake_minimum_required(VERSION 3.10)
project(MatrixProject)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включаем директории с исходниками
include_directories(include)

# Добавляем исполняемый файл
add_executable(matrix_app
    src/main.cpp
    src/matrix.cpp
)