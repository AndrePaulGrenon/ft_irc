#include "../Servers.hpp"

int     Servers::User(Users &user, Parser &parser)
{
    std::cout << " -- [USER] Command has been Chosen " << std::endl;
    if (parser.getArgs().size() != 4)
    {
        send(user.getFd(), parser.SendReply("461", parser.getArgs()[0], "Command needs 4 parameters\n"), sizeof(parser.getReply()), 0);
        close_connection = true;
        return (1);
    }
    if (Nickname_list.find(parser.getArgs()[0]) != Username_list.end())
    {
            send(user.getFd(), parser.SendReply("462", parser.getArgs()[0], "Username already in use, please enter another valid Nickname\n"), sizeof(parser.getReply()), 0);
            close_connection = true;
            return (1);
    }
    user.setUserName(parser.getArgs()[0]);
    Username_list.insert(parser.getArgs()[0]);
    user.setRealName(parser.getArgs()[3]);
    send(user.getFd(), parser.SendReply("001", parser.getArgs()[0], "Username valid\n"), sizeof(parser.getReply()), 0);
    user.setRegistration(true);
    return (0);
}