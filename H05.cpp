#include <iostream>
#include <iomanip>
#include <cmath>
#include <clocale>

using namespace std;

// Функция usain_run: рассчитывает скорость на N-м круге и общее время бега
// V — начальная скорость в км/ч, N — номер круга
pair<double, double> usain_run(double V, int N) {
    double speed = V;         // текущая скорость
    double total_t = 0.0;     // общее время (в секундах)

    for (int i = 0; i < N; ++i) {
        double speed_mps = speed * 1000 / 3600; // перевод скорости из км/ч в м/с
        double lap_t = 500 / speed_mps;         // время на круг (500 м) = расстояние / скорость
        total_t += lap_t;                       // добавляем время круга к общему времени
        speed *= 0.95;                          // уменьшаем скорость на 5%
    }

    return make_pair(speed, total_t);  // возвращаем: конечную скорость и общее время
}

// Функция x: считает, сколько кругов пробежит Усейн,
// пока его скорость не станет ниже заданного минимума
pair<int, double> x(double start_speed, double min_speed) {
    double speed = start_speed;  // начальная скорость
    double total_t = 0.0;        // общее время
    int laps = 0;                // количество кругов

    // Бежим, пока скорость >= минимальной
    while (speed >= min_speed) {
        double speed_mps = speed * 1000 / 3600; // перевод в м/с
        double lap_t = 500 / speed_mps;         // время круга
        total_t += lap_t;                       // прибавляем ко времени
        speed *= 0.95;                          // уменьшаем скорость на 5%
        ++laps;                                 // увеличиваем счётчик кругов
    }

    return make_pair(laps, total_t);  // возвращаем круги и время
}

// Функция x: определяет, сколько кругов можно пробежать
// за заданное время, начиная с определённой скорости
int x(double start_speed, double time_l) {
    double speed = start_speed;
    double total_t = 0.0;
    int laps = 0;

    while (true) {
        double speed_mps = speed * 1000 / 3600; // перевод в м/с
        double lap_t = 500 / speed_mps;         // время круга

        // если добавление ещё одного круга превысит лимит времени — останавливаемся
        if (total_t + lap_t > time_l) break;

        total_t += lap_t;      // добавляем время круга
        speed *= 0.95;         // уменьшаем скорость на 5%
        ++laps;                // увеличиваем счётчик кругов
    }

    return laps;  // возвращаем количество кругов
}

int main() {
    setlocale(LC_ALL, "Russian");  // включаем поддержку русской локализации (для вывода кириллицы)

    // Первый сценарий: начальная скорость 40 км/ч, пока не опустится ниже 4 км/ч
    auto [laps_40, total_t_40] = simulate_until_threshold(40.0, 4.0);

    // Второй сценарий: начальная скорость 35 км/ч, бег столько же времени, как и в первом случае
    int laps_35 = simulate_with_time_limit(35.0, total_t_40);

    // Устанавливаем точность вывода до 2 знаков после запятой
    cout << fixed << setprecision(2);

    // Выводим таблицу результатов
    cout << "--------------------------------------------------\n";
    cout << "| Начальная скорость | Кругов | Общее время (сек) |\n";
    cout << "--------------------------------------------------\n";
    cout << "|       40 км/ч      |   " << setw(4) << laps_40
         << "  |     " << setw(8) << total_t_40 << "    |\n";
    cout << "|       35 км/ч      |   " << setw(4) << laps_35
         << "  |     " << setw(8) << total_t_40 << "    |\n";
    cout << "--------------------------------------------------\n";

    return 0;
}

