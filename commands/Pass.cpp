#include "../Servers.hpp"

int     Servers::Pass(Users &user, Parser &parser)
{
    std::cout << " -- [PASS] Command has been Chosen " << std::endl;


    parser.PrintElements();

    // if (parser.getArgs()[0] != Password)
    // {
    
    //     close_connection = true;
    // }
    

    (void)user;
    (void) parser;
    return (0);
}