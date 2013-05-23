#include <iostream>
using namespace std ;
double a(){
  return 0.1;
}
long ago(){
	char *a ;
        char b[100];
        a=b;
 *(b+1)='w';
 return 100;
}
int main(){
	double *arry = new double [100];
for(int i=0;i!=100;i++){
	cout<<*(arry+i)<<endl;
}
return 0;
}
