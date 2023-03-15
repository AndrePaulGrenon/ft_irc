#include "Parser.hpp"

Parser::Parser(char *buff)
{
    std::string line(buff);
    unsigned long pos = 0;

    while (pos != line.npos)
    {
        pos = line.find(' ');
        if (pos == line.npos)
        {
            my_args.push_back(line);
            break;
        }
        my_args.push_back(line.substr(0, pos));
        line = line.substr(pos + 1, line.size());
    }


    //CODE is to check what is parse:
    if (prefix.length() > 0)
        std::cout << "Prefix: " << prefix << std::endl; 
    std::cout << "CMD: " << command << std::endl;
    std::vector<std::string>::iterator it = my_args.begin();
    std::vector<std::string>::iterator ite = my_args.end();
    std::cout << "ARGS " ;
    for (;it != ite; it++)
    {
        std::cout << " - " << *it;
    }
    std::cout << std::endl;

}

Parser::~Parser()
{

}

std::vector<std::string> &Parser::getArgs()
{
    return this->my_args;
}