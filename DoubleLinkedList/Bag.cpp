#include <cassert>
#include <cstdlib>
#include <iostream>
#include "Bag.h"
#include "DoubleLinkedList.h"

Bag::Bag()
{
	head_ptr = NULL;
	many_nodes = 0;
}


Bag::Bag(string name)
{
	this->name = name;
}

Bag::Bag(const Bag& source)
{
	DoubleLinkedList *tail_ptr;

	list_copy(source.head_ptr, head_ptr, tail_ptr);
	many_nodes = source.many_nodes;
}

Bag::~Bag()
{
	list_clear(head_ptr);
	many_nodes = 0;
}

Bag::size_type Bag::count(const value_type& target) const
{
	size_type answer;
	const DoubleLinkedList *cursor;

	answer = 0;
	cursor = list_search(head_ptr, target);
	while (cursor != NULL)
	{
		++answer;
		cursor = cursor->next_link();
		cursor = list_search(cursor, target);
	}
	return answer;
}

bool Bag::erase_one(const value_type& target)
{
	DoubleLinkedList *target_ptr;

	target_ptr = list_search(head_ptr, target);
	if (target_ptr == NULL)
		return false;
	target_ptr->set_data(head_ptr->data());
	list_head_remove(head_ptr);
	--many_nodes;
	return true;
}


void Bag::show_content() const
{
	DoubleLinkedList *current_ptr = this->head_ptr;

	if (current_ptr == NULL) {
		cout << "No data in bag." << endl;
		return;
	}

	cout << "-------------------------*" << endl;
	cout << "  head_ptr : " << current_ptr << endl;
	cout << "-------------------------*" << endl;
	while (1)
	{ // print data list in bag
		cout << "address  : " << current_ptr << endl;
		cout << "prev_ptr : " << current_ptr->prev_link() << endl;
		cout << "data     : " << current_ptr->data() << endl;
		cout << "next_ptr : " << current_ptr->next_link() << endl;
		cout << "-------------------------*" << endl;
		if (current_ptr->next_link() == NULL)
			break;
		current_ptr = current_ptr->next_link();
	}

		
}

Bag::value_type Bag::grab() const
{
	size_type i;
	const DoubleLinkedList *cursor;

	assert(size() > 0);
	i = (rand() % size()) + 1;
	cursor = list_locate(head_ptr, i);
	return cursor->data();
}

void Bag::insert(const value_type& entry)
{
	list_head_insert(head_ptr, entry);
	++many_nodes;
}


void Bag::sort()
{
	DoubleLinkedList* tmp_ptr = head_ptr;
	value_type* ptr = new value_type[many_nodes];
	value_type temp = 0;
	for (int i = 0; i < many_nodes; i++)
	{
		ptr[i] = tmp_ptr->data();
		tmp_ptr = tmp_ptr->next_link();

	}
	for (int i = 0; i < many_nodes; i++)
	{
		for (int j = i + 1; j < many_nodes; j++)
		{
			if (ptr[j] >= ptr[i]) {
				temp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = temp;
			}
		}
	}
	list_clear(head_ptr);
	for (int i = 0; i < many_nodes; i++)
		list_head_insert(head_ptr, ptr[i]);
}

void Bag::operator +=(const Bag& addend)
{
	DoubleLinkedList *copy_head_ptr = head_ptr;
	DoubleLinkedList *copy_tail_ptr = NULL;
	if (copy_head_ptr != NULL){
		while (copy_head_ptr->next_link() != NULL)
			copy_head_ptr = copy_head_ptr->next_link();
	}
	if (addend.many_nodes > 0)
	{
		list_copy(addend.head_ptr, copy_head_ptr, copy_tail_ptr);
		copy_tail_ptr->set_next_link(head_ptr);
		head_ptr = copy_head_ptr;
		many_nodes += addend.many_nodes;
	}
}

void Bag::operator =(const Bag& source)
{
	DoubleLinkedList *tail_ptr;
	if (this == &source) {
		cout << "Already same." << endl;
		return;
	}
	list_clear(head_ptr);
	many_nodes = 0;
	list_copy(source.head_ptr, head_ptr, tail_ptr);

	many_nodes = source.many_nodes;
}

bool Bag::operator ==(const Bag& source)
{
	return this->head_ptr == source.head_ptr;
}

Bag operator +(const Bag& b1, const Bag& b2)
{
	Bag answer;
	answer += b1;
	answer += b2;
	return answer;
	
}