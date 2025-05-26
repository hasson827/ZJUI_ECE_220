#include <stdio.h>
#include <stdlib.h>
#include "farey_seq.h"

int main()
{
	int n;
	printf("Please enter n: ");
	scanf("%d", &n);
	node * head;
	head = farey_seq(n);
	if(head == NULL)
		printf("The linked list is empty");
	delete_list(head);
}

node * farey_seq(int n)
{
	if (n <= 0){return NULL;} // Handle invalid input

	// 当order为1时，初始化链表
	node* list_head = (node*)malloc(sizeof(node));
	if (list_head == NULL) {
		printf("Memory allocation failed\n");
		return NULL;
	} // 为链表头分配内存

	list_head->numerator = 0;
	list_head->denominator = 1;

	list_head->next = (node*)malloc(sizeof(node));
	if (list_head->next == NULL) {
		printf("Memory allocation failed\n");
		free(list_head);
		return NULL;
	} // 为链表的下一个节点分配内存

	list_head->next->numerator = 1;
	list_head->next->denominator = 1;
	list_head->next->next = NULL;

	// 如果n为1，直接返回链表
	if (n == 1){
		print_list(list_head, 1);
		return list_head;
	}

	// 对于n > 1的情况，使用Farey序列的递归定义
	print_list(list_head, 1);
	for (int i = 2; i <= n; i++){
		node* p1 = list_head; // p1指向链表的头节点
		while (p1 != NULL && p1->next != NULL){
			node* p2 = p1->next; // p2指向p1的下一个节点

			int a_num = p1->numerator;
			int c_den = p1->denominator;
			int b_num = p2->numerator;
			int d_den = p2->denominator;

			if (c_den + d_den <= i){
				// 计算新分数的分子和分母
				int new_numerator = a_num + b_num;
				int new_denominator = c_den + d_den;

				// 创建新节点
				node* new_node = (node*)malloc(sizeof(node));
				if (new_node == NULL) {
					printf("Memory allocation failed\n");
					delete_list(list_head);
					return NULL;
				} // 为新节点分配内存
				new_node->numerator = new_numerator;
				new_node->denominator = new_denominator;
				new_node->next = p2; // 将新节点插入到p1和p2之间

				p1->next = new_node; // 更新p1的next指针
				p1 = new_node; // 移动p1到新节点
			} else {
				p1 = p2; // 移动到下一个节点
			}
		}
		print_list(list_head, i); // 打印当前级别的链表
	}
	return list_head; // 返回链表头
}

void print_list(node * head, int n)
{
	if(head == NULL)
		return;	
	printf("level %d: ", n);
	while(head != NULL)
	{
		printf("%d/%d  ", head->numerator, head->denominator);
		head = head->next;
	}
	printf("\n");
}

void delete_list(node * head)
{
	node * temp;	
	while(head != NULL){
		temp = head->next;
		free(head);
		head = temp;
	}
}
