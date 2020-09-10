#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

using namespace boost;

int main()
{
	std::cout << "Hello\n";
	std::cout << boost::filesystem::current_path() << std::endl;
}

