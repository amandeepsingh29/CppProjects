#include<iostream>
using namespace std;
int main(){
            // Fibonacci Series
int nextnumber=0;
int a=0;
int b=1;
cout<<a<<" "<<b<<" ";

int n=10;
for(int i =1;i<=(n-2);i++){
    nextnumber=a+b;
    cout<<nextnumber<<" ";
    a=b;
    b=nextnumber;
}

}