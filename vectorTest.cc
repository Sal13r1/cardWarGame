/**
 * 	Silne Veras
 * 	Aug 2024
 * 	This is my last ditch effort at getting this to work on my mac. This is a from scratch recreation of my Vector program before I throw in the towel and whine to Krystal.
 */

#include <iostream>
#include "vector.hh"
#include "catch2/catch_amalgamated.hpp"
#include "meaMath.hh"
TEST_CASE("default vector ctor")
{
	Vector<int> v;
	REQUIRE(v.Size() == 0);
	REQUIRE(v.Capacity() == 0);
}

TEST_CASE("array ctor")
{
	int array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};	

	Vector<int> v(array1, 9);
	REQUIRE(v.Size() == 9);
	REQUIRE(v.front() == 1);
	REQUIRE(v.back() == 9);
}

TEST_CASE("pushBack")
{
	int array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};	
	Vector<int> v(array1, 9);
	REQUIRE(v.Size() == 9);
	REQUIRE(v.front() == 1);
	REQUIRE(v.back() == 9);
	v.pushBack(122);
	REQUIRE(v.back() == 122);
	REQUIRE(v.Size() == 10);
}

TEST_CASE("pushFront")
{
	int array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};	
	Vector<int> v(array1, 9);
	REQUIRE(v.back() == 9);
	v.pushFront(132);
	REQUIRE(v.front() == 132);;
	REQUIRE(v.Capacity() == 10);
}

TEST_CASE("reserve")
{
	int array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	Vector<int> v(array1, 9);
	REQUIRE(v.back() == 9);
	REQUIRE(v.reserve(4) == false);
	REQUIRE(v.Capacity() == 9);
	REQUIRE(v.front() == 1);
	REQUIRE(v.back() == 9);
	REQUIRE(v.reserve(100) == true);
	REQUIRE(v.Capacity() == 100);
	REQUIRE(v.back() == 9);
}

TEST_CASE("shrinkToFit")
{
	int array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	Vector<int> v(array1, 9);
	REQUIRE(v.back() == 9);
	v.reserve(100);
	REQUIRE(v.Capacity() == 100);
	REQUIRE(v.back() == 9);
	v.shrinkToFit();
	REQUIRE(v.Capacity() == 9);
}

TEST_CASE("popFront")
{
	int array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	Vector<int> v(array1, 9);
	REQUIRE(v.popFront() == 1);
	REQUIRE(v.front() == 2);
	REQUIRE(v.Size() == 8);
}

TEST_CASE("popBack()")
{
	int array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	Vector<int> v(array1, 9);
	REQUIRE(v.popBack() == 9);
	REQUIRE(v.back() == 8);
	REQUIRE(v.Size() == 8);
}

TEST_CASE("At()")
{
	int array1[] = {1,2,3,4,5,6};
	Vector<int> v(array1, 6);
	REQUIRE(v.At(5) == 6);
}

TEST_CASE("OverloadedOperator ==")
{
	int array1[] = {1,2,3,4,5,6,7,8,9,10};
	int array2[] = {10,9,8,7,6,5,4,3,2,1};
	int array3[] = {11231, 23};

	Vector<int> v0(array1, 10);
	Vector<int> v1(array2, 10);
	Vector<int> v2(array1, 10);
	Vector<int> v3(array3, 2);


	REQUIRE((v0==v1) == false);
	REQUIRE((v0==v2) == true);
	REQUIRE((v0==v3) == false);
}

TEST_CASE("OverloadedOperator !=")
{
	int array1[] = {1,2,3,4,5,6,7,8,9,10};
	int array2[] = {10,9,8,7,6,5,4,3,2,1};
	int array3[] = {11231, 23};

	Vector<int> v0(array1, 10);
	Vector<int> v1(array2, 10);
	Vector<int> v2(array1, 10);
	Vector<int> v3(array3, 2);

	REQUIRE((v0!=v1) == true);
	REQUIRE((v0!=v2) == false);
	REQUIRE((v0!=v3) == true);
}

TEST_CASE("OverloadedOperator []")
{
	int array1[] = {1,2,3,4,5,6,7,8,9,10};

	Vector<int> v0(array1, 10);

	v0[0] = 2;
	REQUIRE(v0[0] == 2);
	v0[9] = 123;
	REQUIRE(v0[9] == 123);
}

TEST_CASE("Range-Based For-Loop")
{
	int array1[] = {1,2,3,4,5};

	Vector<int> v(array1, 5);

	REQUIRE(*v.begin() == 1);
	REQUIRE(*(v.end() - 1) == 5);

	for (int* it = v.begin(); it <= (v.end() - 1); it++)
	{
		*it += 5;
	}

	std::cout << std::endl;
	REQUIRE(*v.begin() == 6);
	REQUIRE(*(v.end() - 1) == 10);

	for(int& t : v)
	{
		t += 5;
	}

	REQUIRE(*v.begin() == 11);
	REQUIRE(*(v.end() - 1) == 15);
}

TEST_CASE("Const")
{
	int array[] = {1,2,3,4,5};

	const Vector<int> v(array, 5);

	REQUIRE(*v.begin() == 1);
	REQUIRE(*(v.end() - 1) == 5);
	REQUIRE(v.At(0) == 1);

	int array1[] = {5,4,3,4,5};

	Vector<int> v1(array1, 5);
	Vector<int> v2(array, 5);

	REQUIRE(v!=v1);
	REQUIRE(v==v2);
}

TEST_CASE("shuffleVector()")
{
	int array[] = {1,2,3,4,5,6,7,8,9};

	Vector<int> v(array, 9);

	REQUIRE(v.front() == 1);
	REQUIRE(v.back() == 9);

	shuffleVector(v);
	v.print();
	std::cout << "MeaMath Above | Vector Shuffle() Below" << std::endl;
	v.shuffle();
	v.print();
}