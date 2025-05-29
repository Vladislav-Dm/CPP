#include <iostream>
#include <fstream>
#include <clocale>

int main() {
    setlocale(LC_ALL, "Russian");

    int a, b;

    std::cout << "Введи A: ";
    std::cin >> a;
    std::cout << "Введи B (больше A): ";
    std::cin >> b;
    std::ofstream f("output");

    // Идем по числам от A до B
    for (int i = a; i <= b; i++) {
        // Записываем в файл число, умноженное на 3, и переходим на новую строку
        f << i * 3 << std::endl;
    }

    return 0;
}

