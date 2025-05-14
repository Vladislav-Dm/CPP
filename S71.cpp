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
        cout << "����� N" << n << ". ������: " << fixed << setprecision(2) << b << " �." << endl;
    }

    void Put(float v) {
        if (v > 0) {
            b = b + v;
            cout << "N" << n << ": + " << v << " �. ������: " << b << " �." << endl;
        } else {
            cout << "N" << n << ": ����� > 0!" << endl;
        }
    }

    void Take(float v) {
        if (v <= 0) {
            cout << "N" << n << ": ������� > 0!" << endl;
            return;
        }

        if (v <= b) {
            b = b - v;
            cout << "N" << n << ": - " << v << " �. ������: " << b << " �." << endl;
        } else {
            cout << "N" << n << ": ���� �����! (" << b << " �.), ����� " << v << " �." << endl;
        }
    }

    void Info() {
        cout << "����� N" << n << ", ������: " << fixed << setprecision(2) << b << " �." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    cout << fixed << setprecision(2);

    cout << "--- ����� m ---" << endl;
    CreditCard m(1234, 50.0f);
    m.Info();

    m.Put(100.0f);
    m.Take(30.0f);
    m.Take(500.0f);
    m.Info();
    cout << endl;

    cout << "--- ����� d (����� ���������) ---" << endl;
    CreditCard d(5678, 1000.0f);
    d.Info();

    CreditCard* p = &d;

    cout << "+200� (->):" << endl;
    p->Put(200.0f);

    cout << "-50� (->):" << endl;
    p->Take(50.0f);

    cout << "���� (->):" << endl;
    p->Info();

    return 0;
}
