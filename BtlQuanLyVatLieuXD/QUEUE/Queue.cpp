#include<iostream>
#include<string>
#include<iomanip>
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
};
nodeNv* khoiTaoNode(nhanVien& x) {
	nodeNv* p = new nodeNv;
	if (p == NULL) {
		cout << "\n Day bo nho!";
		return NULL;
	}
	p->nv = x;
	p->pNext = NULL;
	return p;
}
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
nodeKh* khoiTaoNodeKh(khachHang x) {
	nodeKh* p = new nodeKh;
	if (p == NULL) {
		return NULL;
	}
	p->kh = x;
	p->pNext = NULL;
	return p;
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
};
struct queuevl {
	nodeVl* pHead;
	nodeVl* pTail;
};
void khoiTaoQueueVL(queuevl& q) {
	q.pHead = NULL;
	q.pTail = NULL;
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
void inVL(vatLieu x) {
	cout << "\n" << setw(16) << x.tenVl;
	cout << setw(16) << x.maVl;
	cout << setw(15) << x.donGia;
	cout << setw(10) << x.soLuong;
	cout << setw(15) << size_t(x.thanhTien);
}
bool IsEmpty(queuevl q) {
	if (q.pHead == NULL) {
		return true;
	}
	return false;
}
bool Push(queuevl& q, nodeVl* p) {
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
bool Pop(queuevl& q, vatLieu& x) {
	if (IsEmpty(q) == true) {
		return false;
	}
	else {
		nodeVl* p = q.pHead;
		x = p->vl;
		q.pHead = q.pHead->pNext;
		delete p;
	}
	return true;
}
bool Top(queuevl& q, vatLieu& x) {
	if (IsEmpty(q) == true) {
		return false;
	}
	x = q.pHead->vl;
	return true;
}
void nhapDSVL(queuevl& q) {
	int n;
	cout << "\n Nhap so vat lieu: "; cin >> n;
	vatLieu x;
	nodeVl* vl;
	for (int i = 0; i < n; i++) {
		nhapVL(x);
		vl = khoiTaoNodeVl(x);
		Push(q, vl);
	}
}
void hienDSVL(queuevl q) {
	table();
	while (IsEmpty(q) == false) {
		vatLieu x;
		Pop(q, x);
		inVL(x);
	}
}
float tongTienVL(queuevl q) {
	float tongTien = 0;
	for (nodeVl* p = q.pHead; p != NULL; p = p->pNext) {
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
	queuevl dsvl;
	float tongTien;
};
struct nodePhieuBan {
	phieuBan pb;
	struct nodePhieuBan* pNext;
};
struct queuePB {
	nodePhieuBan* pHead;
	nodePhieuBan* pTail;
};
void khoiTaoQueuePB(queuePB& q) {
	q.pHead = NULL;
	q.pTail = NULL;
}
nodePhieuBan* khoiTaoNodePB(phieuBan x) {
	nodePhieuBan* p = new nodePhieuBan;
	if (p == NULL) {
		cout << "\n Het bo nho!";
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
	khoiTaoQueueVL(x.dsvl);
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
bool IsEmptyPB(queuePB q) {
	if (q.pHead == NULL) {
		return true;
	}
	return false;
}
bool PushPB(queuePB& q, nodePhieuBan* p) {
	if (p == NULL) {
		return false;
	}
	if (IsEmptyPB(q) == true) {
		q.pHead = q.pTail = p;
	}
	else
	{
		q.pTail->pNext = p;
		q.pTail = p;
	}
	return true;
}
bool PopPB(queuePB& q, phieuBan& x) {
	if (IsEmptyPB(q) == true) {
		return false;
	}
	else {
		nodePhieuBan* p = q.pHead;
		x = p->pb;
		q.pHead = q.pHead->pNext;
		//delete p;
	}
	return true;
}
bool Top(queuePB& q, phieuBan& x) {
	if (IsEmptyPB(q) == true) {
		return false;
	}
	x = q.pHead->pb;
	return true;
}
void nhapDSPhieu(queuePB& q) {
	cout << "\n Nhap so luong phieu ban: "; int n; cin >> n;
	phieuBan x;
	nodePhieuBan* p;
	for (int i = 0; i < n; i++) {
		cout << "\n Nhap phieu thu: " << i + 1;
		NhapPhieu(x);
		p = khoiTaoNodePB(x);
		PushPB(q, p);
	}
}
void hienDSPhieuban(queuePB s) {
	while (IsEmptyPB(s) == false) {
		phieuBan x;
		PopPB(s, x);
		HienPhieu(x);
		cout << "\n\t\t*---------------------------------*\n";
	}
}
void chenVaoDauPhieu(queuePB& l, nodePhieuBan* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void chenVaoCuoiPhieu(queuePB& l, nodePhieuBan* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
float timKiemPhieuCoTongTienMin(queuePB l) {
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
float timkiemPhieuCoTongTienMax(queuePB l) {
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
void PhieuCoTongTienMin(queuePB l) {
	for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->pb.tongTien == timKiemPhieuCoTongTienMin(l)) {
			HienPhieu(k->pb);
		}
	}
}
void themVaoSauPhieuCoTienMin(queuePB& l) {
	phieuBan pb;
	cout << "\n Nhap phieu can them!";
	NhapPhieu(pb);
	nodePhieuBan* p = khoiTaoNodePB(pb);
	for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->pb.tongTien == timKiemPhieuCoTongTienMin(l)) {
			nodePhieuBan* h = khoiTaoNodePB(p->pb);
			h->pNext = k->pNext;
			k->pNext = h;
		}
	}
}
void themVaoTruocPhieuCoTienMax(queuePB& l) {
	phieuBan pb;
	cout << "\n Nhap phieu can them!";
	NhapPhieu(pb);
	nodePhieuBan* p = khoiTaoNodePB(pb);
	nodePhieuBan* g = new nodePhieuBan;
	if (l.pHead == NULL || l.pHead == p) {
		chenVaoDauPhieu(l, p);
	}
	for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->pb.tongTien == timkiemPhieuCoTongTienMax(l)) {
			nodePhieuBan* h = khoiTaoNodePB(p->pb);
			h->pNext = k;
			g->pNext = h;
		}
		g = k;
	}
}
void themVaoViTriBatKi(queuePB& l, nodePhieuBan* p) {
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
void sapXepTangDSPhieuBanTheoTongTien(queuePB& l) {
	for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext) {
		for (nodePhieuBan* h = k->pNext; h != NULL; h = h->pNext) {
			if (k->pb.tongTien > h->pb.tongTien) {
				hoanVi(k->pb, h->pb);
			}
		}
	}
}
void tongTienThuPhieu(queuePB& l) {
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
void timKiemTheoTen(queuePB l) {
	string tenKh;
	cout << "\n Nhap ten khach hang can tim: ";
	cin.ignore();
	bool kt = false;
	getline(cin, tenKh);
	for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext) {
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
void timKiemMaNhanVien(queuePB l) {
	int id;
	cout << "\n Nhap ma can tim: "; cin >> id;
	bool kt = false;
	for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext) {
		if (id == k->pb.nv.maNv) {
			HienPhieu(k->pb);
			kt = true;
		}
	}
	if (kt == false) {
		cout << "\n Khong ton tai nhan vien ma: " << id;
	}
}
void XoaDauDanhSachPhieu(queuePB& l) {
	if (l.pHead == NULL) {
		return;
	}
	nodePhieuBan* p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;
}
void XoaCuoiDanhSach(queuePB& l) {
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
void xoa1PhieuBatKiTheoMaNV(queuePB& l) {
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
void ghiFilePB(queuePB& l)
{
	fstream f;
	f.open("PhieuBanQueue.dat", ios::out | ios::binary);
	for (nodePhieuBan* p = l.pHead; p != NULL; p = p->pNext) {
		f.write((char*)&(p->pb), sizeof(phieuBan));
	}
	f.close();
	cout << "\n Luu file thanh cong!";
}
void docFilePB(queuePB& l)
{
	fstream f;
	f.open("PhieuBanQueue.dat", ios::in);
	phieuBan x;
	nodePhieuBan* p;
	khoiTaoQueuePB(l);
	while (f.read((char*)&x, sizeof(phieuBan))) {
		p = khoiTaoNodePB(x);
		PushPB(l, p);
	}
	f.close();
	cout << "\nDoc file thanh cong..\n";
	hienDSPhieuban(l);
}

void GiaiPhongBoNho(queuePB& l) {
	nodePhieuBan* k = new nodePhieuBan;
	while (l.pHead != NULL) {
		k = l.pHead;
		l.pHead = l.pHead->pNext;
		delete k;
	}
}
void SuatheomaPB(queuePB& l) {
	int id;
	bool kt = false;
	cout << "\n Nhap ma phieu can sua thong tin: "; cin >> id;
	for (nodePhieuBan* k = l.pHead; k != NULL; k = k->pNext) {
		if (id == k->pb.maPh) {
			//			int x;
			//			cout<<"\n Sua lai ma nhan vien";
			//			cin>>x;
			//			k->pb.nv.maNv=x;
			queuevl a;
			khoiTaoQueueVL(a);
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
void menu(queuePB& l) {
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
		cout << "\n\t14. Sua thong tin danh sach vat lieu: ";
		cout << "\n\t15. Xoa phieu o dau danh sach";
		cout << "\n\t16. Xoa phieu o cuoi danh sach";
		cout << "\n\t17. Xoa phieu cua nhan vien ma X";
		cout << "\n\t18. Giai phong bo nho cap phat";
		cout << "\n Lua chon cua ban: ";
		cin >> chon;
		if (chon == 1) {
			nhapDSPhieu(l);
		}
		else if (chon == 2) {
			hienDSPhieuban(l);
			system("pause");
		}
		else if (chon == 3) {
			ghiFilePB(l);
			system("pause");
		}
		else if (chon == 4) {
			docFilePB(l);
			system("pause");
		}
		else if (chon == 5) {
			cout << "\n Nhap phieu can them!";
			phieuBan pb;
			NhapPhieu(pb);
			nodePhieuBan* p = khoiTaoNodePB(pb);
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
			NhapPhieu(pb);
			nodePhieuBan* p = khoiTaoNodePB(pb);
			themVaoViTriBatKi(l, p);
		}
		else if (chon == 10) {
			sapXepTangDSPhieuBanTheoTongTien(l);
			hienDSPhieuban(l);
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
	queuePB q;
	khoiTaoQueuePB(q);
	menu(q);
	return 0;
}