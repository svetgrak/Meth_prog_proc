#include <fstream>
#include <string>
#include "shape.h"
#include <math.h>
using std::endl;


bool check_int(string row){
	try{
    	int i;
    	i = stoi(row);
  	}catch(...){
    	return false;
  	}
  	return true;
}

bool check_float(string row){
	try{
    	float i;
    	i = stof(row);
  	}catch(...){
    	return false;
  	}
  	return true;
}

string get_type_shape(Shape *shape){
	switch (shape -> type_shape) {
        case Shape::BALL:
            return "Ball";
        case Shape::PARALLELEPIPED:
            return "Parallelepiped";
        case Shape::TETRAHEDRON:
        	return "Tetrahedron";
        default:
            return "";
    }
}

float get_volume(Shape* shape) {

	switch (shape -> type_shape) {
		case Shape::BALL:
			return 3.14 * 4 * pow(shape -> ball.radius, 3) / 3  ;
		case Shape::PARALLELEPIPED:
			return shape -> parallelepiped.edge1 * shape -> parallelepiped.edge2 * shape -> parallelepiped.edge3;
		case Shape::TETRAHEDRON:
			return pow(2, 0.5) / 12 * pow(shape -> tetrahedron.len_side, 3);
	}
}

bool read(Shape *shape, ifstream *in){
	string row, type_shape, densit, melt_point;
	getline(*in, row);             
    getline(*in, type_shape); 
	getline(*in, densit);
	getline(*in, melt_point); 
	
	if (check_float(densit) != true){
		return false;
	}
	
	if (check_int(melt_point) != true){
		return false;
	}
	
	shape -> density = stof(densit);  
	shape -> melting_point = stoi(melt_point);

    if (type_shape == "Ball"){
    	shape -> type_shape = Shape::BALL;
    	read(&shape -> ball, in);    	
	} else if (type_shape == "Parallelepiped"){
		shape -> type_shape = Shape::PARALLELEPIPED;
		read(&shape -> parallelepiped, in);  
	} else if (type_shape == "Tetrahedron"){
		shape -> type_shape = Shape::TETRAHEDRON;
		read(&shape -> tetrahedron, in);
	} else{
		return false;
	}
	return true; 
}

bool read(Shape::Ball *ball, ifstream *in){
	string rad;
	getline(*in, rad); 
	if (check_int(rad) != true){
		return false;
	}
	ball -> radius = stoi(rad);
	return true;
} 

bool read(Shape::Parallelepiped *parallelepiped, ifstream *in) {
	string edg1,edg2,edg3;
	getline(*in, edg1); 
	getline(*in, edg2); 
	getline(*in, edg3); 
	
	if (check_float(edg1) != true and check_float(edg2) != true and check_float(edg3) != true){
		return false;
	}
	
	parallelepiped -> edge1 = stoi(edg1);
	parallelepiped -> edge2 = stoi(edg2);
	parallelepiped -> edge3 = stoi(edg3);
	return true; 
} 

bool read(Shape::Tetrahedron *tetrahedron, ifstream *in) {
	string len_s;
	getline(*in, len_s); 
	if (check_int(len_s) != true){
		return false;
	}
	tetrahedron -> len_side = stoi(len_s);
	return true; 
}


void write(Shape *shape, ofstream *out){
	string type_shape;

    *out << endl; 
    *out << "Shape: " << get_type_shape(shape) << endl;
    *out << "Density: " << shape -> density << endl;
    *out << "Volume: " << get_volume(shape) << endl;
    *out << "Melting point: " << shape -> melting_point << endl;
    
    switch (shape -> type_shape){
        case Shape::BALL:
            write(&shape -> ball, out);
            break;
        case Shape::PARALLELEPIPED:
            write(&shape -> parallelepiped, out);
            break;
        case Shape::TETRAHEDRON:
        	write(&shape -> tetrahedron, out);
        	break;
    }
    
}

void write(Shape::Ball *ball, ofstream *out) {
    *out << "Radius: " << ball -> radius << endl;
}

void write(Shape::Parallelepiped *parallelepiped, ofstream *out) {
    *out << "Edge 1: " << parallelepiped -> edge1 << endl;
    *out << "Edge 2: " << parallelepiped -> edge2 << endl;
    *out << "Edge 3: " << parallelepiped -> edge3 << endl;
}

void write(Shape::Tetrahedron *tetrahedron, ofstream *out) {
	*out << "Len side: " << tetrahedron->len_side << endl;
}


