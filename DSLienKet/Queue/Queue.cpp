/*
QUEUE: Hàng đợi
Thêm vào cuối dãy
Làm việc theo kiểu First In First Out: FIFO
=======Bài toán=====
Thêm vào mảng queue bằng các số nguyên
*/
#include<iostream>
using namespace std;
struct node {
	int data;
	struct node* pNext;
};
struct queue {
	node* pHead;
	node* pTail;
};
void KhoiTaoQueue(queue& q) {
	q.pHead = NULL;
	q.pTail = NULL;
}
node* khoiTaoNode(int x) {
	node* p = new node;
	if (p == NULL) {
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}
//Kiểm tra xem queue có rỗng hay không
bool IsEmpty(queue q) {
	if (q.pHead == NULL) {
		return true;
	}
	return false;
}
//Thêm 1 phần tử vào cuối
bool Push(queue& q, node* p) {
	if (p == NULL) {
		return false;
	}
	if (IsEmpty(q) == true) {
		q.pHead = q.pTail = p;
	}
	else
	{
		q.pTail->pNext = p;
		q.pTail = p;
	}
	return true;
}
// lấy 1 phần tử đầu và hủy nó đi
bool Pop(queue& q, int &x) {
	if (IsEmpty(q) == true) {
		return false;
	}
	else {
		node* p = q.pHead;
		x = p->data;
		q.pHead = q.pHead->pNext;
		delete p;
	}
	return true;
}
// xem thông tin phần tử đầu
bool Top(queue& q, int &x) {
	if (IsEmpty(q) == true) {
		return false;
	}
	x = q.pHead->data;
	return true;
}
void XuatQueue(queue q) {
	while (IsEmpty(q) == false)
	{
		int x;
		Pop(q, x);
		cout << x << " ";
	}
}
void nhap(queue& q) {
	int choice;
	while (true) {
		system("cls");
		cout << "\n1.Nhap";
		cout << "\n2. Hien 1 phan tu dau";
		cout << "\n3.Danh sach";
		cout << "\n Chon: ";
		cin >> choice;
		if (choice == 1) {
			int x;
			cout << "\n Nhap phan tu: "; cin >> x;
			node* p = khoiTaoNode(x);
			Push(q, p);
		}
		else if (choice == 2) {
			int x;
			Top(q, x);
			cout << "\n Phan tu dau: " << x;
			system("pause");
		}
		else if (choice == 3) {
			XuatQueue(q);
			system("pause");
		}
	}
}
int main() {
	queue q;
	KhoiTaoQueue(q);
	nhap(q);
	system("pause");
	return 0;
}