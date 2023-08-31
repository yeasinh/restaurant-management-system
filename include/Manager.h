#ifndef MANAGER_H
#define MANAGER_H
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<mysql.h>
#include<graphics.h>
#include<fstream>
#include"Person.h"
#include"Foodview.h"

using namespace std;


class Manager:public Person
{
    public:

        Manager();
        void sign_in_up();
        void view();


        int op();

        int show_total_cash();

        int show_card_pay();


        int add_food();


        int delete_food();


        int update_food();

        int backup_system();




    protected:
        int selected=0;


    private:
};

#endif // MANAGER_H
