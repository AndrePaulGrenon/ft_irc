#include "Servers.hpp"

Servers::Servers(std::string pw, size_t p): Password(pw), Port(p)
{
	std::cout << "Welcome, it is I, your servers" << std::endl;
}

Servers::~Servers()
{
	std::cout << "Get the F out! This ain't 4chan" << std::endl;
}