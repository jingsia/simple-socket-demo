
#include "client_socket.h"
#include "socket_exception.h"
#include <iostream>
#include <string>
using namespace std;

const string kServer_Address = "192.168.0.109";

int main ( int argc, char* argv[] )
{
    try
    {

        ClientSocket client_socket ( kServer_Address, 30000 );

        std::string reply;

        try
        {
			if(argc == 2)
			{
				client_socket << argv[1];
				client_socket >> reply;
			}
        }
        catch ( SocketException& ) {}

        std::cout << "We received this response from the server:\n\"" << reply << "\"\n";;

    }
    catch ( SocketException& e )
    {
        std::cout << "Exception was caught:" << e.description() << "\n";
    }

    return 0;
}
