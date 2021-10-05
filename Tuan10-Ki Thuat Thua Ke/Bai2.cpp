
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class SINHVIEN
{
protected:
    string maso, hoten, khoa;
    int loai;
    double DTB;
public:
    SINHVIEN(string ="",string ="",string ="", int =0, double=0);
    string GetMaSo();
    string GetHoTen();
    string GetKhoa();
    int Getloai();
    double GetDTB();
    void SetHoTen(string);
    void SetKhoa(string);
    void SetDTB(double);
    virtual void nhap();
    virtual void xuat();
    virtual double GetDRL();
    virtual int GetSBV();
    virtual void SetDRL(double);
    virtual void SetSBV(int);
    virtual long HocBong()=0;
};
SINHVIEN::SINHVIEN(string ms, string ht, string kh, int l, double dtb):maso(ms), hoten(ht), khoa(kh), loai(l), DTB(dtb){}

int SINHVIEN::Getloai(){
    return loai;
}
string SINHVIEN::GetMaSo() {
    return maso;
}
string SINHVIEN::GetHoTen() {
    return hoten;
}
string SINHVIEN::GetKhoa() {
    return khoa;
}
double SINHVIEN::GetDTB() {
    return DTB;
}
void SINHVIEN::SetHoTen(string ht) {
    hoten=ht;
}
void SINHVIEN::SetKhoa(string kh) {
    khoa=kh;
}
void SINHVIEN::SetDTB(double dtb) {
    DTB=dtb;
}
void SINHVIEN::SetDRL(double) {
    return;
}
void SINHVIEN::SetSBV(int) {
    return;
}
int SINHVIEN::GetSBV(){
    return -1;
}
double SINHVIEN::GetDRL(){
    return -1;
}
void SINHVIEN::nhap()
{
    cin.ignore();
    cout<<"Ma so: ";
    getline(cin, maso);
    cout<<"Ho Ten: ";
    getline(cin, hoten);
    cout<<"Khoa: ";
    getline(cin, khoa);
    cout<<"DTB: ";
    cin>>DTB;
}
void SINHVIEN::xuat()
{
    cout<<"MaSo: "<<maso<<"\t"<<"Ho Ten: "<<hoten<<"\t"<<"Khoa: "<<khoa<<"\t"<<"DTB: "<<DTB<<"\t"<<"Loai: "<<(loai==1?"SVCQ ":(loai==2?"SVLT":"???"));
}

//-------------------------
class SVCQ:public SINHVIEN
{
private:
    int DRL;
public:
    SVCQ(string ="",string ="",string ="", int =0,double=0, double=0);
    void nhap();
    void xuat();
    double GetDRL();
    void SetDRL(double);
    long HocBong();
};
SVCQ::SVCQ(string ms, string ht, string khoa, int l, double dtb,double drl):SINHVIEN(ms, ht, khoa, 1,dtb), DRL(0){}
double SVCQ::GetDRL() {
    return DRL;
}
void SVCQ::SetDRL(double drl){
    do{
        cout<<"Nhap DRL: ";
        cin>>drl;
    }while(drl<0|| drl>100);
    DRL=drl;
}
long SVCQ::HocBong()
{
    long hb=0;
    if(DRL>85 && DTB>=7.5)
    {
        if(DTB>7.5 && DTB< 8.5)
            hb=1000000;
       else if(DTB>8.5 && DTB< 9.5)
            hb=1200000;
        else
            hb=1500000;
    }
    return hb;
}
void SVCQ::nhap()
{
    loai=1;
    SINHVIEN::nhap();
    do{
        cout<<"Nhap DRL: "; cin>>DRL;
    }while(DRL<0 || DRL>100);
}
void SVCQ::xuat()
{
    SINHVIEN::xuat();
    cout<<"DRL: "<<DRL<<"\t"<<"Hoc Bong: "<<HocBong()<<endl;
}
//--------------------
class SVLT: public SINHVIEN
{
private:
    int SBV;
public:
    SVLT(string ="",string ="",string ="", int =0, double=0, int =0);
    void nhap();
    void xuat();
    int GetSBV();
    void SetSBV(int);
    long HocBong();
};
SVLT::SVLT(string ms, string ht, string khoa, int l, double dtb, int sbv): SINHVIEN(ms, ht, khoa,2,dtb), SBV(sbv) {}

int SVLT::GetSBV()
{
    return SBV;
}
void SVLT::SetSBV(int sbv){
    cout<<"Nhap SBV: ";
    cin>>SBV;
    SBV=sbv;
}
void SVLT::nhap()
{
    SINHVIEN::nhap();
    cout<<"SBV: ";
    cin>>SBV;
}
void SVLT::xuat()
{
    SINHVIEN::xuat();
    cout<<"\t"<<"SBV: "<<SBV<<"\t"<<"Hoc Bong: "<<HocBong()<<endl;
}
long SVLT::HocBong()
{
    long hb=0;
    if(SBV<=3 && DTB>=7)
    {
        if(DTB>7 && DTB<8)
            hb=1000000;
       else if(DTB>8 && DTB<9)
            hb=1200000;
        else
            hb=1500000;
    }
    return hb;
}
//-----------------------
class TRUONGDH
{
private:
    SINHVIEN **dtsv;
    int sl;
public:
    TRUONGDH();
    ~TRUONGDH();
    int GetSL();
    void nhap();
    SINHVIEN*nhap1();
    void xuat();
    void LietKe_SVCQcoDRLla100();
    int DemSVLTKhongNghiBuoiNao();
    long TinhTongHocBongCapChoSV();
    double TinhDTB_SVCQDuocCapHocBong();
    void KiemTraCoSVLTCoDTBTu9trolenkhongnghibuoinao();
    void TimCacSVCQCoDTBCaoNhat();
    string DoiChuoiInHoa(string);
    string DoiChuoiInThuong(string);
    void XapSepDSTangdantheomaso();
    void Them1SV(SINHVIEN*, int);
    int Xoa1SV(string);
    void TimKiemSVTheoKhoa(string);
    int xoa(string);
    void GhiFile(string);
    void DocFile(string);
    void DocFileSINHVIEN(string);
    void GhiFileSINHVIEN(string);
};
TRUONGDH::TRUONGDH()
{
    dtsv=NULL;
    sl=0;
}
TRUONGDH::~TRUONGDH()
{
    delete[]dtsv;
    dtsv=NULL;
    sl=0;
}
int TRUONGDH::GetSL() {
    return sl;
}
void TRUONGDH::nhap()
{
    int l;
    do{
        cout<<"Nhap So Luong SINH VIEN: ";
        cin>>sl;
    }while(sl<1);
    dtsv= new SINHVIEN*[sl];
    for(int i=0; i<sl; i++)
    {
        cout<<"----------------------------\n";
        cout<<"Nhap Thong Tin SINH VIEN thu "<<i+1<<":\n";
        do {
            cout<<"Nhap loai (1: SVCQ, 2: SVLT): ";
            cin>>l;
        }while(l<1 || l>2);
        if(l==1)
            dtsv[i]= new SVCQ;
        else
            dtsv[i]= new SVLT;
        dtsv[i]->nhap();
    }
}
SINHVIEN *TRUONGDH::nhap1()
{
    int l;
    SINHVIEN *pdt;
    do {
        cout<<"Nhap loai (1: SVCQ, 2:SVLT): ";
        cin>>l;
    }while(l<1 || l>2);
    if(l==1)
        pdt=new SVCQ;
    else
        pdt=new SVLT;
    pdt->nhap();
    return pdt;
}
void TRUONGDH::xuat()
{
    for(int i=0; i<sl; i++)
        dtsv[i]->xuat();
}
void TRUONGDH::LietKe_SVCQcoDRLla100()
{
    int dem=0;
    for(int i=0; i<sl; i++)
        if(dtsv[i]->Getloai()==1 && dtsv[i]->GetDRL()==100)
        {
             dtsv[i]->xuat();
                dem++;
        }
    if(dem==0)
        cout<<"Khong co SVCQ Co DRL 100";
}
int TRUONGDH::DemSVLTKhongNghiBuoiNao()
{
    int dem=0;
    for(int i=0; i<sl; i++)
        if(dtsv[i]->Getloai()==2 && dtsv[i]->GetSBV()==0)
            dem++;
    return dem;
}
long TRUONGDH::TinhTongHocBongCapChoSV()
{
    long sum=0;
    for(int i=0; i<sl; i++)
        sum+=dtsv[i]->HocBong();
    return sum;
}
double TRUONGDH::TinhDTB_SVCQDuocCapHocBong()
{
    int sum=0;
    int dem=0;
    for(int i=0; i<sl; i++)
        if(dtsv[i]->Getloai()==1 && dtsv[i]->HocBong()!=0)
        {
            sum+=dtsv[i]->GetDTB();
            dem++;
        }
    return dem>0?sum/dem:0;
}
void TRUONGDH::KiemTraCoSVLTCoDTBTu9trolenkhongnghibuoinao()
{
    int dem=0;
    for(int i=0; i<sl; i++){
        if(dtsv[i]->Getloai()==2 && dtsv[i]->GetDTB()>=9 && dtsv[i]->GetSBV()!=0)
            dem++;
    }
    if(dem==0)
        cout<<"Khong co SVLT nao co DTB tren 9 va khong Nghi Buoi nao\n";
    else
        cout<<"Co "<<dem<<"SVLT DTB tren 9, Khong nghi buoi nao\n";
}
void TRUONGDH::TimCacSVCQCoDTBCaoNhat()
{
    int DTBMax=-1, vt=-1;
    for(int i=0; i<sl; i++)
            if(dtsv[i]->Getloai()==1)
            {
                vt=i;
                DTBMax=dtsv[i]->GetDTB();
                break;
            }
    if(vt!=-1)
    {
        for(int i=vt+1; i<sl; i++)
            if(dtsv[i]->Getloai()==1 && dtsv[i]->GetDTB()>DTBMax)
                DTBMax=dtsv[i]->GetDTB();
        for(int i=0; i<sl; i++)
            if(dtsv[i]->Getloai()==1 && dtsv[i]->GetDTB()==DTBMax)
                dtsv[i]->xuat();
    }
    else
        cout<<"Khong co SVCQ";
}
string TRUONGDH::DoiChuoiInHoa(string str)
{
    for(int i=0; i<str.length(); i++)
        str[i]=toupper(str[i]);
    return str;
}
string TRUONGDH::DoiChuoiInThuong(string str)
{
    for(int i=0; i<str.length(); i++)
        str[i]=tolower(str[i]);
    return str;
}
void TRUONGDH::XapSepDSTangdantheomaso()
{
    for(int i=0; i<sl-1; i++)
        for(int j=i+1; j<sl; j++)
            if(DoiChuoiInHoa(dtsv[i]->GetMaSo())>DoiChuoiInHoa(dtsv[j]->GetMaSo()))
            {
                SINHVIEN*temb=dtsv[i];
                dtsv[i]=dtsv[j];
                dtsv[j]=temb;
            }
}
void TRUONGDH::Them1SV(SINHVIEN*pdt, int vt)
{
    SINHVIEN** pnew =new SINHVIEN*[sl+1];
    for(int i=0; i< vt-1; i++)
        pnew[i]= dtsv[i];
    pnew[vt-1]= pdt;
    for(int i=vt; i<sl+1; i++)
        pnew[i]= dtsv[i-1];
    delete[]dtsv;
    dtsv = pnew;
    sl++;
}
int TRUONGDH::Xoa1SV(string ms)
{
    int vt=-1;// chua tim thay SINHVIEN
    for(int i=0; i<sl; i++)
        if(DoiChuoiInHoa(dtsv[i]->GetMaSo())== DoiChuoiInHoa(ms))
        {
            vt = i;
            break;
        }
    if(vt!=-1)
    {
        SINHVIEN**pnew=new SINHVIEN*[sl-1];
        for(int i=0; i<vt; i++)
            pnew[i]=dtsv[i];
        for(int i=vt; i<sl-1; i++)
            pnew[i]= dtsv[i+1];
        delete[]dtsv;
        dtsv=pnew;
        sl--;
    }
    else
        cout<<"Khong tim thay SINH VIEN co Ma So "<<ms<<endl;
    return vt;
}
void TRUONGDH::TimKiemSVTheoKhoa(string kh)
{
    int dem=0;
    for(int i=0; i<sl; i++)
        if(DoiChuoiInHoa(dtsv[i]->GetKhoa())==DoiChuoiInHoa(kh))
        {
            dtsv[i]->xuat();
            dem++;
        }
    if(dem==0)
        cout<<"Khong co SINH VIEN thuoc Khoa "<<kh<<endl;
}

void TRUONGDH::GhiFile(string tenfile)
{
   string nd;
   ofstream outputFile(tenfile);
   if(!outputFile.fail())
   {
       cout<<"Nhap ND File(bam ~ de ket thuc): ";
       while(1)
       {
           getline(cin, nd);
           if(nd.back()!='~')
               outputFile<<nd<<endl;
           else
           {
               nd.back()='\0';
               outputFile<<nd;
               break;
           }
       }
       outputFile.close();
       cout<<"Da ghi File thanh cong\n";
   }
   else
       cout<<"Loi tao File\n";
}
void TRUONGDH::DocFile(string tenfile)
{
   string nd;
   ifstream inputFile(tenfile);
   if(!inputFile.fail())
   {
       while(getline(inputFile, nd))
           cout<<nd<<endl;
       inputFile.close();
       cout<<"Da doc file thanh cong\n";
   }
   else
       cout<<"Loi doc file\n";
}

void TRUONGDH::DocFileSINHVIEN(string tenfile)
{
   ifstream inputFile(tenfile);
   if(!inputFile.fail())
   {
       inputFile>>sl;
       if(sl>0)
       {
           dtsv=new SINHVIEN*[sl];
           string ms, ht, kh;
           int l, sbv;
           double dtb,drl;
           long hb;
           for(int i=0;i<sl; i++)
           {
               inputFile>>ms;
               inputFile>>ht;
               inputFile>>kh;
               inputFile>>dtb;
               inputFile>>l;
               if(l==1)
               {
                   inputFile>>drl;
                   dtsv[i]=new SVCQ(ms, ht, kh, dtb, drl);
               }
               else 
               {
                   inputFile>>sbv;
                   dtsv[i]= new SVLT(ms, ht, kh, dtb, sbv);
               }
               inputFile>>hb;
           }
           cout<<"Da doc file va luu D/S SINHVIEN thanh cong\n";
       }
       else
           cout<<"So luong SINHVIEN phai > 0\n";
       inputFile.close();
   }
   else
       cout<<"Loi doc File\n";
}

void TRUONGDH::GhiFileSINHVIEN(string tenfile)
{
   ofstream outputFile(tenfile);
   if(!outputFile.fail())
   {
       outputFile<<sl<<endl;
       for(int i=0; i<sl; i++)
       {
           outputFile<<dtsv[i]->GetMaSo()<<"\t"<<dtsv[i]->GetHoTen()<<"\t"<<dtsv[i]->GetKhoa()<<"\t"<<dtsv[i]->Getloai()<<"\t"<<dtsv[i]->GetDTB()<<"\t";
           if(dtsv[i]->Getloai()==1)
               outputFile<<dtsv[i]->GetDRL()<<"\t";
           else 
               outputFile<<dtsv[i]->GetSBV()<<"\t";
             outputFile<<dtsv[i]->HocBong()<<"\t";
       }
       outputFile.close();
       cout<<"Da ghi File thanh cong\n";
   }
   else
       cout<<"Loi Ghi File\n";
}

int main()
{
    TRUONGDH trg;
    int chon;
    do{
        cout<<"\n===QUAN LI SINH VIEN TRUONG DAI HOC===\n";
        cout<<"1. Nhap d/s SINH VIEN\n";
        cout<<"2. Xuat d/s SINH VIEN\n";
        cout<<"3. Liet Ke SVCQ Co DRL la 100\n";
        cout<<"4. Dem SL SVLT khong nghi buoi nao\n";
        cout<<"5. Tinh tong hoc bong cap cho SV\n";
        cout<<"6. Tinh DTB cac SVCQ duoc cap HB\n";
        cout<<"7. Kiem Tra Truong co SVLT co DTB tu 9 tro len va khong nghi buoi nao\n";
        cout<<"8. Tim cac SVCQ co DTB cao nhat\n";
        cout<<"9. Sap xep d/s tang dan theo ma so\n";
        cout<<"10. Them 1 SINH VIEN MOI\n";
        cout<<"11. Xoa 1 SINH VIEN (theo ma so)\n";
        cout<<"12. Tim Kiem SINH VIEN theo Khoa\n";
        cout<<"13. Tao File\n";
        cout<<"14. Doc File\n";
        cout<<"15. Doc va luu vao D/S SINH VIEN\n";
        cout<<"16. Luu File D/S SINH VIEN\n";
        cout<<"0. Thoat Chuong Trinh\n";
        cout<<"-------------------------------------------------------\n";
        cout<<"Moi ban chon: ";
        cin>>chon;
        switch(chon) {
            case 1:
            {
                if(trg.GetSL()>0)
                    trg.~TRUONGDH();
                trg.nhap();
                break;
            }
            case 2:
            {
                if(trg.GetSL()>0)
                    trg.xuat();
                else
                    cout<<"Chua nhap Thong Tin\n";
                break;
            }
            case 3:
            {
                if(trg.GetSL()>0)
                    trg.LietKe_SVCQcoDRLla100();
                else
                    cout<<"Chua nhap thong tin\n";
                break;
            }
            case 4:
            {
                int dem;
                if(trg.GetSL()>0)
                {
                    dem=trg.DemSVLTKhongNghiBuoiNao();
                    if(dem>0)
                        cout<<"Co "<<dem<<"SVLT khong nghi buoi nao\n";
                    else
                        cout<<"Khong co SVLT khong nghi buoi nao\n";
                }
                else
                    cout<<"Chua cap nhat thong tin\n";
                break;
            }
            case 5:
            {
                if(trg.GetSL()>0)
                {
                    long sum=trg.TinhTongHocBongCapChoSV();
                    if(sum>0)
                        cout<<"Tong Tien Hoc Bong cap cho SV "<<sum<<endl;
                    else
                        cout<<"Khong co SV nao nhan duoc hoc bong\n";
                }
                else
                    cout<<"Chua cap nhat thong tin\n";
                break;
            }
            case 6:
            {
               if(trg.GetSL()>0)
                   cout<<"DTB cac SINH VIEN duoc cap hoc bong la: "<<trg.TinhDTB_SVCQDuocCapHocBong();
                else
                    cout<<"Chua cap nhat thong tin\n";
                break;
            }
            case 7:
            {
                if(trg.GetSL()>0)
                    trg.KiemTraCoSVLTCoDTBTu9trolenkhongnghibuoinao();
                else
                    cout<<"Chua cap nhat thong tin\n";
                break;
            }
            case 8:
            {
                if(trg.GetSL()>0)
                    trg.TimCacSVCQCoDTBCaoNhat();
                else
                    cout<<"Chua cap nhat thong tin\n";
                break;
            }
            case 9:
            {
                 if(trg.GetSL()>0)
                 {
                     trg.XapSepDSTangdantheomaso();
                     trg.xuat();
                 }
                else
                    cout<<"Chua cap nhat thong tin\n";
                break;
            }
            case 10:
            {
                
                SINHVIEN*pdt;
                int vt=1;
                pdt=trg.nhap1();
                if(trg.GetSL()>0)
                {
                    do {
                        cout<<"Nhap vi tri muon them sinh vien tu 1 den "<<trg.GetSL()+1<<": ";
                        cin>>vt;
                    }while(vt<1||vt>trg.GetSL()+1);
                }
                trg.Them1SV(pdt,vt);
                cout<<"D/s DTXS sau khi them sinh vien moi tai vi tri thu "<<vt<<" la:\n";
                trg.xuat();
                break;
            }
            case 11:
            {
                
                if(trg.GetSL()>0)
                {
                    string ms;
                    cout<<"Nhap ma so sinh vien muon xoa: ";
                    cin>>ms;
                    int kq=trg.Xoa1SV(ms);
                    if(kq!=-1){
                        if(trg.GetSL()>0) {
                            cout<<"D/S sinh vien sau khi xoa sinh vien co ma so "<<ms<<" la\n";
                            trg.xuat();
                        }
                        else
                            cout<<"D/S sinh vien rong\n";
                    }
                }
                else
                    cout<<"Chua nhap thong tin\n";
                break;
            }
            case 12:
            {
                if(trg.GetSL()>0)
                {
                    string kh;
                    cin.ignore();
                    cout<<"Nhap Khoa Can tim: ";
                    getline(cin, kh);
                    trg.TimKiemSVTheoKhoa(kh);
                }
                else
                    cout<<"Chua Cap Nhap Thong Tin\n";
                break;
            }
            case 13:
            {   
                string tenfile;
                cin.ignore();
                cout<<"Nhap ten file: ";
                getline(cin, tenfile);
                trg.GhiFile(tenfile);
                break;
            }
            case 14:
            { 
                string tenfile;
                cin.ignore();
                cout<<"Nhap ten file; ";
                trg.DocFile(tenfile);
                break;
            }
            case 15:
            { 
                string tenfile;
                cin.ignore();
                cout<<"Nhap ten file; ";
                getline(cin, tenfile);
                trg.DocFileSINHVIEN(tenfile);
                break;
            }
            case 16:
            { 
                if(trg.GetSL()>0)
                { 
                    string tenfile;
                    cin.ignore();
                    cout<<"Nhap ten file: ";
                    getline(cin, tenfile);
                    trg.GhiFileSINHVIEN(tenfile);
                }
                else
                    cout<<"Chua nhap thong tin\n";
                break;
            }
        }
    }while(chon!=0);
    cout<<"Thoat Chuong Trinh!!!"<<endl;
    return 0;
}
