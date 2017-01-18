
#include "server_socket.h"
#include "socket_exception.h"
#include <string>
#include <iostream>
using namespace std;

int main ( int argc, char* argv[] )
{
    std::cout << "running....\n" << std::endl;

    try
    {
        // Create the socket
        ServerSocket server ( 30000 );

        while ( true )
        {

            ServerSocket new_sock;
            server.accept ( new_sock );

            try
            {
                while ( true )
                {
					std::string data;
                    new_sock >> data;
					std::cout << "We received this response from the client:\n\"" << data << "\"\n";;
                    new_sock << data;
                }
            }
            catch ( SocketException& ) {}

        }
    }
    catch ( SocketException& e )
    {
        std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }

    return 0;
}
