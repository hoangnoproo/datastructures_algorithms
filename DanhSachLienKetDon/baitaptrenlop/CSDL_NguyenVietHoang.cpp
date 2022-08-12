/*
Ho va ten: Nguyen Viet Hoang
Nhom 18
   De bai: Quan ly mua ban vat lieu xay dung
   •Su dung danh sach lien ket don de quan ly danh sach doi tuong voi cac yeu cau
-Nhap danh sach doi tuong
-In danh sach doi tuong
In doi tuong theo dieu kien xac dink
-Sap xep tang dan
-Tim kiem vat lieu co thanh tien nho nhat
Viet chuong trinh chinh (duoi dang menu goi lan luot cac yeu cau tren)
*/
#include<iostream>
#include<string>
#include<math.h>
#include<iomanip>
using namespace std;
struct VatLieu {
	int idVaterial;
	string materialName;
	int amount;
	float unitPrice;
	float intoMoney;
};
struct  Node {
	VatLieu data;
	struct Node* pNext;
};
struct list {
	Node* pHeal;
	Node* pTail;
};
void KhoiTaoDs(list& l) {
	l.pHeal = NULL;
	l.pTail = NULL;
}
Node* khoiTaoNode(VatLieu x) {
	Node* p = new Node;
	if (p == NULL) {
		cout << "\n Khong du bo nho!";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}
void nhap( VatLieu &hh) {
	cout << "\nNhap ma vat lieu: ";
	cin >> hh.idVaterial;
	cout << "\nNhap ten vat lieu: ";
	cin.ignore();
	getline(cin, hh.materialName);
	cout << "\n Nhap so luong: ";
	cin >> hh.amount;
	cout << "\n Nhap don gia: ";
	cin >> hh.unitPrice;
	hh.intoMoney = hh.amount * hh.unitPrice;
}
void hien(VatLieu hh) {
	cout << setw(7)<<hh.idVaterial;
	cout << setw(20) << hh.materialName;
	cout << setw(20) << hh.amount;
	cout << setw(20) << hh.unitPrice;
	cout << setw(20) << (size_t)hh.intoMoney<<"\n";
}
void themDau(list& l, Node *p) {
	if (l.pHeal == NULL) {
		l.pHeal = p;
		l.pTail = l.pHeal;
	}
	else {
		p->pNext = l.pHeal;
		l.pHeal = p;
	}
}
void themCuoi(list& l, Node* p) {
	if (l.pHeal == NULL) {
		l.pHeal = p;
		l.pTail = l.pHeal;
	}
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void sort_ascending(list& l) {
	for (Node* k = l.pHeal; k != NULL; k = k->pNext) {
		for (Node* h = k->pNext; h != NULL; h = h->pNext) {
			if (k->data.idVaterial > h->data.idVaterial) {
				swap(k->data, h->data);
			}
		}
	}
}
void searchID(list &l) {
	int ma;
	cout << "\n Nhap ma can tim: "; cin >> ma;
	for (Node* k = l.pHeal; k != NULL; k = k->pNext) {
		if (k->data.idVaterial ==ma) {
			hien(k->data);
		}
	}
}
void minimum(list l) {
	float min = l.pHeal->data.intoMoney;
	for (Node* k = l.pHeal->pNext; k != NULL; k = k->pNext) {
		if (k->data.intoMoney < min) {
			min = k->data.intoMoney;
		}
	}
	for (Node* k = l.pHeal; k != NULL; k = k->pNext) {
		if (k->data.intoMoney == min) {
			cout << "\n Gia tri min: " << (size_t)min;
		}
	}
}
void hiendanhsach(list l) {
	cout << setw(7) << "Ma vat kieu";
	cout << setw(20) << "Ten vat lieu";
	cout << setw(20) << "So luong";
	cout << setw(20) << "Don gia";
	cout << setw(20) << "Thanh Tien\n";
	for (Node* p = l.pHeal; p != NULL; p = p->pNext) {
		hien(p->data);
	}
}
void menu(list& l) {
	int luachon;
	while (true) {
		system("cls");
		cout << "\n\t\t\t________MENU________";
		cout << "\n\t\t1.Nhap vat lieu";
		cout << "\n\t\t2.Hien vat lieu";
		cout << "\n\t\t3.Sap xep tang dan theo ma";
		cout << "\n\t\t4.Tim kiem theo ma";
		cout << "\n\t\t5.Vat lieu co thanh tien nho nhat";
		cout << "\n\t\t0.Ket thuc";
		cout << "\n\t Nhap vao lua chon: "; cin >> luachon;
		if (luachon < 0 || luachon>5) {
			cout << "\n Vui long nhap lai";
		}
		else if(luachon == 1) {
			VatLieu x;
			nhap(x);
			Node* p = khoiTaoNode(x);
			themCuoi(l, p);
		}
		else if (luachon == 2) {
			hiendanhsach(l);
			system("pause");
		}
		else if (luachon == 3) {
			sort_ascending(l);
			hiendanhsach(l);
			system("pause");
		}
		else if (luachon == 4) {
			searchID(l);
			system("pause");
		}
		else if (luachon == 5) {
			minimum(l);
			system("pause");
		}
		else {
			break;
		}
	}
}
int main() {
	list l;
	KhoiTaoDs(l);
	menu(l);
	return 0;

}