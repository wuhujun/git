#include <stdio.h>
#include <mysql.h>
#include <string>
#include <iostream>

using namespace std;


/*定义一个异常类，用来存储，打印出在连接数据库过程中发生的异常。
 */
class FFError
{
public:
    std::string    Label;

    FFError( ) {
	    Label = (char *)"Generic Error"; 
    }
    FFError( char *message ) {
	    Label = message; 
    }
    ~FFError() { }
    inline const char*   GetMessage  ( void )   { 
	    return Label.c_str();
    }
};
class MysqlConnect{
	private:
		string host ;
		string user ;
		string password ;
		string database ;
	public :
		MysqlConnect(string Host ,string User , string PassWord , string DataBase ){
			this->host = Host ;
			this->user =  User ;
			this->password = PassWord ;
			this->database = DataBase ; 
		}
		int Query(string sql ){
		  unsigned int i = 0;
		  MYSQL* MySQLConnection  ;
		  MySQLConnection = mysql_init(NULL) ;
		  MYSQL_ROW row ;
		  MYSQL_RES * result ;
		  unsigned int fields_no ;

		  try{
		 	MYSQL * mysql_con_result =  mysql_real_connect(MySQLConnection , host.c_str() ,
			user.c_str() , 	password.c_str() , database.c_str() , 0,  NULL, 0 );
			if(NULL == mysql_con_result){
				throw FFError((char *) mysql_error(MySQLConnection));
			}
		        if(mysql_query(MySQLConnection, sql.c_str())){
		  	        throw FFError( (char *) mysql_error(MySQLConnection) ) ;
		         }
		         result = mysql_store_result(MySQLConnection);
                         fields_no = mysql_num_fields(result);
			 cout<<"The result of Query of "<<sql.c_str()<<endl;
		  	while(row = mysql_fetch_row(result)){
				for(int i=0 ;i!=fields_no ;i++){
					cout<<(row[i] ? row[i] : NULL);
				}
				cout<<'\n';
		  	}
		   }catch(FFError e){
		   	cout<<e.Label<<endl;
			return 1 ;
		   }
			return 0;		
		}
	  int Alter(string sql){
		MYSQL* MySQLConnection  ;
	        MySQLConnection = mysql_init(NULL) ;
		try{
			MYSQL * ConnectionResult = mysql_real_connect(MySQLConnection,
					host.c_str(),
					user.c_str(),
					password.c_str(),
					database.c_str(),
					0,
					NULL,
					0
					);
			if(NULL==ConnectionResult){
				throw FFError((char *)mysql_error(MySQLConnection)) ;
			}
			if(mysql_query(MySQLConnection , sql.c_str())){
				throw FFError((char*)mysql_error(MySQLConnection)) ;
			}else{			
		cout<<"Query OK, "<<mysql_affected_rows(MySQLConnection)<<" rows affected ;"<<"\n" ; 
			}
		}catch (FFError e){
			cout<<e.Label<<endl;
			return 1 ;
		}
	      return 0;
	  }

};

int main()
{
      MysqlConnect connection("localhost" ,"root" ,"123" ,"ia") ;
      connection.Query("select * from TABLE1");
      connection.Alter("update demo1 set product = \'computer\' ") ;
    // --------------------------------------------------------------------
    // Connect to the database
    /*连接到数据。
     * 创建一个连接。
     */
    MYSQL      *MySQLConRet;
    MYSQL      *MySQLConnection = NULL;
    /*配置数据库连接参数。
     *hostname:
     *user:
     *password:
     */
    string hostName = "localhost";
    string userId   = "root";
    string password = "123";
    /* 数据库连接句柄初始化。
     * 将一个初始化的句柄传给MySQLConnection. 
     */
    MySQLConnection = mysql_init(NULL);

    try
    {
	/*
	 *已经成功连接的数据库连接。
	 */
        MySQLConRet = mysql_real_connect( MySQLConnection,
                                          hostName.c_str(), 
                                          userId.c_str(), 
                                          password.c_str(), 
                                          "ia",  // No database specified
                                          0, 
                                          NULL,
                                          0 );
	/* 测试数据库连接是否成功。
	 */
        if ( MySQLConRet == NULL )  
            throw FFError( (char*) mysql_error(MySQLConnection) );
	/*
	 * 如果测试连接不成功抛出异常。
	 */
	/* 定义数据库检索句柄。
	 * 定义数据库查询的行句柄。
	 */
  	  MYSQL_RES *result;
  	  MYSQL_ROW row; 
  	  int num_fields;
  	  int i;
	  mysql_query(MySQLConnection , "SELECT * FROM 	TABLE1");
	  /*抓取查询的结果。
	   */
	  result = mysql_store_result(MySQLConnection);
          num_fields = mysql_num_fields(result);
  	while ((row = mysql_fetch_row(result)))
  	{
      		for(i = 0; i < num_fields; i++)
      		{
          		cout<<(row[i] ? row[i] : "NULL");
      		}
		cout<<"\n";
  	}
	//逐行输出查询的结果。
	// MySQL连接的一些信息。
        cout<<"MySQL Connection Info:  "<<mysql_get_host_info(MySQLConnection)<<endl;
        cout<<"MySQL Client Info: " <<mysql_get_client_info()<<endl;
        cout<<"MySQL Server Info: "<<mysql_get_server_info(MySQLConnection)<<endl;
	cout<<"MySQL connection has been building："<<endl;
    }
    catch ( FFError e )
    {	
	/*异常处理机制。
	 */
        printf("%s\n",e.Label.c_str());
        return 1;
    }  
    // --------------------------------------------------------------------
    // Now that database has been created set default database
    /*执行查询SQL语句，如果成功返回 。
     */
    if (mysql_query(MySQLConnection, "USE ia") )
    {
        printf("Error %u: %s\n", mysql_errno(MySQLConnection), mysql_error(MySQLConnection));
        return(1);
    }
    else{
	 /*执行相互依赖的SQL查询。
	  * 将查询出的结果打印。
	  */
	 MYSQL_RES *result;
  	 MYSQL_ROW row;
  	 int num_fields;    	
	 mysql_query(MySQLConnection, "SELECT * FROM  demo2 ") ;
	 result =  mysql_store_result(MySQLConnection);
	 num_fields =  mysql_num_fields(result);
	while(row = mysql_fetch_row(result)){
		for(int n =0 ;n!= num_fields ;n++ ){
			cout<<(row[n] ? row[n] : NULL )<<"\t";
		}
		cout<<"\n";
	}

    }
    /*设置数据库连接为autocommit模式。
     */
    if(mysql_autocommit(MySQLConnection , true)){
        cout<<"Error  "<<mysql_errno(MySQLConnection)<<""<<mysql_error(MySQLConnection)<<'\n';
    }
    // --------------------------------------------------------------------
    //  Create table and records
    //  如果数据表存在删除数据表。
    if(mysql_query(MySQLConnection , " DROP TABLE if exists family ")){
    	cout<<"Error "<<mysql_errno(MySQLConnection)<<" "<<mysql_error(MySQLConnection);
    }
    /*
     * 如果表不存在创建表。
     */
    if (mysql_query(MySQLConnection, 
	           "CREATE TABLE if not exists family (Name char(20),Room char(8),Phone char(24)) ") )
    {
        printf("Error %u: %s\n", mysql_errno(MySQLConnection), mysql_error(MySQLConnection));
        return(1);
    }else{
    	cout<<"Query OK, "<<mysql_affected_rows(MySQLConnection)<<" rows affected ;"<<"\n" ;
    }
    /*
     *返回当前线程的ID。
     */
    unsigned  long  thread_id = 0;

    if(thread_id = mysql_thread_id(MySQLConnection)) {
        cout<<"The thread Id of the runing  thread is  :"<<mysql_thread_id(MySQLConnection)<<endl;
    }
   /*
    *向当前数据库中插入数据。
    */
  if (mysql_query(MySQLConnection, 
               "INSERT INTO family VALUES ('Gomez Adams', 'master', '1-555-1212')") )
  {
        printf("Error %u: %s\n", mysql_errno(MySQLConnection), mysql_error(MySQLConnection));
        return(1);
  }
  else		MYSQL_RES * result ;

  {
    	cout<<"Query OK, "<<mysql_affected_rows(MySQLConnection)<<" rows affected ;"<<"\n" ;
  }
    
    // --------------------------------------------------------------------
    /*如果数据库存在，删除数据库。
     */
    if(mysql_query(MySQLConnection, 
	          "DROP  DATABASE if exists wuhujun "))
    {	
    cout<<"Error No: "<<mysql_errno(MySQLConnection)<<"\t"<<mysql_error(MySQLConnection);
       return (1);
    }
    /*
     * 更改使用用户。
     */
    string n_user  = "wuhujun";

    string n_password = "ia"; 

    string n_database = "ia" ;
    try{
    	mysql_change_user(MySQLConnection,
			n_user.c_str() ,
			n_password.c_str() ,
			n_database.c_str() );
	if(NULL==MySQLConnection){
		 throw FFError( (char*) mysql_error(MySQLConnection) );   
	}
	//当前连接的默认字符集。
	string default_name = mysql_character_set_name(MySQLConnection) ;
	cout<<"The current connection 's default name :"<<default_name<<endl;

    }catch( FFError e){
    	cout<<e.Label<<endl;	
    }
     /*提交当前事务。
      */
      if(mysql_commit(MySQLConnection)){
      	 cout<<"Error commit the query failed !!!"<<'\n';
      }
     /*
      */

    /*关闭连接
     */
    mysql_close(MySQLConnection);
    return 0;
}


