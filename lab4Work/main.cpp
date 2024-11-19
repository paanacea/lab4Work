#include "Time.h"
#include <iostream>

int main() {
    try {
        unsigned int inputHours, inputMinutes; // Временные переменные для ввода
        std::cout << "Введите часы (0-23): ";
        std::cin >> inputHours;
        if (inputHours > 23) throw std::invalid_argument("Часы должны быть в диапазоне 0-23.");

        std::cout << "Введите минуты (0-59): ";
        std::cin >> inputMinutes;
        if (inputMinutes > 59) throw std::invalid_argument("Минуты должны быть в диапазоне 0-59.");

        // Преобразование в unsigned char
        unsigned char hours = static_cast<unsigned char>(inputHours);
        unsigned char minutes = static_cast<unsigned char>(inputMinutes);

        Time t(hours, minutes);
        std::cout << "Созданное время: " << t << std::endl;

        // Добавление минут
        unsigned int addMinutes;
        std::cout << "Введите количество минут для добавления: ";
        std::cin >> addMinutes;
        Time t1 = t + addMinutes;
        std::cout << "После добавления " << addMinutes << " минут: " << t1 << std::endl;

        // Вычитание минут
        unsigned int subMinutes;
        std::cout << "Введите количество минут для вычитания: ";
        std::cin >> subMinutes;
        Time t2 = t - subMinutes;
        std::cout << "После вычитания " << subMinutes << " минут: " << t2 << std::endl;

        // Унарные операции
        ++t;
        std::cout << "После префиксного ++: " << t << std::endl;
        t++;
        std::cout << "После постфиксного ++: " << t << std::endl;

        --t;
        std::cout << "После префиксного --: " << t << std::endl;
        t--;
        std::cout << "После постфиксного --: " << t << std::endl;

        // Операции приведения типа
        short int hoursAsShort = static_cast<short int>(t);
        std::cout << "Часы (short int): " << hoursAsShort << std::endl;

        if (t) {
            std::cout << "Время не равно 00:00" << std::endl;
        } else {
            std::cout << "Время равно 00:00" << std::endl;
        }

    } catch (const std::exception& ex) {
        std::cerr << "Ошибка: " << ex.what() << std::endl;
    }

    return 0;
}
