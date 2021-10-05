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
    void InBCCthun();
    void BCCnm();
    void BCCtu2den9();
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
void BCC::InBCCthun()
{
    cout<<"Xuat BCC:\n";
    for(int i=1; i<=10 ; i++)
        cout<<n<<"x"<<i<<"="<<n*i<<endl;
}
void BCC::BCCnm()
{
    if (n>m)
    {
        cout<<"Bang cuu chuong tu "<<n<<" ve "<<m<<" la:"<<endl;
        for (int i = 1; i <= 10; i++)
        {
            for(int k=n;k>=m;k--)
                cout << k << " x " << i << " = " << k * i <<"\t";
            cout<<endl;
        }
    }
    else
    {
        cout<<"Bang cuu chuong tu "<<n<<" den "<<m<<" la:"<<endl;
        for (int i = 1; i <= 10; i++)
        {
            for(int k=n;k<=m;k++)
                cout << k << " x " << i << " = " << k * i <<"\t";
            cout<<endl;
        }
    }
}
void BCC:: BCCtu2den9()
{
    cout<<"BCC Tu 2->9: "<<endl;
    for(int i=1; i<=10; i++){
        for(int j=2; j<=9; j++)
            cout<<i*j<<"\t";
        cout<<endl;
    }
}
int main()
{
    BCC k;
    //k.Create();
    //k.Create(5);
    k.Create(3, 6);
    //k.Nhap_mn();
    k.InBCCthun();
    k.BCCnm();
    k.BCCtu2den9();
    return 0;
}

