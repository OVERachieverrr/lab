#include<iostream>
using namespace std;
class Person
{
    protected:
    string name;
    int Age,ID;
    public:
   void getdata()
   {
    cout<<"enter name: ";
    cin>>name;
    cout<<"enter age: ";
    cin>>Age;
    cout<<"enter ID: ";
    cin>>ID;

   }
   void show()
   {
    cout<<"name= "<<name<<endl<<"Age= "<<Age<<endl<<"ID= "<<ID<<endl;
   }
        
};
class Employee : public Person
{
    protected:
    string designation;
    float salary;
    int overtime;
    public:
    void getdata()
    {
        Person::getdata();
        cout<<"enter designation"<<endl;
        cin>>designation;
        cout<<"enter salary"<<endl;
        cin>>salary;
        cout<<"enter overtime"<<endl;
        cin>>overtime;
    }
    void show()
    {
        Person::show();
        cout<<"designation= "<<designation<<endl<<"salary= "<<salary<<endl<<"overtime= "<<overtime<<endl;
    }

};
class computedSalary : public Employee
{
    private:
    float totalSalary;

    public:
    void getdata()
    {
        Employee::getdata();

    }
    void show()
    {
        Employee::show();
        cout<<"total salary= "<<totalSalary;
    }
    float calculated_total_salary()
    {
        totalSalary=salary+overtime*salary*0.5;
    }
};
int main()
{
    computedSalary cS1;
    cS1.getdata();
    cS1.calculated_total_salary();
    cS1.show();
    return 0;


}
