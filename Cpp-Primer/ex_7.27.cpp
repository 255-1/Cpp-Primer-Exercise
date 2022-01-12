#include <iostream>
#include "Screen.h"

int main727() {

	//Screen myScreen(2,2,'X');
	//const Screen cMyScreen(2, 2, 'C');
	//myScreen.display(std::cout);
	//myScreen.set('A').display(std::cout);
	//std::cout << std::endl;
	//myScreen.set('A').display(std::cout).set('A').display(std::cout);
	//std::cout << std::endl;
	//cMyScreen.display(std::cout);

	Screen myScreen(5, 5, 'X');
	myScreen.move(4, 0).set('#').display(std::cout);
	std::cout << "\n";
	myScreen.display(std::cout);
	std::cout << "\n";

	return 0;
}