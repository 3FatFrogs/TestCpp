#pragma once

struct node
{
	int info;
	struct node *next;
}*start;


class LList
{
	public:
		node* create_node(int);
		void insert_begin();
		void insert_pos();
		void insert_last();
		void delete_pos();
		void sort();
		void update();
		void reverse();
		void display();
		bool findCircular(node *head);

		LList();
		virtual ~LList();
};

