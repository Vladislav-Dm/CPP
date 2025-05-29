#include <iostream>
#include <iomanip>
#include <clocale>

using namespace std;

class CreditCard {
public:
    int n;
    float b;

    CreditCard(int num, float bal) {
        n = num;
        b = bal;
        cout << "Карта N" << n << ". Баланс: " << fixed << setprecision(2) << b << " р." << endl;
    }

    void Put(float v) {
        if (v > 0) {
            b = b + v;
            cout << "N" << n << ": + " << v << " р. Баланс: " << b << " р." << endl;
        } else {
            cout << "N" << n << ": Сумма > 0!" << endl;
        }
    }

    void Take(float v) {
        if (v <= 0) {
            cout << "N" << n << ": Снимать > 0!" << endl;
            return;
        }

        if (v <= b) {
            b = b - v;
            cout << "N" << n << ": - " << v << " р. Баланс: " << b << " р." << endl;
        } else {
            cout << "N" << n << ": Мало денег! (" << b << " р.), хотят " << v << " р." << endl;
        }
    }

    void Info() {
        cout << "Карта N" << n << ", Баланс: " << fixed << setprecision(2) << b << " р." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    cout << fixed << setprecision(2);

    cout << "--- Карта m ---" << endl;
    CreditCard m(1234, 50.0f);
    m.Info();

    m.Put(100.0f);
    m.Take(30.0f);
    m.Take(500.0f);
    m.Info();
    cout << endl;

    cout << "--- Карта d (через указатель) ---" << endl;
    CreditCard d(5678, 1000.0f);
    d.Info();

    CreditCard* p = &d;

    cout << "+200р (->):" << endl;
    p->Put(200.0f);

    cout << "-50р (->):" << endl;
    p->Take(50.0f);

    cout << "Инфо (->):" << endl;
    p->Info();

    return 0;
}
