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
		virtual bool input_data(ifstream &inp) = 0;
		virtual bool output_data(ofstream &out) = 0;
		virtual bool out_truck(ofstream &out);
		virtual void multimethod(Transport *other, ofstream &out) = 0;
		virtual void mm_truck(ofstream &out) = 0;
		virtual void mm_bus(ofstream &out) = 0;
		virtual void mm_car(ofstream &out) = 0;
		virtual double quotient() = 0;
		bool compare(Transport *other);
		virtual ~Transport() {};
	};

	class Truck: public Transport {
		unsigned int loadCapacity;
	public:
		bool input_data(ifstream &inp);
		bool output_data(ofstream &out);
		bool out_truck(ofstream &out);
		void multimethod(Transport *other, ofstream &out);
		void mm_truck(ofstream &out);
		void mm_bus(ofstream &out);
		void mm_car(ofstream &out);
		double quotient();
		~Truck();
	};

	class Bus: public Transport {
		unsigned short passCapacity;
	public:
		bool input_data(ifstream &inp);
		bool output_data(ofstream &out);
		void multimethod(Transport *other, ofstream &out);
		void mm_truck(ofstream &out);
		void mm_bus(ofstream &out);
		void mm_car(ofstream &out);
		double quotient();
		~Bus();
	};

	class Car: public Transport {
		unsigned short maxSpeed;
	public:
		bool input_data(ifstream &inp);
		bool output_data(ofstream &out);
		bool out_truck(ofstream &out);
		void multimethod(Transport *other, ofstream &out);
		void mm_truck(ofstream &out);
		void mm_bus(ofstream &out);
		void mm_car(ofstream &out);
		double quotient();
		~Car();
	};

	class NodeOfList {
	public:
		Transport *tr;
		NodeOfList *next;
		NodeOfList *prev;

		~NodeOfList();
		bool fill(ifstream &inp);
		bool out(ofstream &out);
		bool out_truck(ofstream &out);
	};

	class RingList {
	public:
		int size;
		NodeOfList *head;
		void fill(ifstream &inp);
		bool out(ofstream &out);
		void clear();
		void swap(int first, int second);
		NodeOfList *get_node(int index);
		void sort(int left=0, int right=-10);
		void multimethod(ofstream &out);
		RingList();
		~RingList();
	};
}
