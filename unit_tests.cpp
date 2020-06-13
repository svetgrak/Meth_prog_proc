#include <iostream>
#include <sstream>
#include <fstream>
#include "unit_tests.h"

using namespace std;

void run_tests(){
	test_size_after_add();
	test_link_in_container();
	test_read_write();
	test_sort();
	test_filter();
	test_calculated_volume();
}

void test_size_after_add(){
	container *container_with_shapes = init_container();
	Shape *shape = new Shape();
	assert(container_with_shapes->size == 0);
	add(container_with_shapes,shape);
	assert(container_with_shapes->size == 1);
	add(container_with_shapes,shape);
	assert(container_with_shapes->size == 2);
	add(container_with_shapes,shape);
	
	cout << "Success final - test size after add"<<endl;
}

void test_link_in_container(){
	container *container_with_shapes = init_container();
	Shape *shape1 = new Shape();
	Shape *shape2 = new Shape();
	Shape *shape3 = new Shape();
	
	add(container_with_shapes, shape1);
	assert(shape1 == container_with_shapes->first->shape);
	add(container_with_shapes, shape2);
	assert(shape2 == container_with_shapes->first->next->shape);
	assert(shape2 == container_with_shapes->last->shape);
	add(container_with_shapes,shape3);
	assert(shape3 == container_with_shapes->first->next->next->shape);
	assert(shape3 == container_with_shapes->last->shape);
	assert(container_with_shapes->last->next == nullptr);
	
	cout << "Success final - test link in container" << endl;
}

void test_read_write(){
	string input = "files_for_unit_tests/for_test_read_write_in.txt";
	string output = "files_for_unit_tests/for_test_read_write_out.txt";

	string correct = "Count shapes: 2\n"
					"\n"
					"Shape: ball\n"
					"Density: 3.123\n"
					"Volume: 267.947\n"
					"Melting point: 90\n"
					"Radius: 4\n"
					"\n"
					"Shape: ball\n"
					"Density: 1.14\n"
					"Volume: 33.4933\n"
					"Melting point: 90\n"
					"Radius: 2\n";

	container *container_with_shapes = init_container();
	read_container(container_with_shapes,input);
	write_container(container_with_shapes,output);
	
	ifstream in_file(output);
	stringstream buff;
	buff << in_file.rdbuf();
	string result_in_file = buff.str();
	
	assert(result_in_file == correct);
	cout << "Success final - test write read" << endl;
}

void test_sort(){
	string input = "files_for_unit_tests/for_test_sort_in.txt";
	string output = "files_for_unit_tests/for_test_sort_out.txt";

	string correct = "Count shapes: 2\n"
					"\n"
					"Shape: ball\n"
					"Density: 3.123\n"
					"Volume: 267.947\n"
					"Melting point: 90\n"
					"Radius: 4\n"
					"\n"
					"Shape: ball\n"
					"Density: 1.14\n"
					"Volume: 33.4933\n"
					"Melting point: 90\n"
					"Radius: 2\n";
					
	container *container_with_shapes = init_container();
	read_container(container_with_shapes,input);
	write_container(container_with_shapes,output);
	
	ifstream in_file(output);
	stringstream buff;
	buff << in_file.rdbuf();
	string result_in_file = buff.str();
	
	assert(result_in_file == correct);
	cout << "Success final - test sort" << endl;
}

void test_filter(){
	string input = "files_for_unit_tests/for_test_filter_in.txt";
	string output = "files_for_unit_tests/for_test_filter_out.txt";

	string correct = "Count shapes: 2\n"
					"\n"
					"Shape: ball\n"
					"Density: 3.123\n"
					"Volume: 267.947\n"
					"Melting point: 90\n"
					"Radius: 4\n"
					"\n"
					"Shape: ball\n"
					"Density: 1.14\n"
					"Volume: 33.4933\n"
					"Melting point: 90\n"
					"Radius: 2\n";
					
	container *container_with_shapes = init_container();
	read_container(container_with_shapes,input);
	write_container(container_with_shapes,output);
	
	ifstream in_file(output);
	stringstream buff;
	buff << in_file.rdbuf();
	string result_in_file = buff.str();
	
	assert(result_in_file == correct);
	cout << "Success final - test filter" << endl;
	
}

void test_calculated_volume(){
	string input = "files_for_unit_tests/for_test_calculated_volume.txt";
	
	container *container_with_shapes = init_container();
	
	read_container(container_with_shapes, input);
	assert(get_volume(container_with_shapes->first->shape)== 140);
	assert(get_volume(container_with_shapes->last->shape) == 6);
	
	cout << "Success final - test calculated volume" << endl;
}

