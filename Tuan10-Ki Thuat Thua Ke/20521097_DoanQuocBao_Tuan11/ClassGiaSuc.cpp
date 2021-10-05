
#include<iostream>
#include<string>
#include<vector>
#include<random>
#include<time.h>

using namespace std;
class GiaSuc
{
private:
    int slcon;
    int litSua;
    string TiengKeu;
public:
    GiaSuc();
    GiaSuc(int con,int sua,const string say);
    virtual ~GiaSuc();
    int GetCon(){
        return slcon;
    }
    int GetLitSua(){
        return litSua;
    }
    string GetTiengKeu(){
        return TiengKeu;
    }
    void Setslcon(int sl);
    void SetLitSua(int milk);
    void SetTiengKeu(string say);
    virtual void Print();
    virtual void  Say()=0;
};
// class con bo
class Cow:public GiaSuc
{
private:
    const string say="CowCowCow";
public:
    Cow();
    ~Cow();
    virtual void Say();
    void Print();
};
//class con cuu
class Sheep:public GiaSuc
{
private:
    const string say="SheepSheepSheep";
public:
    Sheep();
    ~Sheep();
    virtual void Say();
    void Print();
};

// class con de
class Goat:public GiaSuc
{
private:
    const string say="GoatGoatGoat";
public:
    Goat();
    ~Goat();
    virtual void Say();
    void Print();
};
GiaSuc::~GiaSuc(){}
GiaSuc::GiaSuc(){
    Setslcon(0);
    SetLitSua(0);
    SetTiengKeu("");
}
GiaSuc::GiaSuc(int con,int sua,const string say){
    SetLitSua(sua);
    Setslcon(con);
    SetTiengKeu(say);
}
void GiaSuc::Setslcon(int sl){
    slcon=sl;
}
void GiaSuc::SetLitSua(int sua){
    litSua=sua;
}
void GiaSuc::SetTiengKeu(string say){
    TiengKeu=say;
}
void GiaSuc::Print(){
    cout<<"sinh "<<GetCon()<<" con va cung cap "<<GetLitSua()<<" lit sua, tieng keu "
    <<GetTiengKeu()<<" khi doi bung";
}
Cow::Cow(){
    SetTiengKeu(say);
    SetLitSua(rand()%20+1);
    Setslcon(rand()%10+1);
}
Cow::~Cow(){}
void Cow::Say(){
    cout<<say;
}
void Cow::Print(){
    cout<<"Bo ";
    GiaSuc::Print();
}
Sheep::Sheep(){
    SetTiengKeu(say);
    SetLitSua(rand()%5+1);
    Setslcon(rand()%10+1);
}
Sheep::~Sheep(){}
void Sheep::Say(){
    cout<<say;
}
void Sheep::Print(){
    cout<<"Cuu ";
    GiaSuc::Print();
}
Goat::Goat(){
    SetTiengKeu(say);
    SetLitSua(rand()%10+1);
    Setslcon(rand()%10+1);
}
Goat::~Goat(){}
void Goat::Say(){
    cout<<say;
}
void Goat::Print(){
    cout<<"De ";
    GiaSuc::Print();
}

void Input(vector<vector<GiaSuc*>> &List){
    int chon;
    do{
        cout<<"1. Nhap con Bo\n";
        cout<<"2. Nhap con Cuu\n";
        cout<<"3. Nhap con De\n";
        cout<<"4. Quay tro ve Menu\n";
        cout<<"--------------------------\n";
        cout<<"Moi ban chon: "; cin>>chon;
        switch (chon)
        {
            case 1:
                int n;
                cout<<"So luong con Bo: ";
                cin>>n;
                List[0].resize(0);
                for(int i=0;i<n;i++){
                    List[0].push_back(new Cow);
                }
                break;
            case 2:
                int p;
                cout<<"So luong con Cuu: ";
                cin>>p;
                List[1].resize(0);
                for(int i=0;i<p;i++){
                    List[1].push_back(new Sheep);
                }
                break;
            case 3:
                int m;
                cout<<"So luong con De: ";
                cin>>m;
                List[2].resize(0);
                for(int i=0;i<m;i++){
                    List[2].push_back(new Goat);
                }
                break;
            default:
                break;
        }
    }while(chon!=4);
}

void Print(vector<vector<GiaSuc*>> &List){
    cout<<"-----D/S gia suc----\n";
    for(int i=0;i<List.size();i++){
        for(int j=0;j<List[i].size();j++){
            List[i][j]->Print();
            cout<<endl;
        }
    }
    cout<<"--------------------------\n";
}
void Say(vector<vector<GiaSuc*>> &List){
    cout<<"-----Tieng Keu----\n";
    for(int i=0;i<List.size();i++){
        for(int j=0;j<List[i].size();j++){
            List[i][j]->Say();
            cout<<endl;
        }
    }
    cout<<"--------------------------\n";
}
int main()
{
    srand((int)time(NULL));
    vector<vector<GiaSuc*>> ListCattle;
    ListCattle.resize(3);
    int chon;
    do{
        cout<<"===Quan ly Gia Suc====\n";
        cout<<"1. Nhap loai Gia Suc\n";
        cout<<"2. In D/S cac loai gia suc \n";
        cout<<"3. Tieng Keu\n";
        cout<<"0. Thoat chuong trinh!!!\n";
        cout<<"------------------------------\n";
        cout<<"Moi ban chon:  ";
        cin>>chon;
        switch (chon)
        {
            case 1:
                Input(ListCattle);
                break;
            case 2:
                Print(ListCattle);
                break;
            case 3:
                Say(ListCattle);
                break;
        }
    }while(chon!=0);
    cout<<"Thoat Chuong Trinh..."<<endl;
    return 0;
}

