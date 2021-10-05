
#include<iostream>

using namespace std;
class HinhVe{
private:
    int H;
    int W;
public:
    void Create();
    void Create(int);
    void Create(int, int);
    void Nhapdodai();
    void VeHCNRong();
    void VeHCNDac();
    void VeTamGiacCanDac();
    void VeTamGiacCanRong();
};
void HinhVe:: Create()
{
    this->H=this->W=1;
}
void HinhVe:: Create(int H, int W)
{
    this->H=H; this->W=W;
}
void HinhVe:: Create(int H)
{
    this->H=H;
}
void HinhVe:: Nhapdodai()
{
    do{
        cout<<"Nhap Chieu Dai: ";
        cin>>this->H;
    } while (H<=0);
    do{
        cout<<"Nhap Chieu Rong: ";
        cin>>this->W;
    } while (W<=0);
}
void HinhVe:: VeHCNRong()
{
    cout<<"Hinh Ve HCN Rong "<<endl;
    for(int i=1;i<=H; i++)
    {
        if(i==1 || i==H)
        {
            for(int j=1; j<=W; j++)
                cout<<"* ";
           cout<<endl;
        }
        else
            {
                for(int j=1; j<=W; j++)
                {
                    if(j==1 || j==W)
                        cout<<"* ";
                    else
                        cout<<"  ";
            }
        cout<<endl;
            }
    }
}
void HinhVe:: VeHCNDac()
{
    cout<<"Hinh Ve HCN dac" <<endl;
    for(int i=1; i<=H; i++)
    {
        for(int j=1; j<=W; j++)
        {
            cout<<"* ";
    }
        cout<<endl;
    }
}
void HinhVe:: VeTamGiacCanDac()
{
    cout<<"Tam Giac Can Dac "<<endl;
    for(int i=1; i<=H; i++)
    {
        for(int j=1; j<=H; j++)
        {
            if (j<=H-i) cout<<"  ";
            else cout<<"* ";
        }
        cout<<endl;
    }
}
void HinhVe:: VeTamGiacCanRong()
{
    cout<<"Ve Tam Giac Can Rong "<<endl;
    for (int i = 1; i < H; i++)
    {
        for (int j = 1; j <= H; j++)
            if((j+i)==H+1||j==H) cout<<"* ";
            else cout<<"  ";
        cout<<endl;
    }
    for (int i = 1; i <= H; i++) cout<<"* ";
    cout<<endl;
}
int main ()
{
    HinhVe HV;
   // HV.Create(5, 6);
   // HV.Create(7);
    HV.Nhapdodai();
   // HV.Create();
    HV.VeHCNRong();
    HV.VeHCNDac();
    HV.VeTamGiacCanDac();
    HV.VeTamGiacCanRong();
    return 0;
}
