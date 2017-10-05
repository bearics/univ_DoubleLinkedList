#ifndef BAG_H  
#define BAG_H
#include <cstdlib>
#include <string>
#include "DoubleLinkedList.h"

using namespace std;



class Bag
{
public:
	typedef int value_type;
	typedef size_t size_type;
	Bag();
	Bag(string name);
	Bag(const Bag& source);
	~Bag();
	// MODIFICATION MEMBER FUNCTIONS
	bool erase_one(const value_type& target);
	void insert(const value_type& entry);
	void sort();
	void operator +=(const Bag& addend);
	void operator =(const Bag& source);
	bool operator ==(const Bag& source);
	// CONSTANT MEMBER FUNCTIONS
	void show_content() const;
	DoubleLinkedList *get_head_ptr() const { return head_ptr; }
	size_type size() const { return many_nodes; }
	size_type count(const value_type& target) const;
	value_type grab() const;
private:
	string name;
	DoubleLinkedList *head_ptr;       // List head pointer 
	size_type many_nodes; // Number of nodes on the list
};

Bag operator+(const Bag& b1, const Bag& b2);

#endif