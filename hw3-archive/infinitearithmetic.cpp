#include<iostream>
#include<string>
//#include"stack.h"
//#include"doublelinkedlist.h"
#include<math.h>
#include"ArgumentManager.h"
#include<fstream>
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



int compareSize(string num1, string num2) {
	int val1;
	int val2;

	if (num1.length() > num2.length())
		return 1;
	else if (num1.length() < num2.length())
		return 2;
	else {
		for (int i = 0; i < num1.length(); i++) {
			val1 = num1[i];
			val2 = num2[i];

			if (val1 > val2)
				return 1;
			else if (val1 < val2)
				return 2;

		}
		return 3;

	}


}




//return 1 if num1 is lower or equal priority to num2
int compare(int num1, int num2) {
	if (num1 < num2)
		return 1;

	else if (num1 > num2)
		return 2;

	else
		return 1;
}
int priority(char op, char op2) {
	int opVal, opVal2;
	if (op == '+' || op == '-')
		opVal = 1;
	else if (op == '/' || op == '*')
		opVal = 2;
	else if (op == '(' || op == ')')
		opVal = 3;
	else
		opVal = 0;

	if (op2 == '+' || op2 == '-')
		opVal2 = 1;
	else if (op2 == '/' || op2 == '*')
		opVal2 = 2;
	else if (op2 == '(' || op2 == ')')
		opVal2 = 3;
	else
		opVal2 = 0;
	return compare(opVal, opVal2);


}
//return 1 if num1 is lower or equal priority to num2


int isOperator(char x) {
	if (isalnum(x))
		return 0;
	else
		return 1;
}
//return 1 if char = (,),*,/,-,+

int symbol(char x) {
	if (isalnum(x))
		return 2;

	else if (x == '(')
		return 3;
	else if (x == ')')
		return 4;
	else
		return 5;
}

string add(DoubleLinkedList& num1, DoubleLinkedList& num2);

string sub(DoubleLinkedList& num1, DoubleLinkedList& num2);

string multi(DoubleLinkedList& num1, DoubleLinkedList& num2);





int main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cerr << "Usage: count filename=input1.txt\n";
	}
	ArgumentManager am(argc, argv);
	string filename = am.get("input");
	int digitsPerNode = atoi(am.get("digitsPerNode").c_str());
	ifstream ifs(filename.c_str());
	std::string num;
	//int digitsPerNode = 5;
	while (getline(ifs, num)) {
		//string num = "0*00000000000000000+0000000000000001";
		stack stack1;
		stack stack2;
		string temp = "";
		string tempNum = "";
		string answer;

		int i = 0;
		int j;
		int result;
		int neg = 0;


		while (i <= num.length()) {
			result = symbol(num[i]);
			j = i + 1;
			if (result == 2) {			//if its still going through number
				if (!isdigit(num[j])) {
					temp += num[i];
					stack2.pushString(temp);
					stack2.setOP(0);		//test
					temp = "";
				}
				else if (isdigit(num[j])) {
					temp += num[i];
				}

			}
			else if (result == 3) {
				stack1.push(num[i]);		//if operator
				stack1.setOP(1);		//test
			}
			else if (result == 4) {
				while (stack1.getTopBool()) {
					if (stack1.getTop() == '(') {
						stack1.pop();
						break;
					}
					else {
						temp = stack1.getTop();
						stack1.pop();
						stack2.pushString(temp);
						stack2.setOP(1);		//test		work
						temp = "";
					}
				}
			}
			else if (result == 5) {
				while (1) {
					if (stack1.getTop() == 0 && i != 0) {
						stack1.push(num[i]);
						stack1.setOP(1);	//test
						break;
					}
					else if (i == 0 && num[i] != '(' && num[i] != ')') {
						temp += num[i];
						break;
					}
					else if (num[i] == '-' && num[i - 1] == '(') {		//if (-1)
						temp += num[i];
						break;
					}
					else if (num[i] == '+' && num[i - 1] == '(') {		//if (+1)
						temp += num[i];
						break;
					}
					else if (stack1.getTop() == '(') {
						stack1.push(num[i]);
						stack1.setOP(1);	//test		fail
						break;
					}

					else if (priority(num[i], stack1.getTop()) == 1) {
						temp = stack1.getTop();
						stack1.pop();
						stack2.pushString(temp);
						stack2.setOP(1);	//test		work
						temp = "";
					}
					else if (priority(num[i], stack1.getTop()) == 2) {
						stack1.push(num[i]);
						stack1.setOP(1);	//test		fail
						break;
					}
					else {
						break;
					}

				}
			}

			i++;
		}

		//makes postfix of num in stack1
		while (stack2.getTopBool()) {
			tempNum = stack2.getTopString();
			stack1.pushString(tempNum);
			stack1.setOP(stack2.getOP());	//test
			stack2.pop();
		}
		//	cout << "postfix = ";
		//	stack1.printString();				//postfix
		//	cout << "\n====================================\n\n";
		//	DoubleLinkedList Result;
		/*int val1 = 0;
		int val2 = 0;
		int result1 = 0;*/
		int g = 0;
		while (stack1.getTop() != 0) {									//if number push into stack2 which is a new stack     stack1.getTop() != 0
			if (stack1.getOP() == 0) {
				//cout << stack1.getTopString() << endl;

				stack2.pushString(stack1.getTopString());
				stack1.pop();
			}
			else {																//if opperator do math
																				//cout << stack1.getTopString() << " is a OP" << endl;
				DoubleLinkedList num2(stack2.getTopString(), digitsPerNode);
				//val1 = stoi(stack2.getTopString());
				stack2.pop();
				DoubleLinkedList num1(stack2.getTopString(), digitsPerNode);
				//val2 = stoi(stack2.getTopString());
				stack2.pop();
				if (stack1.getTopString() == "*") {
					//result1 = val1 * val2;
					answer = multi(num1, num2);
					//cout << "answer after * is: " << answer << endl;
				}
				else if (stack1.getTopString() == "-") {
					answer = sub(num1, num2);						//W		I	  P
																	//	cout << "answer after - is: " << answer << endl;												//result1 = val1 - val2;
				}
				else if (stack1.getTopString() == "+") {
					answer = add(num1, num2);							//Works
																		//	cout << "answer after + is: " << answer << endl;
				}
				else if (stack1.getTopString() == "/") {
					//result1 = val1 / val2;
				}
				stack2.pushString(answer);

				//num1.Print();
				//cout << stack1.getTopString();
				//num2.Print();
				//cout << "=\n";
				stack1.pop();

			}


		}
		if (answer[0] == '-') {
			answer.erase(answer.begin());
			neg = 1;
		}

		int k = 0;
		while (answer[k] == '0' && answer.length() > 1) {
			answer.erase(answer.begin());
		}
		if (neg == 1)
			answer.insert(answer.begin(), '-');

		cout << num << "=" << answer << endl;
		//cout << answer << endl;
	}		//end of while
	//system("pause");
	return 0;
}





int isNegative(DoubleLinkedList& num1, DoubleLinkedList& num2) {
	if (num1.getSign() == 1 && num2.getSign() == 1)
		return 1;
	else if (num1.getSign() == 0 && num2.getSign() == 0)
		return 2;
	else if (num1.getSign() == 1 && num2.getSign() == 0)
		return 3;
	else if (num1.getSign() == 0 && num2.getSign() == 1)
		return 4;
	else
		return 0;
}
int isLarger(DoubleLinkedList& num1, DoubleLinkedList& num2) {
	if (num1.getNOD() > num2.getNOD())
		return 1;
	else if (num1.getNOD() < num2.getNOD())
		return 2;
	else if (num1.getNOD() == num2.getNOD())
		return 3;

}


//=================================================		ADD		======================================================================================

string add(DoubleLinkedList& num1, DoubleLinkedList& num2) {
	int val1, val2;
	int result = 0;
	int tempChange;
	string resultstr = "";
	string carry = "0";
	string temp;
	string tempS;
	string finalResult;
	val1 = num1.getLastData();
	val2 = num2.getLastData();
	//DoubleLinkedList num3;


	string number1 = "";
	string number2 = "";


	number1 += num1.getFirstDataString();
	while (num1.movePrev()) {					//exit when reaches tail
		number1 += num1.getNextDataString();
	}
	number2 += num2.getFirstDataString();											//use to see if number is bigger or not before deciding how to add/ sub
	while (num2.movePrev()) {					//exit when reaches tail
		number2 += num2.getNextDataString();
	}

	if (number1[0] == '-') {
		number1.erase(number1.begin());
	}
	if (number2[0] == '-') {
		number2.erase(number2.begin());
	}

	while (num1.moveNext() || num2.moveNext()) {				//while they are same size

		val1 = num1.getPrevData();
		val2 = num2.getPrevData();
		if (val1 < 0)
			val1 = val1 * -1;
		if (val2 < 0)
			val2 = val2 * -1;

		if (isNegative(num1, num2) == 1) {					//if num1 and num2 are both neg
			result = val1 + val2 + stoi(carry);
			temp = to_string(result);

			if (temp.length() > num2.getDPN()) {
				temp.erase(temp.begin());
				carry = "1";
			}
			else
				carry = "0";
		}

		else if (isNegative(num1, num2) == 2) {			//if num1 and num2 are both pos
			result = val1 + val2 + stoi(carry);
			temp = to_string(result);

			if (temp.length() > num2.getDPN()) {
				temp.erase(temp.begin());
				carry = "1";
			}
			else
				carry = "0";
		}

		else if (isNegative(num1, num2) == 3) {		//if num1 is neg and num2 is pos
			if (compareSize(number1, number2) == 1 || compareSize(number1, number2) == 3) {
				if (val1 == 0 && carry == "1") {															//=======================================
					result = pow(10, num2.getDPN()) - (val2 - (val1 - stoi(carry)));
					carry = "1";
				}
				else if (val2 > val1) {
					result = pow(10, num2.getDPN()) - (val2 - (val1 - stoi(carry)));
					carry = "1";
				}
				else {
					result = val1 - val2 - stoi(carry);
					carry = "0";
				}
			}
			else if (compareSize(number1, number2) == 2) {
				if (val1 > val2) {
					result = pow(10, num2.getDPN()) - (val1 - (val2 - stoi(carry)));
					carry = "1";
				}
				else {
					result = val2 - val1 - stoi(carry);
					carry = "0";
				}

			}
			temp = to_string(result);
		}

		else if (isNegative(num1, num2) == 4) {			//num1 is pos num2 is neg
			if (val1 == 0 && carry == "1") {															//======================================
				result = pow(10, num2.getDPN()) - (val2 - (val1 - stoi(carry)));
				carry = "1";
			}
			else if (compareSize(number1, number2) == 1 || compareSize(number1, number2) == 3) {
				if (val1 < val2) {
					result = pow(10, num2.getDPN()) - (val2 - (val1 - stoi(carry)));
					carry = "1";
				}
				else {
					result = val1 - val2 - stoi(carry);
					carry = "0";
				}
			}

			else if (compareSize(number1, number2) == 2) {
				if (val1 > val2) {
					result = pow(10, num2.getDPN()) - (val1 - (val2 - stoi(carry)));
					carry = "1";
				}
				else {
					result = val2 - val1 - stoi(carry);
					carry = "0";
				}

			}
			temp = to_string(result);


		}




		if (temp.length() < num2.getDPN()) {
			for (int i = temp.length(); i < num2.getDPN(); i++)
				temp.insert(temp.begin(), '0');
		}

		for (int i = temp.length() - 1; i >= 0; i--) {
			finalResult.insert(finalResult.begin(), temp[i]);
		}

	}

	if (isNegative(num1, num2) == 1) {
		finalResult.insert(finalResult.begin(), '-');		//works
	}
	else if (isNegative(num1, num2) == 2) {
		//works
	}
	else if (isNegative(num1, num2) == 3) {
		if (compareSize(number1, number2) == 1)					//works
			finalResult.insert(finalResult.begin(), '-');
	}
	else if (isNegative(num1, num2) == 4) {
		if (compareSize(number1, number2) == 2)					//works
			finalResult.insert(finalResult.begin(), '-');
	}

	//result = stoi(finalResult);
	return finalResult;
}

//======================================================== S U B ==================================================================

string sub(DoubleLinkedList& num1, DoubleLinkedList& num2) {
	int val1, val2;
	int result = 0;
	int tempChange;
	string resultstr = "";
	string carry = "0";
	string temp;
	string tempS;
	string finalResult;
	val1 = num1.getLastData();
	val2 = num2.getLastData();


	string number1 = "";
	string number2 = "";


	number1 += num1.getFirstDataString();
	while (num1.movePrev()) {					//exit when reaches tail
		number1 += num1.getNextDataString();
	}
	number2 += num2.getFirstDataString();											//use to see if number is bigger or not before deciding how to add/ sub
	while (num2.movePrev()) {					//exit when reaches tail
		number2 += num2.getNextDataString();
	}

	if (number1[0] == '-') {
		number1.erase(number1.begin());
	}
	if (number2[0] == '-') {
		number2.erase(number2.begin());
	}

	while (num1.moveNext() || num2.moveNext()) {				//while they are same size

		val1 = num1.getPrevData();
		val2 = num2.getPrevData();
		if (val1 < 0)
			val1 = val1 * -1;
		if (val2 < 0)
			val2 = val2 * -1;

		if (isNegative(num1, num2) == 1) {					//if num1 and num2 are both neg

			if (compareSize(number1, number2) == 1 || compareSize(number1, number2) == 3) {
				if (val2 > val1) {
					result = pow(10, num2.getDPN()) - (val2 - (val1 - stoi(carry)));
					carry = "1";
				}
				else {
					result = val1 - val2 - stoi(carry);
					carry = "0";
				}
			}
			else if (compareSize(number1, number2) == 2) {
				if (val1 > val2) {
					result = pow(10, num2.getDPN()) - (val1 - (val2 - stoi(carry)));
					carry = "1";
				}
				else {
					result = val2 - val1 - stoi(carry);
					carry = "0";
				}

			}
			temp = to_string(result);


		}

		else if (isNegative(num1, num2) == 2) {			//if num1 and num2 are both pos
			if (compareSize(number1, number2) == 1 || compareSize(number1, number2) == 3) {
				if (val1 == 0 && carry == "1") {																	//===============================works
					result = pow(10, num2.getDPN()) - (val2 - (val1 - stoi(carry)));
					carry = "1";
				}
				else if (val1 < val2) {
					result = pow(10, num2.getDPN()) - (val2 - (val1 - stoi(carry)));
					carry = "1";
				}
				else {
					result = val1 - val2 - stoi(carry);
					carry = "0";
				}
			}

			else if (compareSize(number1, number2) == 2) {
				if (val1 == 0 && carry == "1") {
					result = pow(10, num2.getDPN()) - (val2 - (val1 - stoi(carry)));
					carry = "1";
				}
				if (val1 > val2) {
					result = pow(10, num2.getDPN()) - (val1 - (val2 - stoi(carry)));
					carry = "1";
				}
				else {
					result = val2 - val1 - stoi(carry);
					carry = "0";
				}

			}
			temp = to_string(result);




		}

		else if (isNegative(num1, num2) == 3) {		//if num1 is neg and num2 is pos

			result = val1 + val2 + stoi(carry);
			temp = to_string(result);

			if (temp.length() > num2.getDPN()) {
				temp.erase(temp.begin());
				carry = "1";
			}
			else
				carry = "0";

		}

		else if (isNegative(num1, num2) == 4) {			//num1 is pos num2 is neg

			result = val1 + val2 + stoi(carry);
			temp = to_string(result);

			if (temp.length() > num2.getDPN()) {
				temp.erase(temp.begin());
				carry = "1";
			}
			else
				carry = "0";

		}




		if (temp.length() < num2.getDPN()) {
			for (int i = temp.length(); i < num2.getDPN(); i++)
				temp.insert(temp.begin(), '0');
		}

		for (int i = temp.length() - 1; i >= 0; i--) {
			finalResult.insert(finalResult.begin(), temp[i]);
		}

	}

	if (isNegative(num1, num2) == 1) {			//num1 is neg, num2 becomes pos	
		if (compareSize(number1, number2) == 1)					//works
			finalResult.insert(finalResult.begin(), '-');
	}
	else if (isNegative(num1, num2) == 2) {		//num1 is pos and num2 becomes neg
		if (compareSize(number1, number2) == 2)					//works
			finalResult.insert(finalResult.begin(), '-');
	}
	else if (isNegative(num1, num2) == 3) {		//num1 is neg num2 becomes neg (always neg result)
		finalResult.insert(finalResult.begin(), '-');
	}
	else if (isNegative(num1, num2) == 4) {		//num1 is pos num2 becomes pos.....always positive result

	}

	//result = stoi(finalResult);
	return finalResult;

}

//====================================================================== M U L T I P L Y ==============================================================

string multi(DoubleLinkedList& num1, DoubleLinkedList& num2) {
	int val1, val2;
	int result = 0;
	int tempChange;
	string resultstr = "";
	string carry = "0";
	string temp;
	string tempS;
	string stackNum1;
	string stackNum2;
	string finalResult;
	val1 = num1.getLastData();
	val2 = num2.getLastData();

	stack stackResult;

	string number1 = "";
	string number2 = "";


	number1 += num1.getFirstDataString();
	while (num1.movePrev()) {					//exit when reaches tail
		number1 += num1.getNextDataString();
	}
	number2 += num2.getFirstDataString();											//use to see if number is bigger or not before deciding how to add/ sub
	while (num2.movePrev()) {					//exit when reaches tail
		number2 += num2.getNextDataString();
	}

	if (number1[0] == '-') {
		number1.erase(number1.begin());
	}
	if (number2[0] == '-') {
		number2.erase(number2.begin());
	}


	int powVal1 = 0;
	int powVal2 = 0;
	while (num2.moveNext()) {
		val2 = num2.getPrevData();
		val1 = num1.getLastData();

		if (val1 < 0)
			val1 = val1 * -1;
		if (val2 < 0)
			val2 = val2 * -1;


		//val2 = val2 * pow(10, powVal2);

		while (num1.moveNext()) {

			if (val1 < 0)
				val1 = val1 * -1;
			if (val2 < 0)
				val2 = val2 * -1;

			//val1 = val1 * pow(10, powVal1);
			tempChange = val1 * val2;
			tempS = to_string(tempChange);

			for (int i = 0; i < powVal1; i++)
				tempS.insert(tempS.end(), '0');

			for (int j = 0; j < powVal2; j++)
				tempS.insert(tempS.end(), '0');

			stackResult.pushString(tempS);

			powVal1 += num2.getDPN();

			val1 = num1.getPrevData();
		}

		powVal1 = 0;
		powVal2 += num2.getDPN();


	}

	while (1) {
		if (stackResult.maxReturn() == 1)
			break;
		stackNum1 = stackResult.getTopString();
		stackResult.pop();
		stackNum2 = stackResult.getTopString();
		stackResult.pop();
		DoubleLinkedList n1(stackNum1, num2.getDPN());
		DoubleLinkedList n2(stackNum2, num2.getDPN());
		tempS = add(n1, n2);
		stackResult.pushString(tempS);


	}
	finalResult = stackResult.getTopString();
	stackResult.pop();
	int x = 0;
	while (finalResult[x] == '0' && finalResult.length() > 1)
		finalResult.erase(finalResult.begin());


	if (isNegative(num1, num2) == 3)
		finalResult.insert(finalResult.begin(), '-');			//works
	else if (isNegative(num1, num2) == 4)
		finalResult.insert(finalResult.begin(), '-');			//works


	return finalResult;
}