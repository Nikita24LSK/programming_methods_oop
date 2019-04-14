#include <iostream>
#include <fstream>
#include "gtest/gtest.h"
#include "interfaces.h"

using namespace std;
using namespace machines;

TEST (test, node) {

	ifstream inp("/home/dragon/prog/c/oopTests/input_files/node");
	ofstream out("/home/dragon/prog/c/oopTests/output_files/node");

	ASSERT_TRUE(inp.is_open());
	ASSERT_TRUE(out.is_open());

	NodeOfList testNode;

	ASSERT_TRUE(testNode.fill(inp));
	ASSERT_EQ(3, testNode.tr->enginePower);
	ASSERT_EQ(4.4, testNode.tr->consumption);
	ASSERT_FALSE(testNode.out(out));
	ASSERT_FALSE(testNode.out_truck(out));

	ASSERT_TRUE(testNode.fill(inp));
	ASSERT_EQ(33, testNode.tr->enginePower);
	ASSERT_EQ(15.8, testNode.tr->consumption);
	ASSERT_FALSE(testNode.out(out));
	ASSERT_FALSE(testNode.out_truck(out));

	ASSERT_TRUE(testNode.fill(inp));
	ASSERT_EQ(22, testNode.tr->enginePower);
	ASSERT_EQ(6.6, testNode.tr->consumption);
	ASSERT_FALSE(testNode.out(out));
	ASSERT_FALSE(testNode.out_truck(out));

	ASSERT_TRUE(testNode.fill(inp));
	ASSERT_EQ(14, testNode.tr->enginePower);
	ASSERT_EQ(77.9, testNode.tr->consumption);
	ASSERT_FALSE(testNode.out(out));
	ASSERT_FALSE(testNode.out_truck(out));

}

int main(int argc, char **argv) {

	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
	
}