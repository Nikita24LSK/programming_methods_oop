#include <iostream>
#include <fstream>
#include "interfaces.h"

using namespace std;

namespace machines {
	void Truck::input_data(ifstream &inp) {
		inp >> loadCapacity >> enginePower;
	}

	void Truck::output_data(ofstream &out) {
		out << "Truck\tLoad Capacity: " << loadCapacity << "\tEngine Power: " << enginePower << "\tAttitude: " << attitude() << "\n";
	}

	double Truck::attitude() {
		return (double)loadCapacity/(double)enginePower;
	}

	void Bus::input_data(ifstream &inp) {
		inp >> passCapacity >> enginePower;
	}

	void Bus::output_data(ofstream &out) {
		out << "Bus\tPassengers Capacity: " << passCapacity << "\tEngine Power: " << enginePower << "\tAttitude: " << attitude() << "\n";
	}

	double Bus::attitude() {
		return (double)(passCapacity*75)/(double)enginePower;
	}

	Bus::~Bus() {}
	Truck::~Truck() {}

	Transport *Transport::input(ifstream &inp) {
		Transport *trp;
		int key;
		inp >> key;

		switch (key) {
			case 1:
				trp = new Truck;
				break;
			case 2:
				trp = new Bus;
				break;
			default:
				return NULL;
		}

		trp->input_data(inp);
		return trp;
	}

	NodeOfList::~NodeOfList() {
		tr->~Transport();
	}

	char NodeOfList::fill(ifstream &inp) {
		tr = Transport::input(inp);
		if (tr == NULL) {
			return 0;
		}
		else
			return 1;
	}

	void NodeOfList::out(ofstream &out) {
		tr->output_data(out);
	}

	RingList::RingList() {
		size = 0;
		head = NULL;
	}

	void RingList::fill(ifstream &inp) {
		if (head != NULL) {
			cout << "Error - fill list: list is not empty!\n";
			return;
		}
		NodeOfList *curNode;
		NodeOfList *tmpNode = new NodeOfList;

		if (tmpNode->fill(inp)) {
			head = tmpNode;
			tmpNode->next = tmpNode;
			tmpNode->prev = tmpNode;

			size++;
			tmpNode = NULL;
			tmpNode = new NodeOfList;
		}
		else {
			return;
		}

		while(tmpNode->fill(inp)) {
			tmpNode->prev = head->prev;
			head->prev->next = tmpNode;
			head->prev = tmpNode;
			tmpNode->next = head;

			size++;
			tmpNode = NULL;
			tmpNode = new NodeOfList;
		}

	}

	void RingList::out(ofstream &out) {
		NodeOfList *curNode;

		if (head == NULL) {
			cout << "Error output list: list is empty!\n";
			return;
		}

		for (int i = 0; i < size; i++) {
			curNode = head;
			for (int j = 0; j < i; j++) {
				curNode = curNode->next;
			}
			curNode->out(out);
		}

	}

	void RingList::clear() {
		NodeOfList *curNode;

		for (int i = size-1; i > 0; i--) {
			curNode = head;
			for (int j = 0; j < i; j++) {
				curNode = curNode->next;
			}
			curNode->~NodeOfList();
		}

		size = 0;
		head = NULL;
	}

	RingList::~RingList() {
		clear();
	}
}


