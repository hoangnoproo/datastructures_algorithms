#include<iostream>
#include<math.h>
using namespace std;
bool scp_1(int n){
	int i=0;
	while(i*i<=n){
		if(i*i==n){
			return true;
			}
		++i;
		}
		return false;
	}
bool scp(int n){
	int sqr= sqrt(n);
	 if(sqr*sqr==n){
	 	return true;
	}
	return false;
	}
int main(){
	int n;
	cin>>n;
	if(scp_1(n)){
		cout<<"\n So chinh phuong";
		}
	else{
		cout<<"\n Khong phai so chinh phuong";
	}
	return 0;
	}
