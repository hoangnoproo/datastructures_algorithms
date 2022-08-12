#include<iostream>
using namespace std;
bool check(int n){
	int sum=0;
	for(int i=1;i<=n/2;i++) {
		if(n%i==0){
			sum+=i;
			}
		}
	if(sum==n) return true;
	else{
		return false;
	}
}
int main(){
	int n; cin>>n;
	if(check(n)){
		cout<<"\n So hoan hao";
		}
	else{
		cout<<"\n Khong phai so hoan hao";
	}
	return 0;
	}
