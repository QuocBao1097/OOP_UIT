#include<iostream>

using namespace std;
class BCC
{
private:
    int n;
    int m;
public:
    void Create();
    void Create(int);
    void Create(int, int);
    void Nhap_mn();
    void InBCCthum();
    void BCCmn(); 
    void BCCtonghop();
};
void BCC:: Create()
{
    this->n=this->m=2;
}
void BCC:: Create(int mm)
{
    this->m=mm;
}
void BCC:: Create(int mm,int nn)
{
    this->m=mm;
    this->n=nn;
}
void BCC:: Nhap_mn()
{
    cout<<"Nhap m va n: "<<endl;
    do {
        cout<<"Nhap m : ";
        cin>>m;
    } while (m<=2 || m>=9);
    do {
        cout<<"Nhap n : ";
        cin>>n;
    }while(n<=2 || n>=9);
}
void BCC::InBCCthum()
{
    cout<<"Xuat BCC "<<m<<endl;
    for(int i=1; i<=10 ; i++)
        cout<<m<<"x ="<<m*i<<endl;
}
void BCC::BCCmn()
{
    if (m>n)
    {
        cout<<"Bang cuu chuong tu "<<m<<" ve "<<n<<" la:"<<endl;
        for (int i = 1; i <= 10; i++)
        {
            for(int k=m;k>=n;k--)
                cout <<k<<"x"<<i<<" = "<< k*i <<"\t";
            cout<<endl;
        }
    }
    else
    {
        cout<<"Bang cuu chuong tu "<<m<<" den "<<n<<" la:"<<endl;
        for (int i = 1; i <= 10; i++)
        {
            for(int k=m;k<=n;k++)
                cout << k << " x " << i << " = " << k * i <<"\t";
            cout<<endl;
        }
    }
}
void BCC:: BCCtonghop()
{
    cout<<"BCC TONG HOP: "<<endl;
    for(int i=1; i<=10; i++){
        for(int j=1; j<=10; j++)
            cout<<i*j<<"\t";
        cout<<endl;
    }
}
int main()
{
    BCC k;
    //k.Create();
    //k.Create(5);
    //k.Create(3, 6);
    k.Nhap_mn();
    k.InBCCthum();
    k.BCCmn();
    k.BCCtonghop();
    return 0;
}
