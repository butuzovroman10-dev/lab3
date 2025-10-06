/**
 * @file main.cpp
 * @brief Основной файл приложения для тестирования шифровальщика
 * @author Ваше Имя
 * @date 2024
 *
 * Содержит тестовые функции для демонстрации работы шифровальщика
 * методом транспонирования матрицы.
 */

#include "../include/matrix.h"
#include <iostream>

/**
 * @brief Тестирует шифрование и дешифрование для заданной фразы
 *
 * Функция выполняет полный цикл:
 * 1. Преобразование текста в матрицу
 * 2. Шифрование транспонированием
 * 3. Дешифрование обратным транспонированием
 * 4. Проверка результата
 *
 * @param phrase Текст для тестирования
 * @param description Описание теста для вывода
 *
 * @see encrypt
 * @see decrypt
 * @see string_to_matrix
 */
void test_phrase(const char* phrase, const std::string& description) {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "Тест: " << description << std::endl;
    std::cout << std::string(50, '=') << std::endl;

    int text_length = strlen(phrase);
    std::cout << "Исходный текст: '" << phrase << "'" << std::endl;
    std::cout << "Длина: " << text_length << " символов" << std::endl;

    // Вычисляем размер матрицы
    int size = calculate_matrix_size(text_length);
    std::cout << "Размер матрицы: " << size << "x" << size << std::endl;

    // Создаем матрицу из строки
    Matrix original = string_to_matrix(phrase, size, size);

    std::cout << "\nИсходная матрица:" << std::endl;
    print_matrix(original);

    // Шифруем
    Matrix encrypted = encrypt(original);
    std::cout << "\nЗашифрованная матрица (транспонированная):" << std::endl;
    print_matrix(encrypted);

    // Показываем шифр как в задании (чтение по столбцам исходной матрицы)
    std::cout << "\nШифр (чтение по столбцам исходной матрицы): \"";
    for (int j = 0; j < original.cols; j++) {
        for (int i = 0; i < original.rows; i++) {
            std::cout << original.data[i][j];
        }
        if (j < original.cols - 1) std::cout << " ";
    }
    std::cout << "\"" << std::endl;

    // Дешифруем
    std::string decrypted = decrypt(encrypted);
    std::cout << "\nРасшифрованный текст: '" << decrypted << "'" << std::endl;

    // Проверка
    if (decrypted == phrase) {
        std::cout << "✓ Шифрование и дешифрование прошли успешно!" << std::endl;
    } else {
        std::cout << "✗ Ошибка в шифровании/дешифровании!" << std::endl;
        std::cout << "Ожидалось: '" << phrase << "'" << std::endl;
        std::cout << "Получено:  '" << decrypted << "'" << std::endl;
    }

    // Освобождаем память
    free_matrix(original);
    free_matrix(encrypted);
}

/**
 * @brief Главная функция приложения
 *
 * Содержит набор тестов для демонстрации работы шифровальщика.
 *
 * @return int Код завершения программы (0 - успех, 1 - ошибка)
 *
 * @test Тест с фразой "ПРИВЕТМИР" из задания
 * @test Тест с английским текстом
 * @test Тест с разной длиной текста
 */
int main() {
    try {
        std::cout << "ШИФРОВАЛЬЩИК СООБЩЕНИЙ" << std::endl;
        std::cout << "Метод: транспонирование матрицы" << std::endl;

        // Тест из задания
        //test_phrase("ПРИВЕТМИР", "Основной тест из задания");

        // Дополнительные тесты
        test_phrase("HELLO", "Тест с английским текстом");
        test_phrase("ABCDEFGHI", "Тест с 9 символами (полный квадрат)");
        test_phrase("TEST", "Тест с 4 символами");

        std::cout << "\n" << std::string(50, '=') << std::endl;
        std::cout << "Все тесты завершены!" << std::endl;
        std::cout << std::string(50, '=') << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Произошла ошибка: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Произошла неизвестная ошибка" << std::endl;
        return 1;
    }

    return 0;
}
