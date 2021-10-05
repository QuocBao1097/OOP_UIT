#include <iostream>
using namespace std;

int UCLN(int a, int b){
    if(b==0) return a;
    if(a%b==0) return b;
    return UCLN(b,a%b);
}
int main(){
    int tu;
    cout<<"Nhap tu so:";
    cin>>tu;
    int mau; 
    do{
          cout<<"Nhap mau so:"; cin>>mau;
    }while(mau==0);
    
    int k=UCLN(tu,mau);
    tu=tu/k;
    mau/=k;
      if(tu==0) cout<<"Khong ton tai phan so";
        if(mau==1) cout<<tu;
        else
            if(mau==-1) cout<<-tu;
        else
            if(mau<0) cout<<-tu<<"/"<<-mau;
        else
            cout<<tu<<"/"<<mau;
      cout<<endl;
    return 0;
}
