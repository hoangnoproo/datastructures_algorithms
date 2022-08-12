#include<iostream>
#include<iomanip>
#include<string>
#include<cstdio>
#include<fstream>
#include<math.h>
#include<cstring>
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
nodeNv* khoiTaoNodeNv(nhanVien x) {
	nodeNv* p = new nodeNv;
	if (p == NULL) {
		return NULL;
	}
	p->nv = x;
	p->pNext = NULL;
	return p;
}
void nhapNv(nhanVien& x) {
	cin.ignore();
	cout << "\n Nhap ten: "; getline(cin, x.tenNv);
	cout << "\n Nhap ma: "; cin >> x.maNv;
	cin.ignore();
	cout << "\nNhap gioi tinh: "; getline(cin, x.gt);
}
void hienNv(nhanVien x) {
	cout << "\n Ten nhan vien tao phieu: " << x.tenNv;
	cout << "\n Ma so nhan vien: " << x.maNv;
	cout << "\n Gioi tinh: " << x.gt;
}
void Ghi_Thong_Tin_Nhan_Vien(ofstream& fileout, nhanVien nv)
{
	fileout << nv.tenNv << ", ";
	fileout <<nv.maNv << ", ";
	fileout << nv.gt;
}
void Doc_Thong_Tin_Nhan_Vien(ifstream& filein, nhanVien& nv)
{
	getline(filein, nv.tenNv, ',');
	filein.seekg(1, 1);
	filein >> nv.maNv;
	filein.seekg(1, 1);
	getline(filein, nv.gt, ',');
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
nodeKh* khoiTaoNodeKh(khachHang x) {
	nodeKh* p = new nodeKh;
	if (p == NULL) {
		return NULL;
	}
	p->kh = x;
	p->pNext = NULL;
	return p;
}
void nhapkH(khachHang& x) {
	cout << "\n Nhap ten: "; getline(cin, x.name);
	cout << "\n Nhap ma: "; cin >> x.ma;
	cin.ignore();
	cout << "\nNhap SDT: "; getline(cin, x.sdt);
}
void inKH(khachHang x) {
	cout << "\n Ten khach hang: " << x.name;
	cout << "\n Ma khach hang: " << x.ma;
	cout << "\n So dien thoai khach hang: " << x.sdt;
}
void Ghi_Thong_Tin_Khach_Hang(ofstream& fileout, khachHang kh)
{
	fileout << kh.name << ", ";
	fileout << kh.ma << ", ";
	fileout << kh.sdt;
}
void Doc_Thong_Tin_Khach_Hang(ifstream& filein, khachHang& kh)
{
	getline(filein, kh.name, ',');
	filein.seekg(1, 1); 
	filein >> kh.ma;
	filein.seekg(1, 1); 
	getline(filein, kh.sdt, ',');
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
struct listVl {
	nodeVl* pHead;
	nodeVl* pTail;
};
void KhoiTaoListVl(listVl& l) {
	l.pHead = NULL;
	l.pTail = NULL;
}
nodeVl* khoiTaoNodeVl(vatLieu x) {
	nodeVl* p = new nodeVl;
	if (p == NULL) {
		cout << "\n Het bo nho!";
		return NULL;
	}
	p->vl = x;
	p->pNext = NULL;
	return p;
}
void nhapVL(vatLieu& x) {
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
void Ghi_Thong_Tin_1_Vat_Lieu(ofstream& fileout, vatLieu vl)
{
	fileout << vl.tenVl << ", ";
	fileout <<vl.maVl<< ", ";
	fileout << vl.donGia << ", ";
	fileout << vl.soLuong << ", ";
	fileout << vl.thanhTien;
}
void Doc_Thong_Tin_1_Vat_Lieu(ifstream& filein, vatLieu& vl)
{
	getline(filein, vl.tenVl, ',');
	filein.seekg(1, 1); 
	filein >> vl.maVl;
	filein.seekg(1, 1); 
	filein >> vl.donGia;
	filein.seekg(1, 1); 
	filein >> vl.soLuong;
	filein.seekg(1, 1);
	filein >> vl.thanhTien;
	filein.seekg(1, 1);
}
void inVL(vatLieu x) {
	cout << "\n" << setw(16) << x.tenVl;
	cout << setw(16) << x.maVl;
	cout << setw(15) << x.donGia;
	cout << setw(10) << x.soLuong;
	cout << setw(15) << size_t(x.thanhTien);
}

void chenDauVl(listVl& l, nodeVl* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void nhapDsVL(listVl& l) {
	int n;
	nodeVl* vl;
	vatLieu x;
	cout << "\n Nhap so vat lieu: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "\n Vat lieu thu: " << i + 1;
		nhapVL(x);
		vl = khoiTaoNodeVl(x);
		chenDauVl(l, vl);
	}
}
float TongTienVL(listVl l) {
	float tongTien = 0;
	for (nodeVl* p = l.pHead; p != NULL; p = p->pNext) {
		tongTien += p->vl.thanhTien;
	}
	return tongTien;
}
void Luu_File_Danh_Sach_Vat_Lieu(listVl l)
{
	ofstream fileout;
	fileout.open("DSVL.TXT", ios::out);
	for (nodeVl* k = l.pHead; k != NULL; k = k->pNext)
	{
		Ghi_Thong_Tin_1_Vat_Lieu(fileout, k->vl);
		fileout << endl;
	}
	fileout.close();
}
void Doc_Danh_Sach_Vat_Lieu(ifstream& filein, listVl& l)
{
	ifstream filein;
	filein.open("DSVL.TXT", ios::in);
	while (!filein.eof())
	{
		vatLieu pb;
		Doc_Thong_Tin_1_Vat_Lieu(filein, pb);
		nodeVl* p = khoiTaoNodeVl(pb);
		chenDauVl(l, p);
	}
}
void inDSVL(listVl l) {
	cout << "\n\t Danh sach cac vat lieu";
	table();
	for (nodeVl* p = l.pHead; p != NULL; p = p->pNext) {
		inVL(p->vl);
	}
}
struct date {
	int day;
	int month;
	int year;
};
void Doc_Ngay_Thang_Nam(ifstream& filein, date& date)
{
	filein >> date.day;
	filein.seekg(1, 1); 
	filein >> date.month;
	filein.seekg(1, 1); 
	filein >> date.year;
}
struct phieuBan {
	nhanVien nv;
	date ngay;
	int maPh;
	khachHang kh;
	listVl dsvl;
	float tongTien;
};
struct nodePhieuBan {
	phieuBan pb;
	struct nodePhieuBan* pNext;
};
struct listPhieuBan {
	nodePhieuBan* pHead;
	nodePhieuBan* pTail;
};
void khoiTaoListPhieu(listPhieuBan& l) {
	l.pHead = NULL;
	l.pTail = NULL;
}
nodePhieuBan* khoiTaonodePhieu(phieuBan& pb) {
	nodePhieuBan* p = new nodePhieuBan;
	if (p == NULL) {
		return NULL;
	}
	p->pb = pb;
	p->pNext = NULL;
	return p;
}
void nhapPhieu(phieuBan& x) {
	cout << "\nNhap ngay: "; cin >> x.ngay.day;
	cout << "\n Nhap thang: "; cin >> x.ngay.month;
	cout << "\nNhap nam: "; cin >> x.ngay.year;
	cout << "\n Nhap ma phieu: "; cin >> x.maPh;
	cout << "\n\t Nhap nhan vien lam phieu: ";
	nhapNv(x.nv);
	cout << "\n\tNhap thong tin khach hang ";
	nhapkH(x.kh);
	KhoiTaoListVl(x.dsvl);
	nhapDsVL(x.dsvl);
	x.tongTien = (size_t)TongTienVL(x.dsvl);
}
void Ghi_Thong_Tin_1_Phieu(ofstream& fileout, phieuBan pb)
{
	fileout << pb.ngay.day << "/" << pb.ngay.month << "/" << pb.ngay.year;
	fileout << pb.maPh << ", ";
	Ghi_Thong_Tin_Nhan_Vien(fileout, pb.nv);
	fileout << ",";
	Ghi_Thong_Tin_Khach_Hang(fileout, pb.kh);
	fileout << ",";
	listVl l=pb.dsvl ;
	for (nodeVl* k = l.pHead; k != NULL; k = k->pNext)
	{
		Ghi_Thong_Tin_1_Vat_Lieu(fileout, k->vl);
	
	}
}
void Doc_Thong_Tin_1_Phieu(ifstream& filein, phieuBan& pb)
{
	Doc_Ngay_Thang_Nam(filein, pb.ngay);
	filein.seekg(2, 1);
	filein >> pb.maPh;
	filein.seekg(1, 1);
	Doc_Thong_Tin_Nhan_Vien(filein, pb.nv);
	filein.seekg(1, 1);
	Doc_Thong_Tin_Khach_Hang(filein, pb.kh);
	filein.seekg(1, 1);
	
	string temp;
	getline(filein, temp);
}
void inPhieu(phieuBan x) {
	listVl l;
	cout << "\n Ngay thang: " << x.ngay.day << "/" << x.ngay.month << "/" << x.ngay.year;
	cout << "\n Ma phieu: " << x.maPh;
	cout << "\n\t Thong tin nhan vien";
	hienNv(x.nv);
	cout << "\n\t Thong tin khach hang";
	inKH(x.kh);
	inDSVL(x.dsvl);
	cout << "\n Tong tien: " << TongTienVL(x.dsvl);
}
void chenVaoDauPhieu(listPhieuBan& l, nodePhieuBan* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void chenVaoCuoiPhieu(listPhieuBan& l, nodePhieuBan* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
float timKiemPhieuCoTongTienMin(listPhieuBan l) {
	float min = l.pHead->pb.tongTien;
	for (nodePhieuBan* k = l.pHead->pNext; k != NULL; k = k->pNext) {
		if (k->pb.tongTien < min) {
			min = k->pb.tongTien;
		}
	}
	for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->pb.tongTien == min) {
			return min;
		}
	}
}
float timkiemPhieuCoTongTienMax(listPhieuBan l) {
	float max = 0;
	for (nodePhieuBan* k = l.pHead->pNext; k != NULL; k = k->pNext) {
		if (k->pb.tongTien > max) {
			max = k->pb.tongTien;
		}
	}
	for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->pb.tongTien == max) {
			return max;
		}
	}
}
void PhieuCoTongTienMin(listPhieuBan l) {
	for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->pb.tongTien == timKiemPhieuCoTongTienMin(l)) {
			inPhieu(k->pb);
		}
	}
}
void themVaoSauPhieuCoTienMin(listPhieuBan& l) {
	phieuBan pb;
	cout << "\n Nhap phieu can them!";
	nhapPhieu(pb);
	nodePhieuBan* p = khoiTaonodePhieu(pb);
	for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->pb.tongTien == timKiemPhieuCoTongTienMin(l)) {
			nodePhieuBan* h = khoiTaonodePhieu(p->pb);
			h->pNext = k->pNext;
			k->pNext = h;
		}
	}
}
void themVaoTruocPhieuCoTienMax(listPhieuBan& l) {
	phieuBan pb;
	cout << "\n Nhap phieu can them!";
	nhapPhieu(pb);
	nodePhieuBan* p = khoiTaonodePhieu(pb);
	nodePhieuBan* g = new nodePhieuBan;
	if (l.pHead == NULL || l.pHead == p) {
		chenVaoDauPhieu(l, p);
	}
	for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->pb.tongTien == timkiemPhieuCoTongTienMax(l)) {
			nodePhieuBan* h = khoiTaonodePhieu(p->pb);
			h->pNext = k;
			g->pNext = h;
		}
		g = k;
	}
}
void themVaoViTriBatKi(listPhieuBan& l, nodePhieuBan* p) {
	int vt;
	cout << "\n Nhap vi tri k can them vao";
	cin >> vt;
	int n = 0;
	for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext) {
		n++;
	}
	if (l.pHead == NULL || vt == 1) {
		chenVaoDauPhieu(l, p);
	}
	if (vt == n + 1) {
		chenVaoCuoiPhieu(l, p);
	}
	else {
		int dem = 0;
		nodePhieuBan* g = new nodePhieuBan;
		for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext) {
			dem++;
			if (dem == vt) {
				nodePhieuBan* h = khoiTaonodePhieu(p->pb);
				h->pNext = k;
				g->pNext = h;
				break;
			}
			g = k;
		}
	}
}
void nhapDSPhieuBan(listPhieuBan& l) {
	int n;
	phieuBan x;
	cout << "\nNhap so phieu ban: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "\n Phieu ban thu: " << i + 1;
		nhapPhieu(x);
		nodePhieuBan* pb = khoiTaonodePhieu(x);
		chenVaoCuoiPhieu(l, pb);
	}
}
void inDsPhieuBan(listPhieuBan l) {
	cout << "\n\t DANH SACH CAC PHIEU DA DUOC TAO";
	int dem = 0;
	for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext) {
		cout << "\n ====Phieu ban==== ";
		inPhieu(k->pb);
	}
}
void Luu_File_Danh_Sach_Phieu(listPhieuBan l)
{
	ofstream fileout;
	fileout.open("DSPhieuBan.TXT", ios::out);
	for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext)
	{
		Ghi_Thong_Tin_1_Phieu(fileout, k->pb);
		fileout << endl;
	}
	fileout.close();
}
void Doc_Danh_Sach_Phieu( listPhieuBan& l)
{
	ifstream filein;
	filein.open("DSPhieuBan.TXT", ios::in);
	while (!filein.eof())
	{
		phieuBan pb;
		Doc_Thong_Tin_1_Phieu(filein, pb);
		nodePhieuBan* p = khoiTaonodePhieu(pb);
		chenVaoCuoiPhieu(l, p);
	}
}

void sapXepTangDSPhieuBanTheoTongTien(listPhieuBan& l) {
	for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext) {
		for (nodePhieuBan* h = l.pHead->pNext; h != NULL; h = h->pNext) {
			if (k->pb.tongTien > h->pb.tongTien) {
				swap(k->pb, h->pb);
			}
		}
	}
}
void tongTienThuPhieu(listPhieuBan& l) {
	int tien = 0;
	for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext) {
		tien += k->pb.tongTien;
	}
	cout << "\n Tong tien thu duoc: " << tien;
}
// Hàm tìm kiếm theo tên khách hàng
// Hàm tách tên
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
void timKiemTheoTen(listPhieuBan& l) {
	string tenKh;
	cout << "\n Nhap ten khach hang can tim: ";
	cin.ignore();
	getline(cin, tenKh);
	for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext) {
		string ten = tenKhachHang(k->pb.kh.name);
		if (_strcmpi((char*)ten.c_str(), (char*)tenKh.c_str()) == 0) {
			inPhieu(k->pb);
		}
		cout << endl;
	}
}
void timKiemMaNhanVien(listPhieuBan& l) {
	int id;
	cout << "\n Nhap ma can tim: "; cin >> id;
	for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext) {
		if (id == k->pb.nv.maNv) {
			inPhieu(k->pb);
		}
	}
}
void XoaDauDanhSachPhieu(listPhieuBan& l) {
	if (l.pHead == NULL) {
		return;
	}
	nodePhieuBan* p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;
}
void XoaCuoiDanhSach(listPhieuBan& l) {
	if (l.pHead == NULL) {
		return;
	}
	for (nodePhieuBan* p = l.pHead; p != NULL; p = p->pNext) {
		if (p->pNext == l.pTail) {
			delete l.pTail;
			p->pNext = NULL;
			l.pTail = p;
			return;
		}
	}
	if (l.pHead->pNext == NULL) {
		XoaDauDanhSachPhieu(l);
	}
}
void xoa1PhieuBatKiTheoMaNV(listPhieuBan& l) {
	int id;
	cout << "\nNhap id cua nhan vien can xoa: "; cin >> id;
	if (l.pHead->pb.nv.maNv == id) {
		XoaDauDanhSachPhieu(l);
		return;
	}
	if (l.pTail->pb.nv.maNv == id) {
		XoaCuoiDanhSach(l);
		return;
	}
	nodePhieuBan* g = new nodePhieuBan;
	for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->pb.nv.maNv == id) {
			g->pNext = k->pNext;
			delete k;
			return;
		}
		g = k;
	}
}


void GiaiPhongBoNho(listPhieuBan& l) {
	nodePhieuBan* k = new nodePhieuBan;
	while (l.pHead != NULL) {
		k = l.pHead;
		l.pHead = l.pHead->pNext;
		delete k;
	}
}
void SuatheomaPB(listPhieuBan& l) {
	int id;
	bool kt = false;
	cout << "\n Nhap ma phieu can tim: "; cin >> id;
	for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext) {
		if (id == k->pb.maPh) {
			//			int x;
			//			cout<<"\n Sua lai ma nhan vien";
			//			cin>>x;
			//			k->pb.nv.maNv=x;
			listVl a;
			KhoiTaoListVl(a);
			cout << "\n Nhap lai danh sach: ";
			nhapDsVL(a);
			k->pb.dsvl = a;
			kt = true;
			inPhieu(k->pb);
		}
	}
	if (kt == false) {
		cout << "\n Khong co phieu chua ma: " << id;
	}
}
void menu(listPhieuBan& l) {
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
		cout << "\n\t 9. Them phieu vao vi tri bat ki la K duoc nhap tu ban phim";
		cout << "\n\t10. Sap xep danh sach tang dan theo tong tien cua phieu";
		cout << "\n\t11. Tong tien thu lai cua cac phieu";
		cout << "\n\t12. Tim kiem phieu theo ten khach hang duoc nhap tu ban phim";
		cout << "\n\t13. Tim kiem phieu theo ma nhan vien tao phieu";
		cout << "\n\t14. Xoa phieu o dau danh sach";
		cout << "\n\t15. Xoa phieu o cuoi danh sach";
		cout << "\n\t16. Xoa phieu cua nhan vien ma X tao";
		cout << "\n\t17. Sua thong tin ve danh sach vat lieu: ";
		cout << "\n\t18. Giai phong bo nho cap phat";
		cout << "\n Lua chon cua ban: ";
		cin >> chon;
		if (chon == 1) {
			nhapDSPhieuBan(l);
		}
		else if (chon == 2) {
			inDsPhieuBan(l);
			system("pause");
		}
		else if (chon == 3) {
			
			system("pause");
		}
		else if (chon == 4) {
			Doc_Danh_Sach_Phieu(l);
			cout << "\n Doc file thanh cong";
			system("pause");
		}
		else if (chon == 5) {
			cout << "\n Nhap phieu can them!";
			phieuBan pb;
			nhapPhieu(pb);
			nodePhieuBan* p = khoiTaonodePhieu(pb);
			chenVaoDauPhieu(l, p);
		}
		else if (chon == 6) {
			cout << "\n\t Phieu co tong tien nho nhat la: ";
			PhieuCoTongTienMin(l);
			system("pause");
		}
		else if (chon == 7) {
			themVaoSauPhieuCoTienMin(l);
		}
		else if (chon == 8) {
			themVaoTruocPhieuCoTienMax(l);
		}
		else if (chon == 9) {
			cout << "\n Nhap phieu can them!";
			phieuBan pb;
			nhapPhieu(pb);
			nodePhieuBan* p = khoiTaonodePhieu(pb);
			themVaoViTriBatKi(l, p);
		}
		else if (chon == 10) {
			sapXepTangDSPhieuBanTheoTongTien(l);
			inDsPhieuBan(l);
			system("pause");
		}
		else if (chon == 11) {
			tongTienThuPhieu(l);
			system("pause");
		}
		else if (chon == 12) {
			cout << "\n Phieu can tim";
			timKiemTheoTen(l);
			system("pause");
		}
		else if (chon == 13) {
			cout << "\n Phieu can tim";
			timKiemMaNhanVien(l);
			system("pause");
		}
		else if (chon == 14) {
			XoaDauDanhSachPhieu(l);
		}
		else if (chon == 15) {
			XoaCuoiDanhSach(l);
		}
		else if (chon == 16) {
			xoa1PhieuBatKiTheoMaNV(l);
		}
		else if (chon == 17) {
			SuatheomaPB(l);
			system("pause");
		}
		else if (chon == 18) {
			GiaiPhongBoNho(l);
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
	listPhieuBan l;
	khoiTaoListPhieu(l);
	menu(l);
	return 0;
}
