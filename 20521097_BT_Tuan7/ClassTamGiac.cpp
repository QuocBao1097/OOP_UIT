
#include <iostream>
#include<cmath>

using namespace std;
class Diem
{
private:
    double x;
    double y;
public:
//    Diem ();
//    Diem(double);
    Diem (double =0, double =0);
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
    Diem   TimDiemDoiXung();
    double TinhChuVi(Diem,Diem);
    double TinhDienTich(Diem, Diem);
    friend istream & operator>>(istream&, Diem &);
    friend ostream & operator<<(ostream&, Diem );
};
//Diem::Diem()
//{
//    setXY(0, 0);
//}
//Diem::Diem(double xx)
//{
//    setXY(xx, 0);
//}
Diem::Diem(double xx, double yy) :x(xx), y(yy){}
//{
//    setXY(xx, yy);
//}
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
    cout<<"X = "; cin>>x;
    cout<<"y = "; cin>>y;
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
double Diem::Khoangcach(Diem dd)
{
    return sqrt((x-dd.x)*(x-dd.x)+(y-dd.y)*(y-dd.y));
}
bool Diem::Ktra2diemtrungnhau(Diem dd)
{
    return (x==dd.x && y==dd.y);
}
Diem Diem::TimDiemDoiXung()
{
    Diem ddx(-this->x, -this->y);
    return ddx;
}
double Diem::TinhChuVi(Diem d1, Diem d2)
{
    double a=this->Khoangcach(d1);
    double b=d1.Khoangcach(d2);
    double c=d2.Khoangcach(*this);
    return a+b+c;
}
double Diem::TinhDienTich(Diem d1, Diem d2)
{
    double a=this->Khoangcach(d1);
    double b=d1.Khoangcach(d2);
    double c=d2.Khoangcach(*this);
    double p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
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

class TAMGIAC
{
private:
    Diem A,B,C;
public:
    TAMGIAC();
    TAMGIAC(double,double,double,double,double,double);
    TAMGIAC(Diem, Diem, Diem);
    Diem GetA();
    Diem GetB();
    Diem GetC();
    void SetA(Diem);
    void SetB(Diem);
    void SetC(Diem);
    void SetABC(Diem, Diem, Diem);
    void Nhap();
    void Xuat();
    double TinhChuVi();
    void Dichuyen(double, double);
    double TinhDienTich();
    bool KiemTraHopLe();
    void PhanLoaiTamGiac();
    friend istream & operator>>(istream &, TAMGIAC&);
    friend ostream & operator<<(ostream &, TAMGIAC);
};
TAMGIAC::TAMGIAC()
{
    while(!KiemTraHopLe())
        cin>>*this;
}
TAMGIAC::TAMGIAC(double xA, double yA,double xB,double yB,double xC,double yC) :A(xA, yA),B(xB, yB), C(xC,yC)
{
    while(!KiemTraHopLe())
        cin>>*this;
}
TAMGIAC ::TAMGIAC(Diem AA, Diem BB, Diem CC)
{
    A=AA;
    B=BB;
    C=CC;
    while(!KiemTraHopLe())
        cin>>*this;
}
Diem TAMGIAC::GetA()
{
    return A;
}
Diem TAMGIAC::GetB()
{
    return B;
}
Diem TAMGIAC::GetC()
{
    return C;
}

void TAMGIAC::SetA(Diem AA)
{
    A=AA;
    while(!KiemTraHopLe())
        cin>>A;
}
void TAMGIAC::SetB(Diem BB)
{
    B=BB;
    while(!KiemTraHopLe())
        cin>>B;
}
void TAMGIAC::SetC(Diem CC)
{
    C=CC;
    while(!KiemTraHopLe())
        cin>>C;
}
void TAMGIAC::SetABC(Diem AA, Diem BB, Diem CC)
{
    A=AA;
    B=BB;
    C=CC;
    while(!KiemTraHopLe())
         cin>>*this;
}
void TAMGIAC::Nhap()
{
    do{
        cout<<"Nhap toa do 3 dinh TG ";
        cin>>A>>B>>C;
    }while(!KiemTraHopLe());
}
void TAMGIAC::Xuat()
{
    cout<<"3 dinh cua tam giac: "<<A<<", "<<B<<", "<<C<<endl;
}
void TAMGIAC::Dichuyen(double dx, double dy)
{
    A.Dichuyen(dx, dy);
    B.Dichuyen(dx, dy);
    C.Dichuyen(dx, dy);
}
double TAMGIAC::TinhChuVi()
{
    double a=A.Khoangcach(B);
    double b=B.Khoangcach(C);
    double c=C.Khoangcach(A);
    return a+b+c;
}

double TAMGIAC::TinhDienTich()
{
    double a=A.Khoangcach(B);
    double b=B.Khoangcach(C);
    double c=C.Khoangcach(A);
    double p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
bool TAMGIAC::KiemTraHopLe()
{
    double a=A.Khoangcach(B);
    double b=B.Khoangcach(C);
    double c=C.Khoangcach(A);
    return a>0 && b>0 && c>0 && a+b>c && a+c>b && b+c>a;
}
void TAMGIAC::PhanLoaiTamGiac()
{
    if(KiemTraHopLe())
    {
        double a=A.Khoangcach(B);
        double b=B.Khoangcach(C);
        double c=C.Khoangcach(A);
        if(a==b&&b==c) cout<<"Tam giac deu";
        else if(a==b||b==c||a==c)
                cout<<"Tam giac Can";
        else if(a*a==b*b+c*c || b*b==a*a+c*c|| c*c==a*a+b*b)
            cout<<"Tam giac vuong";
        else if(a*a > b*b+c*c || b*b > a*a+c*c || c*c > a*a+b*b)
            cout<<"Day la tam giac tu";
        else
            cout<<"Day la tam giac nhon";
    }
    else
        cout<<"Tam Giac Khong Hop Le";
}
istream & operator>>(istream &is, TAMGIAC &tg)
{
    do{
        cout<<"Nhap toa do 3 dinh TG\n";
        is>>tg.A>>tg.B>>tg.C;
    }while(!tg.KiemTraHopLe());
    return is;
}
ostream &operator <<(ostream &os, TAMGIAC tg)
{
    os<<"TG qua 3 dinh: "<<tg.A<<"; "<<tg.B<<"; "<<tg.C<<endl;
    return os;
}
int main()
{
    TAMGIAC tg1, tg2(0,2,3,4,1,2), tg3(Diem(1,2),Diem(-2,8),Diem(-4.2,1.7));
    cout<<tg1<<tg2<<tg3;
    cout<<"\nTam giac 1 la ";
    tg1.PhanLoaiTamGiac();
    cout<<"\nChu vi:"; cout<<tg1.TinhChuVi();
    cout<<"\nDien tich: "; cout<<tg1.TinhDienTich();
    cout<<"\n-------------------------\n";
    cout<<"\nTam giac 2 la ";
    tg2.PhanLoaiTamGiac(); cout<<"\nChu vi:"; cout<<tg2.TinhChuVi();
    cout<<"\nDien tich: "; cout<<tg2.TinhDienTich();
    cout<<"\n-------------------------\n";
    cout<<"\nTam giac 3 la ";
    tg3.PhanLoaiTamGiac();
    cout<<"\nChu vi:"; cout<<tg3.TinhChuVi();
    cout<<"\nDien tich: "; cout<<tg3.TinhDienTich();
    cout<<"\n----------------------------\n";
    TAMGIAC *tg4=new TAMGIAC(0,1,2,3,4,5);
    cout<<*tg4;
    cout<<"Tam giac 4 la "; tg4->PhanLoaiTamGiac();
    cout<<"\nChu vi: "; cout<<tg4->TinhChuVi();
    cout<<"\nDien tich: "; cout<<tg4->TinhDienTich();
    return 0;
}
