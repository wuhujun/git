 #include <gsl/gsl_matrix.h>
 #include <gsl/gsl_math.h>
 #include <iostream>

 using namespace std ;
 int   main (void)
 {
   int i, j; 
   gsl_matrix * m = gsl_matrix_alloc (10, 3); 
   for (i = 0; i < 10; i++)
   { 
   	for (j = 0; j < 3; j++)
       	{
		gsl_matrix_set (m, i, j, 0.23 + 100*i + j);
	}
   }
for(int i= 0 ;i!=10;i++){
 	cout<<gsl_matrix_get(m,i,2)<<endl;
}
 cout<<"This is a very good Library"<<endl;
 gsl_matrix_free (m);
 gsl_matrix * m2 = gsl_matrix_alloc(100,34);
 do{
 	cout<<gsl_matrix_get(m2,i,23)<<endl;
	i++;
 }while(i==10);
 cout<"自然对数："<<M_E<<endl;
 cout<<GSL_POSINF<<endl;
 return 0;
 }
class Reader{
	private:
	string datafile ;
	public :
	void setDatafile(string file_name){
		this.datafile = file_name ;
	}
	string getDatafile(){
		return this.datafile ;
	}
	string readLine(){
		return 	NULL ;		
	}
	Reader(){
		datafile = 0;
	}
	~Reader(){
	}
};
