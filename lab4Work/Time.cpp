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

Time::Time(byte h, byte m) : hours(h), minutes(m) {
    validateTime();
}

Time::Time(const Time& other) : hours(other.hours), minutes(other.minutes) {}

// Методы доступа
byte Time::getHours() const { return hours; }
byte Time::getMinutes() const { return minutes; }

void Time::setHours(byte h) {
    hours = h;
    validateTime();
}

void Time::setMinutes(byte m) {
    minutes = m;
    validateTime();
}

// Добавление произвольного количества минут
Time Time::addMinutes(unsigned int addMinutes) const {
    unsigned totalMinutes = static_cast<int>(hours) * 60 + static_cast<int>(minutes) + addMinutes;
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
    if (static_cast<int>(minutes) == 0) {
        minutes = 59;
        hours = (static_cast<int>(hours) == 0) ? 23 : hours - 1;
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
    return static_cast<int>(hours) != 0 || static_cast<int>(minutes) != 0;
}

// Бинарные операции
Time Time::operator+(unsigned int minutesToAdd) const {
    unsigned int totalMinutes = static_cast<int>(hours) * 60 + static_cast<int>(minutes) + minutesToAdd;
    byte newHours = static_cast<byte>((totalMinutes / 60) % 24);
    byte newMinutes = static_cast<byte>(totalMinutes % 60);
    return Time(newHours, newMinutes);
}

Time Time::operator-(unsigned int minutesToSubtract) const {
    int totalMinutes = (static_cast<int>(hours) * 60 + static_cast<int>(minutes)) - minutesToSubtract;

    if (totalMinutes < 0) {
        totalMinutes = (24 * 60 + totalMinutes) % (24 * 60);
    }

    byte newHours = static_cast<byte>((totalMinutes / 60) % 24);
    byte newMinutes = static_cast<byte>(totalMinutes % 60);
    return Time(newHours, newMinutes);
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, const Time& time) {
    os << (static_cast<int>(time.hours) < 10 ? "0" : "") << static_cast<int>(time.hours) << ":"
       << (static_cast<int>(time.minutes) < 10 ? "0" : "") << static_cast<int>(time.minutes);
    return os;
}
