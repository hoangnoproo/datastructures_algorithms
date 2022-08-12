#include<iostream>
using namespace std;
int UCLN(int A, int B){
	for(int i=min(A,B);i>0;i--){
		if(A%i==0&&B%i==0){
			return i;
			}
		}
	}
int UCLN_2(int A, int B){
	if(A==0||B==0){
		return A+B;
		}
	while(A!=B){
		if(A>B){
			A-=B;
			}
		else{
			B-=A;
		}
	}
	return A;
	}
int UCLN_3(int A, int B){
	while(A*B!=0){
		if(A>B){
			A%=B;
			}
		else{
			B%=A;
		}
	}
	return A+B;
	}
int UCLN_4(int A, int B){
	if(B==0){
		return A;
		}
		return UCLN_4(B, A%B);
		}
int main(){
	int A, B;
	cin>>A;
	cin >>B;
	cout<<"UCLN: "<<UCLN_4(A, B);
	return 0;
	}
