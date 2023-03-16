#include "../Servers.hpp"

bool    ft_isgoodchar(std::string nick)
{
    for(std::string::iterator it = nick.begin(); it != nick.end(); it++)
    {
        std::cout << "sauce " << *it << std::endl;
        if (it == nick.end())
            return true;
        if (!isalnum(*it) && *it != '-' && *it != '[' &&
            *it != ']' && *it != '_' && *it != '{' && *it != '\r' &&
            *it != '}' && *it != '\\' && *it != '`' && *it != '|' && *it != '\n')
            return false;
    }
    return true;
}

int     Servers::Nick(Users &user, Parser &parser)
{
    if (parser.getArgs().empty())
    {
            send(user.getFd(), parser.SendReply("431", parser.getArgs()[0], "Nickname empty, please enter valid Nickname\n"), 512, 0);
            close_connection = true;
            return (1);
    }
    if (parser.getArgs()[0].length() > 9 || !ft_isgoodchar(parser.getArgs()[0]))
    {
            send(user.getFd(), parser.SendReply("432", parser.getArgs()[0], "Nickname invalid, please enter valid Nickname\n"), 512, 0);
            close_connection = true;
            return (1);
    }
    if (Nickname_list.find(parser.getArgs()[0]) != Nickname_list.end())
    {
            send(user.getFd(), parser.SendReply("433", parser.getArgs()[0], "Nickname already in use, please enter another valid Nickname\n"), 512, 0);
            close_connection = true;
            return (1);
    }
    if (Nickname_list.find(user.getNickname()) != Nickname_list.end())
        Nickname_list.erase(user.getNickname());
    user.setNickname(parser.getArgs()[0]);
    Nickname_list.insert(parser.getArgs()[0]);
    send(user.getFd(), parser.SendReply("001", parser.getArgs()[0], "Nickname valid\n"), 512, 0);
    return (0);
}
