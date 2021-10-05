
#include<iostream>
#include<cstring>
using namespace std;

class String
{
private:
    char *pstring;
    int dodai;
public:
    String ();
    String ( char * str);
    String ( String &a);
    int Getlength();
    void Xuat();
    void Nhap();
    int sosanh( String &a);
    void NoiChuoi( String &a);
    void DaoChuoi();
    ~String();
};

String ::String()
{
    dodai=1;
    pstring=NULL;
}
String ::String(char *str)
{
    dodai = strlen(str)+1;
    pstring = new char[dodai];
    strcpy(pstring, str);
    pstring[dodai-1] = '\0';
}
String::String( String & a)
{
    dodai = a.dodai;
    pstring = new char[dodai];
    strcpy(pstring, a.pstring);
}

String::~String()
{
    delete [] pstring;
}
int String::Getlength()
{
    return dodai -1;
}
void String::Xuat()
{
    if(pstring!=NULL)
        cout<<pstring;
}

int String::sosanh(String &a)
{
    if(a.pstring==NULL && pstring==NULL)
        return 0;
    if(a.pstring==NULL)
        return -1;
    return strcmp(pstring, a.pstring);
}

void String::NoiChuoi( String &a)
{
    if (a.pstring == NULL && pstring == NULL)
        return;
    if (a.pstring == NULL)
        return;
    char *p = new char[dodai + a.dodai - 1];
    if (pstring == NULL)
    {
        strcpy(p, a.pstring);
        delete [] pstring;
        pstring = p;
        return;
    }
    for (int i = 0; i <= dodai-2; i++)
        p[i] = pstring[i];
    for (int i = 0; i < a.dodai; i++)
        p[i + dodai - 1] = a.pstring[i];
    delete [] pstring;
    pstring = p;
    dodai = dodai + a.dodai- 1;
}
void String::Nhap()
{
    cin>>pstring;
    dodai = strlen(pstring);
}
void String::DaoChuoi()
{
    strrev(pstring);
}
