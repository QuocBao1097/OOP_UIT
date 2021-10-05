
#include <iostream>
#include<cmath>

using namespace std;
class Diem
{
private:
    double x;
    double y;
public:
    Diem ();
    Diem(double);
    Diem (double, double);
    double getX();
    double getY();
    void setX(double);
    void setY(double);
    void setXY(double, double);
    void Nhap();
    void Xuat();
    void Dichuyen(double, double);
    bool Ktra2diemtrungnhau(Diem);
    double Khoangcach(Diem);
    friend istream & operator>>(istream&, Diem &);
    friend ostream & operator<<(ostream&, Diem );
};
Diem::Diem()
{
    setXY(0, 0);
}
Diem::Diem(double xx)
{
    setXY(xx, 0);
}
Diem::Diem(double xx, double yy)
{
    setXY(xx, yy);
}
double Diem::getX()
{
    return x;
}
double Diem::getY()
{
    return y;
}
void Diem::setX(double xx)
{
    x=xx;
}
void Diem::setY(double yy)
{
    y=yy;
}
void Diem::setXY(double xx, double yy)
{
    x=xx;
    y=yy;
}
void Diem::Nhap()
{
    cout<<"x= "; cin>>x;
    cout<<"y= "; cin>>y;
}
void Diem::Xuat()
{
    cout<<"("<<x<<","<<y<<")";
}
void Diem::Dichuyen(double dx, double dy)
{
    x=x+dx;
    y=y+dy;
}
bool Diem::Ktra2diemtrungnhau(Diem dd)
{
    return (x==dd.x && y==dd.y);
}
double Diem::Khoangcach(Diem dd)
{
    return sqrt((x-dd.x)*(x-dd.x)+(y-dd.y)*(y-dd.y));
}
ostream & operator <<(ostream &os, Diem d)
{
    os<<"("<<d.x<<","<<d.y<<")";
    return os;
}
istream &operator >>(istream &is, Diem &d)
{
    cout<<"x = ";
    is>>d.x;
    cout<<"y =  ";
    is>>d.y;
    return is;
}


class HCN
{
private:
    Diem A,B;
public:
    HCN();
    HCN(double,double, double, double);
    HCN(Diem, Diem);
    Diem GetA();
    Diem GetB();
    Diem GetC();
    Diem GetD();
    void SetA(Diem);
    void SetB(Diem);
    void SetAB(Diem, Diem);
    void Nhap();
    void Xuat();
    double TinhChuVi();
    void Dichuyen(double, double);
    double TinhDienTich();
    bool KiemTrakhongHopLe();
    friend istream & operator>>(istream &, HCN&);
    friend ostream & operator<<(ostream &, HCN);
};
HCN ::HCN()
{
    while(KiemTrakhongHopLe())
        cin>>*this;
}
HCN ::HCN(double xA, double yA, double xB, double yB) :A(xA, yA),B(xB, yB)
{
    while(KiemTrakhongHopLe())
        cin>>*this;
}
HCN ::HCN(Diem AA, Diem BB)
{
    A=AA;
    B=BB;
    while(KiemTrakhongHopLe())
        cin>>*this;
}
Diem HCN::GetA()
{
    return A;
}
Diem HCN::GetB()
{
    return B;
}
Diem HCN::GetC()
{
    Diem C(B.getX(), A.getY());
    return C;
}
Diem HCN::GetD()
{
    Diem D(A.getX(), B.getY());
    return D;
}
void HCN::SetA(Diem AA)
{
    A=AA;
    while(KiemTrakhongHopLe())
        cin>>A;
}
void HCN::SetB(Diem BB)
{
    B=BB;
    while(KiemTrakhongHopLe())
        cin>>B;
}

void HCN::SetAB(Diem AA, Diem BB)
{
    A=AA;
    B=BB;
    while(KiemTrakhongHopLe())
        cin>>*this;
}
void HCN::Nhap()
{
    do{
        cout<<"Nhap toa do 2 duong cheo ";
        cin>>A>>B;
    }while(KiemTrakhongHopLe());
}
void HCN::Xuat()
{
    cout<<"Toa do 2 dinh duong cheo: "<<A<<", "<<B<<endl;
}
void HCN::Dichuyen(double dx, double dy)
{
    A.Dichuyen(dx, dy);
    B.Dichuyen(dx, dy);
}
double HCN::TinhChuVi()
{
    double a=A.Khoangcach(GetD());
    double b=B.Khoangcach(GetD());
    return (a+b)*2;
}

double HCN::TinhDienTich()
{
    double a=A.Khoangcach(GetD());
    double b=B.Khoangcach(GetD());
    return a*b;
}
bool HCN::KiemTrakhongHopLe()
{
    return A.Ktra2diemtrungnhau(B) && A.getX()==B.getX() && A.getY()==B.getY();
}
istream & operator>>(istream &is, HCN &hcn)
{
    do{
        cout<<"Nhap toa do 2 dinh 2 duong cheo\n";
        is>>hcn.A>>hcn.B;
    }while(hcn.KiemTrakhongHopLe());
    return is;
}
ostream &operator <<(ostream &os, HCN hcn)
{
    os<<"HCN qua 2 duong cheo: "<<hcn.A<<"; "<<hcn.B<<endl;
    return os;
}
int main()
{
    HCN hcn1, hcn2(2,5,6,3), hcn3(Diem(1,2), Diem(-3,7));
    cout<<hcn1<<hcn2<<hcn3;
    cout<<"\n---------------------------------\n";
    cout<<"HINH CHU NHAT 1 ";
    cout<<"\nChu vi: ";cout<<hcn1.TinhChuVi();
    cout<<"\nDien tich: ";cout<<hcn1.TinhDienTich();
    cout<<"\n---------------------------------\n";
    cout<<"HINH CHU NHAT 2 ";
    cout<<"\nChu vi: ";cout<<hcn2.TinhChuVi();
    cout<<"\nDien tich: ";cout<<hcn2.TinhDienTich();
    cout<<"\n---------------------------------\n";
    cout<<"HINH CHU NHAT 3 ";
    cout<<"\nChu vi: ";cout<<hcn3.TinhChuVi();
    cout<<"\nDien tich: ";cout<<hcn3.TinhDienTich();
    cout<<endl;
    return 0;
}
