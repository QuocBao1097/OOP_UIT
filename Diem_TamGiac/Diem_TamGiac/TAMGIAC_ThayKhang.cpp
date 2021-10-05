#include<iostream>
#include<cmath>
using namespace std;

struct diem
{
    float x;
    float y;
};
typedef struct diem DIEM;

struct tamgiac
{
    DIEM A;
    DIEM B;
    DIEM C;
};
typedef struct tamgiac TAMGIAC;

void nhap(DIEM& p)
{
    cout<<"\nNhap x: "; cin>>p.x;
    cout<<"Nhap y: "; cin>>p.y;
}
void xuat(DIEM p)
{
    cout<<"("<<p.x<<","<<p.y<<")";
}
void nhap(TAMGIAC &t)
{
    cout<<"Nhap A:";
    //cin>>t.A.x>>t.A.y;
    nhap(t.A);
    cout<<"\nNhap B:";
    //cin>>t.B.x>>t.B.y;
    nhap(t.B);
    cout<<"\nNhap C:";
    //cin>>t.C.x>>t.C.y;
    nhap(t.C);
}
float Khoangcach(DIEM P, DIEM Q)
{
    return sqrt((Q.x-P.x)*(Q.x-P.x)+(Q.y-P.y)*(Q.y-P.y));
}
float chuvi(TAMGIAC t)
{
    return (Khoangcach(t.A,t.B)+Khoangcach(t.B,t. C)+Khoangcach(t.C,t. A));
}
float Dientich(TAMGIAC &t)
{
    float a=Khoangcach(t.A,t. B);
    float b=Khoangcach(t.B,t. C);
    float c=Khoangcach(t.C, t.A);
    float p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
DIEM trongtam(TAMGIAC t)
{
    DIEM temp;
    temp.x=t.A.x+t.B.x+t.C.x;
    temp.y=t.A.y+t.B.y+t.C.y;
    return temp;
}
void xuat(TAMGIAC t)
{
    cout<<"--------------\n";
    cout<<"\nXuat A";
    xuat(t.A);
    cout<<"\nXuat B";
    xuat(t.B);
    cout<<"\nXuat C ";
    xuat(t.C);
}
int main()
{
    TAMGIAC tg;
    nhap(tg);
    xuat(tg);
    cout<<"\nTrong tam cua tam giac: ";
    xuat(trongtam(tg));// vi trong tam la 1 diem
    cout<<"\nKhoang cach AB:";
    cout<<Khoangcach(tg.A, tg.B);
    cout<<"\nChu vi: ";
    cout<<chuvi(tg);
    cout<<"\nDien tich: ";
    cout<<Dientich(tg);
    return 0;
}
