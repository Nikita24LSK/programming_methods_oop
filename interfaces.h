#include <fstream>

using namespace std;

namespace machines {
	class Transport {

	public:
		unsigned int enginePower;
		static Transport *input(ifstream &inp);
		virtual void input_data(ifstream &inp) = 0;
		virtual void output_data(ofstream &out) = 0;
		virtual ~Transport() {};
	};

	class Truck: public Transport {
		unsigned int loadCapacity;
	public:
		void input_data(ifstream &inp);
		void output_data(ofstream &out);
		~Truck();
	};

	class Bus: public Transport {
		unsigned short passCapacity;
	public:
		void input_data(ifstream &inp);
		void output_data(ofstream &out);
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
		RingList();
		~RingList();
	};
}
