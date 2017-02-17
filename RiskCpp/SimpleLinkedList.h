#pragma once

struct Node {
	int name;
	Node *next;
};

class SimpleLinkedList
{
	private:
		Node * head;
	public:
		void display(struct Node *p);
		int insertHead(struct Node **head, int value);
		int insertTail(struct Node **head, int value);
		bool findCircular(Node *head);
		SimpleLinkedList();
		~SimpleLinkedList();
};

