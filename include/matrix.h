#pragma once
#include <string>
typedef struct {
    char** data; // Указатель на двумерный массив
    int rows;      // Количество строк
    int cols;      // Количество столбцов
} Matrix;

// Базовые функции
Matrix create_matrix(int rows, int cols);
void   free_matrix(Matrix m);


// Вспомогательные функции
Matrix string_to_matrix(char* text, int rows, int cols);

Matrix encrypt(Matrix chars);

std::string decrypt(Matrix encrypted);

