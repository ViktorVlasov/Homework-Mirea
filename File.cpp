#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;
/* 
	6)Создать файл из натуральных чисел. В файле натуральных чисел найти
	наименьший и наибольший общие делители, также определить все простые
	числа и их количество. Все простые числа сохранить в другой файл.
	Предусмотреть возможность просмотра содержимого всех файлов.
*/

void createdFile() {
	ofstream outf("NaturalNum.txt");

	if (!outf) {
		cout << "Sorry, I can't open file." << endl;
		exit(1);
	}

	string str;
	getline(cin, str);
	outf << str;

	outf.close();
}

int evklid(int a, int b) {
	if (b == 0)
		return a;
	else
		return evklid(b, a % b);
}

// Функция, которая проверяет числа на простоту. 
// Если число составное, возвращаем 1, если простое, возвращаем 0
int check(int num) {
	int Counter = 0;

	for (int i = 1; i <= num; i++)
		if (num % i == 0)
			Counter++;

	if (Counter > 2) {
		return 1;
	}
	else {
		return 0;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	createdFile(); // Создаем файл из простых чисел
	
	// Обработка простых чисел.
	ifstream in("NaturalNum.txt");

	string n; // переменная, в которую мы считываем числа из файла
	int m; // переменная для преобразования считанного числа из типа string в тип int
	vector<int> a; // массив в который помещаем все числа из файла
	vector<int> b; // массив для простых чисел

	// получаем число из файла, преобразуем его в тип int и добавляем в массив
	for (int i = 0; in >> n; i++) {
		m = stoi(n);
		if (m != 1) { // единица не простое и не составное число
			a.push_back(m);
		}
	}

	// выводим полученный массив
	cout << "Введённые числа: ";
	for (int i = 0; i<a.size(); i++) {
		cout << a[i] << " ";
	}

	in.close();

	
	// Поиск НОД
	int nod = a[0];
	for (int i = 1; i < a.size(); i++) {
		nod = evklid(nod, a[i]);
	}


	// Проверяем каждое число на простоту, если оно простое, то помещаем его в массив b
	for (int i = 0; i < a.size(); i++) {
		if (!check(a[i])) {
			b.push_back(a[i]);
		}
	}

	if (b.empty()) {
		cout << "\nПростых чисел нет" << endl;
	}
	else {
		// Выводим массив из простых чисел
		cout << "\nПростые числа: ";
		for (int i = 0; i < b.size(); i++) {
			cout << b[i] << " ";
		}

		// Создаем новый файл для простых чисел
		ofstream prime("PrimeNumbers.txt");

		int count = 0;
		// Заполняем этот файл числами из массива простых чисел
		for (int i = 0; i < b.size(); i++) {
			count += 1;
			prime << b[i] << " ";
		}
		
		prime.close();
		cout << "\n-------------------" << endl;
		cout << "Количество простых чисел: " << count << endl;

	}
	
	cout << "Наибольший общий делитель всех чисел: " << nod << endl;
	cout << "Наименьший общий делитель всех чисел: 1" << endl;
	
}

