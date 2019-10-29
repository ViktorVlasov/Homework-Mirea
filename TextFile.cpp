#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void createdFile() {
	ofstream outf("TextFile.txt");

	if (!outf) {
		cout << "Sorry, I can't open file." << endl;
		exit(1);
	}

	string str;
	getline(cin, str);
	outf << str;
	
	outf.close();
}

int main()
{
	setlocale(LC_ALL, "russian");
	
	createdFile();

	ifstream inf("TextFile.txt");

	// Проверяем, открылся ли файл.
	if (!inf.is_open()) {
		cout << "Sorry, I can't read file." << endl;
		exit(1);
	}
	else {
		string word, minword;
		int minlenght = 1000000;

		// Ищем слово, минимальное по длине
		while (inf >> word) {
			if (word.length() < minlenght) {
				minlenght = word.length();
				minword = word;
			}
		}

		inf.clear(); // очищаем поток
		inf.seekg(0, ios_base::beg); // переходим в начало файла.


		string result = minword;
		int count = 1;
		// Проверяем, есть ли в строке слово такой же минимальной длины
		while (inf >> word) {
			if (minword.length() == word.length() && result != word) {
				result = result + " " + word;
				count += 1;
			}
		}

		inf.close(); 

		cout << result << endl;
		cout << "Наименьшая длина слова(слов): " << minlenght << endl;
		cout << "Количество слов: " << count << endl;
		
	}
}

