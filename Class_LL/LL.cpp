#include "LL.h"

LL::LL(int* a, int size)
{
	head = NULL;
	for (int i = 0; i < size; i++)
	{
		add_node(create_node(a[i]));
	}
}


LL::LL(const LL& A)
{
	head = NULL;
	if (A.head == NULL)
		return;

	Node* i;
	i = A.head;
	Node* p;
	Node* last = NULL;
	while (i != NULL)
	{
		p = new Node;
		//p->data = i->data; // more data to add?
		memcpy(p,i,sizeof(Node));
		//*p = *i; overload = operator 
		p->next = NULL;
		i = i->next;
		//add_node(p);
		if (head == NULL)
		{
			head = p;
			last = head;
		}
		else
		{
			last->next = p;
			last = last->next; // or = p
		}
	}
}



LL::~LL()
{
	Node* p;
	while (head != NULL)
	{
		p = head;
		head = head->next;
		delete p;
	}
}

Node* LL::create_node(int k)
{
	Node* p;
	p = new Node;
	p->data = k;
	p->next = NULL;
	return p;
}

void LL::add_node(Node* n)
{
	Node * p1, * p2;
	if (head == NULL)//check for empty list
	{
		head = n;
		return;
	}
	if (n->data < head->data)//check for first node
	{
		n->next = head;
		head = n;
		return;
	}
	//general case
	p1 = p2 = head;
	while (p2 != NULL)
	{
		if (n->data < p2->data)
		{
			n->next = p2;
			p1->next = n;
			return;
		}
		else
		{
			p1 = p2;
			p2 = p2->next;
		}
	}//while
	//last case (last node)
	n->next = p2;// p2 is NULL
	p1->next = n;
	
}

void LL::print_LL()
{
	Node* p;
	p = head;
	if (p == NULL)
	{
		cout << "Empty List \n";
		return;
	}
	while (p != NULL)
	{
		cout << p->data;
		if(p->next!=NULL)
			cout << "->";
		p = p->next;
	}
	cout << endl;
}

LL& LL::operator=(const LL&A)
{
	if (head != NULL)
		this->~LL();
	if (this == &A)
		return *this;

	
	if (A.head == NULL)
		return *this;

	Node* i;
	i = A.head;
	Node* p;
	Node* last=NULL;
	while (i != NULL)
	{
		p = new Node;
		//p->data = i->data; // more data to add?
		memcpy(p, i, sizeof(Node));
		//*p = *i; overload = operator 
		p->next = NULL;
		i = i->next;

		if (head == NULL)
		{
			head = p;
			last = head;
		}
		else
		{
			last->next =p;
			last = last->next; // or = p
		}
		//add_node(p);


	}


	return *this;
	
}

LL& LL::operator!()
{
	Node* p, * p1, * p2;
	p1 = p2 = NULL;
	p = head;
	while (p != NULL)
	{

		p2 = p->next;
		p->next = p1; // reversing....

		// safe to move pointers.
		p1 = p;
		p = p2;
	}
	head = p1;

	return *this;
}

Node* LL::findMid()
{
	Node* p1, * p2;
	p1 = p2 = head;

	if(head!=NULL)
	{
		while (p2 != NULL && p2->next != NULL)
		{
			p2 = p2->next->next;
			p1 = p1->next;
		}

		// p1 is the middle node;
		Node* n;
		n = new Node;
		memcpy(n,p1,sizeof(Node));
		n->next = NULL;
		return n;
	}
	return NULL;
}

Node* LL::lastNth(int n)
{
	Node* p1, * p2;
	p1 = p2 = head;
	int c = 0;

	if (head != NULL)
	{
		while (c < n)
		{
			if (p2 == NULL)
			{
				return NULL;
			}
			p2 = p2->next;
			c++;
		} // distance between p1&p2 = n

		while (p2->next != NULL)
		{
			p1 = p1->next;
			p2 = p2->next;
		}

		Node* n;
		n = new Node;
		memcpy(n, p1, sizeof(Node));
		n->next = NULL;
		return n;

	}
	return NULL;

}

void operator<<(ostream& out, LL& A)
{
	A.print_LL();
	//return out;
}

LL operator+( LL& O1,  LL&O2)
{
	Node* p1 = O1.head;
	Node* p2 = O2.head;
	LL O3;
	Node* lastO3=O3.head;
	if (p1 == NULL)
	{
		return  O2;
	}
	if (p2 == NULL)
	{
		return  O1;
	}
	 // we have data
	Node* n;


	while(p1!=NULL && p2!=NULL)
	{

		if (p1->data < p2->data)
		{

		
			n = new Node;
			memcpy(n, p1, sizeof(Node));
			n->next = NULL;

			if (O3.head == NULL)
			{
				O3.head = n;
				lastO3 = n;
			}
			else
			{
				lastO3->next = n;
				lastO3 = lastO3->next; // or = n
			}

			p1 = p1->next;

		}
		else
		{
			n = new Node;
			memcpy(n, p2, sizeof(Node));
			n->next = NULL;

			if (O3.head == NULL)
			{
				O3.head = n;
				lastO3 = O3.head;
			}
			else
			{
				lastO3->next = n;
				lastO3 = lastO3->next; // or = n
			}

			p2 = p2->next;

		}



	}


	if (p1 == NULL)
	{
		while (p2 != NULL)
		{
			n = new Node;
			memcpy(n, p2, sizeof(Node));
			n->next = NULL;

			//
			lastO3->next = n;
			lastO3 = lastO3->next;
			p2 = p2->next;
		}

	}

	if (p2 == NULL)
	{
		while (p1 != NULL)
		{
			n = new Node;
			memcpy(n, p1, sizeof(Node));
			n->next = NULL;

			//
			lastO3->next = n;
			lastO3 = lastO3->next;
			p1 = p1->next;
		}

	}

	return O3;

	//return LL();
}
