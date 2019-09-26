#include"Vector.h"
#include<iostream>
#include<string>
#include"Exception.h"
using namespace std;

void main()
{
	try {
		int mas1[] = { 1,2,3,4,6 };
		Vector<int> s(5, mas1);
		Vector<int> ss(5, mas1);
		Vector<int> sss(5);
		Vector<int> vv(3);
		sss = s + ss;
		cout << sss << endl;
		Vector<int> v(6);
		v += vv;
		//v -= vv;
		//s = v + s;
		//s = v - s;
	    //s = v * s;//скал€рное умножение
		//s = v / 0;
		cout << sss[-3];
	}

	catch (Exception e)
	{
		e.print();
	}
	int key;
	cin >> key;
}