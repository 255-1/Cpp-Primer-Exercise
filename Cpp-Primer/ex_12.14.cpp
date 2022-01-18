#include <iostream>
struct connection {
	
};

void disconnect(connection* p) {
	std::cout << "disconnect " << std::endl;
}
void func1214(connection* p) {
	std::cout << "func1214 " << std::endl;
	disconnect(p);
}

int main1214() {
	std::shared_ptr<connection> p(new connection, func1214);

	return 0;
}