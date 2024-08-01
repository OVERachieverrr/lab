#include<iostream>
#include<cstring>
using namespace std;
 class Inventory 
{
    private:
    int quant;
    int reorder;
    double price;
    char* descrip; 
    public:
    Inventory (int q, int r, double p,const char* d):quant(q),reorder(r),price(p)
    {
        descrip = new char[strlen(d)+1];
        strcpy(descrip,d);
    }
    ~Inventory(){ 
        cout<<"destructor of inventory has been called "<<endl;
        delete[] descrip; 
        }
    Inventory(const Inventory& I)
    {
        quant = I.quant;
        reorder = I.reorder;
        price = I.price;
        descrip=new char[strlen(I.descrip)+1];
        strcpy(descrip,I.descrip);
    } // copy constructor
    

    void print();
 };
void Inventory::print()
{
    cout<<"quantity: "<<quant<<endl;
    cout<<"reorder: "<<reorder<<endl;
    cout<<"price: $"<<price<<endl;
    cout<<"descripton: "<<descrip<<endl;
    
}
class Auto : public Inventory 
{
    char * manufacturer;
  public:
    Auto (int q, int r, double p, const char * d,const char *  man):Inventory(q,r,p,d) 
    {
        manufacturer = new char[strlen(man)+1];
        strcpy(manufacturer, man);

    }
    ~Auto()
    {
        cout<<"destructor of auto has been called "<<endl;
        delete [] manufacturer;
    }
        void print();
 };
 void Auto::print() 
 {
    Inventory::print();
    cout<<"manufacturer: "<<manufacturer<<endl;
    
 }
class Transmission : public Inventory 
{
    char * vendor;
    public:
    Transmission (int q, int r, double p, const char * d, const char * ven):Inventory(q,r,p,d)
    {
        vendor = new char[strlen(ven)+1];
        strcpy(vendor,ven);
    }
    ~ Transmission ()
    {
        cout<<"destructor of transmission has been called "<<endl;
        delete[] vendor;
    }
    void print() ;
};

void Transmission::print() 
{
    Inventory::print();
    cout<<"vendor: "<<vendor<<endl;
}
int main()
{
    Auto car( 5, 2 , 15545.91 , "the car obtained from the Toyota" , "Toyota" );
    car.print();

    cout<<endl<<endl;

    Transmission trans( 25, 10, 1789.98,"the car obtained from the Toyota","Aztec Inc.");
    trans.print();
    return 0;

}