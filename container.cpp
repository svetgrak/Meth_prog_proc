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
	
	multimethod(container_with_shapes, &out);
	
	out.close();
	return true;
	
}

void multimethod(container *container_with_shapes, ofstream *out){
	
	*out << "Result multimethod: " << endl;
	if (!container_with_shapes->size){
		return;
	}
	
	for (item* shape_item_1 = container_with_shapes->first; shape_item_1->next; shape_item_1 = shape_item_1->next) {
		for (item* shape_item_2 = shape_item_1->next; shape_item_2; shape_item_2 = shape_item_2->next){
			switch (shape_item_1->shape->type_shape){
				case Shape::typeShape::BALL:
					switch (shape_item_2->shape->type_shape){
						case Shape::typeShape::BALL:
							*out << "BALL and BALL" << endl;
							break;
						case Shape::typeShape::PARALLELEPIPED:
							*out << "BALL and PARALLELEPIPED" << endl;
							break;
						default:
							*out << "BALL and unknown type" << endl;
							break;
					}
					break;
				case Shape::typeShape::PARALLELEPIPED:
					switch (shape_item_2->shape->type_shape){
						case Shape::typeShape::BALL:
							*out << "PARALLELEPIPED and BALL" << endl;
							break;
						case Shape::typeShape::PARALLELEPIPED:
							*out << "PARALLELEPIPED and PARALLELEPIPED" << endl;
							break;
						default:
							*out << "PARALLELEPIPED and unknown type" << endl;
							break;
					}
					break;
				default:
					*out << "unknown types" << endl;
					break;
			}
		}	
	}
	
} 


