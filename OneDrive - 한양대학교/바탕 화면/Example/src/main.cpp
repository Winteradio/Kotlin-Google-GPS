#include <cstdlib>
#include <iostream>

int main()
{
	const char* project_dir = "./../../project";
	const char* build_dir = "./../../project/build";

	int result = std::system(("cmake " + std::string( project_dir ) + " -B " + build_dir).c_str() );

	if ( result !=0 )
	{
		std::cout << "CMake Error " << std::endl;
		return -1;
	}

	result = std::system(("cmake --build " + std::string( build_dir )).c_str());
	if ( result != 0 )
	{
		std::cout << "CMake Build Error " << std::endl;
	}

	result = std::system(( "start " + std::string( build_dir ) + "/Debug/Example.exe").c_str());
	if ( result != 0 )
	{
		std::cout << "Run File Error" << std::endl;
	}

	return 0;
}