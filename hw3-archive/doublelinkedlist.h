#include<iostream>
#include<string>
#include<math.h>
using namespace std;

struct Node {
	long long num;
	int count;
	string numstr;
	Node* prev;
	Node* next;
	int op;
	char data;
};
class DoubleLinkedList {
public:
	void Insert(int num)
	{
		Node * nd = new Node();
		Node * cur = tail->prev;
		nd->num = num;
		nd->numstr = "";
		string tempstr = to_string(num);

		count++;

		if (count < nod)
		{
			for (int i = tempstr.length(); i < m_digitsPerNode; i++)
			{
				tempstr.insert(tempstr.begin(), '0');
			}
			nd->numstr = tempstr;
		}
		else
		{
			nd->numstr = tempstr;

		}



		nd->next = head->next;
		nd->prev = head;

		head->next->prev = nd;
		head->next = nd;

	}

	void Print()
	{
		Node * c = head->next;
		string line = to_string(c->num);
		string line2;
		while (c != tail)
		{
			cout << c->numstr;
			//line2.append(c->numstr);
			c = c->next;
		}

		//return line2;

	}

	int WhatList = 0;
	DoubleLinkedList() {		//first node of list starting from the front
		head = new Node();
		tail = new Node();
		nod = 0;
		head->next = tail;
		head->prev = NULL;
		tail->prev = head;
		tail->next = NULL;
		count = 0;
		sign = true;
		m_digitsPerNode = 0;

	};   // default construct


	DoubleLinkedList(const std::string& num, int digitsPerNode) {			//need to fix for negative number
		head = new Node();
		tail = new Node();
		head->next = tail;
		head->prev = NULL;
		tail->prev = head;
		tail->next = NULL;
		m_digitsPerNode = digitsPerNode;
		int numberNode = 0;
		int remainNum = 0;
		int tnum = 0;
		count = 0;
		string num1 = num;
		if (num[0] == '-') {
			sign = true;
			num1.erase(num1.begin());
		}
		numberNode = num1.length() / digitsPerNode;
		remainNum = num1.length() % digitsPerNode;


		if (remainNum != 0)
		{
			numberNode++;
		}

		int i = num.length() - 1;

		int count = num.length() - 1;
		nod = numberNode;

		int checkNum = 0;

		if (remainNum == 0) {

			for (int i = 0; i < numberNode; i++)
			{
				for (int j = 0; j < digitsPerNode; j++)
				{
					tnum = tnum + (num[count--] - 48) * pow(10, checkNum++);

				}
				if (i == numberNode - 1 && sign == true) {
					tnum = tnum * -1;
				}
				this->Insert(tnum);
				checkNum = 0;
				tnum = 0;
			}

		}
		else
		{
			for (int i = 0; i < numberNode - 1; i++)
			{
				for (int j = 0; j < digitsPerNode; j++)
				{
					tnum = tnum + (num[count--] - 48) * pow(10, checkNum++);

				}
				this->Insert(tnum);


				checkNum = 0;
				tnum = 0;
			}


		}

		if (remainNum != 0)
		{
			for (int i = 0; i < remainNum; i++)
			{
				tnum = tnum + (num[count--] - 48) * pow(10, checkNum++);
			}
			if (sign == true) {
				tnum = tnum * -1;
			}

			this->Insert(tnum);

		}



	};



public:
	void Set(const std::string& num, int dpn, int sn) {

		m_digitsPerNode = dpn;

		int numOfNode, total = 0, check = 0;
		int idx = num.length() - 1;


		numOfNode = num.length() / dpn;

		if (num.length() % dpn != 0)
			numOfNode++;

		nod = numOfNode;

		if (sn == 1)
			sign = true;
		else
			sign = false;

		for (int i = 0; i < numOfNode; i++)
		{
			for (int j = 0; j < dpn; j++)
			{
				total = total + (num[idx--] - 48) * pow(10, j);
				check++;
				if (check == num.length())
					break;
			}
			Insert(total);
			total = 0;
		}




	}
	int getDPN()
	{

		return m_digitsPerNode;
	}
	int getFirstData()
	{
		c = head->next;

		return c->num;


	}
	string getFirstDataString()
	{
		c = head->next;

		return c->numstr;


	}
	int getSign()
	{
		if (sign == true)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	bool moveNext()
	{
		if (c == head)
		{
			return false;
		}

		//c = c->prev;
		return true;
	}
	bool movePrev()
	{
		if (c == tail)
		{
			return false;
		}

		c = c->next;
		return true;
	}
	int getNextData()
	{
		if (c->next == NULL || c->next == tail)
		{
			return -1;
		}

		c = c->next;
		return c->num;


	}
	string getNextDataString()
	{
		if (c->next == NULL)
		{
			return c->numstr;
		}

		return c->numstr;


	}
	int getLastData()
	{
		c = tail->prev;

		return c->num;


	}
	int getPrevData()		//edit
	{
		if (c->prev == NULL)
		{
			return 0;
		}
		else
		{
			c = c->prev;
			return c->num;
		}



	}

	int getNOD()
	{

		return nod;
	}


	const Node* GetHead() const {
		return head;

	};
	const Node* GetTail() const {
		return tail;

	};

private:
	Node* head;
	Node* tail;
	Node* n;
	Node* list1;
	Node* list2;
	Node* c;
	Node* top;
	bool sign;
	int count;
	int nod;
	int isNeg;
	int m_digitsPerNode;
	long long remainder; // for / operator
	float decimal;

};
