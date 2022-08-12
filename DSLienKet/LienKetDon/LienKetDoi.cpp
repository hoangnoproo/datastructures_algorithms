/*
Cho thông tin của cán bộ bao gồm: mã, họ tên, ngày sinh, hệ số lương, phụ cấp và lương(=hsl*105000+phụ cấp)
-Nhập danh sách cán bộ
-In lại danh sách
- tính  tổng lương của các cán bộ
*/
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
struct Date {
	int day;
	int month;
	int year;
};
struct CanBo {
	int id;
	string name;
	Date date;
	float hsl;
	float phuCap;
	float luong;
};
struct node {
	CanBo data;
	node* pNext;
	node* prev;
};
struct list {
	node* pHead;
	node* pTail;
};
void khoiTaoList(list &l) {
	l.pHead = NULL;
	l.pTail = NULL;
}
node* KhoiTaoNode(CanBo x) {
	node* p = new node;
	if (p == NULL) {
		cout << "\n khong du  bo nho!";
		return NULL;
	}
	p->data=x;
	p->pNext = NULL;
	p->prev = NULL;
	return p;
}
void addLast(list& l, node* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		l.pTail->pNext = p;
		p->prev = l.pTail;
		l.pTail = p;
	}
}
void addFirst(list& l, node* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		l.pHead->prev = p;
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void inPut(list& l) {
	int n;
	cout << "\n Nhap n: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		CanBo x;
		cout << "\n Nhap ma: ";
		cin >> x.id;
		cout << "\n Nhap ten: ";
		cin.ignore();
		getline(cin, x.name);
		cout << "\n Nhap ngay: ";
		cin >> x.date.day;
		cout << "\n Nhap thang: ";
		cin >> x.date.month;
		cout << "\n Nhap nam: ";
		cin >> x.date.year;
		cout << "\n Nhap HSL: ";
		cin >> x.hsl;
		cout << "\n Nhap phu cap: ";
		cin >> x.phuCap;
		x.luong = x.hsl * 105000 + x.phuCap;
		node* p = KhoiTaoNode(x);
		addLast(l, p);
	}
}
void hien1canbo(CanBo x) {
	cout << setw(7) << x.id;
	cout << setw(20) << x.name;
	cout << setw(4) << x.date.day << "/" <<setw(2)<<x.date.month << "/"<<setw(4) << x.date.year;
	cout << setw(20) << x.hsl;
	cout << setw(20) << x.phuCap;
	cout << setw(15) << (size_t)x.luong <<"\n";
}
void Output(list l) {
	cout << setw(7) <<"Ma";
	cout << setw(20) << "Ten";
	cout << setw(12) << "Ngay";
	cout << setw(20) << "HSL";
	cout << setw(20) << "Phu cap";
	cout << setw(17) << "Luong\n";
	for (node* k = l.pHead; k != NULL; k = k->pNext) {
		hien1canbo(k->data);
	}
}
void TongLuong(list l) {
	float tong = 0;
	for (node* k = l.pHead; k != NULL; k = k->pNext) {
		tong += k->data.luong;
	}
	cout << "\n Tong luong: " << (size_t)tong;
}
void TimKiemMa(list l) {
	int ma;
	cout << "\n Nhap ma can tim: "; cin >> ma;
	for (node* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->data.id == ma) {
			hien1canbo(k->data);
		}
	}
}
int main() {
	list l;
	khoiTaoList(l);
	inPut(l);
	Output(l);
	TongLuong(l);
	TimKiemMa(l);
	system("pause");
	return 0;
}