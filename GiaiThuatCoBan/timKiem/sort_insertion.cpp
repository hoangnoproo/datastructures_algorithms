#include<iostream>
using namespace std;
void nhapMang(int a[], int &n){
	for(int i=0;i<n;i++){
		cout<<"\n Nhap a["<<i<<"]=";
		cin>>a[i];
	}
}
void hienMang(int a[], int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
void insertionSort(int a[], int n){
	for(int i=1;i<n;i++){
		int key=a[i];
		int j=i-1;
		while(j>=0&&a[j]>key){
			a[j+1]=a[j];
			j=j-1;
			}
		a[j+1]=key;
		}
	}
int main(){
	int n; cin>>n;
	int a[n];
	nhapMang(a,n);
	hienMang(a,n);
	insertionSort(a,n);
	cout<<"\n sau khi sap xep: ";
	hienMang(a,n);
	return 0;
	}
