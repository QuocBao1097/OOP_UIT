#include<iostream>
using namespace std;
struct K
{
    int day, month,year;
};
K lastday;
void inputdayandnextday(K &lastday){
    int x;
    cout<<"DAY:";
    cin>>lastday.day;
    cout<<"Month:";
    cin>>lastday.month;
    cout<<"Year:";
    cin>>lastday.year;
    switch(lastday.month)
    {
        case 1: case 3: case 5:  case 7: case 8: case 10: case 12:
            x=31;
            break;
        case 4: case 6: case 9: case 11:
            x=30; break;
        case 2:
            if((lastday.year %400==0) ||(lastday.year % 4==0 && lastday.year % 100!=0))
                 x=29;
            else x=28; break;
    default:x=0;
 }
 if(lastday.day<0 || x==0 || lastday.day>x )
 cout<<"Ngay nhap sai!\n";
    if(lastday.day==x)
    {
        lastday.day=1;
        if(lastday.month==12)
        {
            lastday.month=1;
            lastday.year++;
        }
        else
        {
            lastday.month++;
        }
    }
    else
        lastday.day++;
    cout<<"Ngay ke tiep la: "<<lastday.day<<"/"<<lastday.month<<"/"<<lastday.year<<endl;
}
int main(){
    K lastday;
    inputdayandnextday(lastday);
}
