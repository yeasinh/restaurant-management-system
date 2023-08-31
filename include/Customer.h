#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<mysql.h>
#include<graphics.h>
#include"Person.h"
#include"Foodview.h"


using namespace std;

class Customer:public Person
{
public:

    Customer();
    void sign_in_up();

    int registration();


    void view();

    void set_quantity();

    int order_details();


    int confirmation();

    int payment(string s);



protected:




private:

    int order;
    int selectedfoodquantity[100];
};

#endif // CUSTOMER_H
