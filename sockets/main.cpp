
#include "c_socket.h"
#include <iostream>

int main() {
	// Socket startup
	c_socket s;

	// Connect to server
	s.connect_("127.0.0.1", 6969);

	// Send data to the server
	s.send_("test");

	// Check if server has any data for us
	std::cout << s.recv_(5) << std::endl;

	// Close the connection
	s.close_();
	return 0;
}
