#include<iostream>
using namespace std;
int binarySearch(int a[], int left, int right, int x){
	int middle;
	while(left<=right){
		middle=(left+right)/2;
		if(a[middle]==x){
			return middle;
			}
		if(x>a[middle]){
			left=middle+1;
			}
		else{
			right=middle-1; 
		}
	}
	return -1;
}
int nhapMang(int a[], int &n){
	for(int i=0;i<n;i++){
		cout<<"\n Nhap: ";
		cin>>a[i];
		}
	}
int hienMang(int a[], int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
		}
}
int main(){
	int n; cin>>n;
	int a[n];
	int x=10;
	nhapMang(a,n);
	hienMang(a,n);
	int result=binarySearch(a,0,n-1,x);
	cout<<"\t vi tri : "<<result;
	}
