// Капли.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>;
using namespace std;

int trap(vector<int>& height) {
    vector<int> left;
    int n, v = 0;
    int summ = 0;
    for (int i = 1; i < height.size(); i++) {
        if (height[i] < height[i - 1]) { left.push_back(i - 1); cout << i-1; cout << "|\n";}
        if (height[i] > height[i - 1]) {
            cout << i; cout << "/\n";
            n = left.size()-1;
            for (int j = n; j >= 0; j--) {
                if (height[left[j]] <= height[i]) {
                    v += (i - left[j] - 1) * (height[left[j]] - height[left[j] + 1]);
                    cout << height[left[j]]; cout << " "; cout << v;  cout << "\n";
                    left.erase(left.end()-1);
                }
                else {
                    v += (i - left[j] - 1) * (height[i] - height[left[j] + 1]);
                    height[left[j] + 1] = height[i];
                    cout << height[left[j]]; cout << " "; cout << v;  cout << "\n";
                    break;
                }
            }
            summ += v;
            v = 0;
        }
    }
    return summ;
}

int main()
{
    vector<int> gr = { 5,5,1,7,1,1,5,2,7,6 };
    int a = trap(gr);
    cout << a;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
