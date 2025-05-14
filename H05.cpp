#include <iostream>
#include <iomanip>
#include <cmath>
#include <clocale>

using namespace std;

// ������� usain_run: ������������ �������� �� N-� ����� � ����� ����� ����
// V � ��������� �������� � ��/�, N � ����� �����
pair<double, double> usain_run(double V, int N) {
    double speed = V;         // ������� ��������
    double total_t = 0.0;     // ����� ����� (� ��������)

    for (int i = 0; i < N; ++i) {
        double speed_mps = speed * 1000 / 3600; // ������� �������� �� ��/� � �/�
        double lap_t = 500 / speed_mps;         // ����� �� ���� (500 �) = ���������� / ��������
        total_t += lap_t;                       // ��������� ����� ����� � ������ �������
        speed *= 0.95;                          // ��������� �������� �� 5%
    }

    return make_pair(speed, total_t);  // ����������: �������� �������� � ����� �����
}

// ������� x: �������, ������� ������ �������� �����,
// ���� ��� �������� �� ������ ���� ��������� ��������
pair<int, double> x(double start_speed, double min_speed) {
    double speed = start_speed;  // ��������� ��������
    double total_t = 0.0;        // ����� �����
    int laps = 0;                // ���������� ������

    // �����, ���� �������� >= �����������
    while (speed >= min_speed) {
        double speed_mps = speed * 1000 / 3600; // ������� � �/�
        double lap_t = 500 / speed_mps;         // ����� �����
        total_t += lap_t;                       // ���������� �� �������
        speed *= 0.95;                          // ��������� �������� �� 5%
        ++laps;                                 // ����������� ������� ������
    }

    return make_pair(laps, total_t);  // ���������� ����� � �����
}

// ������� x: ����������, ������� ������ ����� ���������
// �� �������� �����, ������� � ����������� ��������
int x(double start_speed, double time_l) {
    double speed = start_speed;
    double total_t = 0.0;
    int laps = 0;

    while (true) {
        double speed_mps = speed * 1000 / 3600; // ������� � �/�
        double lap_t = 500 / speed_mps;         // ����� �����

        // ���� ���������� ��� ������ ����� �������� ����� ������� � ���������������
        if (total_t + lap_t > time_l) break;

        total_t += lap_t;      // ��������� ����� �����
        speed *= 0.95;         // ��������� �������� �� 5%
        ++laps;                // ����������� ������� ������
    }

    return laps;  // ���������� ���������� ������
}

int main() {
    setlocale(LC_ALL, "Russian");  // �������� ��������� ������� ����������� (��� ������ ���������)

    // ������ ��������: ��������� �������� 40 ��/�, ���� �� ��������� ���� 4 ��/�
    auto [laps_40, total_t_40] = simulate_until_threshold(40.0, 4.0);

    // ������ ��������: ��������� �������� 35 ��/�, ��� ������� �� �������, ��� � � ������ ������
    int laps_35 = simulate_with_time_limit(35.0, total_t_40);

    // ������������� �������� ������ �� 2 ������ ����� �������
    cout << fixed << setprecision(2);

    // ������� ������� �����������
    cout << "--------------------------------------------------\n";
    cout << "| ��������� �������� | ������ | ����� ����� (���) |\n";
    cout << "--------------------------------------------------\n";
    cout << "|       40 ��/�      |   " << setw(4) << laps_40
         << "  |     " << setw(8) << total_t_40 << "    |\n";
    cout << "|       35 ��/�      |   " << setw(4) << laps_35
         << "  |     " << setw(8) << total_t_40 << "    |\n";
    cout << "--------------------------------------------------\n";

    return 0;
}

