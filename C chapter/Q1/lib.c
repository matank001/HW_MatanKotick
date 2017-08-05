#include "lib.h"

//------------------------------------------------------------------------- PART 1

list create_lst(){
	list new_lst;
	new_lst.sum = 0;
	new_lst.size = 0;
	new_lst.first = NULL;
	new_lst.last = NULL;
	return new_lst;
}

node* create_node_by_value(int val){
	node* new_node = (node*)(malloc(sizeof(node)));
	new_node->data = val;
	new_node->next = NULL;
	new_node->perv = NULL;
	return new_node;
}

void destroy_lst(list lst){

	if (lst.first == NULL){
		return;
	}

	node* curr = lst.first;
	node* next = curr->next;
	while (curr != NULL){
		free(curr);
		curr = next;
		if (curr != NULL){
			next = curr->next;
		}
	}
	//no need to set sum and size because after destroyed it shouldn't be used
}

node* get_perv_node(node* n){ return n->perv; }
node* get_next_node(node* n){ return n->next; }
int get_node_data(node* n){ return n->data; }

void add_node(list* lst, node* new_node){
	lst->size++;
	lst->sum += new_node->data;

	if (lst->first == NULL){
		lst->first = new_node;
		lst->last = new_node;
		return;
	}

	new_node->perv = lst->last;
	new_node->next = NULL;
	lst->last->next = new_node;
	lst->last = new_node;
}

void delete_node(list* lst, node* nd){
	lst->sum -= nd->data;
	lst->size--;

	if (lst->first == nd){ // first node case
		lst->first = lst->first->next;
		if (lst->first != NULL){
			lst->first->perv = NULL;
		}
		free(nd);
		return;
	}
	if (lst->last == nd){ // last node case
		lst->last = lst->last->perv;
		lst->last->next = NULL;
		free(nd);
		return;
	}
	//general case
	nd->perv->next = nd->next;
	nd->next->perv = nd->perv;
	free(nd);
}

int get_list_size(list lst){ return lst.size; }
double get_list_avg(list lst){ return (double)lst.sum / lst.size; }
node* get_first_node(list lst){ return lst.first; }
node* get_last_node(list lst){ return lst.last; }


//------------------------------------------------------------------------- PART 2

queue create_queue(){
	queue new_q;
	new_q.lst = create_lst();
}

void destroy_queue(queue que){
	destroy_lst(que.lst);
}
void add_queue(queue* que, int num){
	add_node(&(que->lst), create_node_by_value(num));
}
int pop(queue* que){
	int first_val = get_node_data(que->lst.first);
	delete_node(&(que->lst), que->lst.first);
	return first_val;
}
int get_queue_length(queue que){ return que.lst.size; }
int get_queue_first(queue que){ return get_node_data(que.lst.first); }