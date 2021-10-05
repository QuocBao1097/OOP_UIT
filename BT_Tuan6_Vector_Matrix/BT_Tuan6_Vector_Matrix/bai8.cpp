
#include<vector>
#include<iostream>
using namespace std;
class CVector
{
private:
    vector<double> VT;
    int Length;
public:
    CVector();
    CVector(int n);
    ~CVector();
    int GetLength();
    double operator[](int i);
    CVector operator+(const CVector & vt );
    CVector operator-(const CVector & vt);
    CVector operator*(const CVector & vt);
    CVector operator*(const int k);
    friend ostream & operator<<(ostream & os,const CVector& vt);
    friend istream & operator>>(istream & is,CVector& vt);
};
CVector::CVector()
{
    int n=0;
}
CVector::CVector(int n)
{
    VT.resize(n);
    Length=n;
    for(int i=0;i<Length;i++){
        VT[i]=0;
    }
}
CVector::~CVector(){
}
CVector CVector::operator+(const CVector & vt )
{
    if(this->Length!=vt.Length){
        cout<<"Not the same lenght!"<<endl;
        return *this;
    }
    CVector res;
    res=*this;
    for(int i=0;i<Length;i++){
        res.VT[i]+=vt.VT[i];
    }
    return res;
}
CVector CVector::operator-(const CVector & vt)
{
    if(this->Length!=vt.Length){
        cout<<"Not the same lenght!"<<endl;
        return *this;
    }
    CVector res;
    res=*this;
    for(int i=0;i<Length;i++){
        res.VT[i]-=vt.VT[i];
    }
    return res;
}
CVector CVector::operator*(const CVector & vt)
{
    if(this->Length!=vt.Length){
        cout<<"Not the same lenght!"<<endl;
        return *this;
    }
    CVector res;
    res=*this;
    for(int i=0;i<Length;i++){
        res.VT[i]*=vt.VT[i];
    }
    return res;
}
CVector CVector::operator*(const int k)
{
    CVector res;
    res=*this;
    for(int i=0;i<Length;i++){
        res.VT[i]*=k;
    }
    return res;
}
ostream & operator<<(ostream & os,const CVector& vt)
{
    os<<"( ";
    for(int i=0;i<vt.Length;i++){
        if(i!=vt.Length-1)
            os<<vt.VT[i]<<" , ";
        else{
            os<<vt.VT[i];
        }
    }
    os<<" )";
    return os;
}
istream & operator>>(istream & is,CVector& vt)
{
    cout<<"Input Length: ";
    is>>vt.Length;
    vt.VT.resize(vt.Length);
    cout<<"Input element: "<<endl;
    for(int i=0;i<vt.Length;i++){
        is>>vt.VT[i];
    }
    return is;
}
double CVector::operator[](int i){
    return VT[i];
}
int CVector::GetLength(){
    return Length;
}

class CMatrix
{
private:
    vector<vector <double>> VT;
    int Rows;
    int Columns;
public:
    CMatrix();
    CMatrix(int m,int n);
    ~CMatrix();
    CMatrix operator+(const CMatrix & MT);
    CMatrix operator-(const CMatrix & MT);
    CMatrix operator*(const CMatrix & MT);
    CMatrix operator*(const int k);
    CMatrix operator*(CVector & vt);
    friend ostream & operator<<(ostream & os,const CMatrix& MT);
    friend istream & operator>>(istream & is,CMatrix& MT);
    
};
CMatrix::CMatrix(){
    Rows=Columns=0;
}
CMatrix::CMatrix(int m,int n){
    Rows=m;
    Columns=n;
    VT.resize(Rows);
    for(int i=0;i<Rows;i++){
        VT[i].resize(Columns);
        for(int j=0;j<Columns;j++){
            VT[i][j]=0;
        }
    }
}
CMatrix::~CMatrix(){
}
CMatrix CMatrix::operator+(const CMatrix & MT)
{
    if(Rows!=MT.Rows||Columns!=MT.Columns){
        cout<<"2 matrix are not compatible!"<<endl;
        return *this;
    }
    CMatrix res;
    res=*this;
    for(int i=0;i<Rows;i++){
        for(int j=0;j<Columns;j++){
            res.VT[i][j]+=MT.VT[i][j];
        }
    }
    return res;
}
CMatrix CMatrix::operator-(const CMatrix & MT)
{
    if(Rows!=MT.Rows||Columns!=MT.Columns){
        cout<<"2 matrix are not compatible!"<<endl;
        return *this;
    }
    CMatrix res;
    res=*this;
    for(int i=0;i<Rows;i++){
        for(int j=0;j<Columns;j++){
            res.VT[i][j]-=MT.VT[i][j];
        }
    }
    return res;
}
CMatrix CMatrix::operator*(const CMatrix & MT){
    if(Columns!=MT.Rows){
        cout<<"2 matrix are not compatible!"<<endl;
        return *this;
    }
    CMatrix res(Rows,MT.Columns);
    for(int i=0;i<Rows;i++){
        for(int j=0;j<MT.Columns;j++){
            for(int k=0;k<Columns;k++){
                res.VT[i][j]+=this->VT[i][k]*MT.VT[k][j];
            }
        }
    }
    return res;
}
CMatrix CMatrix::operator*(const int k)
{
    for(int i=0;i<Rows;i++){
        for(int j=0;j<Columns;j++){
            this->VT[i][j]*=k;
        }
    }
    return *this;
}
CMatrix CMatrix::operator*(CVector & vt)
{
    CMatrix VT_To_MT(1,vt.GetLength());
    for(int i=0;i<VT_To_MT.Columns;i++){
        VT_To_MT.VT[0][i]=vt[i];
    }
    return *this*VT_To_MT;
}
ostream & operator<<(ostream & os,const CMatrix& MT)
{
    for(int i=0;i<MT.Rows;i++){
        for(int j=0;j<MT.Columns;j++){
            os<<MT.VT[i][j]<<" ";
        }
        os<<endl;
    }
    return os;
}
istream & operator>>(istream & is,CMatrix& MT)
{
    cout<<"Input row and column: ";
    is>>MT.Rows>>MT.Columns;
    MT.VT.resize(MT.Rows);
    for(int i=0;i<MT.Rows;i++){
        MT.VT[i].resize(MT.Columns);
        for(int j=0;j<MT.Columns;j++){
            is>>MT.VT[i][j];
        }
    }
    return is;
}
int main(){
    cout<<"----Vector----"<<endl;
    CVector Vt1,Vt2;
    cout<<"Input Vector1: "<<endl;
    cin>>Vt1;
    cout<<"Input Vector2: " <<endl;
    cin>>Vt2;
    CVector sum,sub,multi,multiK;
    sum=Vt1+Vt2;
    sub=Vt1-Vt2;
    multi=Vt1*Vt2;
    multiK=Vt2*5;
    cout<<"Vt1 : "<<Vt1<<endl;
    cout<<"Vt2 : "<<Vt2<<endl;
    cout<<"Vt1 + Vt2 \n"<<sum<<endl;
    cout<<"Vt1 - Vt2 \n "<<sub<<endl;
    cout<<"Vt1 * Vt2 \n"<<multi<<endl;
    cout<<"Vt2*5 = "<<multiK<<endl<<endl;
    cout<<"----Matrix----"<<endl;
    cout<<"Input Matrix1: "<<endl;
    CMatrix MT1,MT2;
    cin>>MT1;
    cout<<"Input Matrix2: "<<endl;
    cin>>MT2;
    CMatrix SumM,SubM,MultiM,MultiMK;
    cout<<"MT1 : \n"<<MT1<<endl;
    cout<<"MT2 : \n"<<MT2<<endl;
    SumM = MT1+MT2;
    cout<<"MT1 + MT2 =\n"<<SumM<<endl;
    SubM = MT1-MT2;
    cout<<"MT1 - MT2 = \n"<<SubM<<endl;
    MultiM = MT1*MT2;
    cout<<"MT1 * MT2 = \n"<<MultiM<<endl;
    MultiMK = MT2*5;
    cout<<"MT2*5 = \n"<<MultiMK<<endl<<endl;
    cout<<"MT1 * Vt1 : "<<endl;
    cout<<"MT1: \n"<<MT1;
    cout<<"Vt1 : \n"<<Vt1<<endl;
    CMatrix MT;
    MT=MT1*Vt1;
    cout<<MT;
    return 0;
}
