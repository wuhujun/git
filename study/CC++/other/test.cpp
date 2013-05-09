#include <iostream>
using namespace std ;
void test(){
while (true) {
cout<<"OK"<<endl ;
}
}
int main(int argc ,char * argv[]){
	double a =  23.0 ;
	double b =  100  ;
	int m ;
	cout<<"Please Enter the m: ";
	cin>>m;
	if(m>10){
		double m = a ; 
	}else{
	 	cout<<b<<endl;
	}
	test();
	return 0;
}
