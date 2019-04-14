#include <iostream>
#include <fstream>
#include <cstdlib>
#include "interfaces.h"

using namespace std;
using namespace machines;

int main(int argc, char *argv[]) {

	if (argc != 3) {
		cout << "Usage: lab_oop <input file> <output file>" << endl;

		return 1;
	}

	ifstream inp(argv[1]);
	ofstream out(argv[2]);

	if (!inp.is_open()) {
		cout << "Could not to open input file!\n";

		exit(1);
	}

	if (!out.is_open()) {
		cout << "Could not to open output file!\n";
		
		exit(1);
	}

	cout << "Start.\n";

	// Инициализируем экземпляр класса контейнера
	RingList container;

	// Считываем данные из входного файла
	cout << "Reading input\n";
	container.fill(inp);

	// Записываем данные в выходной файл
	cout << "Writing information\n";
	container.out(out);

	// Попытка заполнить непустой контейнер
	container.fill(inp);

	// Сортируем контейнер
	cout << "Sorting list\n";
	container.sort();

	// Записываем отсортированные данные в выходной файл
	out << "\nSorting data\n";
	container.out(out);

	// Вызываем мультиметод контейнера
	container.multimethod(out);

	// Очищаем контейнер
	cout << "Clearing list\n";
	container.clear();
	container.out(out);

	return 0;

}