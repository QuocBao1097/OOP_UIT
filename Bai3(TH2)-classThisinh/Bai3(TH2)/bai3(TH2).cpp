
#include <iostream>

using namespace std;
class Candidate
{
private:
    int ma;
    char day[20];
    char ten[20];
    float Toan, Van, Anh;
public:
    void Nhap();
    void Xuly();
};
void Candidate::Nhap()
{
    cout << "Nhap ma sinh vien: ";
    cin>> ma;
    cout << "Nhap ten sinh vien: ";
    cin>>ten;
    cout << "Nhap ngay thang nam sinh: ";
    cin.ignore();
    cin>>day;
    do
    {
        cout << "Nhap diem Toan: ";
        cin >> Toan;
    }
    while(Toan<0||Toan>10);
    do
    {
        cout << "Nhap diem Van: ";
        cin >> Van;
    }
    while(Van<0||Van>10);
    do
    {
        cout << "Nhap diem Anh: ";
        cin >> Anh;
    }
    while(Anh<0||Anh>10);
}
void Candidate::Xuly()
{
    cout<<"---------------------------------------"<<endl;
    if(Toan+Van+Anh>15)
    {
        cout << "Ma sinh vien: "<<ma<<endl;
        cout << "Ten sinh vien: "<<ten << endl;
        cout << "Ngay thang nam sinh: "<< day << endl;
        cout << "Diem Toan: "<< Toan << endl;
        cout << "Diem Van: "<< Van << endl;
        cout << "Diem Anh: "<< Anh << endl;
        cout <<"Tong Diem: "<<float(Toan+Van+Anh)<<endl;
    }
}
class TestCandidate
{
private:
    int n;
public:
    void Nhap();
};
void TestCandidate::Nhap()
{
    Candidate thisinh[50];
    cout << "Nhap so luong thi sinh: "; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout<<endl;
        cout<<"Nhap thong tin sinh vien thu "<<i+1<<endl;
        thisinh[i].Nhap();
    }
    for (int i = 0; i < n; i++)
    {
        thisinh[i].Xuly();
    }
}
int main()
{
    TestCandidate thisinh;
    thisinh.Nhap();
    return 0;
}
