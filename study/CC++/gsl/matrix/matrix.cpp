 #include  <cmath>
 #include <gsl/gsl_block.h>
 #include <gsl/gsl_matrix.h>
 #include <gsl/gsl_math.h>
 #include <iostream> 
 #include <gsl/gsl_vector.h>
 #include <gsl/gsl_poly.h>
 #include <gsl/gsl_poly.h>
 #include <gsl/gsl_complex.h>
 #include <gsl/gsl_sf.h>
 #include <gsl/gsl_vector.h>
 #include <gsl/gsl_rng.h>
 #include <gsl/gsl_randist.h>

using namespace std ;
 
 class Reader{
	private:
	string datafile ;
	public :
void setDatafile(string file_name){
		this->datafile = file_name ;
	}
	string getDatafile(){
		return this->datafile ;
	}
	string readLine(){
		return 	NULL ;		
	}
	Reader(){
	     this->datafile = "" ;	
	}
	~Reader(){
	}
	void test1(){
		double * p = new double [100];
		cout<<"指向数组的指针"<<p<<endl;
		cout<<M_LN10<<endl;
		cout<<M_1_PI<<endl;
		cout<<M_SQRT1_2<<endl;
		cout<<M_SQRT2<<endl;
		cout<<M_EULER<<endl;
		cout<<gsl_pow_2(34)<<endl;
	double a[6] = {-1,  34.8 , 89.8 , 0 , 0 , 7.6};
	double b[6] = {-2,  56.9 , 23.1 , 9 , 23 , 7.08};
        gsl_poly_complex_workspace * w = gsl_poly_complex_workspace_alloc (6);
	double z[20]; 
	gsl_poly_complex_solve (a, 6, w, z);     
	gsl_poly_complex_workspace_free (w) ;
	cout<<"This is the result of solve:";
	for(int i =0 ;i!=20;i++){
		cout<<z[i]<<endl;
	 }
	}
        void test2(){
		gsl_block * b = gsl_block_alloc(100);
		cout<<"数据块长度："<<(b->size)<<endl;
		cout<<"数据块："<<b->data<<endl;
		gsl_block_free(b);
		string str = "12 34 45 \n34 45 100 \n3 2 89\n";
		cout<<str<<endl;
		gsl_matrix * m = gsl_matrix_alloc(10,10);
		for(int i =0 ;i!=10;i++){
			for(int j=0 ;j!=10;j++){
				gsl_matrix_set(m,i,j,sin(i)+cos(j));
			}
		}
		for(int j=0 ;j!=10;j++){
			gsl_vector_view  column  = gsl_matrix_column(m,j);
			gsl_vector * v = &column.vector;
			cout<<"V["<<j<<"]:     "<<gsl_vector_get(v,j)<<endl;
		}
		cout<<"t-分布(-10----10)"<<endl;
		for(int i=-10; i!=10 ;i++){
			cout<<(gsl_ran_tdist_pdf (i, 3))<<endl; ;
		}
	}
	void test3(){
		int i = 0;
		do{
			cout<<i<<"\t";
			if(i==5){
			cout<<"\n";
			}
			i++; 
		}while(i!=10); 
	}
};
int   main (void)
 {
   int i, j; 
   gsl_matrix * m = gsl_matrix_alloc (10, 3); 
   for (i = 0; i < 10; i++)
   { 
   	for (j = 0; j < 3; j++)
       	{
		gsl_matrix_set(m, i, j, 0.23 + 100*i + j);
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
 cout<<"自然对数："<<M_E<<endl;
 cout<<"Log2(e):"<<M_LOG2E<<endl;
 cout<<"log10(e):"<<M_LOG10E<<endl;
 cout<<"根号下2 :"<<M_SQRT2<<endl;
 cout<<"The square root of the  pi "<<M_SQRTPI<<endl;
 cout<<"The square root of two :"<<M_SQRT1_2<<endl;
 cout<<"The square rooot of one-half :"<<M_SQRT1_2<<endl;
 Reader reader ;
 reader.test3();
 return 0;
 }



