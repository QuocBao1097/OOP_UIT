#include <iostream>
using namespace std;

int UCLN(int a, int b){
    if(b==0) return a;
    if(a%b==0) return b;
    return UCLN(b, a%b);
}
class Fraction
{
private:
    int tuso;
    int mauso;
    void RutGon()
    {
        int k=UCLN(this->tuso,this->mauso);
        this->tuso/=k;
        this->mauso/=k;
    }
public:
    void Create(int , int );
    void Input();
    Fraction Cong(Fraction);
    Fraction Tru(Fraction);
    Fraction Nhan(Fraction);
    Fraction Chia(Fraction);
    void Output();
};
void Fraction::Create(int tuso, int mauso){
    this->tuso=tuso;
    this->mauso=mauso;
}
void Fraction :: Input(){
    cout<<"Nhap tu so: ";
    cin>>tuso;
    do{
        cout<<"Nhap mau so khac 0: " ;
        cin>>mauso;
    } while (this->mauso==0);
}

void Fraction:: Output(){
    RutGon();
    if(this->mauso==1) cout<<this->tuso;
    else
        if(this->mauso==-1) cout<<-(this->tuso);
    else
        if(this->mauso<0) cout<<-(this->tuso)<<"/"<<-this->mauso;
    else
        cout<<this->tuso<<"/"<<this->mauso;
}
Fraction Fraction::Cong(Fraction Fr2)
{
    Fraction Tong;
    Tong.tuso=tuso*Fr2.mauso+mauso*Fr2.tuso;
    Tong.mauso=mauso*Fr2.mauso;
    Tong.RutGon();
    return Tong;
}
Fraction Fraction::Tru(Fraction Fr2)
{
    Fraction Hieu;
    Hieu.tuso=tuso*Fr2.mauso-mauso*Fr2.tuso;
    Hieu.mauso=mauso*Fr2.mauso;
    Hieu.RutGon();
    return Hieu;
}
Fraction Fraction::Nhan(Fraction Fr2)
{
    Fraction Tich;
    Tich.tuso=tuso*Fr2.tuso;
    Tich.mauso=mauso*Fr2.mauso;
    Tich.RutGon();
    return Tich;
}
Fraction Fraction::Chia(Fraction Fr2)
{
    Fraction Thuong;
    Thuong.tuso=tuso*Fr2.mauso;
    Thuong.mauso=mauso*Fr2.tuso;
    Thuong.RutGon();
    return Thuong;
}
int main() {
   Fraction Fr1; Fraction Fr2;
    /*cout<<"Khoi Tao Phan So Truoc "<<endl;
    Fr1.Create(-5, 6);
    Fr1.Output(); cout<<endl;
    Fr2.Create(6, 3);
    Fr2.Output(); cout<<endl;
     */
    cout<<"Phan So 1\n";
    Fr1.Input();
    Fr1.Output();
    cout<<endl;
    cout<<"Phan So 2\n";
    Fr2.Input();
    Fr2.Output();
    cout<<endl;
    Fraction Fr3=Fr1.Cong(Fr2);
    cout<<"Tong Hai Phan So: ";
    Fr3.Output();
    Fraction Fr4=Fr1.Tru(Fr2);
    cout<<"\nHieu Hai Phan So: ";
    Fr4.Output();
    cout<<"\nTich Hai Phan So: ";
    Fr1.Nhan(Fr2).Output();
    cout<<"\nThuong Hai Phan So: ";
    Fr1.Chia(Fr2).Output();
    return 0;
}
