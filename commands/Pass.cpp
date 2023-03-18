#include "../Servers.hpp"

int     Servers::Pass(Users &user, Parser &parser)
{
    std::cout << " -- [PASS] Command has been Chosen " << std::endl;

    parser.PrintElements();
    if (parser.getArgs()[0] != _server_data.Password)
    {
    
        _close_connection = true;
        return (-1);
    }
    user.setPass(true);
    return (0);
}