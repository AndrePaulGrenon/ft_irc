#include "Servers.hpp"

void    compress_function(struct pollfd *fds, int nfds);

Servers::Servers(size_t pt, std::string pw): Port(pt), Password(pw)
{
    Servers::ServerInit();
	std::cout << "Welcome, it is I, your server" << std::endl;
}

Servers::~Servers()
{
	std::cout << "Get the F out! This ain't 4chan" << std::endl;
}


void Servers::ServerInit()
{
    commandMap["PASS"] = &Servers::Pass;
    commandMap["NICK"] = &Servers::Nick;
    commandMap["USER"] = &Servers::User;
    commandMap["AWAY"] = &Servers::Away;
    commandMap["INVITE"] = &Servers::Invite;
    commandMap["JOIN"] = &Servers::Join;
    commandMap["KICK"] = &Servers::Kick;
    commandMap["LIST"] = &Servers::List;
    commandMap["MODE"] = &Servers::Mode;
    commandMap["NAMES"] = &Servers::Names;
    commandMap["NOTICE"] = &Servers::Notice;
    commandMap["PART"] = &Servers::Part;
    commandMap["PING"] = &Servers::Ping;
    commandMap["PONG"] = &Servers::Pong;
    commandMap["PRIVMSG"] = &Servers::Privmsg;
    commandMap["QUIT"] = &Servers::Quit;
    commandMap["SHUTDOWN"] = &Servers::Shutdown;
    commandMap["TOPIC"] = &Servers::Topic;
}

void	Servers::start()
{
    int i_bind, i_listen;
    bool compression = false;
    end_server = false;
    
  // [message]
    char message[256] = "Anthony est sexy, Arrêtez de me demander !";
    (void) message;
    // [SOCKET CREATION] 

    //SOCK ADDRESS: basic structure for all syscalls and functions that deal with internet addresses.
    struct sockaddr_in address;
    
    address.sin_family = AF_INET; //Address family for internet protocols (for TCP)
    address.sin_port = htons(Port) ; // Contains the port number
    address.sin_addr.s_addr = INADDR_ANY; // Use when we don't want to bind a socket to any specific IP. For example if we don't know the IP. 

    // SOCKET CREATE: 1.Returns fd 2. PF_INET or PF_INET6 protocol internet for IPV4 or IPV6 
        // 3.Sock_stream : default for TCP usage 4. Protocol value for IP = 0 
    // int antho_fd = socket(PF_INET, SOCK_STREAM, 0);
    int antho_fd = socket(PF_INET, SOCK_STREAM, 0);

    // SETSOCKETOPT : Set options for the specified socket. enable to reuse socket address. Prevent error such as "Address already in use" 
        // 1. SOL_SOCKET is default to manipulate options at the socket level 2. SO_REUSEADDR is an option for the socket. 
        // 3. option_value and option len (NULL, 0), is a buffer of len size that returns the value of the option
    setsockopt(antho_fd, SOL_SOCKET, SO_REUSEADDR, NULL, 0);

    // FCNTL : Enables the descriptor to be in NON-BLOCKING MODE
    fcntl(antho_fd, F_SETFL, O_NONBLOCK);
  
    //BIND : binds the socket to the address and port number specified in the sockaddr_in struct
    i_bind = bind(antho_fd, reinterpret_cast<struct sockaddr *>(&address), sizeof(address));

    //  [LISTENING]
    //defines the sockets to listen to, and the amount of request that can be pending
    i_listen = listen(antho_fd, SOMAXCONN);

    // [POLLING]: Checks if a FD is ready to perform. It allows the process to wait for an event to occur. 
    
    struct pollfd my_pollfd[124];// Sets the array of files descriptors to monitor for I/O events. 
    
    memset(my_pollfd, 0 , sizeof(my_pollfd)); //Initialize this array to 0
    my_pollfd[0].fd = antho_fd; // Assign the FD of the socket
    my_pollfd[0].events = POLLIN; // Checks if data may be read without blocking 
    int countdown = (3 * 60 * 1000); // Countdown 
    
    int nfds = 1;//current numbre of socket descriptor open;
    
    do
    {
        //POLLL
        std::cout << "Waiting for poll motherfucker ... ! : " << my_pollfd[0].revents << std::endl;
        int result = poll(my_pollfd, nfds, countdown);

        //If an error with poll : exit
        if (result < 0 || end_server)
        {
            std::cerr << "Its not working man ! :( I'm CRASSSSSHHHING ... \n" ;
            break;
        }
        //If poll timesout : exit
        if (result == 0)
        {
            std::cout << "Nobody loves you ! No messages :(" << std::endl;
            break;
        }
        int currentsize = nfds;

        //We check all our tracked socket descriptors
        for (int i = 0; i < currentsize; i++)
        {
            if (my_pollfd[i].revents != 0)
                std::cout << "Poll fd : " << my_pollfd[i].fd << " Poll revent : " << my_pollfd[i].revents << std::endl;
            
            //If socket has no changes... go to next;
            if (my_pollfd[i].revents == 0)
                continue;
            if (my_pollfd[i].revents != POLLIN) //if error, end server;
            {
                // end_server = true; //Original line to close server when socket disconnects
                DeleteUsers(usersMap[my_pollfd[i].fd]);
                close(my_pollfd[i].fd);
                my_pollfd[i].fd = -1;
                compression = true;
                if (my_pollfd[0].revents == 32)
                    end_server = true;
                break;
            }
            if (my_pollfd[i].fd == antho_fd) // If listenning socket has a change, accept new connection
            {
                std::cout << "New connection is requested" <<  std::endl;

                int new_sd;
                // [ACCEPT new connection]
                do
                {
                    new_sd = accept(antho_fd, NULL, NULL); //return a socket description of new connection socket
                    if (new_sd < 0)
                    {
                        if (errno != EWOULDBLOCK)
                        {
                            perror("Acceptance of new connection has failed !");
                            end_server = true;
                        }
                        break;
                    }
                    my_pollfd[nfds].fd = new_sd;
                    my_pollfd[nfds].events = POLLIN;
                    nfds++;
                    usersMap[new_sd];
                    usersMap[new_sd].setFd(new_sd);
                    usersMap[new_sd].setFd(new_sd);
                    std::cout << " New connection has been added to descriptor: " << new_sd << std::endl;
                } while (new_sd != -1);
            }
            else //if any active socket has a change, then receive data
            {
                std::cout << " Active socket is readable for data " << std::endl;

                close_connection = false;
                char buff[512];
                bool crlf = false;
                memset(buff, 0, sizeof(buff));
                do
                {
                    result = recv(my_pollfd[i].fd, buff, sizeof(buff), 0); //receive message from socket   
                    if (result < 0)
                    {
                        if (errno != EWOULDBLOCK)
                        {
                            perror("Socket reception has failed, massive crash, connection will be flushed ! Bye loser XD");
                            close_connection = true;
                        }
                        // break;
                    }
                    if (result == 0)
                    {
                        close_connection = true;
                        break;
                    }

                    //CHECKS for CR and LR caracters 
                    int i = 0;
                    while (buff[i] != '\0' || i > 510)
                    {
                        if (buff[i] == '\r' && buff[i + 1] == '\n')
                        {
                            buff[i] = ' ';
                            buff[i + 1] = ' ';
                            // buff[i + 2] = '\n';
                            crlf = true;
                            std::cout << "FOUND backslasshes" << std::endl;
                            break; 
                        }
                        i++;
                    }
                    std::cout << "In the loop , use ^M to exit " << std::endl;           

                } while (crlf == false); //As long has CR - LF (\r\n) has not been found

                
                std::cout << " REceived in buff :" << buff << std::endl;
                //PARSING
                Parser parser(reinterpret_cast<char *>(buff));
                std::map<int, Users>::iterator itUM = usersMap.find(my_pollfd[i].fd); //Tries to find the user

                //EXECUTE CMD:
                std::map<std::string, fct>::iterator it = commandMap.find(parser.getCommand()); //Looks for iterator pointing to Command function
                if (it != commandMap.end()) //If command exists
                {
                    (this->*(it->second))(itUM->second, parser); // send the reference of existing user
                }
                
                if (close_connection == true)
                {
                    DeleteUsers(usersMap[my_pollfd[i].fd]);
                    close(my_pollfd[i].fd);
                    my_pollfd[i].fd = -1;
                    compression = true;
                }
            } //End of tracking loop
        } //End of polling loop
        if (compression)
        {
             std::cout << "Enters compression !" << std::endl;
            compress_function(my_pollfd, nfds);
            compression = false;
        }
    
    } while (end_server == false);

    close(antho_fd);

    return ;
}


void    Servers::DeleteUsers(Users &user)
{
    Nickname_list.erase(user.getNickname());
    Username_list.erase(user.getUsername());
    usersMap.erase(user.getFd());
    return ;
}





