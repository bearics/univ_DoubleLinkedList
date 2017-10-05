#include "DoubleLinkedList.h"
#include <cassert> 
#include <iostream>
#include <cstdlib>

using namespace std;

DoubleLinkedList::DoubleLinkedList()
{

}

DoubleLinkedList::DoubleLinkedList(	const value_type& init_data = value_type() , DoubleLinkedList* init_next_link = NULL, DoubleLinkedList* init_prev_link = NULL)
{
	data_field = init_data;
	next_field = init_next_link;
	prev_field = init_prev_link;
}


DoubleLinkedList::~DoubleLinkedList()
{
}

void DoubleLinkedList::set_data(const value_type& new_data)
{
	data_field = new_data;
}

void DoubleLinkedList::set_next_link(DoubleLinkedList* new_link)
{
	next_field = new_link;
}

void DoubleLinkedList::set_prev_link(DoubleLinkedList* new_link)
{
	prev_field = new_link;
}

DoubleLinkedList::value_type DoubleLinkedList::data() const
{
	return data_field;
}

const DoubleLinkedList* DoubleLinkedList::next_link() const
{
	return next_field;
}

DoubleLinkedList* DoubleLinkedList::next_link()
{
	return next_field;
}

const DoubleLinkedList* DoubleLinkedList::prev_link() const
{
	return prev_field;
}

DoubleLinkedList* DoubleLinkedList::prev_link()
{
	return prev_field;
}

size_t list_length(const DoubleLinkedList* head_ptr)
{
	const DoubleLinkedList* cursor;
	size_t answer=0;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->next_link())
		++answer;
	return answer;
}

void list_head_insert(DoubleLinkedList*& head_ptr, const DoubleLinkedList::value_type& entry)
{
	if (head_ptr == NULL){
		head_ptr = new DoubleLinkedList(entry, head_ptr, NULL);
	}
	else {
		head_ptr = new DoubleLinkedList(entry, head_ptr, NULL);
		head_ptr->next_link()->set_prev_link(head_ptr);
	}
}

void list_insert(DoubleLinkedList* previous_ptr, const DoubleLinkedList::value_type& entry)
{
	DoubleLinkedList* insert_ptr;
	insert_ptr = new DoubleLinkedList(entry, previous_ptr->next_link(), previous_ptr);
	previous_ptr->set_next_link(insert_ptr);
	if (previous_ptr->next_link() == NULL) {
		insert_ptr->set_next_link(NULL);
		return;
	}
}

DoubleLinkedList* list_search(DoubleLinkedList* head_ptr, const DoubleLinkedList::value_type& target)
{
	DoubleLinkedList* cursor;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->next_link())
		if (target == cursor->data())
			return cursor;
	return NULL;
}

const DoubleLinkedList* list_search(const DoubleLinkedList* head_ptr, const DoubleLinkedList::value_type& target)
{
	const DoubleLinkedList* cursor;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->next_link())
		if (target == cursor->data())
			return cursor;
	return NULL;
}

DoubleLinkedList* list_locate(DoubleLinkedList* head_ptr, size_t position)
{
	DoubleLinkedList* cursor;
	size_t i;

	assert(0 < position);
	cursor = head_ptr;
	for (i = 1; (i < position) && (cursor != NULL); i++)
		cursor = cursor->next_link();
	return cursor;
}

const DoubleLinkedList* list_locate(const DoubleLinkedList* head_ptr, size_t position)
{
	const DoubleLinkedList* cursor;
	size_t i;

	assert(0 < position);
	cursor = head_ptr;
	for (i = 1; (i < position) && (cursor != NULL); i++)
		cursor = cursor->next_link();
	return cursor;
}

void list_head_remove(DoubleLinkedList*& head_ptr)
{
	DoubleLinkedList* remove_ptr;

	remove_ptr = head_ptr;
	head_ptr = head_ptr->next_link();
	delete remove_ptr;
}

void list_remove(DoubleLinkedList* previous_ptr)
{
	DoubleLinkedList* remove_ptr;

	remove_ptr = previous_ptr->next_link();
	previous_ptr->set_next_link(remove_ptr->next_link());
	delete remove_ptr;
}

void list_clear(DoubleLinkedList*& head_ptr)
{
	while (head_ptr != NULL)
		list_head_remove(head_ptr);
}

void list_copy(const DoubleLinkedList* source_ptr, DoubleLinkedList*& head_ptr, DoubleLinkedList*& tail_ptr)
{
	head_ptr = NULL;
	tail_ptr = NULL;
	if (source_ptr == NULL)
		return;
	list_head_insert(head_ptr, source_ptr->data());
	tail_ptr = head_ptr;
	source_ptr = source_ptr->next_link();
	while (source_ptr != NULL)
	{
		list_insert(tail_ptr, source_ptr->data());
		tail_ptr = tail_ptr->next_link();
		source_ptr = source_ptr->next_link();
	}
}

