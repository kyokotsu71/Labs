#include <iostream>
#include <string>
#include <fstream>

//1.	Дана строка длиной не более 100 символов.Посчитать количество знаков препинания в ней.
//2.	Дан файл, содержащий русский текст, размер текста не превышает 10 К байт.Найти в тексте N(N ≤ 100) 
	//	самых коротких слов, содержащих какую - либо букву три раза.Записать найденные слова в текстовый 
	//	файл в порядке не убывания длины.Все найденные слова должны быть разными.Число N вводить из файла.

int main()
{
	//5.1
	/*setlocale(0, "ru");
	int sc = 0;
	char str[100];
	char aboba[7] = { '.', ',', ':', ';', '!', '?', '-'};
	gets_s(str, 100);

	std::cout << str << std::endl; // мб удалить

	for (int j = 0; j < 7; j++) {
		for (int i = 0; i < strlen(str); i++) {
			if (str[i] == aboba[j]) {
				sc++;
			}
		}
	}

	std::cout << "Кол-во знаков препинания: " << sc;
	*/

	//5.2
	using namespace std;
	setlocale(0, "ru");
	string text;
	string sortword[100];
	string sortedword;
	string sortedwords[100];
	string finallysorted[100];
	int samecount = 0;
	string temp;
	string temp2;
	string threeletters;
	char s;
	int num = 0;
	int num2 = 0;
	int Num;

	ifstream in("input.txt", std::ios::in);
	ofstream out("output.txt", std::ios::out);

	in >> Num;

	for (int i = 0; i < 100; i++) {
		in >> text;
		sortword[i] = text;
	}

	for (int i = 0; i < 100; i++) {
		temp = sortword[i];
		for (int i = 0; i < temp.length(); i++) {
			s = temp[i];
			for (int i = 0; i < temp.size(); i++) {
				if ((s == temp[i]) || (s == temp[i] + 32)) {
					samecount++;
				}
			}
			if (samecount == 3) {
				threeletters += temp;
				threeletters += ' ';
				break;
			}
			samecount = 0;
		}
		temp = "";
	}

	for (int i = 0; i < threeletters.length(); i++) {
			if ((threeletters[i] != ' ')&& (threeletters[i] != '.')
										&& (threeletters[i] != ',') 
										&& (threeletters[i] != ':') 
										&& (threeletters[i] != ';') 
										&& (threeletters[i] != '?') 
										&& (threeletters[i] != '!')
										&& (threeletters[i] != '"')
										&& (threeletters[i] != '-')) {
				sortedword += threeletters[i];
			}
			if ((threeletters[i] == '.')
				|| (threeletters[i] == ',')
				|| (threeletters[i] == ':')
				|| (threeletters[i] == ';')
				|| (threeletters[i] == '?')
				|| (threeletters[i] == '!')
				|| (threeletters[i] == '"')
				|| (threeletters[i] == '-')) {
				i++;
			}
			if (threeletters[i] == ' ') {
				sortedwords[num] = sortedword;
				num++;
				sortedword = "";
			}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = i + 1; j < 101; j++) {
			if (sortedwords[i] == sortedwords[j]) {
				sortedwords[j] = "";
			}
		}
	}

	for (int i = 0; i < Num; i++){
		for (int j = i+1; j < Num+1; j++) {
			if (sortedwords[i].length() > sortedwords[j].length()) {
				swap(sortedwords[i], sortedwords[j]);
			}
		}
	}

	for (int i = 0; i < Num; i++) {
			if ((sortedwords[i] == " ") || (sortedwords[i] == "")) {
				i++;
			}
			if (sortedwords[i] != " ") {
				out << sortedwords[i] << endl;
			}
	}
}