public class Test{
	public static void main(String args[]){
		int i= 5;
		if(i!=10){
			double avg = 565 ;
			System.out.println(avg);
		}
		else if(i!=5){
				double avg = 78 ;
				System.out.println(avg);
			}
			else{
				System.out.println("else");
			}
			
		int test_no = 86;
		if(test_no>100){
			System.out.println("b>100");
		}else if(test_no>90){
			System.out.println("90<b<100");
			} else if( test_no>80){
				System.out.println("80<b<90");
				}else if(test_no>70){
					System.out.println("70<b<80");
					}else {
					System.out.println("b=<70");
					}
		int b = 90;
		Integer ia = new Integer(45);
		System.out.println(ia.equals(45));
		String a = "ABCDEFG";
		System.out.println(a.substring(0,1));
		System.out.println(a.substring(0,2));
		System.out.println(a.substring(1,3));
		System.out.println(a.substring(5,7));
		for( i =0  ; i!=10 ;i++){
			System.out.println(i);
			if(i==5){
				break ;
			}
		}
		for(i =0  ; i!=10 ;i++){
			for(int j= 0 ;j!=10 ;j++){
				System.out.println(i*j);
				if(3==j){
				System.out.println("break");
					break ;
				}
			}
		}
	}
}
