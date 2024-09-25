#pragma once
#include <iostream>
using namespace std;
struct Node {
	int data;
	// more data
	Node* next;
};
class LL
{
private:
	Node* head;
	void print_LL();
	Node* create_node(int);
	void add_node(Node*);
public:
	LL() { head = NULL; };
	LL(int* a, int size);
	LL(const LL&);
	~LL();
	LL& operator = (const LL&);
	friend void operator<<(ostream &, LL&);
	LL& operator ! ();

	Node* findMid();
	Node* lastNth(int);
	friend LL operator+( LL&, LL&);
	
	/// reverse // done
	//// midpoint
	//// merge //
	/// lastNth_Node
	//// operator overload shift right or left
	/// !
	/// read from file
	/// /// out to file

};

