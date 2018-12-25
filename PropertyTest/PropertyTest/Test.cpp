#include "../../Property.h"

#include <iostream>
class A {
public:
	PropertyDecare(int, a, 5);
	PropertyGetter(int, a);
	PropertySetter(int, a);
	PropertyPrivate(float, Float, 0.0f);
	PropertyReadOnly(double, Double, 5.5f);
};

int main(){
	A a;
	a.Seta(5);
	
	std::cout << a.Geta();
	
	std::cin.get();

	return 0;
}