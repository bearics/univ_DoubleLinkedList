#ifndef DOUBLE_LINKED_LIST_H  
#define DOUBLE_LINKED_LIST_H
#include <cstdlib>

class DoubleLinkedList
{
public:
	typedef double value_type;
	DoubleLinkedList();
	DoubleLinkedList(const value_type& init_data, DoubleLinkedList* init_next_link, DoubleLinkedList* init_prev_link);
	~DoubleLinkedList();

	void set_data(const value_type& new_data);
	void set_next_link(DoubleLinkedList* new_link);
	void set_prev_link(DoubleLinkedList* new_link);
	value_type data() const;
	const DoubleLinkedList* next_link() const;
	DoubleLinkedList* next_link();
	const DoubleLinkedList* prev_link() const;
	DoubleLinkedList* prev_link();
private:
	value_type data_field;
	DoubleLinkedList* next_field;
	DoubleLinkedList* prev_field;
};

size_t list_length(const DoubleLinkedList* head_ptr);
void list_head_insert(DoubleLinkedList*& head_ptr, const DoubleLinkedList::value_type& entry);
void list_insert(DoubleLinkedList* previous_ptr, const DoubleLinkedList::value_type& entry);
DoubleLinkedList* list_search(DoubleLinkedList* head_ptr, const DoubleLinkedList::value_type& target);
const DoubleLinkedList* list_search(const DoubleLinkedList* head_ptr, const DoubleLinkedList::value_type& target);
DoubleLinkedList* list_locate(DoubleLinkedList* head_ptr, size_t position);
const DoubleLinkedList* list_locate(const DoubleLinkedList* head_ptr, size_t position);
void list_head_remove(DoubleLinkedList*& head_ptr);
void list_remove(DoubleLinkedList* previous_ptr);
void list_clear(DoubleLinkedList*& head_ptr);
void list_copy(const DoubleLinkedList* source_ptr, DoubleLinkedList*& head_ptr, DoubleLinkedList*& tail_ptr);

#endif
