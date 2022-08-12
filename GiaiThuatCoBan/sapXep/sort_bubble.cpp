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
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
void bubbleSort(int a[], int n){
	bool haveSwap=true;
	for(int i=0;i<n-1;i++){
		haveSwap =false;
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				swap(a[j], a[j+1]);
				haveSwap=true;
			}
	    }
	    if(haveSwap==false){
	    	break;
		}
	}
}
int main(){
	int n; cin>>n;
	int a[n];
	nhapMang(a,n);
	hienMang(a,n);
	bubbleSort(a,n);
	cout<<"\n Sau khi sap xep: "; 
	hienMang(a,n);
	return 0;
}
