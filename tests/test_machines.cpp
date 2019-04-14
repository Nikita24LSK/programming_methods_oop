#include <iostream>
#include <fstream>
#include "gtest/gtest.h"
#include "interfaces.h"

using namespace std;
using namespace machines;

TEST (test, machines) {

	ifstream inp("/home/dragon/prog/c/oopTests/input_files/machines");
	ofstream out("/home/dragon/prog/c/oopTests/output_files/machines");

	ASSERT_TRUE(inp.is_open());
	ASSERT_TRUE(out.is_open());

	Truck testTruck;
	Bus testBus;
	Car testCar;

	ASSERT_FALSE(testTruck.input_data(inp));
	ASSERT_FALSE(testBus.input_data(inp));
	ASSERT_FALSE(testCar.input_data(inp));

	ASSERT_TRUE(testTruck.compare(&testBus));
	ASSERT_TRUE(testTruck.compare(&testCar));

	EXPECT_EQ(3.0, testTruck.quotient());
	EXPECT_EQ(225.0, testBus.quotient());
	EXPECT_EQ(37.5, testCar.quotient());

	ASSERT_FALSE(testTruck.output_data(out));
	ASSERT_FALSE(testTruck.out_truck(out));
	ASSERT_FALSE(testBus.output_data(out));
	ASSERT_FALSE(testBus.out_truck(out));
	ASSERT_FALSE(testCar.output_data(out));
	ASSERT_FALSE(testCar.out_truck(out));

}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}