#include "../Servers.hpp"

int     Servers::Nick(Users &user, Parser &parser)
{
     std::cout << " -- [NICK] Command has been Chosen " << std::endl;
    char buff[] = ":IRC 001 borja :Welcome to the Internet Relay Network ";
    send(4, buff, sizeof(buff), 0); //send the message through the socket
    (void) user;
    (void) parser;
    return (0);
}