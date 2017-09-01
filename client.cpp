12344
2244

55411
#include "client_socket.h"
#include "socket_exception.h"
#include <iostream>
#include <string>
using namespace std;

const string kServer_Address = "192.168.71.49";

int main ( int argc, char* argv[] )
{
    try
    {

        ClientSocket client_socket ( kServer_Address, 5600 );

        std::string reply;

        try
        {
			if(argc == 2)
			{
				//static unsigned char kick_pkt[4] = {0x00, 0x00, 0xFF, 0x85};
				//std::cout << "====" << argv[1] << std::endl;
				//std::cout << "====" << std::string(kick_pkt) << std::endl;
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
