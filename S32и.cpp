#include <iostream>
#include <cstring>
#include <clocale>

using namespace std;

void shiftLetters(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        char* p = str + i;

        if ((*p >= 'a' && *p <= 'z')) {
            *p = (*p == 'z') ? 'a' : *p + 1;
        } else if ((*p >= 'A' && *p <= 'Z')) {
            *p = (*p == 'Z') ? 'A' : *p + 1;
        }
    }
}

int main() {

    setlocale(LC_ALL, "Russian");
    char str[100];
    cout << "Введите строку: ";
    cin.getline(str, 100);

    shiftLetters(str);

    cout << "Результат: " << str << endl;

    return 0;
}
