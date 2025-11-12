#include <iostream>
#include <string>
#include <windows.h>
#include "point1.h"
#include "point2.h"

void setupConsole() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
}

// Функции для ввода с проверкой
double inputDouble(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            break;
        } else {
            std::cout << "Ошибка: введите корректное число!" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }
    return value;
}

int inputInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            break;
        } else {
            std::cout << "Ошибка: введите целое число!" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }
    return value;
}

// Функция для задачи 1 (базовый класс)
void task1() {
    std::cout << "\n=== ЗАДАЧА 1: point1 ===" << std::endl;

    // Тест 1: Конструктор по умолчанию
    std::cout << "\n1. Тестирование конструктора по умолчанию:" << std::endl;
    Point1 p1;
    std::cout << "Создана точка: " << p1 << std::endl;
    std::cout << "Расстояние до начала координат: " << p1.distanceToOrigin() << std::endl;

    // Тест 2: Конструктор с параметрами
    std::cout << "\n2. Тестирование конструктора с параметрами:" << std::endl;
    double x1 = inputDouble("Введите координату x: ");
    double y1 = inputDouble("Введите координату y: ");
    Point1 p2(x1, y1);
    std::cout << "Создана точка: " << p2 << std::endl;
    std::cout << "Расстояние до начала координат: " << p2.distanceToOrigin() << std::endl;

    // Тест 3: Конструктор копирования
    std::cout << "\n3. Тестирование конструктора копирования:" << std::endl;
    Point1 p3(p2);
    std::cout << "Скопирована точка: " << p3 << std::endl;
    std::cout << "Расстояние до начала координат: " << p3.distanceToOrigin() << std::endl;

    // Тест 4: Сеттеры и геттеры
    std::cout << "\n4. Тестирование сеттеров и геттеров:" << std::endl;
    Point1 p4;
    double newX = inputDouble("Введите новую координату x: ");
    double newY = inputDouble("Введите новую координату y: ");
    p4.setX(newX);
    p4.setY(newY);
    std::cout << "Точка после изменения: " << p4 << std::endl;
    std::cout << "Координата x (через геттер): " << p4.getX() << std::endl;
    std::cout << "Координата y (через геттер): " << p4.getY() << std::endl;
    std::cout << "Расстояние до начала координат: " << p4.distanceToOrigin() << std::endl;

    std::cout << "\nЗадача 1 завершена успешно!" << std::endl;
}

// Функция для задачи 2 (класс с перегруженными операциями)
void task2() {
    std::cout << "\n=== ЗАДАЧА 2: Point2 С ПЕРЕГРУЖЕННЫМИ ОПЕРАЦИЯМИ ===" << std::endl;

    // Создание тестовых точек
    std::cout << "\n1. Создание тестовых точек:" << std::endl;
    double x1 = inputDouble("Введите координату x для точки 1: ");
    double y1 = inputDouble("Введите координату y для точки 1: ");
    Point2 p1(x1, y1);
    std::cout << "Создана точка 1: " << p1 << std::endl;

    double x2 = inputDouble("Введите координату x для точки 2: ");
    double y2 = inputDouble("Введите координату y для точки 2: ");
    Point2 p2(x2, y2);
    std::cout << "Создана точка 2: " << p2 << std::endl;

    // Тестирование унарных операций
    std::cout << "\n2. Тестирование унарных операций:" << std::endl;
    
    // Префиксный --
    std::cout << "Префиксный --p1:" << std::endl;
    std::cout << "До: " << p1 << std::endl;
    Point2 p1_prefix = --p1;
    std::cout << "После: " << p1 << std::endl;
    std::cout << "Результат: " << p1_prefix << std::endl;

    // Постфиксный --
    std::cout << "\nПостфиксный p2--:" << std::endl;
    std::cout << "До: " << p2 << std::endl;
    Point2 p2_postfix = p2--;
    std::cout << "После: " << p2 << std::endl;
    std::cout << "Результат: " << p2_postfix << std::endl;

    // Унарный - (смена координат местами)
    std::cout << "\nУнарный -p1 (смена координат местами):" << std::endl;
    Point2 p1_swapped = -p1;
    std::cout << "Исходная: " << p1 << std::endl;
    std::cout << "После смены: " << p1_swapped << std::endl;

    // Тестирование операций приведения типа
    std::cout << "\n3. Тестирование операций приведения типа:" << std::endl;
    
    // Неявное приведение к int
    int intValue = p1;
    std::cout << "Неявное приведение p1 к int: " << intValue << " (целая часть x)" << std::endl;
    
    // Явное приведение к double
    double doubleValue = static_cast<double>(p1);
    std::cout << "Явное приведение p1 к double: " << doubleValue << " (координата y)" << std::endl;

    // Тестирование бинарных операций
    std::cout << "\n4. Тестирование бинарных операций:" << std::endl;
    
    // Вычитание целого числа
    int subtractValue = inputInt("Введите целое число для вычитания из координаты x: ");
    Point2 p3 = p1 - subtractValue;
    std::cout << "p1 - " << subtractValue << " = " << p3 << std::endl;
    
    // Расстояние между точками
    double distance = p1 - p2;
    std::cout << "Расстояние между " << p1 << " и " << p2 << " = " << distance << std::endl;

    std::cout << "\nЗадача 2 завершена успешно!" << std::endl;
}

// Главное меню
void showMenu() {
    std::cout << "\n=== ГЛАВНОЕ МЕНЮ ===" << std::endl;
    std::cout << "1 - Задача 1 (Базовый класс Point)" << std::endl;
    std::cout << "2 - Задача 2 (Класс Point с перегруженными операциями)" << std::endl;
    std::cout << "0 - Выход" << std::endl;
    std::cout << "Выберите задачу: ";
}

int main() {
    setupConsole();
    int choice = 0;
    
    do {
        showMenu();
        std::cin >> choice;
        
        switch(choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 0:
                std::cout << "Выход из программы..." << std::endl;
                break;
            default:
                std::cout << "Неверный выбор! Попробуйте снова." << std::endl;
                break;
        }
        
        if (choice != 0) {
            std::cout << "\nНажмите Enter для продолжения...";
            std::cin.ignore();
            std::cin.get();
        }
        
    } while (choice != 0);
    
    return 0;
}