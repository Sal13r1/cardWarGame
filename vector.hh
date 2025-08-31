/**
 * 	Silne Veras
 * 	Aug 2024
 * 	This is my implementation of a vector.
 */

#pragma once
#include <random>
#include <iostream>
#include <type_traits>

template<typename T>
class Vector
{
private:
	T* array = NULL;
	size_t size = 0;
	size_t capacity = 0;

private:
	/**
	 * copyArray() will copy an already existing array to a new array with the current capacity
	 * 
	 * @param void:  This method  involves no parameters. 
	 * 
	 * Big Oh: O(n)
	 */
	void copyArray(void)
	{
		T* newArray = new T[capacity];
		for(int i = 0; i < size; ++i)
		{
			newArray[i] = array[i];
		}

		delete [] array;
		array = newArray;
	}

	/**
	 * copyArrayPrepend() will copy the array while assigning the space to the 'front' of the array
	 * 
	 * @param void: This method takes no paramters.
	 * 
	 * Big Oh: O(n)
	 */
	void copyArrayPrepend(void)
	{
		T* newArray = new T[capacity];
		for (int i = 0; i < size; ++i)
		{
			newArray[i + 1] = array[i];
		}

		delete [] array;
		array = newArray;
	}

public:
	/**
	 * ~Vector() is my default ctor
	 * 
	 * Big Oh: O(n)
	 */
	Vector()
	{
	}
	/**
	 * ~Vector() is my default dtor
	 * 
	 * Big Oh: O(n)
	 */
	~Vector()
	{
		for (int i = 0; i < capacity; ++i)
		{
			array[i] = 0;
		}

		size = 0;
		capacity = 0;

		delete [] array;
	}

	/**
	 * Vector(T*, int) is an alternatie ctor that will use an array and the size of the array to create a new vector
	 * 
	 * @param userArray: This is an array of Type T that will be used to create the vector
	 * 
	 * @param arraySize This is the number of elements of the array
	 * 
	 * Big Oh: O(n)
	 */
	Vector(const T* userArray, const int arraySize)
	{
		size = arraySize;
		capacity = arraySize;
		array = new T[capacity];

		for (int i = 0; i < arraySize; i++)
		{
			array[i] = userArray[i];
		}

		return;
	}

	/**
	 * Size() will return the size of the vector
	 * 
	 * @return the value of the size of the vector
	 * 
	 * Big Oh: O(1)
	 */
	size_t Size() const
	{
		return size;
	}

	/** Capacity() checks the capacity of the Vector 
	 * 
	 * return size_t will return the capacity value of the vector. 
	 * 
	 * Big Oh: O(1)
	 */
	size_t Capacity() const
	{
		return capacity;
	}

	/**
	 * front() will return the first elementi n the array.
	 * 
	 * @return size_t will return a reference to the first element of an array.
	 * 
	 * Big Oh: O(1)
	 */
	T& front()
	{
		return array[0];

	}

	/**
	 * constfront() will return the first elementi n the array.
	 * 
	 * @return size_t will return a reference to the first element of an array as const.
	 * 
	 * Big Oh: O(1)
	 */
	const T& front() const
	{
		return array[0];
	}

	/**
	 * back() will check and return the last element of the array
	 * 
	 * @return T will return a reference to the last element of the array
	 * 
	 * Big Oh: O(1)
	 */ 
	T& back()
	{
		return array[(size - 1)];
	}

	/**
	 * back() will check and return the last element of the array
	 * 
	 * @return T will return a reference to the last element of the array as const
	 * 
	 * Big Oh: O(1)
	 */ 
	const T& back() const
	{
		return array[(size - 1)];
	}

	/**
	 * pushBack() will append data to the array
	 * 
	 * @param T data the new element of the array to be added.
	 * 
	 * return void
	 * 
	 * Big Oh: O(n)
	 */
	void pushBack(const T data)
	{
		if ((size + 1) > capacity)
		{
			capacity++;
		}

		copyArray();
		array[size] = data;
		size++;
	}

/**
	 * pushFront() will prepend data to the array
	 * 
	 * @param T data the new element of the array to be added.
	 * 
	 * return void
	 * 
	 * Big Oh: O(n)
	 */
	 void pushFront(const T data)
	{
		capacity++;
		copyArrayPrepend();
		array[0] = data;
		size++;
	}

	/**
	 * reserve() expands the capacity of the vector to size of newCapacity
	 * 
	 * @param newCapacity this argument is what the new capacity of the vector will be adjusted to
	 * 
	 * @return this method will return a boolean true or false depending on if the newCapacity is valid
	 * 
	 * Big Oh: O(n)
	 */ 
	bool reserve(const int newCapacity)
	{
		if (newCapacity < size)
		{
			return false;
		}

		capacity = newCapacity;

		copyArray();
		return true;
	}

	/**
	 * shrinkToFit will shrink the capacity to fit the size.
	 * 
	 * @return void
	 * 
	 * Big Oh: O(n)
	 */ 
	void shrinkToFit()
	{
		capacity = size;
		copyArray();
	}

	/**
	 * popFront() will remove the first element of the array and return it.
	 * 
	 * @return Type T first element of the array
	 * 
	 * Big Oh: O(n)
	 */
	T popFront(void)
	{
		T element = front();

		T* newArray = new T[capacity];
		size--;
		for (int i = 0; i < size; ++i)
		{
			newArray[i] = array[i+1];
		}

		delete [] array;
		array = newArray;
		return element;
	}

	/**
	 * popBack() will remove the last element of the array and return it.
	 * 
	 * @return Type T last element of the array
	 * 
	 * Big Oh:O(1)
	 */
	T popBack(void)
	{
		T element = back();
		size--;
		array[size] = 0;


		return element;
	}

	/**
	 * at() will return the element of the array at 'index' of the array
	 * 
	 * Big Oh: O(1)
	 */
	T& At(const int index)
	{
		return array[index];
	}
	/**
	 * at() will return the element of the array at 'index' of the array
	 * This is the const version of this method
	 *  
	 * Big Oh: O(1)
	 */
	const T& At(const int index) const
	{
		return array[index];
	}

	/**
	 * This is an overloaded operator ==() that will take a reference to another Vector and compare the arrays to nsure they are equal
	 * 
	 * @param other This is a reference to the other Vector.
	 * return returns true or false. 
	 *
	 * Big Oh: O(n)
	 */ 
	const bool operator==(const Vector& other) const
	{
		bool bl = true;
		if (this->size != other.size)
		{
			return false;
		}

		for (int i = 0; i < size; ++i)
		{
			if (array[i] == other.array[i])
			{
				continue;
			} else bl = false;
		}

		return bl;
	}

	/**
	 * This is an overloaded operator !=() that will take a reference to another Vector and compare the arrays to ensure the arrays are not equal
	 * 
	 * @param other This is a reference to the other Vector.
	 * return returns true or false. 
	 *
	 * Big Oh: O(n)
	 */
	const bool operator!=(const Vector& other) const
	{
		return !operator==(other);
	}


	/**
	 * This is an overloaded operator[] to make editing the arrays of the vector simpler.
	 * 
	 * @param index - The index we wish to change
	 * @return the nth index of the array
	 */
	T& operator[](int index)
	{
		return array[index];
	}

	/**
	 * This is an overloaded operator[] to make editing the arrays of the vector simpler.
	 * 
	 * @param index - The index we wish to change
	 * @return the nth index of the array
	 */
	const T& operator[](int index) const
	{
		return array[index];
	}

	/**
	 * begin() will return the beginning of a vector of T*
	 * 
	 * @return returns the beginning element of array
	 */
	T* begin()
	{
		return &array[0];
	}

	/**
	 * const version of begin() will return the beginning of a vector of T*
	 * 
	 * @return returns the beginning element of array
	 */
	const T* begin() const
	{
		return &array[0];
	}

	/**
	 * end() will return past the last element of a vector of T*
	 * 
	 * @return returns an iterator that is past the last element of array
	 */
	T* end()
	{ 
		return &array[size];
	}

	/**
	 * const version of end() will return past the last element of a vector of T*
	 * 
	 * @return returns an iterator that is past the last element of array
	 */
	const T* end() const
	{ 
		return &array[size];
	}


	/**
	 * This seeds ands returns a reference to a mersenne twister engine. Depending on if random devices are truly random
	 * if not, this will seed based on time. This is only used to seed the RNG for shuffling Vectors.
	 */
	std::mt19937& rng() {
		static std::random_device rd;
		static std::mt19937 gen;
		static bool seeded = false;

		if (!seeded) {
			if (rd.entropy() > 0) {
				gen.seed(rd());
			} else {
				gen.seed(time(NULL));
			}
			seeded = true;
		}
		return gen;
	}

	/**
	 * This shuffles the vector
	 * return none
	 * Big O(n)
	 */
	void shuffleVector(Vector<T>& v)
	{
		int size = v.Size();
		for (int i = (size - 1); i > 0; --i)
		{
			std::uniform_int_distribution<int> dist(0, i);
			int j = dist(rng());            
			T temp = v[i];
			v[i] = v[j];
			v[j] = temp;
		}
	}

	/**
	 * This calls my shuffleVector method.
	 * return Void
	 * Big O(1) or Big(n)
	 */
	void shuffle()
	{
		shuffleVector(*this);
	}

	/**
	 * print() will output all elements in the vector to console
	 * 
	 * @return void
	 * 
	 * Big Oh: O(n)
	 */
	void print() const
	{
	    std::cout << "[";

	    for (int i = 0; i < size; ++i)
	    {
	        std::cout << array[i];
	        if (i < size - 1)  // Don't add comma after last element
	        {
	            std::cout << ", ";
	        }
	    }
	    
	    std::cout << "]" << std::endl;
	}
};
