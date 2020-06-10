#include <fstream>
#include "container.h"

using std::ifstream;
using std::ofstream;
using std::endl;

container* init_container(){
	container *container_with_shapes = new container();
	container_with_shapes->size = 0;
	container_with_shapes->first = nullptr;
	container_with_shapes->last = nullptr;
	return container_with_shapes;
}

void add(container *container_with_shapes, Shape *shape){
	item *new_shape= new item();
	new_shape->shape = shape;
	new_shape->next = nullptr;
	
	if (container_with_shapes->size == 0){
		container_with_shapes->first = new_shape;
	} else if (container_with_shapes->size == 1){
		container_with_shapes->first->next = new_shape;
		container_with_shapes->last = new_shape;
	} else {
		container_with_shapes->last->next = new_shape;
		container_with_shapes->last = new_shape;
	}
	
	container_with_shapes->size++;
}

bool read_container(container *container_with_shapes, string filename){
	ifstream in(filename);
	
	if (!in.is_open()){
		return false;
	}
	
	int count_shapes;
	string row;
	string type_shapes;
	float density; 
	
	getline(in, row);
	count_shapes = stoi(row);
	
	for (int i = 0; i < count_shapes; i++){
		Shape *shape = new Shape();
		read(shape, &in);
		add(container_with_shapes,shape);
	}
	in.close();
	return true;
}

bool write_container(container *container_with_shapes, string filename){
	ofstream out(filename);
	
	out << "Count shapes: " << container_with_shapes->size << endl;
	
	if (!container_with_shapes->size){
		out.close();
		return true;
	}
	
	item *shape_item = container_with_shapes->first;
	
	for (int i = 0; i < container_with_shapes->size; i++){
		write(shape_item->shape, &out);
		shape_item = shape_item->next;
	}
	
	out.close();
	return true;
	
}




