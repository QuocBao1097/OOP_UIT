#include <iostream>

using namespace std;
struct PhanSo{
    int tu;
    int mau;
};
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
    PhanSo ps1; PhanSo ps2;
    cout<<"Nhap Phan So dau tien: ";
    cin>>ps1.tu>>ps1.mau;
    cout<<"Nhap Phan So thu hai: ";
    cin>>ps2.tu>>ps2.mau;
    rutgon(ps1.tu, ps1.mau); rutgon(ps2.tu, ps2.mau);
    float tong=(float)(ps1.tu*ps2.mau+ps1.mau*ps2.tu)/(ps1.mau*ps2.mau);
    cout<<"Tong cua hai phan so = "<<tong<<endl;
    float hieu=(float)(ps1.tu*ps2.mau-ps1.mau*ps2.tu)/(ps1.mau*ps2.mau);
     cout<<"Hieu cua hai phan so = "<<hieu<<endl;
    float tich=(float)(ps1.tu*ps2.tu)/(ps2.mau*ps1.mau);
     cout<<"Tich cua hai phan so = "<<tich<<endl;
    float thuong=(float)(ps1.tu*ps2.mau)/(ps1.mau*ps2.tu);
     cout<<"Thuong cua hai phan so = "<<thuong<<endl;
    return 0;
}