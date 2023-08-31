#ifndef DATABASE_H
#define DATABASE_H
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<mysql.h>
#include<graphics.h>


using namespace std;
class Database
{
public:
    Database();

    void open_database(string s);


    int query_all(string s);
    int query_where(string s,string s1,string s2);
    int query_where_date(string s);

    int update_foodlist(string s,string s1,string s2);

    int update_totalcash(string s);

    int update_order_main_db(string s,string s1);

    int insert_customer_info(string s,string s1,string s2,string s3,string s4,string s5);

    int insert_card_info(string s,string s1);

    int insert_order_list(string s,string s1,string s2);

    int insert_food(string s,string s1,string s2);

    int insert_pendinglist(string s,string s1,string s2,string s3,string s4,string s5,string s6,string s7,string s8);

    int delete_food(string s);

    friend class Restaurant;

    friend class Foodview;

    friend class Person;

    friend class Customer;

    friend class Manager;

    friend class DeliveryPerson;


protected:

    MYSQL_ROW row;
    MYSQL_RES* res;
    MYSQL *conn=mysql_init(0);
    int qstate11,qstate12;


private:
};

#endif // DATABASE_H
