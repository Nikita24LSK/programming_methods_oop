#include <iostream>
#include <fstream>
#include "interfaces.h"

using namespace std;

namespace machines {

	void Truck::multimethod(Transport *other, ofstream &out) {
		other->mm_truck(out);
	}

	void Truck::mm_truck(ofstream &out) {
		out << "Truck and truck\n";
	}

	void Truck::mm_bus(ofstream &out) {
		out << "Bus and truck\n";
	}

	void Truck::input_data(ifstream &inp) {
		inp >> loadCapacity >> enginePower;
	}

	void Truck::output_data(ofstream &out) {
		out << "Truck\tLoad Capacity: " << loadCapacity << "\tEngine Power: " << enginePower << "\n";
	}

	void Bus::multimethod(Transport *other, ofstream &out) {
		other->mm_bus(out);
	}

	void Bus::mm_bus(ofstream &out) {
		out << "Bus and bus\n";
	}

	void Bus::mm_truck(ofstream &out) {
		out << "Truck and bus\n";
	}

	void Bus::input_data(ifstream &inp) {
		inp >> passCapacity >> enginePower;
	}

	void Bus::output_data(ofstream &out) {
		out << "Bus\tPassengers Capacity: " << passCapacity << "\tEngine Power: " << enginePower << "\n";
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

	NodeOfList *RingList::get_node(int index) {

		NodeOfList *retNode = head;

		for (int i=0; i < index; i++) {
			retNode = retNode->next;
		}

		return retNode;

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

	void RingList::multimethod(ofstream &out) {

		out << "Multimethod\n";

		for (int i=0; i < size-1; i++) {
			for (int j=i+1; j < size; j++) {
				get_node(i)->tr->multimethod(get_node(j)->tr, out);
				get_node(i)->out(out);
				get_node(j)->out(out);
			}
		}

	}

	RingList::~RingList() {
		clear();
	}
}


