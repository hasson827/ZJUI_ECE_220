typedef struct node {
	int numerator;
	int denominator;
	struct node* next;
} node;

node * farey_seq(int n);
void print_list(node * head, int n);
void delete_list(node * head);
