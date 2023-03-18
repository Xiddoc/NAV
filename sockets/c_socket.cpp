
#include "c_socket.h"
#include <windows.h>
#include <string>

c_socket::c_socket() {
	// Use windows startup function
	WSAData wsaData{};
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	// Set to fields
	conn_info.ai_family = AF_UNSPEC; // IPV4
	conn_info.ai_socktype = SOCK_STREAM;
	conn_info.ai_protocol = IPPROTO_TCP; // Talk over TCP

	// Create a c_socket for connections
	conn = socket(conn_info.ai_family, conn_info.ai_socktype, conn_info.ai_protocol);
}

bool c_socket::connect_(const std::string &address, int port) {
	// Resolve the address
	struct addrinfo *remote_addr = nullptr;
	int status = getaddrinfo(address.c_str(), std::to_string(port).c_str(), &conn_info, &remote_addr);

	// Check for errors
	if (status != 0) {
		return false;
	}

	// Connect to the address using our socket
	int connection_result = connect(conn, remote_addr->ai_addr, (int) remote_addr->ai_addrlen);

	// Free the address memory
	freeaddrinfo(remote_addr);

	// Return connection status (success returns true)
	return connection_result != SOCKET_ERROR;
}

int c_socket::send_(const std::string &data) const {
	// Convert to C string and send
	return send(conn, data.c_str(), (int) data.size(), 0);
}

void c_socket::close_() const {
	// Shutdown the socket, if it is open
	shutdown(conn, SD_BOTH);
	// Close the socket
	closesocket(conn);
	// Stop windows c_socket
	WSACleanup();
}

std::string c_socket::recv_(int length) const {
	// Make a buffer to hold the received data
	char buffer[length];
	// Retrieve the data
	recv(conn, buffer, length, 0);
	// Return the data
	return std::string{buffer};
}



