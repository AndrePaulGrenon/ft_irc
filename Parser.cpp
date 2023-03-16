#include "Parser.hpp"

Parser::Parser(char *buff)
{
    std::string line(buff);
    _server_name = IRC;
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
            line.erase(line.end() - 1);
            line.erase(line.end() - 1);
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
    PrintElements();
}

Parser::Parser(const Parser &other) : _command(other.getCommand()), _my_args(other.getArgs()), _prefix(other.getPrefix()), 
        _message(other.getMessage()), _server_name(other._server_name)
{

}

Parser::~Parser()
{

}

Parser  &Parser::operator=(const Parser &other)
{
    _command = other.getCommand();
    _message = other.getMessage();
    _my_args = other.getArgs();
    _prefix = other.getPrefix();
    return (*this);
}

const char    *Parser::SendReply(const std::string code, 
                const std::string args, const std::string message) 
{
    _reply.clear();
    _reply = _server_name + ".42.qc " + code + " " + args + " :" + message + "\r\n";
    if (_reply.size() > 512)
        return NULL;
    return (_reply.c_str());
}

//CODE Pints every elements of the Parser
void    Parser::PrintElements(void)
{
    
    std::cout << MAG;
    if (_prefix.length() > 0)
        std::cout << "Prefix: " << _prefix << std::endl; 
    std::cout <<  "CMD: " << _command << std::endl;
    
    std::vector<std::string>::iterator it = _my_args.begin();
    std::vector<std::string>::iterator ite = _my_args.end();
    std::cout << "ARGS " ;
    for (;it != ite; it++)
    {
        std::cout << " - " << *it;
    }
    std::cout << std::endl;
    if (_message.length() > 0)
        std::cout <<  "Message: " << _message << std::endl;
    std::cout << CLEAR << std::endl;
}

const std::vector<std::string>  &Parser::getArgs() const
{
    return (_my_args);
}

const std::string               &Parser::getCommand() const
{
    return (_command);
}

const std::string               &Parser::getPrefix() const
{
    return (_prefix);
}

const std::string               &Parser::getMessage() const
{
    return (_message);
}

const std::string                 &Parser::getReply() const
{
    return (_reply);
}