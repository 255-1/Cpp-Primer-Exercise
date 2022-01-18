#include <iostream>
struct connection {
};

void disconnect1215(connection* p) {
	std::cout << "disconnect " << std::endl;
}

int main1215() {
	std::shared_ptr<connection> p(new connection, 
		[](connection *p) {
			std::cout << "lambda " << std::endl;
			disconnect1215(p);
		});

	return 0;
}