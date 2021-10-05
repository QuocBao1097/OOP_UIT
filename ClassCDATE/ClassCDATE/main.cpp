
#include <iostream>

using namespace std;

class CDate
{
private:
    int Ngay,Thang,Nam;
public:
    CDate()//Ham khoi tao khong doi so
    {
        Ngay=8;
        Thang=1;
        Nam=2002;
    }
   // ~CDate(){};
    CDate(int date,int month,int year)//Ham khoi tao co doi so
    {
        Ngay=date;
        Thang=month;
        Nam=year;
    }
    CDate(CDate &c)//Ham tao sao chep
    {
        Ngay=c.Ngay; Thang=c.Thang; Nam=c.Nam;
    };
    const CDate&operator=(const CDate&); //Ham gan
    bool namNhuan();// Kiểm tra có phải là năm nhuân hay không?
    int daysIn();// Số ngày trong tháng
    void  reset(int date,int month,int year)// Hàm tạo giá trị mới cho ngày-tháng-năm
    {
        Ngay=date; Thang=month; Nam=year;
    }
    friend istream& operator>>(istream&, CDate&);
    friend ostream& operator<<(ostream&, CDate&);
    CDate operator+(int );// Cộng thêm số ngày
};

const CDate& CDate::operator=(const CDate &c)
{
    Ngay=c.Ngay;
    Thang=c.Thang;
    Nam=c.Nam;
    return *this;
}
bool CDate::namNhuan()
{
    if((Nam % 4==0 && Nam%100!=0)||Nam % 400==0)
        return true;
        else
            return false;
}
int CDate::daysIn()
{
    if(Thang==1||Thang==3||Thang==5||Thang==7||Thang==8||Thang==10||Thang==12) return 31;
    else
        if(Thang==4||Thang==6||Thang==9||Thang==11) return 30;
        else
            if(namNhuan()) return 29;
            else return 28;
}

istream& operator>>(istream &nhap,CDate &c)
{
    cout<<"\nNhap nam : "; cin>>c.Nam;
    while(c.Nam<1900){
        cout<<"Nam khong hop le, hay nhap lai.. "; cin>>c.Nam;
    }
    cout<<"Nhap thang : "; cin>>c.Thang;
    while(c.Thang<1||c.Thang>12){
        cout<<"Thang chi co the la [1..12], hay nhap lai.. "; cin>>c.Thang;
    }
    cout<<"Nhap ngay : "; cin>>c.Ngay;
    while((c.Ngay>c.daysIn())||c.Ngay<1)
    {
        cout<<"\nThang "<<c.Thang<<"-"<<c.Nam<<" co "<<c.daysIn()<<" ngay, nhap lai cho dung.. ";
        cin>>c.Ngay;
    }
    return nhap;
}
ostream& operator<<(ostream &xuat,CDate &c)
{
    cout<<c.Ngay<<"-"<<c.Thang<<"-"<<c.Nam;
    return xuat;
}
CDate CDate::operator+(int d)
{
    CDate c=*this;
    c.Ngay+=d;
    do{
        if(c.Ngay>c.daysIn()){c.Ngay-=c.daysIn(); c.Thang++;}
        if(c.Thang>12){c.Thang-=12; c.Nam++;}
    }while(c.Ngay>c.daysIn());
    return c;
}
int main()
{
    CDate a,b;
    cout<<"Nhap ngay thang nam :"; cin>>a;
    b=a+20;
    cout<<"Cong them 20 ngay thanh : "<<b<<endl;
    return 0;
}
