
#include <iostream>
using namespace std;

class SoPhuc
{
private:
    float a;//phanthuc
    float b;//phanao
public:
    friend SoPhuc operator+(SoPhuc sp1,SoPhuc sp2);
    friend SoPhuc operator-(SoPhuc sp1 ,SoPhuc sp2);
    SoPhuc operator * (SoPhuc sp);
    SoPhuc operator / (SoPhuc sp);
    bool operator == (SoPhuc sp);
    bool operator!=(SoPhuc sp);
    bool operator>(SoPhuc sp);
    bool operator>=(SoPhuc sp);
    bool operator<(SoPhuc sp);
    bool operator<=(SoPhuc sp);
    friend istream & operator >>(istream &is, SoPhuc &sp);
    friend ostream & operator <<(ostream &os, SoPhuc &sp);
    SoPhuc()
    {
        a=1;
        b=1;
    }
    SoPhuc(float aa, float bb)
    {
        a=aa;
        b=bb;
    }
};
istream & operator>>(istream &is, SoPhuc &sp)
{
    cout<<"Phan thuc: "; is>>sp.a;
    cout<<"Phan ao: "; is>>sp.b;
    return is;
}
ostream & operator <<(ostream &os, SoPhuc &sp)
{
    os<<sp.a;
    if(sp.b>0) os<<"+";
    os<<sp.b<<"i";
    return os;
}
SoPhuc operator + (SoPhuc sp1, SoPhuc sp2)
{
    SoPhuc tong;
    tong.a=sp1.a+sp2.a;
    tong.b=sp1.b+sp2.b;
    return tong;
}
SoPhuc operator - (SoPhuc sp1, SoPhuc sp2)
{
    SoPhuc hieu;
    hieu.a=sp1.a-sp2.a;
    hieu.b=sp1.b-sp2.b;
    return hieu;
}
SoPhuc SoPhuc::operator * (SoPhuc sp)
{
    SoPhuc tich;
    tich.a=a*sp.a-b*sp.b;
    tich.b=a*sp.b+b*sp.a;
    return tich;
}
SoPhuc SoPhuc::operator / (SoPhuc sp)
{
    SoPhuc thuong;
    thuong.a=(a*sp.a+b*sp.b) / ((sp.a*sp.a+sp.b*sp.b));
    thuong.b=(b*sp.a-a*sp.b) / ((sp.a*sp.a+sp.b*sp.b));
    return thuong;
}
bool SoPhuc::operator==(SoPhuc sp)
{
    if((a==sp.a) && (b==sp.b)) return true;
    return false;
}
bool SoPhuc::operator!=(SoPhuc sp)
{
    if((a==sp.a) && (b==sp.b)) return false;
    return true;
}
bool SoPhuc::operator>(SoPhuc sp)
{
    if((a>sp.a) && (b>sp.b))
        return true;
       return false;
}
bool SoPhuc::operator<(SoPhuc sp)
{
    if((a<sp.a) && (b<sp.b))
        return true;
    return false;
}
int main()
{
    SoPhuc sp1, sp2, sptong, sphieu, spthuong, sptich;
    cout<<"Nhap So phuc 1"<<endl;
    cin>>sp1;
    cout<<"\nNhap So phuc 2 "<<endl;
    cin>>sp2;
    sptong=sp1+sp2;
    sphieu=sp1-sp2;
    sptich=sp1*sp2;
    spthuong=sp1/sp2;
    cout<<"----------------------------"<<endl;
    cout<<"So phuc 1: "<<sp1<<endl;
    cout<<"So phuc 2: "<<sp2<<endl;
    if(sp1==sp2)
        cout<<"\nSo phuc 1 = So phuc 2";
    if(sp1!=sp2)
        cout<<"\nSo phuc 1 != So phuc 2";
    if(sp1>sp2)
        cout<<"\nSo phuc 1 > so phuc 2";
    if(sp1<sp2)
        cout<<"\nSo phuc 1 < so phuc 2";
    cout<<"\nTong hai so phuc: "<<sptong;
    cout<<"\nHieu hai so phuc: "<<sphieu;
    cout<<"\nTich hai so phuc: "<<sptich;
    cout<<"\nThuong hai so phuc:"<<spthuong;
    return 0;
}
