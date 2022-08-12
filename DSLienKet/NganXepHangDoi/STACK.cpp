/*
STACK : ngăn xếp. Cấu trúc hoạt động theo kiểu last in first out- đối tượng vào sau ra trước
IsEmpty: Kiểm tra xẹm stack rỗng hay không
Push: thêm 1 đối tượng vào đầu stack -LIFO
Pop: Lấy đầu phần tử của stack sẽ trả về giá trị của đối tượng đồng thời phá hủy nó đi
Top: Xem thông tin phần tử đầu của stack và không hủy nó
======Bài tập===
Nhập danh sách số nguyên vào 1 stack và hiện ra màn hình

*/
#include<iostream>
using namespace std;
// Khai báo cấu trúc 1 node
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
// Kiểm tra hàm stack còn trống hay k
bool IsEmpty(stack s) {
	if (s.pTop == NULL) {
		return true;
	}
	return false;
}
// Thêm 1 phần tử vào đầu stack 
bool Push(stack& s, node* p) {
	if (IsEmpty(s) == true) {
		s.pTop = p;
	}
	else {
		p->pNext = s.pTop;
		s.pTop = p;
	}
	return true;
	if (p == NULL) {
		return false;
	}
}
node* khoiTaoNode(int x) {
	node* p = new node;
	if (p == NULL) {
		cout << "\n khong du bo nho";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}
//Lấy ra phần tử đầu và hủy nó 
bool Pop(stack& s, int &x) {
	if (IsEmpty(s) == true) {
		return false;
	}
	else {
		node* p = s.pTop;
		x = p->data;
		s.pTop = s.pTop->pNext;
		delete p;
	}
	return true;
}
// Xem phần tử đầu và  không hủy nó đi
bool Top(stack& s, int& x) {
	if (IsEmpty(s) == true) {
		return false;
	}
	x = s.pTop->data;
	return true;
}
void XuatStack(stack s) {
	while (IsEmpty(s) == false) {
		int x;
		Pop(s, x);
		cout << x<<" ";
	}
	if (IsEmpty(s) == true) {
		cout << "Dang rong";
	}
	else {
		cout << "\n Con phan tu";
	}
}
void nhapStack(stack& s) {
	int choice;
	while (true) {
		system("cls");
		cout << "\n\t\t\t MENU";
		cout << "\n1. Them phan tu vao stack";
		cout << "\n2. Xem thong tin cua phan tu dau";
		cout << "\n3. Hien danh sach va huy no di";
		cout << "\n0. Huy";
		cout << "\nNhap lua chon: ";
		cin >> choice;
		
		if(choice==1) {
			int x;
			cout << "\n Nhap phan tu: ";
			cin >> x;
			node* p = khoiTaoNode(x);
			Push(s, p);
		}
		else if (choice == 2) {
			int x;
			Top(s, x);
			cout << "\n Phan tu dau la: " << x;
			system("pause");
		}
		else if(choice==3) {
			XuatStack(s);
			system("pause");
		}
	}
}
int main() {
	stack s;
	khoiTaoStack(s);
	nhapStack(s);
	system("pause");
	return 0;
}
