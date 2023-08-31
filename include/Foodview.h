#ifndef FOODVIEW_H
#define FOODVIEW_H
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<mysql.h>
#include<graphics.h>
#include "Database.h"
#include"Restaurant.h"


class Foodview:public Restaurant
{
    public:
        Foodview();

        int food_list();

        friend class Person;
        friend class Customer;
        friend class Manager;

    protected:
        int foodcount;
        string foodname[1000];
        string foodprice[1000];
        string foodstock[1000];

    private:
};

#endif // FOODVIEW_H
