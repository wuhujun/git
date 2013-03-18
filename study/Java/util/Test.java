package com.genertech.util;

import java.util.*;

public class Test{
	public  static void main(String args[]){
	Worker worker = new Worker();
	worker.test2();
	System.out.println("OK");
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
