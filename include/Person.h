#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<mysql.h>
#include<graphics.h>
#include "Database.h"
#include"Foodview.h"

using namespace std;


class Person
{
    public:
        Person();
        int access_login(string s);
        int registration();

        virtual void sign_in_up()=0;


         void view();



    protected:
        string userid;
        string password;
        string selectedfood[100];
        string selectedfoodstock[100];
        string selectedfoodprice[100];
        Database d1;
        Foodview f1;

    private:
};

#endif // PERSON_H
