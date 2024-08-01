#include<iostream>
#include <iomanip>

using namespace std;
class Date 
{
        int day,month,year;
  public:
      Date();
        ~Date();
        void display(); 
        Date get(); 
        void set();     
 };
 Date::Date():day(0),month(0),year(0){}
Date::~Date()
{
    cout<<"destructor is called"<<endl;
}
void Date::display()
{
    cout<<setfill('0')<<setw(2)<<day<<"/"<<setfill('0')<<setw(2)<<month<<"/"<<setfill('0')<<setw(2)<<year<<endl;
}
Date Date::get()
{
    Date d;
    d.day=day;
    d.month=month;
    d.year=year;
    return d;
}
void Date::set()
{
    cout<<"enter year"<<endl;
    cin>>year;
    cout<<"enter month"<<endl;
    cin>>month;
    cout<<"enter day"<<endl;
    cin>>day;
}
class Time
{
        int hour;
        int minute;
        int second;
        string X;
  public:
        Time();
        ~Time();
        void display();
        Time get();
        void set(); 
 };
 Time::Time():hour(0),minute(0),second(0){}
 Time::~Time(){cout<<"destructor is called"<<endl;}
 void Time::display()
 {
    cout<<setfill('0')<<setw(2)<<hour<<":"<<setfill('0')<<setw(2)<<minute<<":"<<setfill('0')<<setw(2)<<second<<" "<<X<<endl;
 }
 Time Time::get()
 {
    Time t;
    t.hour=hour;
    t.minute=minute;
    t.second=second;
 }
 void Time::set()
 {
    cout<<"enter hour"<<endl;
    cin>>hour;
    cout<<"enter minute"<<endl;
    cin>>minute;
    cout<<"enter second"<<endl;
    cin>>second;
    cout<<"enter am or pm"<<endl;
    cin>>X;
 }
 class DateAndTime : public Date, public Time
{
 public:
    void display();
};

void DateAndTime::display()
{
    Date::display();
    Time::display();
}

int main()
{
    DateAndTime watch;
    cout<<"before setting date and time "<<endl;
    watch.display();
    watch.Date::set();
    watch.Time::set();
    cout<<"after setting date and time"<<endl;
    watch.display();
    
}

