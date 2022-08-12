#include<iostream>
using namespace std;
struct node {
	int data;
	struct node* pNext;
};
struct stack {
	node* pTop;
};
void khoiTaoStack(stack &s) {
	s.pTop = NULL;
}
node* KhoiTaoNode(int x) {
	node* p = new node;
	if (p == NULL) {
		cout << "\n khong du bo nho!";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}
bool IsEmpty(stack s) {
	if (s.pTop == NULL) {
		return true;
	}
	return false;
}
bool Push(stack& s, node* p) {
	if (p == NULL) {
		return false;
	}
	if (IsEmpty(s) == true) {
		s.pTop = p;
	}
	else {
		p->pNext = s.pTop;
		s.pTop = p;
	}
	return true;
}
bool Pop(stack& s, int& x) {
	if (IsEmpty(s) == true) {
		return false;
	}
	else {
		node* p = s.pTop;
		s.pTop = s.pTop->pNext;
		x = p->data;
	}
	return true;
}
bool Top(stack& s, int& x) {
	if (IsEmpty(s) == true) {
		return false;
	}
	x = s.pTop->data;
	return true;
}
void chuyenDoiCoSo(stack& s,int n, int heso) {
	while (n != 0) {
		int x = n % heso;
		node* p = KhoiTaoNode(x);
		Push(s, p);
		n /= heso;
	}
}
void HienStack(stack &s) {
	while (IsEmpty(s) == false) {
		int x; 
		Pop(s, x);
		if (x < 10)
			cout << x;
		else
		{
			if (x == 10)
			{
				cout << "A";
			}
			else if (x == 11)
			{
				cout << "B";
			}
			else if (x == 12)
			{
				cout << "C";
			}
			else if (x == 13)
			{
				cout << "D";
			}
			else if (x == 14)
			{
				cout << "E";
			}
			else if (x == 15)
			{
				cout << "F";
			}
			system("pause");
		}
	}
}
int main() {
	stack s;
	khoiTaoStack(s);
	int n; int heso;
	cout << "\n Nhap so can chuyen doi: "; cin >> n;
	cout << "\n Nhap he so: "; cin >> heso;
	chuyenDoiCoSo(s,n,heso);
	HienStack(s);
	system("pause");
	return 0;
}