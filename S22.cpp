#include <iostream>
#include <fstream>
#include <clocale>

int main() {
    setlocale(LC_ALL, "Russian");
    std::ifstream x("output");

    int c;   //
    int n = 0; // �������, ����� �����, ����� ����� �� �������

    // ���� ���� ����� ��������, ���� �� ����� ������� ������ ����� �� �����.
    // ���� ����������, ���� ������������. ���� ��� (���� �������� ��� ��� �� �����) - ���� �����������.
    while (x >> c) {
        n = n + 1; // ����������� ��� ������� �� 1
        std::cout << n << ". �����: " << c << std::endl;
    }

    return 0;
}
