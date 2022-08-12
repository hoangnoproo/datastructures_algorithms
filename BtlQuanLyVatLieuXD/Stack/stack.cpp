#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<math.h>
using namespace std;
struct nhanVien {
	int maNv;
	string tenNv;
	string gt;
};
struct nodeNv {
	nhanVien nv;
	struct nodeNv* pNext;
};
void NhapNhanVien(nhanVien& x) {
	cout << "\n Nhap ma nhan vien: "; cin >> x.maNv;
	cin.ignore();
	cout << "\n Nhap ten nhan vien: "; getline(cin, x.tenNv);
	cout << "\n Nhap gioi tinh: "; getline(cin, x.gt);
}
void hienNhanVien(nhanVien x) {
	cout << "\n Ma nhan vien: " << x.maNv;
	cout << "\n Ten nhan vien: " << x.tenNv;
	cout << "\n Nhap gioi tinh: " << x.gt;
}
struct khachHang {
	int ma;
	string name;
	string sdt;
};
struct nodeKh {
	khachHang kh;
	struct nodeKh* pNext;
};
void nhapKhachHang(khachHang& x) {
	cout << "\n Nhap ma khach hang: "; cin >> x.ma;
	cin.ignore();
	cout << "\n Nhap ten khach hang: "; getline(cin, x.name);
	cout << "\n Nhap vao sdt: "; getline(cin, x.sdt);
}
void hienKhachHang(khachHang x) {

	cout << "\n Ma khach hang: " << x.ma;
	cout << "\n Ten khach hang: " << x.name;
	cout << "\n SDT: " << x.sdt;
}
struct vatLieu {
	string tenVl;
	int maVl;
	float donGia;
	int soLuong;
	float thanhTien;
};
struct nodeVl {
	vatLieu vl;
	struct nodeVl* pNext;
};
struct stackvl {
	nodeVl* pTop;
};
void khoiTaoStackvl(stackvl& s) {
	s.pTop = NULL;
}
nodeVl* khoiTaoNodeVl(vatLieu& x) {
	nodeVl* p = new nodeVl;
	if (p == NULL) {
		cout << "\n Khong du bo nho";
		return NULL;
	}
	p->vl = x;
	p->pNext = NULL;
	return p;
}
void nhapVatLieu(vatLieu& x) {
	cin.ignore();
	cout << "\n Nhap ten: "; getline(cin, x.tenVl);
	cout << "\n Nhap ma VL: "; cin >> x.maVl;
	cout << "\n Nhap don gia: "; cin >> x.donGia;
	cout << "\n Nhap so luong: "; cin >> x.soLuong;
	x.thanhTien = x.soLuong * x.donGia;
}
void table() {
	cout << "\n" << setw(16) << "Ten vat lieu";
	cout << setw(16) << "Ma vat lieu";
	cout << setw(15) << "Don gia";
	cout << setw(10) << "So luong";
	cout << setw(15) << "Thanh tien";

}
void hienVatLieu(vatLieu x) {
	cout << "\n" << setw(16) << x.tenVl;
	cout << setw(16) << x.maVl;
	cout << setw(15) << x.donGia;
	cout << setw(10) << x.soLuong;
	cout << setw(15) << size_t(x.thanhTien);
}

// Hàm kiểm tra xem stack còn rỗng hay không
bool IsEmpty(stackvl s) {
	if (s.pTop == NULL) {
		return true;
	}
	return false;
}
// Hàm thêm 1 phần tử vào stack
bool Push(stackvl& s, nodeVl* p) {
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

// Hàm lấy ra 1 phần tử đầu xem và hủy nó đi
bool Pop(stackvl& s, vatLieu& vl) {
	if (IsEmpty(s) == true) {
		return false;
	}
	else {
		nodeVl* p = s.pTop;
		vl = p->vl;
		s.pTop = s.pTop->pNext;
		//delete p;
	}
	return true;
}
// Hàm chỉ hiện ra xem và không xóa nó đi
bool Top(stackvl& s, vatLieu& vl) {
	if (IsEmpty(s) == true) {
		return false;
	}
	vl = s.pTop->vl;
	return true;
}
void nhapDSVL(stackvl& s) {
	int n;
	cout << "\n Nhap so vat lieu: "; cin >> n;
	vatLieu x;
	nodeVl* vl;
	for (int i = 0; i < n; i++) {
		nhapVatLieu(x);
		vl = khoiTaoNodeVl(x);
		Push(s, vl);
	}
}
void hienDSVL(stackvl s) {
	table();
	while (IsEmpty(s) == false) {
		vatLieu x;
		Pop(s, x);
		hienVatLieu(x);
	}
}
float tongTienVL(stackvl s) {
	float tongTien = 0;
	for (nodeVl* p = s.pTop; p != NULL; p = p->pNext) {
		tongTien += p->vl.thanhTien;
	}
	return tongTien;
}
struct date {
	int day;
	int month;
	int year;
};
struct phieuBan {
	nhanVien nv;
	date ngay;
	int maPh;
	khachHang kh;
	stackvl dsvl;
	float tongTien;
};
struct nodePhieuBan {
	phieuBan pb;
	struct nodePhieuBan* pNext;
};
struct stackphieuBan {
	nodePhieuBan* pTop;
};
void khoiTaoStackPb(stackphieuBan& s) {
	s.pTop = NULL;
}
nodePhieuBan* khoiTaoNodePB(phieuBan& x) {
	nodePhieuBan* p = new nodePhieuBan;
	if (p == NULL) {
		cout << "\n Khong du bo nho";
		return NULL;
	}
	p->pb = x;
	p->pNext = NULL;
	return p;
}
void NhapPhieu(phieuBan& x) {
	cout << "\nNhap ngay: "; cin >> x.ngay.day;
	cout << "\n Nhap thang: "; cin >> x.ngay.month;
	cout << "\nNhap nam: "; cin >> x.ngay.year;
	cout << "\n Nhap ma phieu: "; cin >> x.maPh;
	cout << "\n\t Nhap nhan vien lam phieu: ";
	NhapNhanVien(x.nv);
	cout << "\n Nhap thong tin khach hang: ";
	nhapKhachHang(x.kh);
	khoiTaoStackvl(x.dsvl);
	nhapDSVL(x.dsvl);
	x.tongTien = tongTienVL(x.dsvl);
}
void HienPhieu(phieuBan x) {
	cout << "\n Ngay thang: " << x.ngay.day << "/" << x.ngay.month << "/" << x.ngay.year;
	cout << "\n Ma phieu: " << x.maPh;
	cout << "\n\t Thong tin nhan vien";
	hienNhanVien(x.nv);
	cout << "\n\t Thong tin khach hang";
	hienKhachHang(x.kh);
	hienDSVL(x.dsvl);
	cout << "\n Tong tien: " << x.tongTien;
}

bool IsEmptyPB(stackphieuBan& s) {
	if (s.pTop == NULL) {
		return true;
	}
	return false;
}
bool PushPB(stackphieuBan& s, nodePhieuBan*p) {
	if (p == NULL) {
		return NULL;
	}
	if (IsEmptyPB(s) == true) {
		s.pTop = p;
	}
	else {
		p->pNext = s.pTop;
		s.pTop = p;
	}
	return true;
}
bool PopPB(stackphieuBan& s, phieuBan& pb) {
	if (IsEmptyPB(s) == true) {
		return false;
	}
	else {
		nodePhieuBan* p = s.pTop;
		pb = p->pb;
		s.pTop = s.pTop->pNext;
		//delete p;
	}
	return true;
}
void nhapDSPhieu(stackphieuBan& s) {
	cout << "\n Nhap so luong phieu ban: "; int n; cin >> n;
	phieuBan x;
	nodePhieuBan* p;
	for (int i = 0; i < n; i++) {
		cout << "\n Nhap phieu thu: " << i + 1;
		NhapPhieu(x);
		p = khoiTaoNodePB(x);
		PushPB(s, p);
	}
}
void hienDSPhieuban(stackphieuBan s) {
	while (IsEmptyPB(s) == false) {
		phieuBan x;
		PopPB(s, x);
		HienPhieu(x);
		cout << "\n\t\t*---------------------------------*\n";
	}
}
void ghiFile(stackphieuBan& l) {
	fstream f;
	f.open("PhieuBanStack.txt", ios::out);
	for (nodePhieuBan* k = l.pTop; k != NULL; k = k->pNext) {
		f.write((char*)&(k->pb), sizeof(phieuBan));
	}
	f.close();
	cout << "\n Ghi file thanh cong";
}
void docFile(stackphieuBan& l) {
	fstream f;
	f.open("PhieuBanStack.txt", ios::in);
	phieuBan x;
	nodePhieuBan* p;
	khoiTaoStackPb(l);
	while (f.read((char*)&x, sizeof(phieuBan))) {
		p = khoiTaoNodePB(x);
		PushPB(l, p);
	}
	f.close();
	cout << "\nDoc file thanh cong..\n";
	hienDSPhieuban(l);
}
float timKiemTongTienMin(stackphieuBan l) {
	float min = l.pTop->pb.tongTien;
	for (nodePhieuBan* k = l.pTop->pNext; k != NULL; k = k->pNext) {
		if (k->pb.tongTien < min) {
			min = k->pb.tongTien;
		}
	}
	for (nodePhieuBan* k = l.pTop; k != NULL; k = k->pNext) {
		if (k->pb.tongTien == min) {
			return min;
		}
	}
}
float timkiemPhieuCoTongTienMax(stackphieuBan l) {
	float max = 0;
	for (nodePhieuBan* k = l.pTop->pNext; k != NULL; k = k->pNext) {
		if (k->pb.tongTien > max) {
			max = k->pb.tongTien;
		}
	}
	for (nodePhieuBan* k = l.pTop; k != NULL; k = k->pNext) {
		if (k->pb.tongTien == max) {
			return max;
		}
	}
}
void PhieuCoTongTienMin(stackphieuBan l) {
	for (nodePhieuBan* k = l.pTop; k != NULL; k = k->pNext) {
		if (k->pb.tongTien == timKiemTongTienMin(l)) {
			HienPhieu(k->pb);
		}
	}
}
void themVaoSauPhieuCoTienMin(stackphieuBan& l) {
	phieuBan pb;
	cout << "\n Nhap phieu can them!";
	NhapPhieu(pb);
	nodePhieuBan* p = khoiTaoNodePB(pb);
	for (nodePhieuBan* k = l.pTop; k != NULL; k = k->pNext) {
		if (k->pb.tongTien == timKiemTongTienMin(l)) {
			nodePhieuBan* h = khoiTaoNodePB(p->pb);
			h->pNext = k->pNext;
			k->pNext = h;
		}
	}
}
void themVaoTruocPhieuCoTienMax(stackphieuBan& l) {
	phieuBan pb;
	cout << "\n Nhap phieu can them!";
	NhapPhieu(pb);
	nodePhieuBan* p = khoiTaoNodePB(pb);
	nodePhieuBan* g = new nodePhieuBan;
	if (l.pTop == NULL || l.pTop == p) {
		PushPB(l, p);
	}
	for (nodePhieuBan* k = l.pTop; k != NULL; k = k->pNext) {
		if (k->pb.tongTien == timkiemPhieuCoTongTienMax(l)) {
			nodePhieuBan* h = khoiTaoNodePB(p->pb);
			h->pNext = k;
			g->pNext = h;
		}
		g = k;
	}
}
void themVaoViTriBatKi(stackphieuBan& l, nodePhieuBan* p) {
	int vt;
	cout << "\n Nhap vi tri k can them vao";
	cin >> vt;
	int n = 0;
	for (nodePhieuBan* k = l.pTop; k != NULL; k = k->pNext) {
		n++;
	}
	if (l.pTop == NULL || vt == 1) {
		PushPB(l, p);
	}
	else {
		int dem = 0;
		nodePhieuBan* g = new nodePhieuBan;
		for (nodePhieuBan* k = l.pTop; k != NULL; k = k->pNext) {
			dem++;
			if (dem == vt) {
				nodePhieuBan* h = khoiTaoNodePB(p->pb);
				h->pNext = k;
				g->pNext = h;
				break;
			}
			g = k;
		}
	}
}
void hoanVi(phieuBan& x, phieuBan& y) {
	phieuBan temp = x;
	x = y;
	y = temp;
}
void sapXepTangDSPhieuBanTheoTongTien(stackphieuBan& l) {
	for (nodePhieuBan* k = l.pTop; k != NULL; k = k->pNext) {
		for (nodePhieuBan* h = k->pNext; h != NULL; h = h->pNext) {
			if (k->pb.tongTien > h->pb.tongTien) {
				hoanVi(k->pb, h->pb);
			}
		}
	}
}
void tongTienThuPhieu(stackphieuBan& l) {
	int tien = 0;
	for (nodePhieuBan* k = l.pTop; k != NULL; k = k->pNext) {
		tien += k->pb.tongTien;
	}
	cout << "\n Tong tien thu duoc: " << tien;
}
string tenKhachHang(string tenKH) {
	int length = tenKH.length();
	int i;
	for (i = length - 1; i >= 0; i--) {
		if (tenKH[i] == ' ') {
			break;
		}
	}
	return tenKH.substr(i + 1);
}
void timKiemTheoTen(stackphieuBan l) {
	string tenKh;
	cout << "\n Nhap ten khach hang can tim: ";
	cin.ignore();
	bool kt = false;
	getline(cin, tenKh);
	for (nodePhieuBan* k = l.pTop; k != NULL; k = k->pNext) {
		string ten = tenKhachHang(k->pb.kh.name);
		if (_strcmpi((char*)ten.c_str(), (char*)tenKh.c_str()) == 0) {
			HienPhieu(k->pb);
			kt = true;
		}
		cout << endl;
	}
	if (kt == false) {
		cout << "\n Khong ton tai khach hang ten: " << tenKh << "\n";
	}
}
void timKiemMaNhanVien(stackphieuBan l) {
	int id;
	cout << "\n Nhap ma can tim: "; cin >> id;
	bool kt = false;
	for (nodePhieuBan* k = l.pTop; k != NULL; k = k->pNext) {
		if (id == k->pb.nv.maNv) {
			HienPhieu(k->pb);
			kt = true;
		}
	}
	if (kt == false) {
		cout << "\n Khong ton tai nhan vien ma: " << id;
	}
}
void SuatheomaPB(stackphieuBan& l) {
	int id;
	bool kt = false;
	cout << "\n Nhap ma phieu can sua thong tin: "; cin >> id;
	for (nodePhieuBan* k = l.pTop; k != NULL; k = k->pNext) {
		if (id == k->pb.maPh) {
			//			int x;
			//			cout<<"\n Sua lai ma nhan vien";
			//			cin>>x;
			//			k->pb.nv.maNv=x;
			stackvl a;
			khoiTaoStackvl(a);
			cout << "\n Nhap lai danh sach: ";
			nhapDSVL(a);
			k->pb.dsvl = a;
			kt = true;
			HienPhieu(k->pb);
		}
	}
	if (kt == false) {
		cout << "\n Khong co phieu chua ma: " << id;
	}
}
void themVaoDanhSachVL(stackphieuBan& l) {
	int ma;
	cout << "\n Nhap vao ma phieu ban can them vat lieu: ";
	cin >> ma;
	for (nodePhieuBan* k = l.pTop; k != NULL; k = k->pNext) {
		if (k->pb.maPh == ma) {
			int n, chon;
			vatLieu x;
			nodeVl* p;
			cout << "1. Chen dau" << endl;
			cout << "2. Chen cuoi" << endl;
			cout << "Lua chon: "; cin >> chon;
			switch (chon) {
			case 1:  cout << "\n\nNhap so vat lieu muon them vao dau:";
				cin >> n;
				for (int i = 0; i < n; i++)
				{
					nhapVatLieu(x);
					p = khoiTaoNodeVl(x);
					Push(k->pb.dsvl, p);
					cout << endl;
				}
				break;
			case 2:
				cout << "\n\nNhap so hoc sinh muon them vao cuoi:";
				cin >> n; cin.ignore();
				for (int i = 0; i < n; i++)
				{
					nhapVatLieu(x);
					p = khoiTaoNodeVl(x);
					Push(k->pb.dsvl, p);
					cout << endl;
				}
				break;
			}
		}
	}
}
void XoaDauDanhSachPhieu(stackphieuBan& l) {
	if (l.pTop == NULL) {
		return;
	}
	nodePhieuBan* p = l.pTop;
	l.pTop = l.pTop->pNext;
	delete p;
}

void GiaiPhongBoNho(stackphieuBan& l) {
	nodePhieuBan* k = new nodePhieuBan;
	while (l.pTop != NULL) {
		k = l.pTop;
		l.pTop = l.pTop->pNext;
		delete k;
	}
}
void menu(stackphieuBan& s) {
	int chon;
	FILE* f;
	while (true) {
		system("cls");
		cout << "\n\t      _______MENU_______";
		cout << "\n\t 1. Nhap danh sach phieu ban";
		cout << "\n\t 2. Hien danh sach phieu ban";
		cout << "\n\t 3. Luu file danh sach phieu ban";
		cout << "\n\t 4. Doc file va hien danh sach ra man hinh";
		cout << "\n\t 5. Them 1 phieu ban moi vao dau danh sach";
		cout << "\n\t 6. Tim kiem phieu co tong tien nho nhat";
		cout << "\n\t 7. Them phieu vao sau phieu con so tien luong nho nhat danh sach da co";
		cout << "\n\t 8. Them phieu vao truoc phieu con so tien luong lon nhat danh sach da co";
		cout << "\n\t 9. Sap xep danh sach tang dan theo tong tien cua phieu";
		cout << "\n\t10. Tong tien thu lai cua cac phieu";
		cout << "\n\t11. Tim kiem phieu theo ten khach hang duoc nhap tu ban phim";
		cout << "\n\t12. Tim kiem phieu theo ma nhan vien tao phieu";
		cout << "\n\t13. Sua thong tin danh sach vat lieu: ";
		cout << "\n\t14. Xoa phieu o dau danh sach";
		cout << "\n\t15. Chen them danh sach vat lieu";
		cout << "\n\t16. Giai phong bo nho cap phat";
		cout << "\n Lua chon cua ban: ";
		cin >> chon;
		if (chon == 1) {
			nhapDSPhieu(s);
		}
		else if (chon == 2) {
			hienDSPhieuban(s);
			system("pause");
		}
		else if (chon == 3) {
			ghiFile(s);
			system("pause");
		}
		else if (chon == 4) {
			docFile(s);
			system("pause");
		}
		else if (chon == 5) {
			cout << "\n Nhap phieu can them!";
			phieuBan pb;
			NhapPhieu(pb);
			nodePhieuBan* p = khoiTaoNodePB(pb);
			PushPB(s, p);
		}
		else if (chon == 6) {
			PhieuCoTongTienMin(s);
			system("pause");
		}
		else if (chon == 7) {
			themVaoSauPhieuCoTienMin(s);
		}
		else if (chon == 8) {
			themVaoTruocPhieuCoTienMax(s);
		}
		else if (chon == 9) {
			sapXepTangDSPhieuBanTheoTongTien(s);
			hienDSPhieuban(s);
			system("pause");
		}
		else if (chon == 10) {
			tongTienThuPhieu(s);
			system("pause");
		}
		else if (chon == 11) {
			cout << "\n Phieu can tim";
			timKiemTheoTen(s);
			system("pause");
		}
		else if (chon == 12) {
			cout << "\n Phieu can tim";
			timKiemMaNhanVien(s);
			system("pause");
		}
		else if (chon == 13) {
			SuatheomaPB(s);
			system("pause");
		}
		else if (chon == 14) {
			XoaDauDanhSachPhieu(s);
		}
		else if (chon == 15) {
			themVaoDanhSachVL(s);
		}
		else if (chon == 16) {
			GiaiPhongBoNho(s);
		}
		else if (chon == 0) {
			break;
		}
		else {
			cout << "\n Vui long nhap lai!";
		}
	}
}
int main() {
	stackphieuBan s;
	khoiTaoStackPb(s);
	menu(s);
}