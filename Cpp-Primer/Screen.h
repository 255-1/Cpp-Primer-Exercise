//#include <string>
//
//class Screen {
//	friend class Window_mgr;
//public:
//	using pos = std::string::size_type;
//	Screen() = default;
//	Screen(pos ht, pos wd) :height(ht), width(wd), contents("") {};
//	Screen(pos ht, pos wd, char c) :height(ht), width(wd),
//		contents(ht* wd, c) {}
//	inline char get() const {
//		return contents[cursor];
//	}
//	inline char get(pos r, pos c)const {
//		pos row = r * width;
//		return contents[row + c];
//	}
//
//	inline Screen& move(pos r, pos c) {
//		pos row = r * width;
//		cursor = row + c;
//		return *this;
//	}
//	inline Screen& display(std::ostream& os) {
//		do_display(os);
//		return *this;
//	}
//
//	inline const Screen& display(std::ostream& os) const {
//		do_display(os);
//		return *this;
//	}
//
//	inline Screen& set(char c) {
//		contents[cursor] = c;
//		return *this;
//	}
//
//	inline Screen& set(pos r, pos c, char ch) {
//		contents[r * width + c] = ch;
//		return *this;
//	}
//	pos size() const;
//
//private:
//	void do_display(std::ostream& os) const {
//		os << contents;
//	}
//
//	pos cursor = 0;
//	pos height = 0, width = 0;
//	std::string contents;
//
//};
//
////Screen::pos Screen::size() const {
////	return height * width;
////}

//-----------------------------chaper16--------------------
#include <iostream>
#include <string>

template<unsigned H, unsigned W> class Screen;
template <unsigned H, unsigned W>
std::ostream& operator<<(std::ostream& os, const Screen<H, W>& s);
template <unsigned H, unsigned W>
std::istream& operator>>(std::istream& is, Screen<H, W>& s);

template <unsigned H, unsigned W>
class Screen {
	friend std::ostream& operator<<<H,W>(std::ostream& os, const Screen<H, W>& s);
	friend std::istream& operator>><H,W>(std::istream& is, Screen<H, W>& s);
public:
	using pos = std::string::size_type;
	Screen() = default;
	Screen(char c) :contents(H* W, c) {}
	char get() const {
		return contents[cursor];
	}
	Screen& move(pos r, pos c) {
		pos row = r * width;
		cursor = row + c;
		return *this;
	}
private:
	pos cursor = 0;
	pos height = H, width = W;
	std::string contents;

};

template <unsigned H, unsigned W>
std::ostream& operator<<(std::ostream& os, const Screen<H, W>& s) {
	unsigned int i, j;
	for (i = 0; i < s.height; ++i)
		os << s.contents.substr(0, W) << std::endl;
	return os;
}

template<unsigned H, unsigned W>
inline std::istream& operator>>(std::istream& is, Screen<H, W>& s)
{
	char a;
	is >> a;
	s.contents = std::string(H * W, a);
	return is;
}
