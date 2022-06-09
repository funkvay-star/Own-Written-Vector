#pragma once

#include <iostream>
#include <stdexcept>
#include <cstdlib>

template<typename T>
class Vector
{
private:
	int vSize;
	int vCapacity;
	char* vArr;

	void normalizeCapacity(int i)
	{
		if (vSize == vCapacity - 1)
		{
			vCapacity *= 2;
			char* vArrSaver = new char[sizeOfTArr(vCapacity)];
			T* newTarr = reinterpret_cast<T*>(vArrSaver);
			T* Tarr = changingPointerToT();

			for (int i = 0; i < vSize; ++i)
			{
				//T saver(Tarr[i]);
				new(newTarr + i) T(Tarr[i]);
				//newTarr[i];
			}

			clear();

			vArr = vArrSaver;
		}
	}


	T* changingPointerToT()
	{
		T* arrOfT = reinterpret_cast<T*>(vArr);
		return arrOfT;
	}

	const T* changingPointerToT() const
	{
		T* arrOfT = reinterpret_cast<T*>(vArr);
		return arrOfT;
	}

	int sizeOfTArr(int size)
	{
		return size * sizeof(T);
	}

	T* copy()
	{
		T* Tarr = changingPointerToT();
		T* Copy = new T[vSize];

		for (int i = 0; i < vSize; ++i)
		{
			Copy[i] = Tarr[i];
		}
		return Copy;
	}

public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
	typedef T value_type;

	Vector()
		:
		vSize(0),
		vCapacity(1),
		vArr(new char[sizeOfTArr(1)])
	{

	}

	Vector(int amount, const T& defaultValue = T())
		:
		vSize(amount),
		vCapacity(amount + 1),
		vArr(new char[sizeOfTArr(amount + 1)])
	{
		T* Tarr = changingPointerToT();
		for (int i = 0; i < vSize; ++i)
		{
			//Tarr[i] = defaultValue; here the constructor of type T is called with default value for a specific memory location
			new(Tarr + i) T(defaultValue);
		}
	}

	Vector(const Vector& v)
		:
		vSize(v.size()),
		vCapacity(v.size() + 1),
		vArr(new char[sizeOfTArr(v.size() + 1)])
	{
		T* Tarr = changingPointerToT();
		for (int i = 0; i < vSize; ++i)
		{
			//Tarr[i] = v[i]; here the constructor of type T is called with v[i]'s value for a specific memory location
			new(Tarr + i) T(v[i]);
		}
	}

	template<typename Iter>
	Vector(Iter first, Iter last)
		:
		vSize(std::abs(last - first)),
		vCapacity(std::abs(last - first) + 1),
		vArr(new char[sizeOfTArr(std::abs(last - first) + 1)])
	{
		T* Tarr = changingPointerToT();
		int index = 0;
		while (first != last)
		{
			//Tarr[index] = *first; here the constructor of type T is called with *first value for a specific memory location
			new(Tarr + index) T(*first);
			++first;
			++index;
		}
	}

	Vector& operator =(const Vector& v)
	{
		vSize = v.size();
		
		if (vCapacity <= v.size())
		{
			clear();
			vSize = v.size();
			vCapacity = vSize + 1;
			vArr = new char[sizeOfTArr(vCapacity)];
		}

		T* Tarr = changingPointerToT();

		for (int i = 0; i < vSize; ++i)
		{
			//Tarr[i] = v[i]; here the constructor of type T is called with v[i]'s value for a specific memory location
			new(Tarr + i) T(v[i]);
		}
		return *this;
	}

	~Vector()
	{
		clear();
	}

	template<typename Iter>
	void assign(Iter first, Iter second)
	{
		int distance = std::abs(second - first);
		if(distance >= vCapacity)
		{
			clear();

			vCapacity = distance + 1;
			vArr = new char[sizeOfTArr(vCapacity)];
			T* Tarr = changingPointerToT();

			for (int i = 0; i < distance; ++i)
			{
				//Tarr[index] = *first; here the constructor of type T is called with *first value for a specific memory location
				new(Tarr + i) T(*first);
				++first;
			}
		}
		else
		{
			T* Tarr = changingPointerToT();
			for (int i = 0; i < distance; ++i)
			{
				if (i < vSize)
				{
					Tarr[i] = *first;
				}
				else
				{
					new(Tarr + i) T(*first);
				}
				++first;
			}
		}
		vSize = distance;
	}
	void assign(int amount, const T& defaultValue = T())
	{
		resize(0);
		resize(amount, defaultValue);
	}

	T& at(int index)
	{
		if (index < 0 || index >= vSize)
		{
			throw std::out_of_range("Out of range. No element with such index");
		}
		T* Tarr = changingPointerToT();
		return Tarr[index];
	}
	T& operator[](int index)
	{
		T* Tarr = changingPointerToT();
		return Tarr[index];
	}
	T& front()
	{
		T* Tarr = changingPointerToT();
		return *Tarr;
	}
	T& back()
	{
		T* Tarr = changingPointerToT();
		return *(Tarr + vSize - 1);
	}
	const T& at(int index) const
	{
		if (index < 0 || index >= vSize)
		{
			throw std::out_of_range("Out of range. No element with such index");
		}
		T* Tarr = changingPointerToT();
		return Tarr[index];
	}
	const T& operator[](int index) const
	{
		const T* Tarr = changingPointerToT();
		return Tarr[index];
	}
	const T& front() const
	{
		T* Tarr = changingPointerToT();
		return *Tarr;
	}
	const T& back() const
	{
		T* Tarr = changingPointerToT();
		return *(Tarr + vSize - 1);
	}

	T* data()
	{
		T* Tarr = changingPointerToT();
		return &Tarr;
	}
	const T* data() const
	{
		T* Tarr = changingPointerToT();
		return &Tarr;
	}

	int size() const
	{
		return vSize;
	}
	int capacity() const
	{
		return vCapacity;
	}
	bool empty() const
	{
		return vSize == 0;
	}
	void clear()
	{
		T* Tarr = changingPointerToT();
		for (int i = 0; i < vSize; ++i)
		{
			Tarr->~T();
		}
		delete[] vArr;
	}
	void reserve(int amount)
	{
		T* Copy = copy();
		vCapacity += amount;
		clear();
		vArr = new char[sizeOfTArr(vCapacity)];
		T* Tarr = changingPointerToT();

		for (int i = 0; i < vSize; ++i)
		{
			//Tarr[i] = Copy[i];
			new(Tarr + i) T(Copy[i]);
		}

		delete[] Copy;
	}
	void resize(int size, const T& defaultValue = T())
	{
		if (vSize < size)
		{
			for (int i = vSize; i < size; ++i)
			{
				push_back(defaultValue);
			}
		}
		vSize = size;
	}
	void shrink_to_fit()
	{
		Vector(*this).swap(*this);
	}

	void pop_back()
	{
		--vSize;
	}
	void push_back(const T& element)
	{
		normalizeCapacity(element);
		T* Tarr = changingPointerToT();
		(Tarr + vSize)->~T();
		new(Tarr + vSize) T(element);
		++vSize;
	}
	template<typename Iter>
	Iter insert(Iter position, const T& element)
	{
		int distance = std::abs(position - this->begin());
		push_back(element);

		Iter positionSaver = this->begin() + distance;
		Iter it = this->end();
		--it;

		int index = vSize - 1;
			
		T* Tarr = changingPointerToT();
		while (it != positionSaver)
		{
			Tarr[index] = Tarr[index - 1];
			--index;
			--it;
		}
		Tarr[index] = element;
		
		return positionSaver;
	}
	template<typename Iter>
	Iter erase(Iter position)
	{
		int distance = std::abs(position - this->begin());

		T* Tarr = changingPointerToT();
		
		for (int i = distance; i < vSize - 1; ++i)
		{
			Tarr[i] = Tarr[i + 1];
		}

		pop_back();
		return position;
	}
	void swap(Vector& v)
	{
		std::swap(vSize, v.vSize);
		std::swap(vCapacity, v.vCapacity);
		std::swap(vArr, v.vArr);
	}

	iterator begin()
	{
		//return const_cast<T&>(static_cast<const Vector*>(this)->begin());
		T* Tarr = changingPointerToT();
		return Tarr;
	}
	const_iterator begin() const
	{
		return cbegin();
	}
	const_iterator cbegin() const
	{
		T* Tarr = changingPointerToT();
		return Tarr;
	}
	reverse_iterator rbegin()
	{
		return std::make_reverse_iterator(end());
	}
	const_reverse_iterator rbegin() const
	{
		return crbegin();
	}
	const_reverse_iterator crbegin() const
	{
		return std::make_reverse_iterator(end());
	}
	iterator end()
	{
		//return const_cast<T&>(static_cast<const Vector*>(this)->end());
		T* Tarr = changingPointerToT();
		return Tarr + vSize;
	}
	const_iterator end() const
	{
		return cend();
	}
	const_iterator cend() const
	{
		T* Tarr = changingPointerToT();
		return Tarr + vSize;
	}
	reverse_iterator rend()
	{
		return std::make_reverse_iterator(begin());
	}
	const_reverse_iterator rend() const
	{
		return crend();
	}
	const_reverse_iterator crend() const
	{
		return std::make_reverse_iterator(begin());
	}
};
