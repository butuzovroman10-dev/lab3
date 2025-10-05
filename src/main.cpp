#include "matrix.h"

// Функция для проверки, является ли число полным квадратом
bool is_perfect_square(int n) {
    if (n < 0) return false;
    int root = static_cast<int>(std::sqrt(n));
    return root * root == n;
}

int main() {
    try {
        // Тест 1: Базовый тест (полный квадрат - 9 символов)
        std::cout << "=== Тест 1: Базовый тест ===" << std::endl;
        char text1[] = "resawyuio";
        int len1 = strlen(text1);
        
        if (!is_perfect_square(len1)) {
            std::cerr << "Ошибка: длина строки " << len1 << " не является полным квадратом!" << std::endl;
            return 1;
        }
        
        int size1 = static_cast<int>(std::sqrt(len1));
        Matrix mat1 = string_to_matrix(text1, size1, size1);
        
        std::cout << "Исходная матрица:" << std::endl;
        for (int i = 0; i < mat1.rows; i++) {
            for (int j = 0; j < mat1.cols; j++) {
                std::cout << mat1.data[i][j] << " ";
            }
            std::cout << std::endl;
        }
        
        Matrix encrypted1 = encrypt(mat1);
        std::cout << "\nЗашифрованная матрица:" << std::endl;
        for (int i = 0; i < encrypted1.rows; i++) {
            for (int j = 0; j < encrypted1.cols; j++) {
                std::cout << encrypted1.data[i][j] << " ";
            }
            std::cout << std::endl;
        }
        
        std::string decrypted1 = decrypt(encrypted1);
        std::cout << "\nРасшифрованный текст: " << decrypted1 << std::endl;
        
        // Освобождение памяти
        free_matrix(mat1);
        free_matrix(encrypted1);
        
        // Тест 2: Не полный квадрат (должен завершиться с ошибкой)
        std::cout << "\n=== Тест 2: Не полный квадрат ===" << std::endl;
        char text2[] = "ABCDEFGHIJKL"; // 12 символов - не полный квадрат
        int len2 = strlen(text2);
        
        if (!is_perfect_square(len2)) {
            std::cerr << "Ошибка: длина строки " << len2 << " не является полным квадратом!" << std::endl;
            std::cout << "Тест пройден: корректно обнаружена строка не квадратной длины" << std::endl;
        } else {
            int size2 = static_cast<int>(std::sqrt(len2));
            Matrix mat2 = string_to_matrix(text2, size2, size2);
            Matrix encrypted2 = encrypt(mat2);
            std::string decrypted2 = decrypt(encrypted2);
            
            std::cout << "Исходный текст: ABCDEFGHIJKL" << std::endl;
            std::cout << "Расшифрованный текст: " << decrypted2 << std::endl;
            
            free_matrix(mat2);
            free_matrix(encrypted2);
        }
        
        // Тест 3: Другой полный квадрат (16 символов)
        std::cout << "\n=== Тест 3: Другой полный квадрат ===" << std::endl;
        char text3[] = "ABCDEFGHIJKLMNOP"; // 16 символов - полный квадрат
        int len3 = strlen(text3);
        
        if (!is_perfect_square(len3)) {
            std::cerr << "Ошибка: длина строки " << len3 << " не является полным квадратом!" << std::endl;
            return 1;
        }
        
        int size3 = static_cast<int>(std::sqrt(len3));
        Matrix mat3 = string_to_matrix(text3, size3, size3);
        
        std::cout << "Исходная матрица 4x4:" << std::endl;
        for (int i = 0; i < mat3.rows; i++) {
            for (int j = 0; j < mat3.cols; j++) {
                std::cout << mat3.data[i][j] << " ";
            }
            std::cout << std::endl;
        }
        
        Matrix encrypted3 = encrypt(mat3);
        std::cout << "\nЗашифрованная матрица 4x4:" << std::endl;
        for (int i = 0; i < encrypted3.rows; i++) {
            for (int j = 0; j < encrypted3.cols; j++) {
                std::cout << encrypted3.data[i][j] << " ";
            }
            std::cout << std::endl;
        }
        
        std::string decrypted3 = decrypt(encrypted3);
        std::cout << "\nРасшифрованный текст: " << decrypted3 << std::endl;
        
        // Освобождение памяти
        free_matrix(mat3);
        free_matrix(encrypted3);
        
        // Тест 4: Пустая строка (0 - считается полным квадратом)
        std::cout << "\n=== Тест 4: Пустая строка ===" << std::endl;
        char text4[] = "";
        int len4 = strlen(text4);
        
        if (!is_perfect_square(len4)) {
            std::cerr << "Ошибка: длина строки " << len4 << " не является полным квадратом!" << std::endl;
            return 1;
        }
        
        int size4 = static_cast<int>(std::sqrt(len4));
        Matrix mat4 = string_to_matrix(text4, size4, size4);
        
        Matrix encrypted4 = encrypt(mat4);
        std::string decrypted4 = decrypt(encrypted4);
        
        std::cout << "Расшифрованный текст (пустой): '" << decrypted4 << "'" << std::endl;
        
        // Освобождение памяти
        free_matrix(mat4);
        free_matrix(encrypted4);
        
    } catch (const std::bad_alloc& e) {
        std::cerr << "Ошибка выделения памяти: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Произошла ошибка: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Произошла неизвестная ошибка" << std::endl;
        return 1;
    }
    
    std::cout << "\nВсе тесты завершены успешно!" << std::endl;
    return 0;
}