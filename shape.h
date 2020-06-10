#include <string>

using std::string;
using std::ifstream;
using std::ofstream;

struct Shape {
	
	enum typeShape{BALL, PARALLELEPIPED};	// ��� ��������� ������ - ��� ��� ��������������
	Shape() = default;
	typeShape type_shape;
	float density; // ����� �������� ��� ���� ����� - ��������� ���������
	
	
	// ��� - ������������� ������
	struct ball{
		int radius;
	} _ball;
	// �������������� - ��� ������������� �����
	struct parallelepiped{
		int edge1;
		int edge2;
		int edge3;
	} _parallelepiped;
	
};

string get_type_shape(Shape *shp);
void read(Shape *shape, ifstream *in);
void read(Shape::ball *_ball, ifstream *in);
void read(Shape::parallelepiped *_parallelepiped, ifstream *in);
void write(Shape *shape, ofstream *out);
void write(Shape::ball *_ball, ofstream *out);
void write(Shape::parallelepiped *_parallelepiped, ofstream *out);


