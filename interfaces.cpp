#include <iostream>
#include <fstream>
#include <cstdlib>
#include "interfaces.h"

using namespace std;

namespace machines {

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

	void Truck::output_data(ofstream &out) {

		out << "Truck\tLoad Capacity: " << loadCapacity << "\tEngine Power: " << enginePower << "\tConsumption: " << consumption << "\tQuotient: " << quotient() << "\n";

	}

	double Truck::quotient() {

		return (double)loadCapacity / (double)enginePower;

	}

	void Truck::out_truck(ofstream &out) {

		output_data(out);

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

	void Bus::output_data(ofstream &out) {

		out << "Bus\tPassengers Capacity: " << passCapacity << "\tEngine Power: " << enginePower << "\tConsumption: " << consumption << "\tQuotient: " << quotient() << "\n";

	}

	double Bus::quotient() {

		return (double)(passCapacity * 75) / (double)enginePower;

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

	void Car::output_data(ofstream &out) {

		out << "Car\tPassengers Capacity: " << passCapacity << "\tEngine power: " << enginePower << "\tMax Speed" << maxSpeed << "\tConsumption: " << consumption << "\tQuotient: " << quotient() << "\n";

	}

	void Car::out_truck(ofstream &out) {

		output_data(out);

	}

	double Car::quotient() {

		return (double)(passCapacity * 75) / (double)enginePower;

	}

	void Transport::out_truck(ofstream &out) {

		out << "";

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

	char NodeOfList::fill(ifstream &inp) {

		tr = Transport::input(inp);

		if (tr == NULL) {
			return 0;
		}
		else {
			return 1;
		}

	}

	void NodeOfList::out(ofstream &out) {

		tr->output_data(out);

	}

	void NodeOfList::out_truck(ofstream &out) {

		tr->out_truck(out);

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

		out << "\nOutput without bus\n";

		for (int i = 0; i < size; i++) {
			curNode = head;
			for (int j = 0; j < i; j++) {
				curNode = curNode->next;
			}
			curNode->out_truck(out);
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
