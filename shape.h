#include <string>

using std::string;
using std::ifstream;
using std::ofstream;

struct Shape {
	
	enum typeShape{BALL, PARALLELEPIPED, TETRAHEDRON};
	Shape() = default;
	typeShape type_shape;
	float density; 
	float volume; 
	int melting_point;
	
	struct ball{
		int radius;
	} _ball;

	struct parallelepiped{
		int edge1;
		int edge2;
		int edge3;
	} _parallelepiped;
	 
	struct tetrahedron{
		int len_side;
	} _tetrahedron;
	
};

string get_type_shape(Shape *shape);
float get_volume(Shape *shape);
bool read(Shape *shape, ifstream *in);
bool read(Shape::ball *_ball, ifstream *in);
bool read(Shape::parallelepiped *_parallelepiped, ifstream *in);
bool read(Shape::tetrahedron *_tetrahedron, ifstream *in);
void write(Shape *shape, ofstream *out);
void write(Shape::ball *_ball, ofstream *out);
void write(Shape::parallelepiped *_parallelepiped, ofstream *out);
void write(Shape::tetrahedron *_tetrahedron, ofstream *out);
bool check_int(string row);
bool check_float(string row);


