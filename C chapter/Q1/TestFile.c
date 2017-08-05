#include "lib.h"
#include <stdio.h>

void main(){
	list lst = create_lst();
	node* n1 = create_node_by_value(8);
	node* n2 = create_node_by_value(2);
	node* n3 = create_node_by_value(5);
	node* n4 = create_node_by_value(4);

	add_node(&lst, n1); add_node(&lst, n2); add_node(&lst, n3); add_node(&lst, n4);
	delete_node(&lst, n3);
	printf("%f\n", get_list_avg(lst));
	printf("%d\n", get_node_data(get_first_node(lst)));
	destroy_lst(lst);

	queue q = create_queue();
	add_queue(&q, 2); add_queue(&q, 5); add_queue(&q, 7); add_queue(&q, 6);
	printf("%d\n", get_queue_first(q));
	printf("%d\n", pop(&q));
	printf("currrent length is: %d\n", get_queue_length(q));
	add_queue(&q, 1000);
	
	while (get_queue_length(q) > 0){
		printf("now poping %d\n", pop(&q));
	}

	system("PAUSE");
}