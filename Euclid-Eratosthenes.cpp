#include <iostream>
#include <vector>
#include <ctime> // для функции time()

using namespace std;

// Алгоритм Евклида
int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main()
{
	setlocale(LC_ALL, "russian");
	srand((time(0))); // устанавливаем значение системных часов в качестве стартового числа
	
	// Задаем промежуток чисел от 0 до n и выводим его.
	int n = rand() % 20 + 10;
	cout << "Промежуток от 1 до " << n << ":" << endl;
	for (int i = 1; i < n + 1; i++) {
		cout << i << " ";
	}
	cout << endl;

	// Алгоритм эратосфена, маркируем простые и составные числа в диапазоне от 2 до n
	vector<char> arr(n + 1, true); 
	arr[0] = arr[1] = false;
	for (int i = 2; i <= n; ++i)
		if (arr[i])
			if (i * 1ll * i <= n) // проверка на переполнение
				for (int j = i * i; j <= n; j += i)
					arr[j] = false;

	// В новый массив записываем только составные числа
	cout << "Составные числа:" << endl;
	vector<int> composite;
	for (int i = 2; i < n + 1; i++) { 
		if (arr[i] == false) {
			composite.push_back(i);
			cout << i << " "; // выводим составные числа
		}
	}
	cout << endl;

	// выбираем два случайных числа из массива составных чисел
	int a = 0, b = 0;
	while (a == b) {
		a = composite[rand() % composite.size()];
		b = composite[rand() % composite.size()];
	}

	cout << "Число а для алгоритма Евклида " << a << endl;
	cout << "Число b для алгоритма Евклида " << b << endl;

	// Вызываем алгоритм Евклида для a и b
	cout << "НОД: " << gcd(a, b) << endl;
	
}
