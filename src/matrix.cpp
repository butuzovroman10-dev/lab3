#include "../include/matrix.h"

Matrix create_matrix(int rows, int cols) {
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.data = new char*[rows];
    
    for (int i = 0; i < rows; i++) {
        mat.data[i] = new char[cols];
        // Инициализируем пробелами
        for (int j = 0; j < cols; j++) {
            mat.data[i][j] = ' ';
        }
    }
    
    return mat;
}

void free_matrix(Matrix& mat) {
    if (mat.data != nullptr) {
        for (int i = 0; i < mat.rows; i++) {
            delete[] mat.data[i];
        }
        delete[] mat.data;
        mat.data = nullptr;
        mat.rows = 0;
        mat.cols = 0;
    }
}

Matrix string_to_matrix(const char* text, int rows, int cols) {
    Matrix mat = create_matrix(rows, cols);
    
    int text_length = strlen(text);
    int pos = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (pos < text_length) {
                mat.data[i][j] = text[pos++];
            }
            // Остальные ячейки остаются с пробелами
        }
    }
    
    return mat;
}

Matrix encrypt(Matrix chars) {
    // При транспонировании строки становятся столбцами и наоборот
    Matrix result = create_matrix(chars.cols, chars.rows);
    
    for (int i = 0; i < chars.rows; i++) {
        for (int j = 0; j < chars.cols; j++) {
            result.data[j][i] = chars.data[i][j];
        }
    }
    
    return result;
}

std::string decrypt(Matrix encrypted) {
    std::string result = "";
    
    // Для обратного преобразования создаем временную матрицу
    // Меняем размеры обратно
    Matrix temp = create_matrix(encrypted.cols, encrypted.rows);
    
    // Транспонируем обратно
    for (int i = 0; i < encrypted.rows; i++) {
        for (int j = 0; j < encrypted.cols; j++) {
            temp.data[j][i] = encrypted.data[i][j];
        }
    }
    
    // Считываем построчно из временной матрицы
    for (int i = 0; i < temp.rows; i++) {
        for (int j = 0; j < temp.cols; j++) {
            if (temp.data[i][j] != ' ') {
                result += temp.data[i][j];
            }
        }
    }
    
    free_matrix(temp);
    return result;
}

bool is_perfect_square(int n) {
    if (n < 0) return false;
    int root = static_cast<int>(std::sqrt(n));
    return root * root == n;
}

void print_matrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        std::cout << "| ";
        for (int j = 0; j < mat.cols; j++) {
            std::cout << mat.data[i][j] << " ";
        }
        std::cout << "|" << std::endl;
    }
}

int calculate_matrix_size(int text_length) {
    int size = static_cast<int>(std::ceil(std::sqrt(text_length)));
    return size;
}