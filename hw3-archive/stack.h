#include<iostream>
#include<string>
using namespace std;


struct stackNode {
	char data;
	stackNode* next;
	string num;
	int op;
};

class stack {
public:
	stack() {
		top = NULL;
		max = 0;
	}
	void push(char num) {
		stackNode* temp = new stackNode;
		temp->data = num;
		if (top == NULL) {
			temp->next = NULL;
		}
		else {
			temp->next = top;
		}
		top = temp;
		max++;

	}
	void pushString(string num) {
		stackNode* temp = new stackNode;
		temp->num = num;
		if (top == NULL) {
			temp->next = NULL;
		}
		else {
			temp->next = top;
		}
		top = temp;
		max++;

	}

	void pop() {
		if (top == NULL) {
			return;
		}
		else {
			stackNode* temp = top;
			top = temp->next;
			free(temp);
			max--;
		}
	}
	char getTop() {
		stackNode* temp = top;
		if (temp == NULL) {
			return 0;
		}
			return temp->data;
	}
	bool getTopBool() {
		stackNode* temp = top->next;
		if (temp == NULL) {
			return false;
		}
		return true;
	}
	//bool getTop() {
	//	stackNode* temp = top;
	//	if (temp == NULL) {
	//		return false;
	//	}
	//	return true;
	//}
	string getTopString() {
		stackNode* temp = top;
		if (temp == NULL) {
			return 0;
		}
		return temp->num;
	}
	void setOP(int x) {
		stackNode* temp = top;
		if (x == 1) {
			temp->op = 1;
		}
		else
			temp->op = 0;
	}
	int getOP() {
		stackNode* temp = top;
		if (temp->op == 1)
			return 1;
		else
			return 0;
	}

	void print() {
		if (top == NULL)
			return;
		else {
			stackNode* temp = top;
			while (temp->next != NULL) {
				cout << "Top: ";
				cout << temp->data << endl;
				temp = temp->next;
			}
			cout << temp->data << endl;
		}

	}
	void printString() {
		if (top == NULL)
			return;
		else {
			stackNode* temp = top;
			while (temp->next != NULL) {
				cout << temp->num;
				temp = temp->next;
			}
			cout << temp->num << endl;
		}

	}

	int maxReturn() {
		return max;
	}


private:
	stackNode* top;
	int max;
};
