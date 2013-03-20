
import java.util.*;

public class Test{
	public  static void main(String args[]){
	Worker worker = new Worker();
	List< Worker > workers = new ArrayList< Worker >();
	for (int i =0; i!= 10 ;i++){
		Worker w = new Worker();
		w.setDays(i);
		w.setWorker(i+2);
		w.setMokey(i/2);
		workers.add(w);
	}

	for(int i =0 ;i!=workers.size();i++){
		System.out.println(workers.get(i).getDays()) ;
		System.out.println(workers.get(i).getWorker());
		System.out.println(workers.get(i).getMokey());
		System.out.println("");
	}
	
	for(int i =0 ;i!=workers.size();i++){
		int max_index = i ;
		int max_value = workers.get(i).getDays();
		for(int j=i ;j!=workers.size();j++){
			if(max_value<workers.get(j).getDays()){
				max_value = workers.get(i).getDays();
				max_index =  j;
			}
		}
		Worker temp ;
		temp  = workers.get(i);
		workers.set(i,workers.get(max_index));
		workers.set(max_index, temp );
	}
	for(int i =0 ;i!=workers.size();i++){
		System.out.println(workers.get(i).getDays()) ;
		System.out.println(workers.get(i).getWorker());
		System.out.println(workers.get(i).getMokey());
		System.out.println("");
	}
         	
	}

}

class Worker{
	public int days;
	
	private int worker ;

	private double mokey;
	
	public void setDays( int days ){
		this.days = days ;
	}

	public int getDays(){
		return this.days ;
	}

	public void setWorker( int worker){
		this.worker = worker ;
	}
	
	public  int getWorker(){
		return this.worker ;
	}

	public void setMokey( double mokey){
		this.mokey = mokey;
	} 

	public double getMokey(){
		return this.mokey ;
	}
	
	public void test(){
		List< Integer > app =  new ArrayList< Integer > () ;
		for(int i=0;i!=10;i++){
			app.add(i);
			app.add(i,i);
			app.set(i,i*i);
		}
		for(int i=0; i!=app.size();i++){
			System.out.println(app.get(i));
		}
		Integer arry[] =  new Integer[20] ;
               String str1 = "oms" ;
	       String str2 = "oms";
	       String str3 = new String();
	       Integer Int1 = 243 ;
	       int Int2 = 67;
	       System.out.println(str1==str2);
	       int a = 90;
	       int b = 45 ;
	       a = b ;
	      System.out.println("a =  " + a );
	      System.out.println("b =  " + b );
	}
	public void test2(){
		Integer a = 78 ;
		String str ="woshishui?" ;
	}
}
