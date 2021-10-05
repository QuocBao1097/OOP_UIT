

#include <iostream>
#include<cmath>
using namespace std;

class CtimeSpan
{
private:
    int gio, phut, giay;
public:
    CtimeSpan(int a=0 , int b=0, int c=0);
    ~CtimeSpan();
    CtimeSpan operator+(CtimeSpan &);
    CtimeSpan operator-(CtimeSpan&);
    bool operator<(CtimeSpan&);
    bool operator<=(CtimeSpan &);
    bool operator>(CtimeSpan&);
    bool operator>=(CtimeSpan &);
    bool operator==(CtimeSpan &);
    bool operator!=(CtimeSpan &);
    friend istream & operator>>(istream &is, CtimeSpan &a);
    friend ostream & operator<<(ostream &os, const CtimeSpan &a );
};
CtimeSpan::CtimeSpan(int a, int b, int c)
{
    gio=(a<0||a>23)?0:a;
    phut=(b<0||b>59)?0:b;
    giay=(c<0||c>59)?0:c;
    
}
CtimeSpan::~CtimeSpan()
{
   // cout<<"Goi ham huy !!!"<<endl;
}
CtimeSpan CtimeSpan::operator+(CtimeSpan &x)
{
    int a, b;
    CtimeSpan c;
    a=(giay+x.phut)/60;
    c.giay=(giay+x.giay)%60;
    b=(phut+x.phut)/60;
    c.phut=(phut+x.phut+a)%60;
    c.gio=gio+b+x.gio;
    return c;
}
ostream &operator<<(ostream &os, const CtimeSpan &a)
{
    if(a.gio<0||a.phut<0||a.giay<0) os<<"-";
    os<<(a.gio<10 && a.gio>=0? "0":"")<<abs(a.gio)<<":"<<(a.phut<10 && a.phut>=0?"0":"")<<abs(a.giay)<<":"<<(a.giay<10 && a.giay>=0?"0":"")<<abs(a.giay);
    return os;
}
istream &operator>>(istream &is, CtimeSpan &a)
{
    is>>a.gio>>a.phut>>a.giay;
    return is;
}
CtimeSpan CtimeSpan::operator-(CtimeSpan &x)
{
    CtimeSpan c; int a, b;
    a=(giay-x.giay<0)?-1:0;
    c.giay=(a==-1)?60+giay-x.giay:giay-x.giay;
    b=(phut-x.phut+a)<0?-1:0;
    c.phut=(b==-1)?(60+phut-x.phut+a):(phut-x.phut);
    c.gio=b+gio-x.gio;
    if(c.gio<0){
        a=(-giay+x.giay<0)?-1:0;
        c.giay=(a==-1)?60-giay+x.giay:-giay+x.giay;
        b=(-phut+x.phut+a)<0?-1:0;
        c.phut=(b==-1)?60-phut+x.phut+a:-phut+x.phut+a;
        c.gio=-(b-gio+x.gio);
        return c;
    }
    return c;
}
bool CtimeSpan::operator<(CtimeSpan &x)
{
    CtimeSpan c;
    int a,b;
    a=(giay-x.giay<0)?-1:0;
    c.giay=(a==-1)?60+giay-x.giay:giay-x.giay;
    b=(phut-x.phut+a)<0?-1:0;
    c.phut=(b==-1)?60+phut-x.phut+a:phut-x.phut+a;
    c.gio=b+gio-x.gio;
    if(c.gio<0) return true;
    return false;
}
bool CtimeSpan::operator<=(CtimeSpan &x)
{
    CtimeSpan c;
    int a,b;
    a=(giay-x.giay<0)?-1:0;
    c.giay=(a==-1)?60+giay-x.giay:giay-x.giay;
    b=(phut-x.phut+a)<0?-1:0;
    c.phut=(b==-1)?60+phut-x.phut+a:phut-x.phut+a;
    c.gio=b+gio-x.gio;
    if(c.gio<=0) return true;
    return false;
}
bool CtimeSpan::operator>(CtimeSpan &x)
{
    CtimeSpan c;
    int a,b;
    a=(giay-x.giay<0)?-1:0;
    c.giay=(a==-1)?60+giay-x.giay:giay-x.giay;
    b=(phut-x.phut+a)<0?-1:0;
    c.phut=(b==-1)?60+phut-x.phut+a:phut-x.phut+a;
    c.gio=b+gio-x.gio;
    if(c.gio>=0 && (c.phut!=0 || c.giay!=0)) return true;
    return false;
}
bool CtimeSpan::operator>=(CtimeSpan &x)
{
    CtimeSpan c;
    int a,b;
    a=(giay-x.giay<0)?-1:0;
    c.giay=(a==-1)?60+giay-x.giay:giay-x.giay;
    b=(phut-x.phut+a)<0?-1:0;
    c.phut=(b==-1)?60+phut-x.phut+a:phut-x.phut+a;
    c.gio=b+gio-x.gio;
    if(c.gio>=0 && c.phut>=0 && c.giay>=0) return true;
    return false;
}
bool CtimeSpan::operator==(CtimeSpan &x)
{
    if(giay==x.giay && phut==x.phut && gio==x.gio) return true;
    return false;
}
bool CtimeSpan::operator!=(CtimeSpan &x)
{
    if(giay!=x.giay || phut!=x.phut || gio!=x.gio) return true;
    return false;
}

int main()
{
    CtimeSpan x(6,4,12), y(1, 2, 23);
    cout<<x+y<<endl;
    cout<<x-y<<endl;
    if(x<=y) cout<<"x <= y"<<endl;
    else cout<<"x >= y"<<endl;
    if(x==y) cout<<"x = y"<<endl;
    else cout<<"X != y";
    cout<<endl;
    return 0;
}
