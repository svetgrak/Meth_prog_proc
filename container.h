#include "shape.h"

using std::string;

struct item{
	Shape *shape;
	item *next;
};

struct container{
	int size;
	item *first;
	item *last;
};

container* init_container();
void add(container *container_with_shapes, Shape *shape);
bool read_container(container *container_with_shapes, string filename);
bool write_container(container *container_with_shapes, string filename);
void multimethod(container *container_with_shapes, ofstream *out);

