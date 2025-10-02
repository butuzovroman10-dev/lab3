#pragma once

typedef struct {
    char** data; // Указатель на двумерный массив
    int rows;      // Количество строк
    int cols;      // Количество столбцов
} Matrix;

// Базовые функции
Matrix create_matrix(int rows, int cols);
void   free_matrix(Matrix m);
Matrix matrix_add(Matrix a, Matrix b);

// Вспомогательные функции
void   print_matrix(Matrix m);
Matrix matrix_from_array(char* data, int rows, int cols);

// Индивидуальное задание
Matrix string_to_matrix(char* data, int rows, int cols);
Matrix encrypt(Matrix chars);
char* decrypt(Matrix encrypted);