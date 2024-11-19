#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time {
private:
    unsigned char hours;   // Часы (0-23)
    unsigned char minutes; // Минуты (0-59)

    void validateTime(); // Проверка корректности времени

public:
    // Конструкторы
    Time();
    Time(unsigned char h, unsigned char m);
    Time(const Time& other);

    // Методы доступа
    unsigned char getHours() const;
    unsigned char getMinutes() const;
    void setHours(unsigned char h);
    void setMinutes(unsigned char m);

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
