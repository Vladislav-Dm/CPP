#include <iostream>
#include <fstream>
#include <clocale>

int main() {
    setlocale(LC_ALL, "Russian");
    std::ifstream x("output");

    int c;   //
    int n = 0; // Счетчик, чтобы знать, какое число по порядку

    // Этот цикл будет работать, пока мы можем успешно читать числа из файла.
    // Если получилось, цикл продолжается. Если нет (файл кончился или там не число) - цикл остановится.
    while (x >> c) {
        n = n + 1; // Увеличиваем наш счетчик на 1
        std::cout << n << ". Число: " << c << std::endl;
    }

    return 0;
}
