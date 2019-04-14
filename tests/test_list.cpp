#include <iostream>
#include <fstream>
#include "gtest/gtest.h"
#include "interfaces.h"

using namespace std;
using namespace machines;

TEST (test, list) {

	ifstream inp("/home/dragon/prog/c/oopTests/input_files/list");
	ofstream out("/home/dragon/prog/c/oopTests/output_files/list");

	ASSERT_TRUE(inp.is_open());
	ASSERT_TRUE(out.is_open());

	RingList container;
	NodeOfList *inspNode;

	ASSERT_TRUE(container.out(out));

	container.fill(inp);
	inspNode = container.head;

	ASSERT_EQ(3, inspNode->tr->enginePower);
	ASSERT_EQ(4.4, inspNode->tr->consumption);
	inspNode = inspNode->next;

	ASSERT_EQ(11, inspNode->tr->enginePower);
	ASSERT_EQ(6.8, inspNode->tr->consumption);
	inspNode = inspNode->next;

	ASSERT_EQ(2, inspNode->tr->enginePower);
	ASSERT_EQ(7.7, inspNode->tr->consumption);

	inspNode = container.get_node(1);
	ASSERT_EQ(11, inspNode->tr->enginePower);
	ASSERT_EQ(6.8, inspNode->tr->consumption);

	container.swap(0, 2);
	inspNode = container.get_node(0);
	ASSERT_EQ(2, inspNode->tr->enginePower);
	ASSERT_EQ(7.7, inspNode->tr->consumption);

	inspNode = container.get_node(2);
	ASSERT_EQ(3, inspNode->tr->enginePower);
	ASSERT_EQ(4.4, inspNode->tr->consumption);

	container.sort();
	inspNode = container.get_node(0);
	ASSERT_EQ(3, inspNode->tr->enginePower);
	ASSERT_EQ(4.4, inspNode->tr->consumption);

	inspNode = container.get_node(2);
	ASSERT_EQ(11, inspNode->tr->enginePower);
	ASSERT_EQ(6.8, inspNode->tr->consumption);

	ASSERT_FALSE(container.out(out));

	container.clear();
	ASSERT_EQ(NULL, container.head);
	ASSERT_EQ(0, container.size);

}

int main(int argc, char **argv) {

	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
	
}