class A {};
class B : public A {};
class C : public B {};
class D : public B, public A {};

int main193() {
	//A* pa = new C;
	//B* pb = dynamic_cast<B*>(pa);
	
	//B* pb = new B;
	//C* pc = dynamic_cast<C*>(pb);
	
	//A* pa = new D;
	//B* pb = dynamic_cast<B*>(pa);

	return 0;
}