#include<iostream>
using namespace std;
long long power(long long a,long long b){
	long long result=1;
	for(int i=1;i<=b;i++){
		result*=a;
		}
	return result;
	}
int main(){
	long long a, b;
	cin>>a>>b;
	cout<<" Luy thua: "<<power(a,b);
	return 0;
	} 
