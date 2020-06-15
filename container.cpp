#include <fstream>
#include "container.h"

using std::ifstream;
using std::ofstream;
using std::endl;

container* init_container() {
	container* container_with_shapes = new container();
	container_with_shapes -> size = 0;
	container_with_shapes -> first = nullptr;
	container_with_shapes -> last = nullptr;
	return container_with_shapes;
}

void add(container* container_with_shapes, Shape* shape) {
	item* new_shape = new item();
	new_shape -> shape = shape;
	new_shape -> next = nullptr;

	if (container_with_shapes -> size == 0) {
		container_with_shapes -> first = new_shape;
	}
	else if (container_with_shapes -> size == 1) {
		container_with_shapes -> first -> next = new_shape;
		container_with_shapes -> last = new_shape;
	}
	else {
		container_with_shapes -> last -> next = new_shape;
		container_with_shapes -> last = new_shape;
	}

	container_with_shapes -> size++;
}

bool read_container(container* container_with_shapes, string filename) {
	ifstream in(filename);

	if (! in.is_open()) {
		return false;
	}

	bool sort_shapes = false;
	int count_shapes;
	string row, filter_shapes;
	string type_shapes;
	float density;

	getline(in, row); // проверка на вводимое число
	if (check_int(row) != true){
		return false;
	}
	count_shapes = stoi(row);
	getline(in, row); 
	if (row == "Sort") {
		sort_shapes = true;
	} else if (row != "No sort") {
		return false;
	}
	
	getline(in, filter_shapes); 
	
	if (filter_shapes == "All" or filter_shapes == "Ball" or filter_shapes == "Parallelepiped" or filter_shapes == "Tetrahedron"){
		for (int i = 0; i < count_shapes; i++){
			Shape *shape = new Shape();
			if (read(shape, &in) != true){
				return false;
			}
			if (filter_shapes == "All" or filter_shapes == get_type_shape(shape)){
				add(container_with_shapes, shape);	
			}
		}
	} else{
		return false;
	}

	if (sort_shapes) {
		sort(container_with_shapes);
	}

	in.close();
	return true;
}

bool write_container(container* container_with_shapes, string filename) {
	ofstream out(filename);

	out << "Count shapes: " << container_with_shapes -> size << endl;

	if (!container_with_shapes -> size) {
		out.close();
		return true;
	}

	item* shape_item = container_with_shapes -> first;

	for (int i = 0; i < container_with_shapes -> size; i++) {
		write(shape_item -> shape, &out);
		shape_item = shape_item -> next;
	}

	out.close();
	return true;

}

void sort(container* container_with_shapes) {
	for (item* shape_item2 = container_with_shapes -> first; shape_item2; shape_item2 = shape_item2 -> next) {
		for (item* shape_item1 = container_with_shapes -> first; shape_item1 -> next; shape_item1 = shape_item1 -> next) {
			if (get_volume(shape_item1 -> shape) < get_volume(shape_item2 -> shape)) {
				std::iter_swap(&shape_item1 -> shape, &shape_item1 -> next -> shape);
			}
		}
	}
}





