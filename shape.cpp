#include <fstream>
#include "shape.h"

using std::endl;

string get_type_shape(Shape *shape){
	switch (shape->type_shape) {
        case Shape::BALL:
            return "ball";
        case Shape::PARALLELEPIPED:
            return "parallelepiped";
        case Shape::TETRAHEDRON:
        	return "tetrahedron";
        default:
            return "";
    }
}

void read(Shape *shape, ifstream *in){
	string row, type_shape, densit, melt_point;
	getline(*in, row);              
    getline(*in, type_shape);   
	getline(*in, densit);
	getline(*in, melt_point);
	shape->density = stof(densit);  
	shape->melting_point = stoi(melt_point);
    
    if (type_shape == "ball"){
    	shape -> type_shape = Shape::BALL;
    	read(&shape->_ball, in);    	
	} else if (type_shape == "parallelepiped"){
		shape -> type_shape = Shape::PARALLELEPIPED;
		read(&shape->_parallelepiped, in);  
	} else if (type_shape == "tetrahedron"){
		shape -> type_shape = Shape::TETRAHEDRON;
		read(&shape->_tetrahedron,in);
	}
}

void read(Shape::ball *_ball, ifstream *in){
	string rad;
	getline(*in, rad); 
	_ball->radius = stoi(rad);
} 

void read(Shape::parallelepiped *_parallelepiped, ifstream *in) {
	string edg1,edg2,edg3;
	getline(*in, edg1);
	getline(*in, edg2);
	getline(*in, edg3); 
	_parallelepiped->edge1 = stoi(edg1);
	_parallelepiped->edge2 = stoi(edg2);
	_parallelepiped->edge3 = stoi(edg3);
} 

void read(Shape::tetrahedron *_tetrahedron, ifstream *in) {
	string len_s;
	getline(*in, len_s);
	_tetrahedron->len_side = stoi(len_s);
}


void write(Shape *shape, ofstream *out){
	string type_shape;

    *out << endl; 
    *out << "Shape: " << get_type_shape(shape) << endl;
    *out << "Density: " << shape->density << endl;
    *out << "Melting point: " <<shape->melting_point << endl;
    
    switch (shape->type_shape) {
        case Shape::BALL:
            write(&shape->_ball, out);
            break;
        case Shape::PARALLELEPIPED:
            write(&shape->_parallelepiped, out);
            break;
        case Shape::TETRAHEDRON:
        	write(&shape->_tetrahedron, out);
        	break;
    }
}

void write(Shape::ball *_ball, ofstream *out) {
    *out << "Radius: " << _ball->radius<< endl;
}

void write(Shape::parallelepiped *_parallelepiped, ofstream *out) {
    *out << "Edge 1: " << _parallelepiped->edge1 << endl;
    *out << "Edge 2: " << _parallelepiped->edge2 << endl;
    *out << "Edge 3: " << _parallelepiped->edge3 << endl;
}

void write(Shape::tetrahedron *_tetrahedron, ofstream *out) {
	*out << "Len side: " << _tetrahedron->len_side << endl;
}

