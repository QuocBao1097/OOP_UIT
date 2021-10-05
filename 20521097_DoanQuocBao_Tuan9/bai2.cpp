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
void Diem::Nhap(){
    cout<<"Hoanh Do: "; cin>>x;
    cout<<"Tung Do: "; cin>>y;
}
void Diem::Xuat(){
    cout<<"("<<x<<";"<<y<<")";
}
void Diem::Dichuyen(double dx, double dy){
    x += dx;
    y += dy;
}
bool Diem::Ktra2diemtrungnhau(Diem dd){
    return (x==dd.x && y==dd.y);
}
double Diem:: Khoangcach(Diem dd){
    return sqrt(pow(x-dd.x,2)+pow(y-dd.y,2));
}
Diem Diem::TimDiemDoiXung(){
    Diem ddx(-x,-y);
    return ddx;
}
double Diem::TinhChuVi(Diem d1, Diem d2){
    double a=this->Khoangcach(d1);
    double b=d1.Khoangcach(d2);
    double c=d2.Khoangcach(*this);
    return a+b+c;
}
double Diem::TinhDienTich(Diem d1, Diem d2){
    double a=this->Khoangcach(d1);
    double b=d1.Khoangcach(d2);
    double c=d2.Khoangcach(*this);
    double p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
istream&operator>>(istream & is, Diem &d){
    cout<<"Hoanh Do: ";
    is>>d.x;
    cout<<"Tung Do: ";
    is>>d.y;
    return is;
}
ostream&operator<<(ostream &os, Diem d){
    os<<"("<<d.x<<","<<d.y<<")";
    return os;
}

//class DIEM3C
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
double DIEM3C::Khoangcach(DIEM3C dd )
{
    return sqrt(pow(x-dd.x,2)+pow(y-dd.y,2)+pow(z-dd.z,2));
}
DIEM3C DIEM3C::TimDiemDoiXung(){
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


// class DiemMau3C
class DIEMMAU3C:public DIEM3C
{
private:
    int Red, Green, Blue;
public:
    ~DIEMMAU3C();
    DIEMMAU3C(double =0, double =0, double=0 , int=0, int =0, int =0);
    int GetR();
    int GetG();
    int GetB();
    void SetR(int);
    void SetG(int);
    void SetB(int);
    void SetRGB(int, int, int);
    void Nhap();
    void Xuat();
    bool KiemTraTrungMau(DIEMMAU3C);
    friend istream&operator>>(istream&is, DIEMMAU3C &);
    friend ostream&operator<<(ostream &os, DIEMMAU3C);
};
DIEMMAU3C:: ~DIEMMAU3C(){};
DIEMMAU3C::DIEMMAU3C (double xx, double yy, double zz, int rr, int gg, int bb):DIEM3C(xx,yy,zz),Red(rr),Green(gg),Blue(bb){};
int DIEMMAU3C::GetR()
{
    return Red;
}
int DIEMMAU3C::GetG()
{
    return Green;
}
int DIEMMAU3C::GetB()
{
    return Blue;
}
void DIEMMAU3C::SetR(int rr)
{
    do{
        cout<<"Nhap mau Red (0-255): "; cin>>rr;
    } while(rr<0 || rr>255);
    Red=rr;
}
void DIEMMAU3C::SetG(int gg)
{
    do{
        cout<<"Nhap mau Green (0-255): "; cin>>gg;
    } while(gg<0 || gg>255);
    Green=gg;
}

void DIEMMAU3C::SetB(int bb)
{
    do{
        cout<<"Nhap mau Blue (0-255): "; cin>>bb;
    } while(bb<0 || bb>255);
    Blue=bb;
}
void DIEMMAU3C::SetRGB(int rr, int gg, int bb)
{
    Red=rr;
    Blue=bb;
    Green=gg;
}
void DIEMMAU3C::Nhap()
{
    DIEM3C::Nhap();
    do{
        cout<<"Red: "; cin>>Red;
    }while(Red <0 || Red>255);
    do{
        cout<<"Green: "; cin>>Green;
    }while(Green <0 || Green >255);
    do{
        cout<<"Blue: "; cin>>Blue;
    }while(Blue <0 || Blue >255);
}
void DIEMMAU3C::Xuat()
{
    DIEM3C::Xuat();
    cout<<"\n-Mau Red: "<<Red;
    cout<<"\n-Mau Green: "<<Green;
    cout<<"\n-Mau Blue: "<<Blue;
}
istream&operator>>(istream &is, DIEMMAU3C &d)
{
    d.DIEM3C::Nhap();
    do{
         cout<<"-Red: "; cin>>d.Red;
    }while(d.Red <0 || d.Red>255);
    do{
          cout<<"-Green: "; cin>>d.Green;
    }while(d.Green <0 || d.Green >255);
    do{
       cout<<"-Blue: "; cin>>d.Blue;
    }while(d.Blue <0 || d.Blue >255);
    return is;
}
ostream&operator<<(ostream &os, DIEMMAU3C d)
{
    d.DIEM3C::Xuat();
    cout<<"\n-Mau Red: "<<d.Red;
    cout<<"\n-Mau Green: "<<d.Green;
    cout<<"\n-Mau Blue: "<<d.Blue;
    return os;
}
bool DIEMMAU3C::KiemTraTrungMau(DIEMMAU3C d)
{
    return (x==d.x && y==d.y && z==d.z && Red==d.Red && Green==d.Green && Blue==d.Blue);
}

int main()
{
    DIEMMAU3C A; DIEMMAU3C B(2,3,4,111,213); DIEMMAU3C C(-3,4,23,82,77,187);
    cout<<"Xuat A: "<<A<<endl;
    cout<<"-----------------"<<endl;
    cout<<"Xuat B: "<<B<<endl;
    cout<<"-----------------"<<endl;
    cout<<"Xuat C: "<<C<<endl;
    cout<<"==========================="<<endl;
    cout<<"Nhap lai Diem A\n";  cin>>A;
    cout<<"-----------------"<<endl;
    cout<<"DIEM A moi nhap: ";A.Xuat();
    B.Dichuyen(2, 4, 1);
    cout<<"\nDi chuyen Diem B (1,2,5)-->B'"; B.Xuat();
    if(B.KiemTraTrungMau(A)) cout<<"\nA & B trung nhau"<<endl;
    else cout<<"\nA & B Khong trung nhau"<<endl;
    return 0;
}
