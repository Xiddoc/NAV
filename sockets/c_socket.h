
#ifndef SOCKET_H
#define SOCKET_H

#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>

class c_socket {
private:
	SOCKET conn;
	struct addrinfo conn_info{};

public:
	c_socket();

	bool connect_(const std::string &address, int port);

	int send_(const std::string &data) const;

	std::string recv_(int length) const;

	void close_() const;

};


#endif //SOCKET_H
