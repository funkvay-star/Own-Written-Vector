//#include "C:\Users\Funkv\source\repos\OMD\OMD\Homework 17 final\Homework 17 task Own Vector final.h"
#include "/home/funkvay/Documents/LabsRep/OwnVector/vector.h"
#include <vector>

template<typename T>
void printv(const Vector<T>& v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] << " ";
	}
	std::cout << "\n";
}

void test()
{
	{ // Testing operator [] and Constructor that gets amount and default value
		Vector<int> v(5, 6);
		bool elementsAreSix = true;

		std::cout << "Testing operator [] and Constructor that gets amount and default value : ";
		for (int i = 0; i < 5; ++i)
		{
			if (v[i] != 6)
			{
				std::cout << "WRONG";
				elementsAreSix = false;
				break;
			}
		}
		if (elementsAreSix)
		{
			std::cout << "SUCCESS";
		}
		std::cout << "\n";
	}

	{ // Testing default Constructor and size() function
		Vector<int> v;

		std::cout << "Testing default Constructor and size() function : ";
		if (v.size() == 0)
		{
			std::cout << "SUCCESS";
		}
		else
		{
			std::cout << "WRONG";
		}
		std::cout << "\n";
	}

	{ // Testing copy constructor
		Vector<int> v1(6);
		v1[0] = 1;
		v1[1] = 4;
		v1[2] = 5;
		v1[3] = 8;
		v1[4] = 19;
		v1[5] = 2;

		Vector<int> v2 = v1;
		bool elementsAreEqual = true;

		std::cout << "Testing copy constructor : ";
		for (int i = 0; i < v2.size(); ++i)
		{
			if (v1[i] != v2[i])
			{
				std::cout << "WRONG";
				elementsAreEqual = false;
				break;
			}
		}
		if (elementsAreEqual)
		{
			std::cout << "SUCCESS";
		}
		std::cout << "\n";
	}

	{ // Testing constructor that gets two iterators
		Vector<int> v1(6);
		v1[0] = 1;
		v1[1] = 4;
		v1[2] = 5;
		v1[3] = 8;
		v1[4] = 19;
		v1[5] = 2;

		Vector<int> v2(v1.begin(), v1.end());
		bool elementsAreEqual = true;

		std::cout << "Testing constructor that gets two iterators : ";
		for (int i = 0; i < v2.size(); ++i)
		{
			if (v1[i] != v2[i])
			{
				std::cout << "WRONG";
				elementsAreEqual = false;
				break;
			}
		}
		if (elementsAreEqual)
		{
			std::cout << "SUCCESS";
		}
		std::cout << "\n";
	}
	{ // Testing constructor that gets two reversed iterators
		Vector<int> v1(6);
		v1[0] = 1;
		v1[1] = 4;
		v1[2] = 5;
		v1[3] = 8;
		v1[4] = 19;
		v1[5] = 2;

		Vector<int> v2(v1.rbegin(), v1.rend());
		bool elementsAreEqual = true;

		std::cout << "Testing constructor that gets two reversed iterators : ";
		for (int i = 0; i < v2.size(); ++i)
		{
			if (v1[i] != v2[v2.size() - i - 1])
			{
				std::cout << "WRONG";
				elementsAreEqual = false;
				break;
			}
		}
		if (elementsAreEqual)
		{
			std::cout << "SUCCESS";
		}
		std::cout << "\n";
	}
	{ // Testing checking if Vector works for chars
		//Vector<char> v(5, 'f');
		//printv(v); 

		//It works xD
	}
	{ // Testing operator = when v2 is empty
		Vector<int> v1(6);
		v1[0] = 1;
		v1[1] = 4;
		v1[2] = 5;
		v1[3] = 8;
		v1[4] = 19;
		v1[5] = 2;

		Vector<int> v2;
		v2 = v1;
		bool elementsAreEqual = true;

		std::cout << "Testing operator = when v2 is empty : ";
		for (int i = 0; i < v2.size(); ++i)
		{
			if (v1[i] != v2[i])
			{
				std::cout << "WRONG";
				elementsAreEqual = false;
				break;
			}
		}
		if (elementsAreEqual)
		{
			std::cout << "SUCCESS";
		}
		std::cout << "\n";
	}
	{ // Testing operator = when v2 is NOT empty
		Vector<int> v1(6);
		v1[0] = 1;
		v1[1] = 4;
		v1[2] = 5;
		v1[3] = 8;
		v1[4] = 19;
		v1[5] = 2;

		Vector<int> v2;
		v2 = v1;
		bool elementsAreEqual = true;

		std::cout << "Testing operator = when v2 is NOT empty : ";
		for (int i = 0; i < v2.size(); ++i)
		{
			if (v1[i] != v2[i])
			{
				std::cout << "WRONG";
				elementsAreEqual = false;
				break;
			}
		}
		if (elementsAreEqual)
		{
			std::cout << "SUCCESS";
		}
		std::cout << "\n";
	}
	{ // Testing function front(), back()
		Vector<int> v(6);
		v[0] = 56;
		v[1] = 4;
		v[2] = 5;
		v[3] = 8;
		v[4] = 19;
		v[5] = 2;

		std::cout << "Testing function front, back : ";

		if (v.front() == 56 && v.back() == 2)
		{
			std::cout << "SUCCESS";
		}
		else
		{
			std::cout << "WRONG";
		}
		std::cout << "\n";
	}
	{ // Testing function at(0)
		Vector<int> v(6);
		v[0] = 56;
		v[1] = 4;
		v[2] = 5;
		v[3] = 8;
		v[4] = 19;
		v[5] = 2;

		std::cout << "Testing function at(0) : ";

		try
		{
			if (v.at(0) == 56)
			{
				std::cout << "SUCCESS";
			}
			else
			{
				std::cout << "WRONG";
			}
		}
		catch (std::out_of_range e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	{ // Testing function at(-1)
		Vector<int> v(6);
		v[0] = 56;
		v[1] = 4;
		v[2] = 5;
		v[3] = 8;
		v[4] = 19;
		v[5] = 2;

		std::cout << "Testing function at(-1) : ";

		try
		{
			if (v.at(-1) == 56)
			{
				std::cout << "SUCCESS";
			}
			else
			{
				std::cout << "WRONG";
			}
		}
		catch (std::out_of_range e)
		{
			std::cout << e.what();
		}
		std::cout << "\n";
	}
	{ // Testing pop_back()
		Vector<int> v(6);
		v[0] = 56;
		v[1] = 4;
		v[2] = 5;
		v[3] = 8;
		v[4] = 19;
		v[5] = 2;

		std::cout << "Testing pop_back() : ";

		v.pop_back();
		if (v.size() == 5)
		{
			std::cout << "SUCCESS";
		}
		else
		{
			std::cout << "WRONG";
		}
		std::cout << "\n";
	}
	{ // Testing reserve()
		Vector<int> v(6);
		v[0] = 56;
		v[1] = 4;
		v[2] = 5;
		v[3] = 8;
		v[4] = 19;
		v[5] = 2;

		std::cout << "Testing reserve() : ";

		std::cout << v.capacity() << " ";
		v.reserve(5);
		std::cout << v.capacity() << " ";

		for (int i = 0; i < v.capacity(); ++i)
		{
			std::cout << v[i] << " ";
		}
	}
}

int main()
{
	test();
}
