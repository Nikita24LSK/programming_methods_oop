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

	void Car::input_data(ifstream &inp) {
		inp >> passCapacity >> enginePower >> maxSpeed;
	}

	void Car::output_data(ofstream &out) {
		out << "Car\tPassengers Capacity: " << passCapacity << "\tEngine power: " << enginePower << "\tMax Speed" << maxSpeed << "\tAttitude: " << attitude() << "\n";
	}

	double Car::attitude() {
		return (double)(passCapacity*75)/(double)enginePower;
	}

	Bus::~Bus() {}
	Truck::~Truck() {}
	Car::~Car() {}

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
			case 3:
				trp = new Car;
				break;
			default:
				return NULL;
		}

		trp->input_data(inp);
		return trp;
	}

	bool Transport::compare(Transport *other) {
		return attitude() < other->attitude();
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

	void RingList::sort(int left, int right) {

		int i, last;

		if (right == -10) {
			right = size-1;
		}

		if (left >= right) {
			return;
		}

		swap(left, (left+right)/2);
		last = left;
		for (i = left+1; i <= right; i++) {
			if (get_node(i)->tr->compare(get_node(left)->tr)) {
				swap(++last, i);
			}
		}
		swap(left, last);
		sort(left, last-1);
		sort(last+1, right);
		
	}

	NodeOfList *RingList::get_node(int index) {

		NodeOfList *retNode = head;

		for (int i = 0; i < index; i++) {
			retNode = retNode->next;
		}

		return retNode;

	}

	void RingList::swap(int first, int second) {
		NodeOfList *temp = new NodeOfList;

		temp->tr = get_node(first)->tr;
		get_node(first)->tr = get_node(second)->tr;
		get_node(second)->tr = temp->tr;
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
