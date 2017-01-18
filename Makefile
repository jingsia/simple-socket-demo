# Makefile for the socket programming example
# #
#

all : simple_server simple_client

simple_server:socket.o server_socket.o server.o
	g++ -o simple_server socket.o server_socket.o server.o
simple_client:socket.o client_socket.o client.o
	g++ -o simple_client socket.o client_socket.o client.o

socket.o: socket.cpp socket.h
	g++ -c socket.cpp
server_socket.o: server_socket.cpp server_socket.h socket_exception.h
	g++ -c server_socket.cpp
client_socket.o: client_socket.cpp client_socket.h socket_exception.h
	g++ -c client_socket.cpp
client.o:client.cpp
	g++ -c client.cpp
server.o:server.cpp
	g++ -c server.cpp

clean:
	rm -f *.o simple_server simple_client
