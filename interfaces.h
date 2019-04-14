#include <fstream>

using namespace std;

namespace machines {
	class Transport {

	public:
		static Transport *input(ifstream &inp);
		virtual void input_data(ifstream &inp) = 0;
		virtual void output_data(ofstream &out) = 0;
		virtual void multimethod(Transport *other, ofstream &out) = 0;
		virtual void mm_truck(ofstream &out) = 0;
		virtual void mm_bus(ofstream &out) = 0;
		virtual ~Transport() {};
	};

	class Truck: public Transport {
		int loadCapacity, enginePower;
	public:
		void input_data(ifstream &inp);
		void output_data(ofstream &out);
		virtual void multimethod(Transport *other, ofstream &out);
		virtual void mm_truck(ofstream &out);
		virtual void mm_bus(ofstream &out);
		~Truck();
	};

	class Bus: public Transport {
		short passCapacity;
		int enginePower;
	public:
		void input_data(ifstream &inp);
		void output_data(ofstream &out);
		virtual void multimethod(Transport *other, ofstream &out);
		virtual void mm_truck(ofstream &out);
		virtual void mm_bus(ofstream &out);
		~Bus();
	};

	class NodeOfList {

	public:
		Transport *tr;
		NodeOfList *next;
		NodeOfList *prev;

		~NodeOfList();
		char fill(ifstream &inp);
		void out(ofstream &out);
	};

	class RingList {
		int size;
		NodeOfList *head;
	public:
		void fill(ifstream &inp);
		void out(ofstream &out);
		void clear();
		void multimethod(ofstream &out);
		NodeOfList *get_node(int);
		RingList();
		~RingList();
	};
}


