#include<iostream>
#include<cmath>

using namespace std;
class Diem
{
protected:
    double x;
    double y;
public:
    ~Diem();
    //Diem ();
    //Diem(double);
    Diem (double =0, double=0);
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
Diem::~Diem(){}
//Diem :: Diem()
//Diem :: Diem(double xx):x(xx), y(0){}
Diem :: Diem(double xx, double yy): x(xx), y(yy){}
double Diem:: getX()
{
    return x;
}
double Diem:: getY()
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
void Diem::setXY(double xx,double yy)
{
    x=xx;
    y=yy;
}
void Diem::Nhap()
{
    cout<<"Hoanh Do: ";
    cin>>x;
    cout<<"Tung Do: ";
    cin>>y;
}
void Diem::Xuat()
{
    cout<<"("<<x<<";"<<y<<")";
}
void Diem::Dichuyen(double dx, double dy)
{
    x += dx;
    y += dy;
}
bool Diem::Ktra2diemtrungnhau(Diem dd)
{
    return (x==dd.x && y==dd.y);
}
double Diem:: Khoangcach(Diem dd)
{
    return sqrt(pow(x-dd.x,2)+pow(y-dd.y,2));
}
Diem Diem::TimDiemDoiXung()
{
    Diem ddx(-x,-y);
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
istream&operator>>(istream & is, Diem &d)
{
    cout<<"Hoanh Do: ";
    is>>d.x;
    cout<<"Tung Do: ";
    is>>d.y;
    return is;
}
ostream&operator<<(ostream &os, Diem d)
{
    os<<"("<<d.x<<","<<d.y<<")";
    return os;
}


class DIEM3C:public Diem
{
protected:
    double z;
public:
    ~DIEM3C();
    DIEM3C(double =0, double =0, double =0);
    double getZ();
    void setZ(double);
    void setXYZ(double, double, double);
    void Nhap();
    void Xuat();
    void Dichuyen(double, double, double);
    bool Ktra2diemtrungnhau(DIEM3C z);
    double Khoangcach(DIEM3C);
    DIEM3C   TimDiemDoiXung();
    double TinhChuVi(DIEM3C, DIEM3C);
    double TinhDienTich(DIEM3C, DIEM3C);
    friend istream & operator>>(istream&, DIEM3C &);
    friend ostream & operator<<(ostream&, DIEM3C );
};
DIEM3C ::~DIEM3C(){}
DIEM3C::DIEM3C(double xx, double yy, double zz) : Diem(xx,yy), z(zz){};
void DIEM3C::setZ(double zz)
{
    z=zz;
}
double DIEM3C::getZ()
{
    return z;
}
void DIEM3C::setXYZ(double xx, double yy, double zz)
{
    x=xx;
    y=yy;
    z=zz;
}
void DIEM3C::Nhap()
{
    Diem::Nhap();
    cout<<"Cao do: ";
    cin>>z;
}
void DIEM3C::Xuat(){
    cout<<"("<<x<<","<<y<<","<<z<<")";
}
istream&operator>>(istream & is, DIEM3C &d)
{
    d.Diem::Nhap();
    cout<<"Cao do: ";
    is>>d.z;
    return is;
}
ostream&operator<<(ostream &os, DIEM3C d)
{
    os<<"("<<d.x<<","<<d.y<<","<<d.z<<")";
    return os;
}
void DIEM3C::Dichuyen(double dx, double dy, double dz)
{
    x+=dx;
    y+=dy;
    z+=dz;
}
bool DIEM3C::Ktra2diemtrungnhau(DIEM3C dd)
{
    return x==dd.x && z==dd.z && y==dd.y;
}
double DIEM3C::Khoangcach(DIEM3C dd)
{
    return sqrt(pow(x-dd.x,2)+pow(y-dd.y,2)+pow(z-dd.z,2));
}
DIEM3C DIEM3C::TimDiemDoiXung()
{
    DIEM3C ddx(x==0?0:-x, y==0?0:-y, z==0?0:-z);
    return ddx;
}
double DIEM3C::TinhChuVi(DIEM3C d1, DIEM3C d2)
{
    double a=this->Khoangcach(d1);
    double b=d1.Khoangcach(d2);
    double c=d2.Khoangcach(*this);
    return a+b+c;
}
double DIEM3C:: TinhDienTich(DIEM3C d1, DIEM3C d2)
{
    double a=this->Khoangcach(d1);
    double b=d1.Khoangcach(d2);
    double c=d2.Khoangcach(*this);
    double p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

int main()
{
    DIEM3C A; DIEM3C B(1,-5); DIEM3C C(7,4,8);
    cout<<"Toa Do DIEM A: "; cout<<A<<endl;
    cout<<"Toa Do DIEM B: "; cout<<B<<endl;
    cout<<"Toa Do DIEM C: "; cout<<C<<endl;
    cout<<"------------------"<<endl;
    cout<<"Nhap lai toa do DIEM A "<<endl;
    cin>>A;
    cout<<"------------------"<<endl;
    cout<<"DIEM A Moi nhap->"; A.Xuat();
    C.Dichuyen(2,1,5);
    cout<<"\nToa do C(7,4,8) sau khi di chuyen (2,1,5) don vi la: "; C.Xuat();
    DIEM3C D=C.TimDiemDoiXung();
    cout<<"\nDiem Doi Xung Voi C"; D.Xuat();
    if(A.Ktra2diemtrungnhau(C)) cout<<"A & C Trung nhau";
    else
        cout<<"\nA & C Khong trung nhau"<<endl;
    cout<<"Chu Vi: "<<A.TinhChuVi(B, C);
    cout<<"\nDien Tich: "<<A.TinhDienTich(B, C)<<endl;
    return 0;
} 
