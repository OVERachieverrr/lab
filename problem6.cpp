#include<iostream>
#include<cstring>
using namespace std;
class student
{
    protected:
    int rollno;
    char name[20];
    public:
    void getdata()
    {
        cout<<"Enter roll no: ";
        cin>>rollno;
        cout<<"Enter name: ";
        cin>>name;
    }
    void showdata()
    {
        cout<<"Name= "<<name<<endl;
        cout<<"rollno= "<<rollno<<endl;
    }
};
class internalExam :  public student
{
    protected:
    int mark[7];
    public:
    void getdata()
    {
        student::getdata();
        cout<<"Enter marks in 7 subjects: "<<endl;
        for(int i=0;i<7;i++)
        {
            cin>>mark[i];
        }
    }
    void showdata()
    {
        student::showdata();
        cout<<"marks in 7 subjects: "<<endl;
        for(int i=0;i<7;i++)
        {
          cout<<mark[i];
          cout<<endl;
        }
    }


};
class finalExam : public student
{
    protected:
    int mark[7];
    public:
    
    void getdata()
    {
        cout<<"Enter internal marks in 7 subjects: "<<endl;
        for(int i=0;i<7;i++)
        {
            cin>>mark[i];
        }
    }
    void showdata()
    {
        cout<<"marks final in 7 subjects: "<<endl;
        for(int i=0;i<7;i++)
        {
            cout<<mark[i]<<endl;
        }
    } 
};
class result: public internalExam, public finalExam
{
    private:
    float avgmark;
    public:
    void getdata()
    {
        internalExam::getdata();
        finalExam::getdata();
    }
    void showdata()
    {
        internalExam::showdata();
        finalExam::showdata();
        cout<<" total average marks = "<<avgmark<<endl;
    }
    void calculate()
    {
        int totalin=0, totalfin=0;
        for(int i=0;i<7;i++)
        {
            totalin+=internalExam::mark[i];
            totalfin+=finalExam::mark[i];
        }
        avgmark=(float)(totalin+totalfin)/14.0;
    }

};
int main()
{
    result r;
    r.getdata();
    r.calculate();
    cout<<endl<<endl;
    r.showdata();
}