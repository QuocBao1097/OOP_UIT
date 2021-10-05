#include <iostream>
using namespace std;

class SoPhuc
{
private:
    double a;//phanthuc
    double b;//phanao
public:
    void Nhap();
    void Xuat();
    friend SoPhuc Cong(SoPhuc,SoPhuc);
    friend SoPhuc Tru (SoPhuc,SoPhuc);
    SoPhuc Nhan(SoPhuc);
    SoPhuc Chia(SoPhuc);
};
void SoPhuc:: Nhap()
{
    cout<<"Phan Thuc: "; cin>>a;
    cout<<"Phan Ao: "; cin>>b;
}
void SoPhuc::Xuat()
{
    if(b>=0) cout<<a<<"+"<<b<<"i";
    else
        cout<<a<<b<<"i";
}
SoPhuc Cong(SoPhuc sp1, SoPhuc sp2)
{
    SoPhuc tong ;
    tong.a=sp1.a+sp2.a;
    tong.b=sp1.b+sp2.b;
    return tong;
}
SoPhuc Tru(SoPhuc sp1, SoPhuc sp2)
{
    SoPhuc hieu;
    hieu.a=sp1.a-sp2.a;
    hieu.b=sp1.b-sp2.b;
    return hieu;
}
SoPhuc SoPhuc::Nhan(SoPhuc sp2)
{
    SoPhuc tich;
    tich.a=a*sp2.a+sp2.b*sp2.b;
    tich.b=a*sp2.b+b*sp2.a;
    return tich;
}
SoPhuc SoPhuc::Chia(SoPhuc sp2)
{
    SoPhuc thuong;
    thuong.a=(a*sp2.a+b*sp2.b)/((sp2.a*sp2.a)*(sp2.b*sp2.b));
    thuong.b=(b*sp2.a-a*sp2.b)/((sp2.a*sp2.a)*(sp2.b*sp2.b));
    return thuong;
}
int main() {
    SoPhuc sp1,sp2;
    cout<<"Nhap so phuc dau tien\n";
    sp1.Nhap();
    cout<<"-->SP1: ";
    sp1.Xuat();
    cout<<endl<<endl;
    cout<<"Nhap so phuc thu hai\n";
    sp2.Nhap();
    cout<<"-->SP2: ";
    sp2.Xuat();
    cout<<"\nTong hai so phuc: ";
    Cong(sp1, sp2).Xuat();
    cout<<"\nHieu hai so phuc: ";
    Tru(sp1, sp2).Xuat();
    cout<<"\nTich hai so phuc: ";
    sp1.Nhan(sp2).Xuat();
    cout<<"\nThuong hai so phuc: ";
    sp1.Chia(sp2).Xuat();
    return 0;
}

