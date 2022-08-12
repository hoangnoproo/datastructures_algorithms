#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;
struct nhanVien {
	int maNv;
	string tenNv;
	string gt;
};
struct nodeNv {
	nhanVien nv;
	struct nodeNv* pNext;
	struct nodeNv* pRev;
};
nodeNv* khoiTaoNodeNv(nhanVien &x) {
	nodeNv* p = new nodeNv;
	if (p == NULL) {
		return NULL;
	}
	p->nv = x;
	p->pNext = NULL;
	p->pRev = NULL;
	return p;
}
void NhapNhanVien(nhanVien& x) {
	cout << "\n Nhap ma nhan vien: "; cin >> x.maNv;
	cin.ignore();
	cout << "\n Nhap ten nhan vien: "; getline(cin, x.tenNv);
	cout << "\n Nhap gioi tinh: "; getline(cin, x.gt);
}
void hienNhanVien(nhanVien x) {
	cout << "\n Ma nhan vien: "<< x.maNv;
	cout << "\n Ten nhan vien: "<< x.tenNv;
	cout << "\n Nhap gioi tinh: "<< x.gt;
}
struct khachHang {
	int ma;
	string name;
	string sdt;
};
struct nodeKh {
	khachHang kh;
	struct nodeKh* pNext;
	struct nodeKh* pRev;
};
nodeKh* khoiTaoKhachHang(khachHang& x) {
	nodeKh* p = new nodeKh;
	if (p == NULL) {
		return NULL;
	}
	p->kh = x;
	p->pNext = NULL;
	p->pRev = NULL;
}
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
	struct nodeVl* pRev;
};
struct listVl {
	nodeVl* pHead;
	nodeVl* pTail;
};
void khoiTaoListVl(listVl& l) {
	l.pHead = NULL;
	l.pTail = NULL;
}
nodeVl* khoiTaoNodeVl(vatLieu& x) {
	nodeVl* p = new nodeVl;
	if (p == NULL) {
		return NULL;
	}
	p->vl = x;
	p->pNext = NULL;
	p->pRev = NULL;
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
void chenDauVatLieu(listVl& l, nodeVl*p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		l.pHead->pRev = p;
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void chenCuoiVatLieu(listVl& l, nodeVl* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		l.pTail->pNext = p;
		p->pRev = l.pTail;
		l.pTail = p;
	}
}
void nhapDSVL(listVl& l) {
	int n;
	cout << "\n Nhap so vat lieu: "; cin >> n;
	vatLieu x;
	nodeVl* vl;
	for (int i = 0; i < n; i++) {
		nhapVatLieu(x);
		vl = khoiTaoNodeVl(x);
		chenDauVatLieu(l, vl);
	}
}
void hienDSVL(listVl l) {
	table();
	for (nodeVl* p = l.pHead; p != NULL; p=p->pNext) {
		hienVatLieu(p->vl);
	}
}
float tongTienVL(listVl l) {
	float tien = 0;
	for (nodeVl* p = l.pHead; p != NULL; p=p->pNext) {
		tien += p->vl.thanhTien;
	}
	return tien;
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
	listVl dsvl;
	float tongTien;
};
struct nodePhieuBan {
	phieuBan pb;
	struct nodePhieuBan* pNext;
	struct nodePhieuBan* pRev;
};
struct listPhieuBan {
	nodePhieuBan* pHead;
	nodePhieuBan* pTail;
};
void khoiTaoList(listPhieuBan& l) {
	l.pHead = NULL;
	l.pTail = NULL;
}
nodePhieuBan* khoiTaoPhieuBan(phieuBan& x) {
	nodePhieuBan* p = new nodePhieuBan;
	if (p == NULL) {
		return NULL;
	}
	p->pb = x;
	p->pNext = NULL;
	p->pRev = NULL;
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
	khoiTaoListVl(x.dsvl);
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
	cout << "\n Tong tien: " << tongTienVL(x.dsvl);
}
void chenDauPhieu(listPhieuBan& l, nodePhieuBan*p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		l.pHead->pRev = p;
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void chenCuoiPhieu(listPhieuBan& l, nodePhieuBan* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		l.pTail->pNext = p;
		p->pRev = l.pTail;
		l.pTail = p;
	}
}
void nhapDSPhieu(listPhieuBan& l) {
	cout << "\n Nhap so luong phieu ban:"; int n; cin >> n;
	phieuBan x;
	nodePhieuBan* p;
	for (int i = 0; i < n; i++) {
		cout << "\n Nhap phieu thu: " << i+1;
		NhapPhieu(x);
		p = khoiTaoPhieuBan(x);
		chenCuoiPhieu(l,p);
	}
}
void hienDSPhieu(listPhieuBan l) {
	for (nodePhieuBan* p = l.pHead; p != NULL; p = p->pNext) {
		HienPhieu(p->pb);
		cout << "\n\t\t*---------------------------------*\n";
	}
}
void ghiFile(listPhieuBan& l) {
	fstream f;
	f.open("PhieuBanDoi.txt", ios::out);
	for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext) {
		f.write((char*)&(k->pb), sizeof(phieuBan));
	}
	f.close();
	cout << "\n Ghi file thanh cong";
}
void docFile(listPhieuBan& l) {
	fstream f;
	nodePhieuBan* p;
	phieuBan x;
	khoiTaoList(l);
	f.open("PhieuBanDoi.txt", ios::in | ios::binary);
	while (f.read((char*)&x, sizeof(phieuBan))) {
		p = khoiTaoPhieuBan(x);
		chenCuoiPhieu(l, p);
	}
	f.close();
	cout << "\nDoc file thanh cong..\n";
	hienDSPhieu(l);
}
float timKiemTongTienMin(listPhieuBan l) {
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
float timKiemTongTienMax(listPhieuBan l) {
	float max = l.pHead->pb.tongTien;
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
	for (nodePhieuBan* p = l.pHead; p != NULL; p = p->pNext) {
		if (p->pb.tongTien == timKiemTongTienMin(l)) {
			HienPhieu(p->pb);
		}
	}
}
void chenNodeVaoSauNodeCoTienMin(listPhieuBan& l) {
	phieuBan pb;
	cout << "\n Nhap phieu can them: ";
	NhapPhieu(pb);
	nodePhieuBan* p = khoiTaoPhieuBan(pb);
	for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->pb.tongTien == timKiemTongTienMin(l)) {
			nodePhieuBan* h = khoiTaoPhieuBan(p->pb);
			h->pNext = k->pNext;
			k->pNext = h;
		}
	}
}
void chenNodeVaoTruocNodeCoTienMax(listPhieuBan& l) {
	phieuBan pb;
	cout << "\n Nhap phieu can them: ";
	NhapPhieu(pb);
	nodePhieuBan* p = khoiTaoPhieuBan(pb);
	nodePhieuBan* g=new nodePhieuBan;
	if (l.pHead == NULL || l.pHead == p) {
		chenDauPhieu(l, p);
	}
	for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->pb.tongTien == timKiemTongTienMax(l)) {
			nodePhieuBan* h = khoiTaoPhieuBan(p->pb);
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
		chenDauPhieu(l, p);
	}
	if (vt == n + 1) {
		chenCuoiPhieu(l, p);
	}
	else {
		int dem = 0;
		nodePhieuBan* g = new nodePhieuBan;
		for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext) {
			dem++;
			if (dem == vt) {
				nodePhieuBan* h = khoiTaoPhieuBan(p->pb);
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
void sapXepTangDSPhieuBanTheoTongTien(listPhieuBan& l) {
	for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext) {
		for (nodePhieuBan* h = k->pNext; h != NULL; h = h->pNext) {
			if (k->pb.tongTien > h->pb.tongTien) {
				hoanVi(k->pb, h->pb);
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
// hàm tách tên
string tachten(string tenKH) {
	int length = tenKH.length();
	int i;
	for (i = length - 1;i>=0; i--) {
		if (tenKH[i] == ' ') {
			break;
		}
	}
	return tenKH.substr(i + 1);
}
void timKiemTen(listPhieuBan l) {
	cout << "\n Nhap ten khach hang can tim kiem: ";
	string ten;
	bool Kt=false;
	cin.ignore();
	getline(cin, ten);
	for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext) {
		string tenkh = tachten(k->pb.kh.name);
		if (_strcmpi((char*)ten.c_str(), (char*)tenkh.c_str()) == 0) {
			HienPhieu(k->pb);
			Kt = true;
		}
		cout << endl;
	}
	if (Kt == false) {
		cout << "\n Khong ton tai khach hang ten: " << ten;
	}
}
void timKiemTheoMaNV(listPhieuBan l) {
	cout << "\n Nhap ma nhan vien lap phieu: "; int x;
	cin >> x;
	bool kt = false;
	for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->pb.nv.maNv == x) {
			HienPhieu(k->pb);
			kt = true;
		}
	}
	if (kt == false) {
		cout << "\n Khong ton tai nhan vien ma so: " << x;
	}
}
void SuatheomaPB(listPhieuBan& l) {
	int id;
	bool kt = false;
	cout << "\n Nhap ma phieu can sua thong tin: "; cin >> id;
	for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext) {
		if (id == k->pb.maPh) {
			//			int x;
			//			cout<<"\n Sua lai ma nhan vien";
			//			cin>>x;
			//			k->pb.nv.maNv=x;
			listVl a;
			khoiTaoListVl(a);
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
void themVaoDanhSachVL(listPhieuBan& l) {
	int ma;
	cout << "\n Nhap vao ma phieu ban can them vat lieu: ";
	cin >> ma;
	for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->pb.maPh== ma) {
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
					chenDauVatLieu(k->pb.dsvl, p);
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
					chenCuoiVatLieu(k->pb.dsvl, p);
					cout << endl;
				}
				break;
			}
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
void menu(listPhieuBan& l) {
	int chon;
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
		cout << "\n\t14. Sua thong tin danh sach vat lieu: ";
		cout << "\n\t15. Xoa phieu o dau danh sach";
		cout << "\n\t16. Xoa phieu o cuoi danh sach";
		cout << "\n\t17. Xoa phieu cua nhan vien ma X ";
		cout << "\n\t18. Chen them danh sach vat lieu";
		cout << "\n\t19. Giai phong bo nho cap phat";
		cout << "\n Lua chon cua ban: ";
		cin >> chon;
		if (chon == 1) {
			nhapDSPhieu(l);
		}
		else if (chon == 2) {
			hienDSPhieu(l);
			system("pause");
		}
		else if(chon==3) {
			ghiFile(l);
			system("pause");
		}
		else if (chon == 4) {
			docFile(l);
			system("pause");
		}
		else if (chon == 5) {
			cout << "\n Nhap phieu can them vao dau danh sach: ";
			phieuBan x;
			NhapPhieu(x);
			nodePhieuBan* p = khoiTaoPhieuBan(x);
			chenDauPhieu(l,p);
		}
		else if (chon == 6) {
			cout << "\n Phieu co tong tien min: ";
			PhieuCoTongTienMin(l);
			system("pause");
		}
		else if (chon == 7) {
			chenNodeVaoSauNodeCoTienMin(l);
		}
		else if (chon == 8) {
			chenNodeVaoTruocNodeCoTienMax(l);
		}
		else if (chon == 9) {
			cout << "\n Nhap phieu can them: ";
			phieuBan x;
			NhapPhieu(x);
			nodePhieuBan* p = khoiTaoPhieuBan(x);
			themVaoViTriBatKi(l, p);
		}
		else if (chon == 10) {
			sapXepTangDSPhieuBanTheoTongTien(l);
			hienDSPhieu(l);
			system("pause");
		}
		else if (chon == 11) {
			tongTienThuPhieu(l);
			system("pause");
		}
		else if (chon == 12) {
			cout << "\n Phieu can tim: ";
			timKiemTen(l);
			system("pause");
		}
		else if (chon == 13) {
			cout << "\n Phieu can tim: ";
			timKiemTheoMaNV(l);
			system("pause");
		}
		else if (chon == 14) {
			cout << "\n Phieu sau khi sua thong tin danh sach vat lieu: ";
			SuatheomaPB(l);
			system("pause");
		}
		else if (chon == 15) {
			XoaDauDanhSachPhieu(l);
		}
		else if (chon == 16) {
			XoaCuoiDanhSach(l);
		}
		else if (chon == 17) {
			xoa1PhieuBatKiTheoMaNV(l);
		}
		else if (chon == 18) {
			themVaoDanhSachVL(l);
		}
		else if (chon == 19) {
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
	khoiTaoList(l);
	menu(l);
}