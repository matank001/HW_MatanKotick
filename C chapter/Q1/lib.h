#include <stdio.h>
#include <stdlib.h>

// ---------------------------------------------------------------------------------  PART 1

typedef struct node{
	int data;
	struct node* next;
	struct node* perv;
}node;

node* get_perv_node(node* n);
node* get_next_node(node* n);
int get_node_data(node* n);

typedef struct list{
	int sum;
	int size;
	struct node* first;
	struct node* last;
}list;

int get_list_size(list lst);
double get_list_avg(list lst);
node* get_first_node(list lst);
node* get_last_node(list lst);

node* create_node_by_value(int val); //create dynamic node with int data
void destroy_lst(list lst); // delete list content

list create_lst();

void add_node(list* lst, node* new_node);
void delete_node(list* lst, node* nd);

// ---------------------------------------------------------------------------------  PART 2

typedef struct queue{
	list lst;
}queue;

queue create_queue();
void destroy_queue(queue* que);
void add_queue(queue* que, int num);
int pop(queue* que);
int get_queue_length(queue que);
int get_queue_first(queue que);
