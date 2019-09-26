#include<iostream>
#include<string>
#include<clocale>
#include"Exception.h"
using namespace std;
template <class T>
class Vector
{
	int size;
	T *mas;
public:
	Vector(int i);
	Vector(const Vector <T> &x);
	Vector();
	~Vector();
	Vector(int i, T *x);
	Vector operator+(const Vector <T> x);
	Vector& operator+=(const Vector<T> x) {
		if (size == x.size) {
			for (int i = 0; i < size; i++)
			{
				mas[i] += x.mas[i];
			}
			return *this;
		}
		else
		{
			Exception ex(__LINE__, __FILE__, __FUNCTION__, "Uncorrect operation");
			throw ex;
		}
	};
	Vector operator-(const Vector<T> x) {
		
		if (size == x.size) {
			Vector res;
			res.size = x.size;
			res.mas = new T[size];
			for (int i = 0; i < size; i++)
			{
				res.mas[i] = mas[i] - x.mas[i];
			}
			return res;
		}
		else
		{
			Exception ex(__LINE__, __FILE__, __FUNCTION__, "Uncorrect operation");
			throw ex;
		}
	};
	Vector& operator-=(const Vector<T> x)
	{
		if (size == x.size) {
			for (int i = 0; i < size; i++)
			{
				mas[i] -= x.mas[i];
			}
			return *this;
		}
		else
		{
			Exception ex(__LINE__, __FILE__, __FUNCTION__, "Uncorrect operation");
			throw ex;
		}
	};
	T operator*(const Vector<T> x)//скал€рное умножение
	{
		if (size == x.size)
		{
			T sum = 0;
			for (int i = 0; i < size; i++)
			{
				sum += mas[i] * x.mas[i];
			}
			return sum;
		}
		else
		{
			Exception ex(__LINE__, __FILE__, __FUNCTION__, "Uncorrect operation");
			throw ex;
		}
	};
	Vector operator*(T y)//умножение на скал€р
	{
		Vector s(size);
		for (int i = 0; i < size; i++)
		{
			s.mas[i] = mas[i] * y;
		}
		return s;
	};
	Vector operator/(T y)//деление на скал€р
	{
		if (y != 0)
		{
			Vector s(size);
			for (int i = 0; i < size; i++)
			{
				s.mas[i] - mas[i] / y;
			}
			return s;
		}
		else
		{
			Exception ex(__LINE__, __FILE__, __FUNCTION__, "Uncorrect operation(деление на ноль)");
			throw ex;
		}
	};
	Vector& operator=(const Vector<T>& x)
	{
		if (this != &x)
		{
			if (size != x.size)
			{
				delete[] mas;
				size = x.size;
				mas = new T[size];
			}
			for (int i = 0; i < size; i++)
			{
				mas[i] = x.mas[i];
			}
		}
		return *this;
	};
	bool operator==(const Vector<T> x)
	{
		bool a;
		if (size == x.size)
		{
			for (int i = 0; i < size; i++)
			{
				if (mas[i] != x.mas[i])
					return a = false;

			}
			if (!a)
				return false;
			else
				return true;
		}
		else
			return false;

	};
	bool operator !=(const Vector<T> x)
	{
		bool a;
		if (size == x.size)
		{
			for (int i = 0; i < size; i++)
			{
				if (mas[i] != x.mas[i])
					return a = true;

			}
			if (a)
				return true;
			else
				return false;
		}
		else
			return true;
	};
	T& operator[](int i)
	{
		if (i >= 0 && i < size)
		{
			return mas[i];
		}
		else
		{
			Exception ex(__LINE__, __FILE__, __FUNCTION__, "Wrong index");
			throw ex;
		}
	};
	Vector operator++()// префиксный ++
	{
		for (int i = 0; i < size; i++)
		{
			mas[i] += 1;
		}
		return *this;
	};
	Vector operator++(int)// постфиксный ++
	{
		Vector tmp(*this);
		for (int i = 0; i < size; i++)
		{
			mas[i]++;
		}
		return tmp;
	};
	friend ostream& operator<<(ostream &os, Vector <T> &x)
	{
		for (int i = 0; i < x.size; i++)
		{
			os << x.mas[i] << endl;
		}
		return os;
	};
	
	friend istream& operator>>(istream &is, Vector <T> &x)
	{
		setlocale(LC_CTYPE, "Russian");
		cout << "введите компоненты  вектора" << endl;
		for (int i = 0; i < x.size; i++)
		{
			cout << "введите "<< i <<" элемент" << endl;
			is >> x.mas[i];
		}
		return is;
	}
};
template <class T>
Vector<T>::Vector()
{
	setlocale(LC_CTYPE, "Russian");
	size = 1;
	try {
		mas = new T[size];
	}
    catch (bad_alloc)
	{
		Exception ex(__LINE__, __FILE__, __FUNCTION__, "bad alloc!");
		throw ex;
	}
}
template <class T>
Vector<T>::Vector(int i)
{
	size = i;
	try {
		mas = new T[i];
	}
	catch (bad_alloc)
	{
		Exception ex(__LINE__, __FILE__, __FUNCTION__, "bad alloc!");
		throw ex;
	}
}
template <class T>
Vector<T>::Vector(const Vector <T> &x)
{
	size = x.size;
	try {
		mas = new T[size];

		for (int i = 0; i < size; i++)
		{
			mas[i] = x.mas[i];
		}
	}
	catch (bad_alloc)
	{
		Exception ex(__LINE__, __FILE__, __FUNCTION__, "bad alloc!");
		throw ex;
	}
}
template <class T>
Vector<T>::~Vector()
{
	delete []mas;
}
template <class T>
Vector<T>::Vector(int i, T *x)
{
	size = i;
	try {
		mas = new T[size];

		for (int j = 0; j < size; j++)
		{
			mas[j] = x[j];
		}
	}
	catch (bad_alloc)
	{
		Exception ex(__LINE__, __FILE__, __FUNCTION__, "bad alloc!");
		throw ex;
	}
}
template <class T>
Vector<T> Vector<T>::operator+(const Vector<T> x)
{
	if (size == x.size)
	{
		Vector res;
		res.size = x.size;
		try {
			res.mas = new T[size];

			for (int i = 0; i < size; i++)
			{
				res.mas[i] = mas[i] + x.mas[i];
			}

			return res;
		}
		catch (bad_alloc)
		{
			Exception ex(__LINE__, __FILE__, __FUNCTION__, "bad alloc!");
			throw ex;
		}
	}
	else
	{
		Exception ex(__LINE__, __FILE__, __FUNCTION__, "Uncorrect operation!");
		throw ex;
	}
}


