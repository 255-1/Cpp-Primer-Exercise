#include <string>

class Screen {
	friend class Window_mgr;
public:
	using pos = std::string::size_type;
	Screen() = default;
	Screen(pos ht, pos wd) :height(ht), width(wd), contents("") {};
	Screen(pos ht, pos wd, char c) :height(ht), width(wd),
		contents(ht* wd, c) {}
	inline char get() const {
		return contents[cursor];
	}
	inline char get(pos r, pos c)const {
		pos row = r * width;
		return contents[row + c];
	}

	inline Screen& move(pos r, pos c) {
		pos row = r * width;
		cursor = row + c;
		return *this;
	}
	inline Screen& display(std::ostream& os) {
		do_display(os);
		return *this;
	}

	inline const Screen& display(std::ostream& os) const {
		do_display(os);
		return *this;
	}

	inline Screen& set(char c) {
		contents[cursor] = c;
		return *this;
	}

	inline Screen& set(pos r, pos c, char ch) {
		contents[r * width + c] = ch;
		return *this;
	}
	pos size() const;

private:
	void do_display(std::ostream& os) const {
		os << contents;
	}

	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;

};

//Screen::pos Screen::size() const {
//	return height * width;
//}