#include <iostream>
#include <fstream>
#include <cstdlib>
#include "interfaces.h"

using namespace std;

namespace machines {

	void Truck::multimethod(Transport *other, ofstream &out) {

		other->mm_truck(out);

	}

	void Truck::mm_truck(ofstream &out) {

		cout << "Truck and truck\n";

	}

	void Truck::mm_bus(ofstream &out) {

		cout << "Bus and truck\n";

	}

	void Truck::mm_car(ofstream &out) {

		cout << "Car and truck\n";

	}

	bool Truck::input_data(ifstream &inp) {

		char inp_str[255];
		int temp_int_val;
		double temp_double_val;

		if (!(inp >> inp_str)) {
			cout << "Error! Unexpected end of input!\n";
			return true;
		}
		temp_int_val = atoi(inp_str);
		if (!temp_int_val) {
			cout << "Error! Invalid input data: " << inp_str << endl;
			return true;
		}
		loadCapacity = temp_int_val;

		if (!(inp >> inp_str)) {
			cout << "Error! Unexpected end of input!\n";
			return true;
		}
		temp_int_val = atoi(inp_str);
		if (!temp_int_val) {
			cout << "Error! Invalid input data: " << inp_str << endl;
			return true;
		}
		enginePower = temp_int_val;

		if (!(inp >> inp_str)) {
			cout << "Error! Unexpected end of input!\n";
			return true;
		}
		temp_double_val = atof(inp_str);
		if (!temp_int_val) {
			cout << "Error! Invalid input data: " << inp_str << endl;
			return true;
		}
		consumption = temp_double_val;

		return false;

	}

	bool Truck::output_data(ofstream &out) {

		out << "Truck\tLoad Capacity: " << loadCapacity << "\tEngine Power: " << enginePower << "\tConsumption: " << consumption << "\tQuotient: " << quotient() << "\n";

		return out.fail();

	}

	double Truck::quotient() {

		return (double)loadCapacity / (double)enginePower;

	}

	bool Truck::out_truck(ofstream &out) {

		if (output_data(out)) {
			return true;
		}

		return false;

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

	void Bus::mm_car(ofstream &out) {

		out << "Car and bus\n";

	}

	bool Bus::input_data(ifstream &inp) {

		char inp_str[255];
		int temp_int_val;
		double temp_double_val;

		if (!(inp >> inp_str)) {
			cout << "Error! Unexpected end of input!\n";
			return true;
		}
		temp_int_val = atoi(inp_str);
		if (!temp_int_val) {
			cout << "Error! Invalid input data: " << inp_str << endl;
			return true;
		}
		passCapacity = temp_int_val;

		if (!(inp >> inp_str)) {
			cout << "Error! Unexpected end of input!\n";
			return true;
		}
		temp_int_val = atoi(inp_str);
		if (!temp_int_val) {
			cout << "Error! Invalid input data: " << inp_str << endl;
			return true;
		}
		enginePower = temp_int_val;

		if (!(inp >> inp_str)) {
			cout << "Error! Unexpected end of input!\n";
			return true;
		}
		temp_double_val = atof(inp_str);
		if (!temp_int_val) {
			cout << "Error! Invalid input data: " << inp_str << endl;
			return true;
		}
		consumption = temp_double_val;

		return false;

	}

	bool Bus::output_data(ofstream &out) {

		out << "Bus\tPassengers Capacity: " << passCapacity << "\tEngine Power: " << enginePower << "\tConsumption: " << consumption << "\tQuotient: " << quotient() << "\n";

		return out.fail();

	}

	double Bus::quotient() {

		return (double)(passCapacity * 75) / (double)enginePower;

	}

	void Car::multimethod(Transport *other, ofstream &out) {

		other->mm_car(out);

	}

	void Car::mm_car(ofstream &out) {

		out << "Car and car\n";

	}

	void Car::mm_truck(ofstream &out) {

		out << "Truck and car\n";

	}

	void Car::mm_bus(ofstream &out) {

		out << "Bus and car\n";

	}

	bool Car::input_data(ifstream &inp) {

		char inp_str[255];
		int temp_int_val;
		double temp_double_val;

		if (!(inp >> inp_str)) {
			cout << "Error! Unexpected end of input!\n";
			return true;
		}
		temp_int_val = atoi(inp_str);
		if (!temp_int_val) {
			cout << "Error! Invalid input data: " << inp_str << endl;
			return true;
		}
		passCapacity = temp_int_val;

		if (!(inp >> inp_str)) {
			cout << "Error! Unexpected end of input!\n";
			return true;
		}
		temp_int_val = atoi(inp_str);
		if (!temp_int_val) {
			cout << "Error! Invalid input data: " << inp_str << endl;
			return true;
		}
		enginePower = temp_int_val;

		if (!(inp >> inp_str)) {
			cout << "Error! Unexpected end of input!\n";
			return true;
		}
		temp_int_val = atoi(inp_str);
		if (!temp_int_val) {
			cout << "Error! Invalid input data: " << inp_str << endl;
			return true;
		}
		maxSpeed = temp_int_val;

		if (!(inp >> inp_str)) {
			cout << "Error! Unexpected end of input!\n";
			return true;
		}
		temp_double_val = atof(inp_str);
		if (!temp_int_val) {
			cout << "Error! Invalid input data: " << inp_str << endl;
			return true;
		}
		consumption = temp_double_val;

		return false;

	}

	bool Car::output_data(ofstream &out) {

		out << "Car\tPassengers Capacity: " << passCapacity << "\tEngine power: " << enginePower << "\tMax Speed" << maxSpeed << "\tConsumption: " << consumption << "\tQuotient: " << quotient() << "\n";

		return out.fail();

	}

	bool Car::out_truck(ofstream &out) {

		if (output_data(out)) {
			return true;
		}

		return false;

	}

	double Car::quotient() {

		return (double)(passCapacity * 75) / (double)enginePower;

	}

	bool Transport::out_truck(ofstream &out) {

		out << "";

		return out.fail();

	}

	Bus::~Bus() {}
	Truck::~Truck() {}
	Car::~Car() {}

	Transport *Transport::input(ifstream &inp) {

		Transport *trp;
		int key;
		if (!(inp >> key)) {
			return NULL;
		}

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
				cout << "Error! Invalid key: " << key;
				exit(1);
		}

		if (trp->input_data(inp)) {
			delete trp;
			exit(1);
		}

		return trp;

	}

	bool Transport::compare(Transport *other) {

		return quotient() < other->quotient();

	}

	NodeOfList::~NodeOfList() {

		tr->~Transport();

	}

	bool NodeOfList::fill(ifstream &inp) {

		tr = Transport::input(inp);

		if (tr == NULL) {
			return false;
		}
		else {
			return true;
		}

	}

	bool NodeOfList::out(ofstream &out) {

		if (tr->output_data(out)) {
			return true;
		}

		return false;

	}

	bool NodeOfList::out_truck(ofstream &out) {

		if (tr->out_truck(out)) {
			return true;
		}

		return false;

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

	bool RingList::out(ofstream &out) {

		NodeOfList *curNode;

		if (head == NULL) {
			cout << "Error output list: list is empty!\n";

			return true;
		}

		for (int i = 0; i < size; i++) {
			curNode = head;
			for (int j = 0; j < i; j++) {
				curNode = curNode->next;
			}
			if (curNode->out(out)) {
				cout << "Cannot to output tarnsport!\n";

				return true;
			}
		}

		out << "\nOutput without bus\n";

		for (int i = 0; i < size; i++) {
			curNode = head;
			for (int j = 0; j < i; j++) {
				curNode = curNode->next;
			}
			if (curNode->out_truck(out)) {
				cout << "Cannot to output transport!\n";

				return true;
			}
		}

		return false;

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

	void RingList::sort(int left, int right) {

		int i, last;

		if (right == -10) {
			right = size - 1;
		}

		if (left >= right) {
			return;
		}

		swap(left, (left+right)/2);
		last = left;
		for (i=left+1; i <= right; i++) {
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

		for (int i=0; i < index; i++) {
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

		for (int i=size-1; i > 0; i--) {
			curNode = head;
			for (int j=0; j < i; j++) {
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
