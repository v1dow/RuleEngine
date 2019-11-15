#include <iostream>
#include <deque>

using namespace std;

int main(){
	deque<double>* d = new deque<double>();
	deque<double>* tmp = new deque<double>{1,2,3};
	delete d;
	d = new deque<double>(*tmp);
	cout<<d->empty()<<endl;


	return 0;
}
