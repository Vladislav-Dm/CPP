#include <iostream>
#include <clocale>

using namespace std;

class Bucket {
public:
    double c;
    double u;

    Bucket(double cap) {
        c = cap;
        u = 0.0;
        cout << "�����: " << c << " �." << endl;
    }

    void flush() {
        u = 0.0;
        cout << "����������." << endl;
    }

    double fill(double a) {
        if (a < 0) {
            cout << "������ < 0!" << endl;
            return 0;
        }

        double f = c - u;

        if (a <= f) {
            u = u + a;
            cout << "������ " << a << " �. � ����� " << u << " �." << endl;
            return 0.0;
        } else {
            double p = f;
            double o = a - f;

            u = c;

            cout << "������ " << a << " �. ������ " << p << " �. ������." << endl;
            cout << "������: " << o << " �." << endl;
            return o;
        }
    }

    void status() {
        cout << "�����: ����� " << c << " �, ������ " << u
             << " �, �������� " << (c - u) << " �." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "--- �����1 (10�) ---" << endl;
    Bucket vedro1(10.0);
    vedro1.status();
    cout << endl;

    cout << "--- ���� 4� ---" << endl;
    vedro1.fill(4.0);
    vedro1.status();
    cout << endl;

    cout << "--- ���� 7� (�������) ---" << endl;
    double o = vedro1.fill(7.0);
    cout << "fill() ������� (������): " << o << " �." << endl;
    vedro1.status();
    cout << endl;

    cout << "--- ���������� ---" << endl;
    vedro1.flush();
    vedro1.status();
    cout << endl;

    cout << "--- ���� 12� (�������) ---" << endl;
    o = vedro1.fill(12.0);
    cout << "fill() ������� (������): " << o << " �." << endl;
    vedro1.status();
    cout << endl;

    return 0;
}
