#include <iostream>
#include "container.h"

using std::cout;
using std::endl;
using std::string;


int main(int argc, char* argv[]) {
	
	if (argc != 3){
		cout << "Choice files" << endl;
		return -1;
	}
	
	container *container_with_shapes = init_container();
	
	string input = argv[1];
	bool is_success_read = read_container(container_with_shapes, input);
	if (!is_success_read){
		cout << "Failed read." << endl;
		return -1;
	}
	
	string output = argv[2];
	bool is_success_write = write_container(container_with_shapes, output);
	if (!is_success_write){
        cout << "Failed write." << endl;
        return -1;
    }
	
    cout << "Success." << endl;
    return 0;
}
