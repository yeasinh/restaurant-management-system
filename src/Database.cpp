#include "Database.h"

Database::Database()
{
}

void Database::open_database(string s)
{
    const char* m = s.c_str();
    conn=mysql_real_connect(conn,"localhost","root","",m,0,NULL,0);
}

int Database::query_all(string s)
{
    if(conn)
    {

        string query="select *from "+s;

        const char* q = query.c_str();
        qstate11=mysql_query(conn,q);
        return qstate11;
    }
    else
    {
        outtextxy(1920/2-300,1050/2-100,"Can Not Connect Database");
        return -2;
    }
}


int Database::query_where(string s,string s1,string s2)
{
    if(conn)
    {
        string query="select *from "+s+" where "+s1+"='"+s2+"'";
        cout<<query<<endl;

        const char* q = query.c_str();
        qstate11=mysql_query(conn,q);
        return qstate11;
    }
    else
    {
        outtextxy(1920/2,1050/2,"Can Not Connect Database");
        return -2;
    }
}



int Database::query_where_date(string s)
{
    if(conn)
    {
        string query="select *from "+s+" where date=curdate()";

        const char* q = query.c_str();
        qstate11=mysql_query(conn,q);
        return qstate11;

    }
    else
    {
        outtextxy(1920/2,1050/2,"Can Not Connect Database");
        return -2;
    }
}


int Database::update_totalcash(string s)
{
    if(conn)
    {
        string query="update totalcash set totalcash="+s+" where date=curdate()";
        const char* q = query.c_str();
        cout<<query;
        qstate11=mysql_query(conn,q);
        return qstate11;
    }
    else
    {
        outtextxy(1920/2,1050/2, "Can Not Connect Database");

        return -2;
    }
}


int Database::update_foodlist(string s,string s1,string s2)
{
    if(conn)
    {
        string query="update foodlist set price='"+s+"' , stock='"+s1+"' where name='"+s2+"'";
        const char* q = query.c_str();
        cout<<query;
        qstate11=mysql_query(conn,q);
        return qstate11;
    }
    else
    {
        outtextxy(1920/2,1050/2, "Can Not Connect Database");

        return -2;
    }
}

int Database::update_order_main_db(string s,string s1)
{
    if(conn)
    {
        string query="update order_employee set total_order='"+s+"' ,pending_order= '"+s1+"' where date=curdate()";
        const char* q = query.c_str();
        cout<<query;
        qstate11=mysql_query(conn,q);
        return qstate11;
    }
    else
    {
        outtextxy(1920/2,1050/2, "Can Not Connect Database");

        return -2;
    }
}

int Database:: insert_customer_info(string s,string s1,string s2,string s3,string s4,string s5)
{
    int width=1920/2-300;
    if(conn)
    {

        string query="insert into customerinfo(userid,password,name,phoneno,emailid,address) values('"+s+"','"+s1+"','"+s2+"','"+s3+"','"+s4+"','"+s5+"') ";


        const char* q = query.c_str();

        qstate11=mysql_query(conn,q);

        return qstate11;
    }
    else
    {
        outtextxy(1920/2-300,1050/2-100,"Can Not Connect Database");
        return -2;

    }
}


int Database::insert_card_info(string s,string s1)
{
    if(conn)
    {

        string query="insert into carddetails(date,id,totalprice) values(curdate(),'"+s+"','"+s1+"') ";


        const char* q = query.c_str();

        qstate11=mysql_query(conn,q);

        return qstate11;
    }
    else
    {
        outtextxy(1920/2-300,1050/2-100,"Can Not Connect Database");
        return -2;

    }
}

int Database::insert_order_list(string s,string s1,string s2)
{
    if(conn)
    {
        string query="insert into orderlist(date,foodname,quantity,price) values(curdate(),'"+s+"','"+s1+"','"+s2+"') ";
        cout<<query<<endl;

        const char* q = query.c_str();
        qstate11=mysql_query(conn,q);

        return qstate11;

    }
    else
    {
        outtextxy(1920/2-300,1050/2-100,"Conn Object Problem");
        return -2;

    }
}


int Database::insert_food(string s,string s1,string s2)
{
    if(conn)
    {
        string query="insert into foodlist(name,price,stock) values('"+s+"','"+s1+"','"+s2+"') ";

        const char* q = query.c_str();
        qstate11=mysql_query(conn,q);

        return qstate11;

    }
    else
    {
        outtextxy(1920/2-300,1050/2-100,"Conn Object Problem");
        return -2;

    }
}

int Database::insert_pendinglist(string s,string s1,string s2,string s3,string s4,string s5,string s6,string s7,string s8)
{

    if(conn)
    {

        string query="insert into pending_list(date,orderid,userid,employeeid,name,resname,quantity,payment,price,status) values(curdate(),'"+s+"','"+s1+"','"+s2+"','"+s3+"','"+s4+"','"+s5+"','"+s6+"','"+s7+"','"+s8+"')";
       cout<<query<<endl;
        const char* q = query.c_str();
        qstate11=mysql_query(conn,q);

        return qstate11;

    }
    else
    {
        outtextxy(1920/2-300,1050/2-100,"Conn Object Problem");
        return -2;

    }
}


int Database::delete_food(string s)
{
    if(conn)
    {

        string query="delete from  foodlist where name='"+s+"'";

        cout<<query<<endl;

        const char* q = query.c_str();
        qstate11=mysql_query(conn,q);

        return qstate11;

    }
    else
    {
        outtextxy(1920/2-300,1050/2-100,"Conn Object Problem");
        return -2;

    }
}

