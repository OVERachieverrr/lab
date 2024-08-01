#include<iostream>
using namespace std;
class publication
{
    protected:
    string title;
    int price;
    public:
    void getdata()
    {
        cout<<"Enter the title of the book or tape: ";
        cin>>title;
        cout<<"Enter the price of the book: ";
        cin>>price;
    }
    void putdata()
    {
        cout<<"title= "<<title<<endl<<"price= "<<price<<endl;
    }
};
class sales
{
    protected:
    float sells[3];
    public:
    void getdata()
    {
    cout<<"Enter the sales of this publication in last three month "<<endl;
        for(int i=0;i<3;++i)
        {
            cin>>sells[i];
        }
    }
    void putdata()
    {
        cout<<"Sales of this publication in last three month "<<endl;
        for(int i=0;i<3;++i)
        {
            cout<<"$"<<sells[i]<<endl;
        }
    }
};
class book:public publication, public sales
{
    int pages;
    public:
    void getdata()
    {
        publication::getdata();
        sales::getdata();
        cout<<"Enter the number of pages: ";
        cin>>pages;
    }
    void putdata()
    {
        publication::putdata();
        sales::putdata();
        cout<<"pages= "<<pages<<endl;
    }
};
class tape:public publication, public sales
{
    int playtime;//minutes
    public:
    void getdata()
    {
        publication::getdata();
        sales::getdata();
        cout<<"Enter the playtime of the tape: ";
        cin>>playtime;
    }
    void putdata()
    {
        publication::putdata();
        sales::putdata();
        cout<<"playtime= "<<playtime<<" minutes"<<endl;
    }
};
int main()
{
    tape t;
    book b;
    int n;
    cout<<"press 1 for books or 2 for tapes :";
    cin>>n;
    switch (n)
    {
    case 1 :
    b.getdata();
    b.putdata();
    break;
    case 2 :
    t.getdata();
    t.putdata();
    break;
    default:
    cout<<"invalid input"<<endl;
    break;
    }
    return 0;

} 
