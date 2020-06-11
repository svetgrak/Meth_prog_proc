#include <string>

using std::string;
using std::ifstream;
using std::ofstream;

struct Shape {
	
	enum typeShape{BALL, PARALLELEPIPED, TETRAHEDRON};
	Shape() = default;
	typeShape type_shape;
	float density; // общий параметр для всех типов - плотность материала
	float volume; // объем
	
	// шар - целочисленный радиус
	struct ball{
		int radius;
	} _ball;
	// параллелепипед - три целочисленных ребра
	struct parallelepiped{
		int edge1;
		int edge2;
		int edge3;
	} _parallelepiped;
	// тетраэдр - целочисленная длина стороны 
	struct tetrahedron{
		int len_side;
	} _tetrahedron;
	
};

string get_type_shape(Shape *shape);
float get_volume(Shape *shape);
void read(Shape *shape, ifstream *in);
void read(Shape::ball *_ball, ifstream *in);
void read(Shape::parallelepiped *_parallelepiped, ifstream *in);
void read(Shape::tetrahedron *_tetrahedron, ifstream *in);
void write(Shape *shape, ofstream *out);
void write(Shape::ball *_ball, ofstream *out);
void write(Shape::parallelepiped *_parallelepiped, ofstream *out);
void write(Shape::tetrahedron *_tetrahedron, ofstream *out);


