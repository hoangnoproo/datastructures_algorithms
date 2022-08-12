#include<iostream>
using namespace std;
int linear_search(int a[], int n, int x){
	for(int i=0;i<n;i++){
		if(a[i]==x){
			return i;
			}
		}
	return -1;
}
int nhapMang(int a[], int &n){
	for(int i=0;i<n;i++){
		cout<<"\n Nhap phan tu thu: "<<i+1<<" ";
		cin>>a[i];
		}
	}
int hienMang(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
		}
	}
int main(){
	 int n, x;
	cin>>n;
	int a[n];
	nhapMang(a,n);
	hienMang(a,n);
	x=10;
	int result=linear_search(a,n,x);
	if(result==-1){
		cout<<"\n Khong co";
		}
	else{
		cout<<"\n vi tri: "<<result;
	}
	return 0;
	}
