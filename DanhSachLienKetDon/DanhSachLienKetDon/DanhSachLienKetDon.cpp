#include<iostream>
using namespace std;
struct node {
	int data;
	struct node* Pnext;
};
typedef struct node NODE;
struct List {
	NODE* pHeal;
	NODE* Ptail;
};
typedef struct List LIST;
// khởi tạo
void KhoiTaoList(LIST &l) {
	l.pHeal = NULL;
	l.Ptail = NULL;
}
NODE* KhoiTaoNODE(int x) {
	NODE* p = new NODE;
	if (p == NULL) {
		cout << "Khong du bo nho";
		return NULL;
	}
	p->data = x;
	p->Pnext = NULL;
	return p;
}
// Hàm thêm vào đầu
void ThemVaoDau(LIST& l, NODE *p) {
	if (l.pHeal == NULL) {
		l.pHeal = l.Ptail = p;
	}
	else {
		p->Pnext = l.pHeal;
		l.pHeal = p;
	}
}
// Hàm thêm vào cuối
void ThemVaoCuoi(LIST& l, NODE* p) {
	if (l.pHeal == NULL) {
		l.pHeal = l.Ptail = p;
	}
	else {
		l.Ptail->Pnext = p;
		l.Ptail = p;
	}
}
// Hàm tìm max
int timMax(LIST& l) {
	int max = l.pHeal->data;
	for (NODE* k = l.pHeal->Pnext; k != NULL; k = k->Pnext) {
		if (k->data > max) {
			max = k->data;
		}
	}
	return max;
}
// Kĩ thuật thêm NODE p vào sau NODE q trong ds lk
void themVaosau1Node(LIST& l, NODE* p) {
	int x; cout << "\nNhap gia trị q: "; cin >> x;
	NODE* q = KhoiTaoNODE(x);
	for (NODE* k = l.pHeal; k != NULL; k = k->Pnext) {
		if (q->data == k->data) {
			NODE* h = KhoiTaoNODE(p->data);
			h->Pnext = k->Pnext;
			k->Pnext = h;
		}
	}
}
// Kĩ thuật thêm node p trước node q trong danh sách
void themVaotruoc1Node(LIST& l, NODE* p) {
	int x; cout << "\n Nhap gia tri q: "; cin >> x;
	NODE* q = KhoiTaoNODE(x);
	NODE* g = new NODE;
	for (NODE* k = l.pHeal; k != NULL; k = k->Pnext) {
		
		if (q->data == k->data) {
			NODE* h = KhoiTaoNODE(p->data);
			h->Pnext = k;
			g->Pnext = h;
		}
		g = k;
	}
}
// Hàm thêm node vào bất kì trong node
void ThemBatKi(LIST& l, NODE*p, int vt) {
	int n = 0;
	for (NODE* k = l.pHeal; k != NULL; k = k->Pnext) {
		n++;
	}
	if (l.pHeal == NULL || vt == 1) {
		ThemVaoDau(l, p);
	}
	else if (vt == n + 1) {
		ThemVaoCuoi(l, p);
	}
	else {
		int dem=0;
		NODE* g = new NODE;
		for (NODE* k = l.pHeal; k != NULL; k = k->Pnext) {
			dem++;
			if (dem == vt) {
				NODE* h = KhoiTaoNODE(p->data);
				h->Pnext = k;
				g->Pnext = h;
				break;
			}
			g = k;
		}
	}
}
//Hàm xóa node đầu và cuối
void xoaDau(LIST& l) {
	if (l.pHeal == NULL) {
		return;
	}
	NODE* p = l.pHeal;// gán thế mạng
	l.pHeal = l.pHeal->Pnext;
	delete p;
}
// hàm xóa node cuối
void xoaCuoi(LIST& l) {
	if (l.pHeal == NULL) {
		return;
	}
	for (NODE* k = l.pHeal; k != NULL; k = k->Pnext) {
		if (k->Pnext == l.Ptail) {
			delete l.Ptail;
			k->Pnext = NULL;
			l.Ptail = k;
			return;
		}
		if (l.pHeal->Pnext == NULL) {
			xoaDau(l);
		}
	}
}
// Hàm xóa 1 node nằm sau node q
void xoaSauq(LIST& l, NODE* q) {
	for (NODE* k = l.pHeal; k != NULL; k = k->Pnext) {
		if (k->data == q->data) {
			NODE* g = k->Pnext;
			k->Pnext = g->Pnext;
			delete g;
		}
	}
}
// hàm xóa 1 node bất kì
void xoaBatKi(LIST& l, int x) {
	if (l.pHeal->data == x) {
		xoaDau(l);
		return;
	}
	if (l.Ptail->data == x) {
		xoaCuoi(l);
		return;
	}
	NODE* g = new NODE;
	for (NODE* k = l.pHeal; k != NULL; k = k->Pnext) {
		if (k->data == x) {
			g->Pnext = k->Pnext;
			delete k;
		}
		g = k;
	}
}
// Hàm xuất ra màn hình
void xuatManHinh(LIST l) {
	for (NODE* k = l.pHeal; k != NULL; k=k->Pnext) {
		cout << k->data << " ";
	}
}
void Menu(LIST& l) {
	int luachon;
	while (true) {
		system("cls");
		cout << "\n1.Nhap vao";
		cout << "\n2.Xuat ra";
		cout << "\n3.Max";
		cout << "\n4.Them vao sau node q: ";
		cout << "\n5.Them vao truoc node q: ";
		cout << "\n6.Them vao vi tri bat ki: ";
		cout << "\n7. Xoa Node dau tien: ";
		cout << "\n8.Xoa node cuoi cung: ";
		cout << "\n\t\tNhap: "; cin >> luachon;
		if (luachon == 1) {
			int x; cout << "Nhap gia trị: "; cin >> x;
			NODE* p = KhoiTaoNODE(x);
			//ThemVaoCuoi(l, p);
			ThemVaoDau(l, p);
		}
		else if (luachon == 2) {
			xuatManHinh(l);
			system("pause");
		}
		else if (luachon == 3) {
			cout<<"Max: "<<timMax(l);
			system("pause");
		}
		else if (luachon == 4) {
			int x; cout << "\n Nhap vao p:";
			cin >> x;
			NODE* p = KhoiTaoNODE(x);
			themVaosau1Node(l, p);
		}
		else if (luachon == 5) {
			int x; cout << "\n Nhap vao p: ";
			cin >> x;
			NODE* p = KhoiTaoNODE(x);
			themVaotruoc1Node(l, p);
		}
		else if(luachon==6) {
			int x; cout << "Nhap vao p: ";
			cin >> x;
			NODE* p = KhoiTaoNODE(x);
			int vt; cout << "Nhap vao vi tri can them";
			cin >> vt;
			ThemBatKi(l, p, vt);
		}
		else if (luachon == 7) {
			xoaDau(l);
		}
		else if (luachon == 8) {
			xoaCuoi(l);
		}
		else {
			break;
		}
	}
}
int main() {
	LIST l;
	KhoiTaoList(l);
	Menu(l);
}