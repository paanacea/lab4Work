#include "Time.h"
#include <stdexcept>

// Проверка корректности времени
void Time::validateTime() {
    if (hours > 23 || minutes > 59) {
        throw std::invalid_argument("Неверное значение времени: часы <= 23, минуты <= 59.");
    }
}

// Конструкторы
Time::Time() : hours(0), minutes(0) {}

Time::Time(unsigned char h, unsigned char m) : hours(h), minutes(m) {
    validateTime();
}

Time::Time(const Time& other) : hours(other.hours), minutes(other.minutes) {}

// Методы доступа
unsigned char Time::getHours() const { return hours; }
unsigned char Time::getMinutes() const { return minutes; }

void Time::setHours(unsigned char h) {
    hours = h;
    validateTime();
}

void Time::setMinutes(unsigned char m) {
    minutes = m;
    validateTime();
}

// Добавление произвольного количества минут
Time Time::addMinutes(unsigned int addMinutes) const {
    unsigned totalMinutes = hours * 60 + minutes + addMinutes;
    unsigned newHours = (totalMinutes / 60) % 24;
    unsigned newMinutes = totalMinutes % 60;
    return Time(newHours, newMinutes);
}

// Унарные операции
Time& Time::operator++() {
    *this = this->addMinutes(1);
    return *this;
}

Time Time::operator++(int) {
    Time temp = *this;
    ++(*this);
    return temp;
}

Time& Time::operator--() {
    if (minutes == 0) {
        minutes = 59;
        hours = (hours == 0) ? 23 : hours - 1;
    } else {
        --minutes;
    }
    return *this;
}

Time Time::operator--(int) {
    Time temp = *this;
    --(*this);
    return temp;
}

// Операции приведения типа
Time::operator short int() const {
    return static_cast<short int>(hours);
}

Time::operator bool() const {
    return hours != 0 || minutes != 0;
}

// Бинарные операции
Time Time::operator+(unsigned int minutesToAdd) const {
    unsigned int totalMinutes = hours * 60 + minutes + minutesToAdd; // Считаем общее количество минут
    unsigned char newHours = (totalMinutes / 60) % 24; // Преобразуем в часы (с учетом переполнения суток)
    unsigned char newMinutes = totalMinutes % 60;      // Вычисляем минуты
    return Time(newHours, newMinutes);
}

Time Time::operator-(unsigned int minutesToSubtract) const {
    int totalMinutes = (hours * 60 + minutes ) - minutesToSubtract; // Вычитаем минуты
    if (totalMinutes < 0) {
        totalMinutes = (24 * 60 + totalMinutes) % (24 * 60); // Учет отрицательного времени, с переходом через полночь
    }
    unsigned char newHours = (totalMinutes / 60) % 24; // Преобразуем в часы
    unsigned char newMinutes = totalMinutes % 60;      // Вычисляем минуты
    return Time(newHours, newMinutes);
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, const Time& time) {
    os << (time.hours < 10 ? "0" : "") << static_cast<int>(time.hours) << ":"
       << (time.minutes < 10 ? "0" : "") << static_cast<int>(time.minutes);
    return os;
}
