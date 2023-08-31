#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include"Restaurant.h"
#include"Customer.h"
#include"Manager.h"
#include<graphics.h>
#include "Database.h"
#include"Foodview.h"
#include"Person.h"

int update_delete=0;
int mx,my;

void loading_section();

int main_section();
using namespace std;

int main()
{


    initwindow(1920,1050,"");
    loading_section();
    readimagefile("front.jpg",0,0,1920,1050);
    delay(2500);
    int mainsection;
    mainsection=main_section();

    if(mainsection==1)
    {
        Person *p;
        Customer c;

        p=&c;

        p->sign_in_up();
        c.view();
        c.set_quantity();
        c.order_details();

    }
    else if(mainsection==2)
    {
        Person *p;
        Manager m;

        p=&m;

        int option,flag;

        p->sign_in_up();


        option_for_work:

        option=m.op();

        if(option==1)
        {
           flag= m.show_total_cash();
           if(flag==1)
           {
               goto option_for_work;
           }
        }
        else if(option==2)
        {
            flag=m.show_card_pay();
            if(flag==1)
            {
                goto option_for_work;
            }
        }
        else if(option==3)
        {
            flag=m.add_food();

            if(flag==1 || flag==2)
            {
                goto option_for_work;
            }
        }
        else if(option==4)
        {
            update_delete=0;
            flag=m.delete_food();
            if(flag==1 ||  flag==2)
            {
                goto option_for_work;
            }
        }
        else if(option==5)
        {
            update_delete=1;
            flag=m.update_food();
            if(flag==1 ||  flag==2)
            {
                goto option_for_work;
            }
        }
        else if(option==6)
        {
            update_delete=1;
            m.view();
            goto option_for_work;
        }
        else if(option==7)
        {
            flag=m.backup_system();
            if(flag==1 || flag==2)
            {
                goto option_for_work;
            }
        }
        else if(option==0)
        {
            return 0;
        }


    }
    else if(mainsection==3)
    {

    }





}

void loading_section()
{
    readimagefile("load.jpg",0,0,1920,1050);
    settextstyle(6,HORIZ_DIR,6);
    rectangle(190,750,1690,750+textheight("  "));
    int a=textwidth(" ");



    for(int i=0; i<85; i=i+5)
    {
        setbkcolor(1);
        settextstyle(6,HORIZ_DIR,6);
        rectangle(200,750,1720,750+textheight("  "));
        setbkcolor(1);

        for(int j=0; j<i; j=j+5)
        {
            outtextxy(200+textwidth(" ")*j,750,"     ");
        }

        delay(500);
    }
    cleardevice();
}

int main_section()
{
    int mx,my;
    readimagefile("mainsection.jpg",0,0,1920,1050);

    settextstyle(6,HORIZ_DIR,5);
    setbkcolor(15);
    setcolor(0);
    outtextxy(200,700,"CUSTOMER");

    outtextxy(850,700,"MANAGER");

    outtextxy(1450,700,"DELIVERY");
    settextstyle(6,HORIZ_DIR,5);


    while(1)
    {
        while (!ismouseclick(WM_LBUTTONDOWN))

        {

        }
        getmouseclick(WM_LBUTTONDOWN, mx, my);


        if(my>=700  && my<=742)
        {
            if(mx>=200 &&  mx<=200+textwidth("CUSTOMER"))
            {
                cleardevice();
                return 1;
            }
            else  if(mx>=850 &&  mx<=850+textwidth("MANAGER"))
            {
                cleardevice();
                return 2;
            }
             else  if(mx>=1450 &&  mx<=1450+textwidth("DELIVERY"))
            {
                cleardevice();
                return 3;
            }

        }
    }
}
