#include "matrix.h"
#include <stdexcept>

int main() {
    try {
        // Тест 1: Базовый тест
        std::cout << "=== Тест 1: Базовый тест ===" << std::endl;
        char text1[] = "resawyuio";
        Matrix mat1 = string_to_matrix(text1, 3, 3);
        
        std::cout << "Исходная матрица:" << std::endl;
        for (int i = 0; i < mat1.rows; i++) {
            for (int j = 0; j < mat1.cols; j++) {
                std::cout << mat1.data[i][j] << " ";
            }
            std::cout << std::endl;
        }
        
        Matrix encrypted1 = encrypt(mat1);
        std::cout << "\n Зашифрованная матрица:" << std::endl;
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
        
        // // Тест 2: Другой размер
        // std::cout << "\n=== Тест 2: Другой размер ===" << std::endl;
        // char text2[] = "ABCDEFGHIJKL";
        // Matrix mat2 = string_to_matrix(text2, 3, 4);
        
        // Matrix encrypted2 = encrypt(mat2);
        // std::string decrypted2 = decrypt(encrypted2);
        
        // std::cout << "Исходный текст: ABCDEFGHIJKL" << std::endl;
        // std::cout << "Расшифрованный текст: " << decrypted2 << std::endl;
        
        // // Освобождение памяти
        // free_matrix(mat2);
        // free_matrix(encrypted2);
        
        // // Тест 3: Пробуем пустую строку
        // std::cout << "\n=== Тест 3: Пустая строка ===" << std::endl;
        // char text3[] = "";
        // Matrix mat3 = string_to_matrix(text3, 0, 0);
        
        // Matrix encrypted3 = encrypt(mat3);
        // std::string decrypted3 = decrypt(encrypted3);
        
        // std::cout << "Расшифрованный текст (пустой): '" << decrypted3 << "'" << std::endl;
        
        // // Освобождение памяти
        // free_matrix(mat3);
        // free_matrix(encrypted3);
        
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