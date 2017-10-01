#include "Bag.h"



Bag::Bag()
{
}

Bag::Bag(size_type init_capacity)
{
	data = new value_type[init_capacity];
	capacity = init_capacity;
	used = 0;
}

Bag::Bag(const Bag& source)
{
	data = new value_type[source.capacity];
	capacity = source.capacity;
	used = source.used;
	copy(source.data, source.data + used, data);
}

Bag::~Bag()
{
	delete[] data; 
}

void Bag::insert(const value_type& entry)	// insert a new number in the bag
{
	if (used == capacity)
		reserve(used + 1);
	data[used++] = entry;
}

void Bag::reserve(size_type new_capacity)
{
	value_type* larger_array;
	if (new_capacity == capacity)
		return;
	if (new_capacity < used)
		new_capacity = used;

	larger_array = new value_type[new_capacity];
	copy(data, data + used, larger_array);
	delete[] data;
	data = larger_array;
	capacity = new_capacity;
}

bool Bag::erase_one(const value_type& target)
{
	size_type index = 0;
	while ((index < used) && (data[index] != target))
		++index;
	if (index == used)
		return false;
	--used;
	data[index] = data[used];
	return true;
}

void Bag::remove()
{

}

void Bag::operator=(const Bag& source)
{
	value_type* new_data;
	if (this == &source)
		return;
	if (capacity != source.capacity)
	{
		new_data = new value_type[source.capacity];
		delete[] data;
		data = new_data;
		capacity = source.capacity;
	}
	used = source.used;
	copy(source.data, source.data + used, data);
}

void Bag::operator+=(const Bag& addend)
{
	if (used + addend.used > capacity)
		reserve(used + addend.used);
	copy(addend.data, addend.data + addend.used, data + used);
	used += addend.used;
}


Bag operator+(const Bag& b1, const Bag& b2)
{
	Bag answer(b1.size() + b2.size());
	answer += b1;
	answer += b2;
	return answer;
} 