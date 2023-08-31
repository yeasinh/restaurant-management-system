#ifndef RESTAURANT_H
#define RESTAURANT_H
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<mysql.h>
#include<graphics.h>
#include "Database.h"


using namespace std;

class Restaurant
{
    public:


        Restaurant();

        void restaurant_list();

friend class Person;


protected:
      string resname;

private:
};

#endif // RESTAURANT_H
