#ifndef TIME_H
#define TIME_H

#include <iostream>

using byte = unsigned char; // Определяем byte как unsigned char

class Time {
private:
    byte hours;   // Часы (0-23)
    byte minutes; // Минуты (0-59)

    void validateTime(); // Проверка корректности времени

public:
    // Конструкторы
    Time();
    Time(byte h, byte m);
    Time(const Time& other);

    // Методы доступа
    byte getHours() const;
    byte getMinutes() const;
    void setHours(byte h);
    void setMinutes(byte m);

    // Добавление произвольного количества минут
    Time addMinutes(unsigned int addMinutes) const;

    // Унарные операции
    Time& operator++();    // Префиксный ++
    Time operator++(int);  // Постфиксный ++
    Time& operator--();    // Префиксный --
    Time operator--(int);  // Постфиксный --

    // Операции приведения типа
    explicit operator short int() const;
    operator bool() const;

    // Бинарные операции
    Time operator+(unsigned int addMinutes) const;
    Time operator-(unsigned int subMinutes) const;

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Time& time);
};

#endif // TIME_H
