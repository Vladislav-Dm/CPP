#include <iostream>
#include <algorithm> // Для std::sort
#include <clocale>

void sort(int arr[10]) {
    std::sort(arr, arr + 10, [](int a, int b) {
        return a > b; // Сортировка по убыванию
    });
}

int main() {
    setlocale(LC_ALL, "Russian");

    int a[10] = {1, 8, 3, 6, 5, 4, 9, 2, 8, 12};

    std::cout << "Исходный массив: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    sort(a);

    std::cout << "Отсортированный массив (по убыванию): ";
    for (int i = 0; i < 10; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
