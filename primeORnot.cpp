#include<iostream>
using namespace std;
int main(){
    cout<<"enter number to be checked";
    int n;
    cin>>n;
    int prime_key=1;
    for(int i = 2;i<n;i++){
        if(n%i==0){
        prime_key=0;
        break;
        }
    }

    if(prime_key){
        cout<<"A prime number";
}
    else{
        cout<<"Not a prime number";
    }
}