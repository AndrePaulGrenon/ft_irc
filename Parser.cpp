#include "Parser.hpp"

Parser::Parser(char *buff)
{
    std::string line(buff);
    unsigned long pos = 0;
    bool first = true;

    while (pos != line.npos)
    {
        while (line[0] == ' ')
            line.erase(line.begin());
        if (line[0] == ':' && first == false)
        {
            _message = line;
            _message.erase(_message.begin());
            break ;
        }
        pos = line.find(' ');
        if (pos == line.npos)
        {
            _my_args.push_back(line);
            break;
        }
        _my_args.push_back(line.substr(0, pos));
        line = line.substr(pos + 1, line.size());
        first = false;
    }

    if (_my_args[0][0] == ':')
    {
        _prefix = _my_args[0];
        _prefix.erase(_prefix.begin());
        _my_args.erase(_my_args.begin());
    }
    _command = _my_args[0];
    _my_args.erase(_my_args.begin());

    //CODE is to check what is parse:
    std::cout << MAG;
    if (_prefix.length() > 0)
        std::cout << "Prefix: " << _prefix << std::endl; 
    std::cout <<  "CMD: " << _command << std::endl;
    std::cout <<  "Message: " << _message << std::endl;
    std::vector<std::string>::iterator it = _my_args.begin();
    std::vector<std::string>::iterator ite = _my_args.end();
    std::cout << "ARGS " ;
    for (;it != ite; it++)
    {
        std::cout << " - " << *it;
    }
    std::cout << CLEAR << std::endl;

}

Parser::~Parser()
{

}

std::vector<std::string> &Parser::getArgs()
{
    return (_my_args);
}

std::string              &Parser::getCommand()
{
    return (_command);
}

std::string              &Parser::getPrefix()
{
    return (_prefix);
}