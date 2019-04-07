#include <fstream>

/*

	Файл с описанием классов, используемых в программе.

	Имеется три типа транспорта - грузовик, автобус и автомобиль.
	В качестве контейнера используется циклический двусвязный список.

*/

using namespace std;

namespace machines {

	class Transport {
	public:
		double consumption;
		unsigned int enginePower;
		unsigned short passCapacity;
		static Transport *input(ifstream &inp);
		virtual void input_data(ifstream &inp) = 0;
		virtual void output_data(ofstream &out) = 0;
		virtual void out_truck(ofstream &out);
		virtual double quotient() = 0;
		bool compare(Transport *other);
		virtual ~Transport() {};
	};

	class Truck: public Transport {
		unsigned int loadCapacity;
	public:
		void input_data(ifstream &inp);
		void output_data(ofstream &out);
		void out_truck(ofstream &out);
		double quotient();
		~Truck();
	};

	class Bus: public Transport {
		unsigned short passCapacity;
	public:
		void input_data(ifstream &inp);
		void output_data(ofstream &out);
		double quotient();
		~Bus();
	};

	class Car: public Transport {
		unsigned short maxSpeed;
	public:
		void input_data(ifstream &inp);
		void output_data(ofstream &out);
		void out_truck(ofstream &out);
		double quotient();
		~Car();
	};

	class NodeOfList {
	public:
		Transport *tr;
		NodeOfList *next;
		NodeOfList *prev;

		~NodeOfList();
		char fill(ifstream &inp);
		void out(ofstream &out);
		void out_truck(ofstream &out);
	};

	class RingList {
		int size;
		NodeOfList *head;
	public:
		void fill(ifstream &inp);
		void out(ofstream &out);
		void clear();
		void swap(int first, int second);
		NodeOfList *get_node(int index);
		void sort(int left=0, int right=-10);
		RingList();
		~RingList();
	};
}
