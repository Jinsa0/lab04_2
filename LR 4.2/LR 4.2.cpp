// Lab_04_2.cpp
// Кіц Роман Романович
// Лабораторна робота № 4.2
// Табуляція функції, заданої формулою: функція однієї змінної.
// Варіант 12

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double x, xp, xk, dx, A, B, y;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;

    cout << fixed;
    cout << "---------------------------" << endl;
    cout << "|" << setw(5) << "x" << "     |"
        << setw(7) << "y" << "       |" << endl;
    cout << "---------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        if (fabs(x) < 1e-9)
        {
            // при x = 0 доданок (2+x)/x^2 не визначений, виводимо "undef"
            cout << "|" << setw(7) << setprecision(2) << x
                << "    |" << setw(10) << "undef"
                << "     |" << endl;
        }
        else
        {
            A = (2 + x) / (x * x) + 1;      // спільна частина

            if (x < 0)
                B = x * x * x - 2 * x * x * x * x;
            else
                if (x <= 2)
                    B = pow(fabs(x) + exp(x), 3);
                else
                    B = 4 * cos(x * x - 2);

            y = A + B;

            cout << "|" << setw(7) << setprecision(2) << x
                << "    |" << setw(10) << setprecision(3) << y
                << "     |" << endl;
        }
        x += dx;
    }
    cout << "---------------------------" << endl;

    return 0;
}
