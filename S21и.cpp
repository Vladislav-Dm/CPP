#include <iostream>
#include <fstream>
#include <clocale>

int main() {
    setlocale(LC_ALL, "Russian");

    int a, b;

    std::cout << "����� A: ";
    std::cin >> a;
    std::cout << "����� B (������ A): ";
    std::cin >> b;
    std::ofstream f("output");

    // ���� �� ������ �� A �� B
    for (int i = a; i <= b; i++) {
        // ���������� � ���� �����, ���������� �� 3, � ��������� �� ����� ������
        f << i * 3 << std::endl;
    }

    return 0;
}

