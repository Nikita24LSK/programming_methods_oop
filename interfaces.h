#include <fstream>

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
		virtual double attitude() = 0;
		bool compare(Transport *other);
		virtual ~Transport() {};
	};

	class Truck: public Transport {
		unsigned int loadCapacity;
	public:
		void input_data(ifstream &inp);
		void output_data(ofstream &out);
		void out_truck(ofstream &out);
		double attitude();
		~Truck();
	};

	class Bus: public Transport {
		unsigned short passCapacity;
	public:
		void input_data(ifstream &inp);
		void output_data(ofstream &out);
		double attitude();
		~Bus();
	};

	class Car: public Transport {
		unsigned short maxSpeed;
	public:
		void input_data(ifstream &inp);
		void output_data(ofstream &out);
		void out_truck(ofstream &out);
		double attitude();
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


