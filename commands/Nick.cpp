#include "../Servers.hpp"

bool    ft_isgoodchar(std::string nick)
{
    for(std::string::iterator it = nick.begin(); it != nick.end(); it++)
    {
        if (!isalnum(*it) && *it != '-' && *it != '[' &&
            *it != ']' && *it != '_' && *it != '{' &&
            *it != '}' && *it != '\\' && *it != '`' && *it != '|')
            return false;
    }
    return true;
}

int     Servers::Nick(Users &user, Parser &parser)
{
    if (parser.getArgs().empty())
    {
            send(user.getFd(), "431", 3, 0);
            return (1);
    }
    if (parser.getArgs()[0].length() > 9 || !ft_isgoodchar(parser.getArgs()[0]))
    {
            send(user.getFd(), "432", 3, 0);
            return (1);
    }
    if (Nickname_list.find(parser.getArgs()[0]) == Nickname_list.end())
    {
            send(user.getFd(), "433", 3, 0);
            return (1);
    }
    if (Nickname_list.find(user.getNickname()) != Nickname_list.end())
        Nickname_list.erase(user.getNickname());
    user.setNickname(parser.getArgs()[0]);
    Nickname_list.insert(parser.getArgs()[0]);
    send(user.getFd(), "001", 3, 0);
    return (0);
}
