
struct Base {
    void bar(int);
protected:
    int ival;
};

struct Derived1 : virtual public Base {
    void bar(char);
    void foo(char);
protected:
    char cval;
};

struct Derived2 : virtual public Base {
    void foo(int);
protected:
    int ival;
    char cval;
};
class VMI : public Derived1, public Derived2 {
public:
    void print() {
        ival = 3;
    }
};