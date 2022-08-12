#include<iostream>
using namespace std;
bool kiemTraSNT(int n){
	if(n<2){
		return false;}
	for(int i=2;i<n;i++){
		if(n%i==0){
			return false;
			}
		}
	return true;}
int main(){
	int n;
	cin>>n;
	if(kiemTraSNT(n)){
		cout<< "la so nguyen to";
		}
	else {
		cout<<"\n Khong la so nguyen to";
		}
	return 0;}
	
