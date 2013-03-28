#include <iostream>
using namespace std ;
//关于指针的长度问题。
void point_len(void ){
   /*
    查看当前的位数。
    sudo file  /sbin/init
    32位机器的指针的长度是4个字节。
    64位机器的指针的长度是8个字节。
   */
   int * pint = new int [10];
   char * pchar = new char [10];
   double *pdouble = new double [10];
   int lenint = sizeof(pint) ;
   cout<<" int 类型指针的长度:  "<<lenint<<"\n";
   int lenchar =sizeof(pchar);
   cout<<" char 类型指针的长度:  "<<lenchar<<"\n";
   int lendouble = sizeof(pdouble) ;
   cout<<" double 类型指针的长度: "<<lendouble<<"\n";
   cout<<sizeof(int*)<<endl;
}
/*
关于面向对象的几个问题。
*/
class apple{
private :
	 int ID ;
 	 string name ;
 	 double price ;
public :
apple(int id, string name_p, double price_p){
 	ID = id ;
 	name = name_p;
 	price = price_p;
}
apple(){
  	ID=10;
  	name="红富士";
  	price = 3.8 ;
}
~apple(){}
void  setname(string name_p ){
   	this->name = name_p ;
}
string   getname(){
   	return this->name ;
}
void setID(int id_p){
 	 this->ID=id_p;
}
int get_ID(){
 	 return this->ID; 
}
void setprice(double price_p){
  	this->price=price_p;
}
double getprice(){
  	return this->price;
} 
};
int main(){
	cout<<"Hello world"<<endl;
	point_len();
	apple App;
	cout<<App.get_ID()<<endl;
	return 0;
	}
