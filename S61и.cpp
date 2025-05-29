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
        cout << "Ведро: " << c << " л." << endl;
    }

    void flush() {
        u = 0.0;
        cout << "Опустошено." << endl;
    }

    double fill(double a) {
        if (a < 0) {
            cout << "Нельзя < 0!" << endl;
            return 0;
        }

        double f = c - u;

        if (a <= f) {
            u = u + a;
            cout << "Налито " << a << " л. В ведре " << u << " л." << endl;
            return 0.0;
        } else {
            double p = f;
            double o = a - f;

            u = c;

            cout << "Хотели " << a << " л. Влезло " << p << " л. Полное." << endl;
            cout << "Лишние: " << o << " л." << endl;
            return o;
        }
    }

    void status() {
        cout << "Ведро: Всего " << c << " л, Занято " << u
             << " л, Свободно " << (c - u) << " л." << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "--- Ведро1 (10л) ---" << endl;
    Bucket vedro1(10.0);
    vedro1.status();
    cout << endl;

    cout << "--- Льем 4л ---" << endl;
    vedro1.fill(4.0);
    vedro1.status();
    cout << endl;

    cout << "--- Льем 7л (перелив) ---" << endl;
    double o = vedro1.fill(7.0);
    cout << "fill() вернуло (лишние): " << o << " л." << endl;
    vedro1.status();
    cout << endl;

    cout << "--- Опустошаем ---" << endl;
    vedro1.flush();
    vedro1.status();
    cout << endl;

    cout << "--- Льем 12л (перелив) ---" << endl;
    o = vedro1.fill(12.0);
    cout << "fill() вернуло (лишние): " << o << " л." << endl;
    vedro1.status();
    cout << endl;

    return 0;
}
