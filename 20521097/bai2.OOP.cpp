
#include <iostream>
using namespace std;

int UCLN(int a, int b){
    if(b==0) return a;
    if(a%b==0) return b;
    return UCLN(b,a%b);
}
void rutgon(int &a, int &b){
    int k=UCLN(a, b);
    a/=k;
    b/=k;
}
int main(){
    int tu1, tu2, mau1, mau2;
    cout<<"Nhap tu so cua PS1:";
    cin>>tu1;
    do{
        cout<<"Nhap mau so PS1:"; cin>>mau1;
    }while(mau1==0);
    cout<<"Nhap tu so cua PS2:";     
    cin>>tu2;
    do{
        cout<<"Nhap mau so PS2:"; cin>>mau2;
    }while(mau2==0);
    rutgon(tu1, mau1);
    rutgon(tu2, mau2);
    float temb1=(float)tu1/mau1;
    float temb2=(float)tu2/mau2;
    if(temb1>temb2){
    cout<<"Phan so lon hon la: ";
    if(mau1==1) cout<<tu1;
    else
        if(mau1==-1) cout<<-tu1;
        else
            if(mau1<0) cout<<-tu1<<"/"<<-mau1;
            else
                cout<<tu1<<"/"<<mau1;
    }
    else if(temb1<temb2){
        cout<<"Phan so lon hon la: ";
        if(mau2==1) cout<<tu2;
        else
            if(mau2==-1) cout<<-tu2;
            else
                if(mau2<0) cout<<-tu2<<"/"<<-mau2;
                else
                    cout<<tu2<<"/"<<mau2;
    }
    cout<<endl;
    return 0;
}
