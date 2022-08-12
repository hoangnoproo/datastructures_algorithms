//Đọc ghi file danh sách liên kết đơn sinh viên
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct date{
	int day;
	int month;
	int year;
};
// Hàm đọc ngày tháng từ file
void readFileDate(date& Date, ifstream& fin) {
	fin >> Date.day;
	fin.seekg(1, 1);
	fin >> Date.month;
	fin.seekg(1, 1);
	fin >> Date.year;
}
struct students {
	string IDStudent;
	string NameStudent;
	date Date;
	float GPA;//Điểm trung bình
};
struct node {
	students data;
	struct node* pNext;
};
struct list {
	node *pHeal;
	node* pTail;
};
void initialazeList(list&l) {
	l.pHeal = NULL;
	l.pTail = NULL;
}
node* initialazeNode(students x) {
	node* p = new node;
	if (p == NULL) {
		cout << "\n Khong du bo nho";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}
void addFirst(list& l, node* p) {
	if (l.pHeal == NULL) {
		l.pHeal = p;
		l.pTail = l.pHeal;
	}
	else {
		p->pNext = l.pHeal;
		l.pHeal = p;
	}
}
void addLast(list& l, node* p) {
	if (l.pHeal == NULL) {
		l.pHeal = p;
		l.pTail = l.pHeal;
	}
	l.pTail->pNext = p;
	l.pTail = p;
}
void readFileOneStudent(ifstream& fin,students& st) {
	getline(fin, st.IDStudent, ',');
	fin.seekg(1, 1);
	getline(fin, st.NameStudent, ',');
	fin.seekg(1, 1);
	readFileDate(st.Date, fin);
	fin.seekg(2, 1);
	fin >> st.GPA;
	// tạo biến để tạm biến xuống dòng \n
	string temp;
	getline(fin, temp);
}

void readFileListStudents(ifstream& fin, list& l) {
	while (!fin.eof()) {
		students st;
		readFileOneStudent(fin,st);
		node* p = initialazeNode(st);
		addLast(l, p);
		//addFirst(l, p);
	}
}
void printScreenOneStudent(students st) {
	cout << "\n Ma sinh vien: " << st.IDStudent;
	cout << "\n Ho ten: " << st.NameStudent;
	cout << "\n Ngay sinh: " << st.Date.day << "/" << st.Date.month << "/" << st.Date.year;
	cout << "\n Diem trung binh: " << st.GPA;
}
void printScreenListStudents(list l) {
	int dem = 1;
	for (node* k = l.pHeal; k != NULL; k = k->pNext) {
		cout << "\n\n\t\t SINH VIEN THU " << dem++;
		printScreenOneStudent(k->data);
	}
}
int main() {
	list l;
	initialazeList(l);
	ifstream fin;
	fin.open("Student.TXT", ios::in);
	readFileListStudents(fin, l);
	printScreenListStudents(l);
	fin.close();
	system("pause");
	return 0;
}