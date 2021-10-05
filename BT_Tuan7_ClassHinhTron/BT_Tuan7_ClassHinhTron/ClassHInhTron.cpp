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
    double Khoangcach(Diem);
    double TinhChuVi(Diem,Diem);
    double TinhDienTich(Diem, Diem);
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
void Diem::Dichuyen(double dx, double dy)
{
    x=x+dx;
    y=y+dy;
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



class Hinhtron
{
private:
    Diem O;
    float R;
public:
    Hinhtron();
    Hinhtron(double,double);
    Hinhtron(Diem);
    Diem GetO();
    void Set0(Diem);
    void Nhap();
    void Xuat();
    double TinhChuVi();
    void Dichuyen(double, double);
    double TinhDienTich();
    bool KiemTraHopLe();
    friend istream & operator>>(istream &, Hinhtron&);
    friend ostream & operator<<(ostream &, Hinhtron);
};
Hinhtron ::Hinhtron()
{
    while(!KiemTraHopLe())
        cin>>*this;
}
Hinhtron ::Hinhtron(double xO, double yO): O(xO, yO)
{
    while(KiemTraHopLe())
        cin>>*this;
}
Diem Hinhtron::GetO()
{
    return O;
}

void Hinhtron::Set0(Diem OO)
{
    O=OO;
    while(!KiemTraHopLe())
        cin>>O;
}

void Hinhtron::Nhap()
{
    cout<<"Nhap Ban Kinh R: "; cin>>R;
    cout<<"\nNhap Toa Do Diem O: ";
    cin>>O;
}

void Hinhtron::Xuat()
{
    cout<<"Ban Kinh R: "; cout<<R;
    cout<<"\nToa do Diem O: "; cout<<O;
}

void Hinhtron::Dichuyen(double dx, double dy)
{
    O.Dichuyen(dx, dy);
}
double Hinhtron::TinhChuVi()
{
    float cv=2*3.14*R;
    return  cv;
}

double Hinhtron::TinhDienTich()
{
    float dt=3.14*R*R;
    return dt;
}

bool Hinhtron::KiemTraHopLe()
{
    return R>0;
}

istream & operator>>(istream &is, Hinhtron &ht)
{
    do{
        cout<<"\nNhap ban kinh R= "; is>>ht.R;
        cout<<"Nhap toa do diem O\n";
        is>>ht.O;
    } while(!ht.KiemTraHopLe());
    return is;
}

ostream & operator<<(ostream &os, Hinhtron ht)
{
    os<<"\nBAN KINH R: "<<ht.R;
    os<<"\nToa Do Tam : "<<ht.O<<endl;
    return os;
}

int main()
{
    Hinhtron ht1, ht2, ht3;
    cout<<"\n---------------\n";
    cout<<"HINH TRON 1 ";
    cout<<"\nChu vi: "; cout<<ht1.TinhChuVi();
    cout<<"\nDien tich: "; cout<<ht1.TinhDienTich();
    cout<<"\n---------------\n";
    cout<<"HINH TRON 2 ";
    cout<<"\nChu vi: "; cout<<ht2.TinhChuVi();
    cout<<"\nDien tich: "; cout<<ht2.TinhDienTich();
    cout<<"\n---------------\n";
    cout<<"HINH TRON 3 ";
    cout<<"\nChu vi: "; cout<<ht3.TinhChuVi();
    cout<<"\nDien tich: "; cout<<ht3.TinhDienTich();
    cout<<endl;
    return 0;
}
