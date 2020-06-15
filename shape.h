#include <string>

using std::string;
using std::ifstream;
using std::ofstream;

struct Shape {
	
	enum type{BALL, PARALLELEPIPED, TETRAHEDRON};
	Shape() = default;
	type type_shape;
	float density; 
	float volume; 
	int melting_point;
	
	struct Ball{
		int radius;
	} ball;

	struct Parallelepiped{
		int edge1;
		int edge2;
		int edge3;
	} parallelepiped;
	 
	struct Tetrahedron{
		int len_side;
	} tetrahedron;
	
};

string get_type_shape(Shape *shape);
float get_volume(Shape *shape);
bool read(Shape *shape, ifstream *in);
bool read(Shape::Ball *ball, ifstream *in);
bool read(Shape::Parallelepiped *parallelepiped, ifstream *in);
bool read(Shape::Tetrahedron *tetrahedron, ifstream *in);
void write(Shape *shape, ofstream *out);
void write(Shape::Ball *ball, ofstream *out);
void write(Shape::Parallelepiped *parallelepiped, ofstream *out);
void write(Shape::Tetrahedron *tetrahedron, ofstream *out);
bool check_int(string row);
bool check_float(string row);


