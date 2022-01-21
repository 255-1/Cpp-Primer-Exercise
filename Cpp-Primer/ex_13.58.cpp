#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Foo
{
public:
	Foo sorted()&& 
	{
		std::cout << "&&" << std::endl;
		sort(data.begin(), data.end());
		return *this;
	}

	Foo sorted() const& 
	{
		std::cout << "const &" << std::endl;
		Foo ret(*this);
		sort(ret.data.begin(), ret.data.end());


		//ex_13.56
		//Foo ret(*this);
		//return ret.sorted();
		
		//ex_13.57
		//return Foo(*this).sorted();

		return ret;
	}
private:
	vector<int> data;
};

int main()
{
	Foo().sorted();
	Foo f;
	f.sorted();

	return 0;
}