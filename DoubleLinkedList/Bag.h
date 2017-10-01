#pragma once

#include <cstdlib>
#include <assert.h>

using namespace std;

typedef int value_type;
typedef size_t size_type;

class Bag
{
public:
	static const size_t CAPACITY = 20;
	Bag();
	Bag(size_type init_capacity);
	Bag(const Bag& source);
	~Bag();
	void insert(const value_type& entry);	// insert a new number in the bag
	void reserve(size_type new_capacity);
	bool erase_one(const value_type& target);
	void remove();	// Removes one copy of a number
	size_type size() const; // counts how many  intergers are in the bag
	size_type occurrences(value_type target) const;	// Counts how many copies of a number occur
	void operator=(const Bag& source);
	void operator+=(const Bag& addend);
private:
	value_type *data;
	size_type used;
	size_type capacity;

};

Bag operator+(const Bag& b1, const Bag& b2);