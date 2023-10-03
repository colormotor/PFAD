#include <iostream>
#include <stdio.h>

using namespace std; // This avoid us having to write std::cout (which is actually OK)

// "main" with this signature is the entry point of most C and C++ programs
// The flow of the program starts from here.
// The arguments are a standard for allowing input on the command line
int main(int argc, char *argv[]) {
	cout << "Hello, C++ world!" << endl; // This is the C++ way of outputting to the console
  printf("Hello, C world\n");          // This is the C way
	return 0;
}
