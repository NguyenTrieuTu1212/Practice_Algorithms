#include <iostream>
using namespace std;




class Node {
public:
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};



class LinkedList {
public:
	Node* head;
	LinkedList() {
		head = NULL;
	}

	void InsertBeforeNode(int data) {
		Node* newNode = new Node(data);
		newNode->next = head;
		head = newNode;
	}

	void InsertAfterNode(int data) {
		Node* newNode = new Node(data);
		if (head == NULL) head = newNode;
		else {
			Node* current = head;
			while (current->next != NULL) current = current->next;
			current->next = newNode;
		}
	}



	// Wrong way

	//void DeleteNode(int nodeNeedDelete) {

	//	while (head != NULL && head->data == nodeNeedDelete)
	//	{
	//		head = head->next;
	//	}
	//	if (head == NULL) return;
	//	
	//	Node* current = head;
	//	// fake node
	//	Node* prev = new Node(-1);
	//	while (current != NULL) {
	//		if (current->data == nodeNeedDelete) {
	//			prev->next = current->next;
	//		}
	//		prev = current;
	//		current = current->next;
	//	}

	//}

	void DeleteNode(int nodeNeedDelete) {

		while (head != NULL && head->data == nodeNeedDelete) {
			head = head->next;
		}
		if (head == NULL) return;
		Node* currentNode = head;
		Node* prev = currentNode;

		while (currentNode != NULL) {

			if (currentNode->data == nodeNeedDelete) prev->next = currentNode->next;
			else prev = currentNode;
			currentNode = currentNode->next;
		}
	}


	void InsertNodeBeforeNode(int nodeData, int newNodeData) {

		Node* current = head;
		//fake node
		Node* prev = new Node(-1);
		if (current->data == nodeData) InsertBeforeNode(newNodeData);
		while (current != NULL) {

			if (current->data == nodeData) {
				Node* newNode = new Node(newNodeData);
				prev->next = newNode;
				newNode->next = current;
			}
			prev = current;
			current = current->next;
		}
	}


	void InsertNodeAfterNode(int node, int newNodeData) {
		Node* current = head;
		while (current != NULL) {

			if (current->data == node) {
				Node* ptr = current->next;
				Node* newNode = new Node(newNodeData);
				current->next = newNode;
				newNode->next = ptr;
			}
			current = current->next;
		}
	}

	void DisplayLinkedList() {
		for (Node* ptr = head; ptr; ptr = ptr->next) {
			cout << ptr->data << "->";
		}
		cout << "NULL" << endl;
	}
};




void main() {

	LinkedList l = LinkedList();
	l.InsertAfterNode(1);
	l.InsertAfterNode(2);
	l.InsertAfterNode(2);
	l.InsertAfterNode(1);
	l.DisplayLinkedList();
	l.DeleteNode(2);
	l.DisplayLinkedList();
	return;
}