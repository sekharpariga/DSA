#include <iostream>
using namespace std;


int func(...){return 0;}

template<typename T>
typename std::enable_if<std::is_integral<T>::value, int>::type func(int k) {return 1;}

int func(float f) { return 2;}


int main()
{
	cout << func(nullptr) << endl;
	cout << func(2) << endl;
	cout << func(2.0) << endl;
	cout << func(2.f) << endl;	
	return 0;
}