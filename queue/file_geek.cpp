// C++ program to demonstrate read/write of class
// objects in C++.
/*https://www.geeksforgeeks.org/readwrite-class-objects-fromto-file-c/*/
// https://www.cplusplus.com/doc/tutorial/files/

#include <iostream>
#include <fstream>
using namespace std;
#include <filesystem>
namespace fs = std::filesystem;

// Class to define the properties
class File {
public:

	// Function declaration of input() to input info
	void input();	
	//Copy the file read by input()
	void output();
private:
	std::filesystem::path src;
	std::filesystem::path dst;
};

// Function definition of input() to input info
void File::input()
{
	
	//const std::filesystem::path src = "Input.txt";
	//cout<<"File copied";
	src = "hello";
	cout<<"File copied";
	
}

// Function output() to save the file to destination
void File::output()
{
	
	dst = "Hello.txt";	
    	std::filesystem::copy_file(src, dst, std::filesystem::copy_options::overwrite_existing);		

	// Output is the file stored
	cout << "\nFile stored"<<endl;
}

// Driver code
int main()
{
	// Creating object of the class
	File object;

	// Copying source file contents
	
	object.input();

	//Outputting data means saving it in a file. 
	object.output();

	return 0;
}

