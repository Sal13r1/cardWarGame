/**
 * Silne Veras
 * This is my helper file for some home grown functions
 */
#pragma once

#include <random>
#include "vector.hh"

int roll(int nSides);
int roll(int nDice, int nSides);
int roll(int nDice, int nSides, int mod);
int rollDice(char* diceStream); // Need to implement

template<typename T, size_t N>
void shuffleArray(T (&array)[N]);

/**
 * This seeds ands returns a reference to a mersenne twister engine. Depending on if random devices are truly random
 * if not, this will seed based on time. 
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
 * This is the Fisher-Yates algorithm, Wikipedia says this is the modern algorithm for randomizing arrays.
 * 
 * This is a randomization algorithm that swaps the current index with the last index not yet swapped. Range-- each loop. God bless Templates
 */
template<typename T, size_t N>
void shuffleArray(T (&array)[N]) {
	for (int i = (N - 1); i > 0; --i) {
		int j = roll(1, i + 1) - 1;
		T tempI = array[i];
		array[i] = array[j];
		array[j] = tempI;
	}
}

int roll(int nSides) {
	if (nSides < 1) return -1;
	std::uniform_int_distribution<> dist(1, nSides);
	int n = dist(rng());
	return n;
}

/**
 * This function randomly rolls for dice and returns the result.
 *
 * nDice - The number of dice to roll
 * nSides - The number of sides each die has.
 *
 * returns result - The sum of all the rolls.
 */
int roll(int nDice, int nSides) {
	if (nDice < 1 || nSides < 1) return -1;

	std::uniform_int_distribution<> dist(1, nSides);
	int total = 0;

	for (int i = 0; i < nDice; ++i) {
		int n = dist(rng());
		total += n;
	}

	return total;
}

/**
 * This function randomly rolls for dice and returns the result.
 *
 * nDice - The number of dice to roll
 * nSides - The number of sides each die has.
 * mod - The number to modify the final roll by.
 *
 * returns result - The sum of all the rolls plus the modifier.
 */
int roll(int nDice, int nSides, int mod) 
{
	if (nDice < 1 || nSides < 1) return -1;

	std::uniform_int_distribution<> dist(1, nSides);
	int total = 0;

	for (int i = 0; i < nDice; ++i) {
		int n = dist(rng());
		total += n;
	}

	return total+mod;
}

/**
 * shuffleVector is designed to shuffle up vectors from my vector.cc
 * Big O(n)
 */
template<typename T>
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