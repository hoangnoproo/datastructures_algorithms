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
void swap(int &x, int &y){
	int temp=x;
	x=y;
	y=temp;
	}
void selectionSort(int a[], int n){
	for(int i=0;i<n;i++){
		int min_i=i;
		for(int j=i+1;j<n;j++){
			if(a[j]<a[min_i]){
				min_i=j;
				}
			swap(a[min_i], a[i] );
			}
		}
	}
int main(){
	int n; cin>>n;
	int a[n];
	nhapMang(a,n);
	hienMang(a,n);
	selectionSort(a,n);
	cout<<"\n Sau khi sap xep: ";
	hienMang(a,n);
	return 0;
	}

