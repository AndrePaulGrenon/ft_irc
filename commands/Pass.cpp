#include "../Servers.hpp"

int     Servers::Pass(Users &user, Parser &parser)
{
    std::cout << " -- [PASS] Command has been Chosen " << std::endl;
    (void)user;
    (void) parser;
    return (0);
}