#include "Manager.h"

extern int mx,my;
extern int update_delete;

Manager::Manager()
{

}

void Manager::sign_in_up()
{
    readimagefile("resman.jpg",0,0,1920,1050);
    f1.restaurant_list();
    int flag=Person::access_login("restaurantinfo");

}

void Manager::view()
{
    int k=1,j,count,i=1,height=1050/2-300+60;
    string x,y,z,w;




restaurant_option:
    int flag=f1.food_list();
    if(flag>=0)
    {
        settextstyle(6,HORIZ_DIR,5);
        setbkcolor(15);
        setcolor(0);
        readimagefile("mnview.jpg",0,0,1920,1050);
        outtextxy(1920/2-370,1050/2-300,"Food Name          ");
        int a=textwidth("Food Name          ");

        settextstyle(6,HORIZ_DIR,4);
        setbkcolor(15);
        setcolor(0);

        while(i<=f1.foodcount)
        {


            char *c=new char(f1.foodname[i].size()+1);

            strcpy(c,f1.foodname[i].c_str());

            outtextxy(1920/2-370+20,height,c);

            if(update_delete==1)
            {

                settextstyle(6,HORIZ_DIR,5);
                outtextxy(1920/2-200,100,"UPDATE FOOD ");
                outtextxy(1920/2-370+a,1050/2-300,"Stock     Price");
                settextstyle(6,HORIZ_DIR,4);

                c=new char(f1.foodstock[i].size()+1);

                strcpy(c,f1.foodstock[i].c_str());

                outtextxy(1920/2+100,height,c);

                c=new char(f1.foodprice[i].size()+1);

                strcpy(c,f1.foodprice[i].c_str());

                outtextxy(1920/2+300,height,c);

            }
            else
            {
                settextstyle(6,HORIZ_DIR,5);
                outtextxy(1920/2-200,100,"DELETE FOOD ");
                settextstyle(6,HORIZ_DIR,4);
            }
            height=height+40;
            i++;
        }


        settextstyle(6,HORIZ_DIR,6);
        setbkcolor(4);
        setcolor(15);
        outtextxy(1920/2-370,930,"BACK");

        outtextxy(1920/2+200,930,"NEXT");

        int x=textheight("NEXT");
        int y=textwidth("NEXT");

        settextstyle(6,HORIZ_DIR,3);
        setbkcolor(7);
        setcolor(1);

        while(1)
        {
            while (!ismouseclick(WM_LBUTTONDOWN))
            {

            }
            getmouseclick(WM_LBUTTONDOWN, mx, my);

            if(mx>=1920/2-370+20 )
            {
                if(my>=285  && my<=285+f1.foodcount*40)
                {
                    for(j=1; j<=f1.foodcount; j++)
                    {
                        if(my>=285+(j-1)*40 && my<=285+j*40)
                        {
                            selectedfood[k]=f1.foodname[j];
                            selectedfoodprice[k]=f1.foodprice[j];
                            selectedfoodstock[k]=f1.foodstock[j];
                            setbkcolor(4);
                            outtextxy(1920/2-370,285+(j-1)*40,"  ");

                            cout<<selectedfood[k]<<endl;

                            selected=k;
                            k++;
                        }
                    }
                }
                else if(my>=930 && my<=930+x)
                {
                    if(mx>=1920/2-370 && mx<=1920/2-370+y)
                    {
                        goto restaurant_option;
                    }
                    else if(mx>=1920/2+200 && mx<=1920/2+200+y)
                    {
                        break;
                    }
                }
            }
        }
    }
}

int Manager::op()
{
    cleardevice();
    setbkcolor(7);
    setcolor(0);
    readimagefile("main11.jpg",0,0,1920,1050);

    settextstyle(6,HORIZ_DIR,6);
    setcolor(1);
    outtextxy(1920/2+250, 1050/2-350, "  Main section");
    settextstyle(6,HORIZ_DIR,4);
    setcolor(0);
    outtextxy(1920/2+300, 1050/2-250, "  Total Order And Cash Today.");
    outtextxy(1920/2+300, 1050/2-200, "  View Card Pay");
    outtextxy(1920/2+300, 1050/2-150, "  Add Food To Menu");
    outtextxy(1920/2+300, 1050/2-100, "  Delete Food");
    outtextxy(1920/2+300, 1050/2-50, "  Update Food");
    outtextxy(1920/2+300, 1050/2, "  Instant Food List ");
    outtextxy(1920/2+300, 1050/2+50, "  Backup System");
    outtextxy(1920/2+300, 1050/2+100, "  Exit");

    while(1)
    {
        while (!ismouseclick(WM_LBUTTONDOWN))

        {

        }
        getmouseclick(WM_LBUTTONDOWN, mx, my);

        if(mx>=1920/2+300 && mx<=1920/2+300+textwidth("  Total Order And Cash Today."))
        {
            if(my>=1050/2-250 && my<=1050/2-250+textheight("  Total Order And Cash Today."))
            {
                return 1;
            }
            else if(my>=1050/2-200 && my<=1050/2-200+textheight("  View Card Pay"))
            {
                return 2;
            }
            else if(my>=1050/2-150 && my<=1050/2-150+textheight("  Add Food To Menu"))
            {
                return 3;
            }
            else if(my>=1050/2-100 && my<=1050/2-100+textheight("  Delete Food"))
            {
                return 4;
            }
            else if(my>=1050/2-50 && my<=1050/2-50+textheight("  Update Food"))
            {
                return 5;
            }
            else if(my>=1050/2 && my<=1050/2+textheight("  Instant Food List "))
            {
                return 6;
            }
            else if(my>=1050/2+50 && my<=1050/2+50+textheight("  Backup System"))
            {
                return 7;
            }
            else if(my>=1050/2+100 && my<=1050/2+100+textheight("  Exit"))
            {
                return 0;
            }
        }
    }
    cleardevice();
}



int Manager::show_total_cash()
{
    string foodname;
    string quantity;
    string price;
    int total=0;
    string text;
    char *c,*c1;


    d1.open_database(f1.resname);

    d1.qstate11=d1.query_where_date("orderlist");

    if(!d1.qstate11)
    {
        readimagefile("money.jpg",0,0,1920,1050);

        settextstyle(6,HORIZ_DIR,6);
        setbkcolor(7);
        setcolor(0);

        text="FOOD NAME";
        c=new char(text.size()+1);
        strcpy(c,text.c_str());
        outtextxy(1920/2-650,1050/2-450,c);

        setbkcolor(15);
        setcolor(0);
        text="QUANTITY  PRICE";
        c=new char(text.size()+1);
        strcpy(c,text.c_str());
        outtextxy(1920/2+110,1050/2-450,c);

        int height=150;
        settextstyle(6,HORIZ_DIR,4);

        d1.res = mysql_store_result(d1.conn);
        while(d1.row=mysql_fetch_row(d1.res))
        {

            foodname=d1.row[1];
            quantity=d1.row[2];
            price=d1.row[3];
            total=total+stoi(price);

            setbkcolor(7);
            setcolor(0);

            c=new char(foodname.size()+1);
            strcpy(c,foodname.c_str());
            outtextxy(1920/2-630,height,c);


            setbkcolor(15);
            setcolor(0);

            c=new char(quantity.size()+1);
            strcpy(c,quantity.c_str());
            outtextxy(1920/2+250,height,c);

            c=new char(price.size()+1);
            strcpy(c,price.c_str());
            outtextxy(1920/2+550,height,c);

            height=height+50;
        }


        line(1920/2+110,700,1920/2+700,700);
        outtextxy(1920/2+380,720,"TOTAL=");

        text=to_string(total);


        c=new char(text.size()+1);
        strcpy(c,text.c_str());
        outtextxy(1920/2+380+textwidth("TOTAL="),720,c);

        settextstyle(6,HORIZ_DIR,5);
        setbkcolor(4);
        setcolor(15);
        outtextxy(1920/2+575,770,"BACK");


        while(1)
        {
            while (!ismouseclick(WM_LBUTTONDOWN))

            {

            }
            getmouseclick(WM_LBUTTONDOWN, mx, my);

            if(mx>=1920/2+575 && mx<=1920/2+575+textwidth("BACk"))
            {
                if(my>=770 && my<=770+textheight("BACK"))
                {
                    return 1;
                }
            }
        }
    }
    else
    {
        return -2;
    }

}


int Manager::show_card_pay()
{
    d1.open_database(f1.resname);
    settextstyle(6,HORIZ_DIR,4);

    setbkcolor(7);
    setcolor(1);

    string x="There is No Card Payment Yet",y="0",z;

    int height=1050/2-390;

    d1.qstate11=d1.query_where_date("carddetails");

    if(!d1.qstate11)
    {

        cleardevice();
        readimagefile("showcard.jpg",0,0,1920,1050);

        outtextxy(1920/2-300,1050/2-475,"     Card NO.            Money $   ");
        outtextxy(1920/2-300,1050/2-425,"----------------------------------------");

        rectangle(1920/2-300,50,1920/2-300+textwidth("----------------------------------------"),900);


        d1.res= mysql_store_result(d1.conn);

        while(d1.row=mysql_fetch_row(d1.res))
        {


            x=d1.row[1];
            y=d1.row[2];
            char *c=new char(x.size()+1);

            strcpy(c,x.c_str());

            outtextxy(1920/2-300+25,height,c);

            c=new char(y.size()+1);

            strcpy(c,y.c_str());

            outtextxy(1920/2+100,height,c);

            height=height+50;

        }



        settextstyle(6,HORIZ_DIR,5);

        setbkcolor(4);
        setcolor(15);
        outtextxy(1920/2-325,930,"GO TO MAIN SECTION");

        while(1)
        {
            while (!ismouseclick(WM_LBUTTONDOWN))

            {

            }
            getmouseclick(WM_LBUTTONDOWN, mx, my);

            if(mx>=1920/2-325 && mx<=1920/2-325+textwidth("GO TO MAIN SECTION"))
            {
                if(my>=930 && my<=930+textheight("GO TO MAIN SECTION"))
                {
                    return 1;
                }
            }
        }


    }
    else
    {
        return -2;
    }

}


int Manager::add_food()
{
    d1.open_database(f1.resname);

foodadd:
    cleardevice();
    string s1,s2="",s3="",s4;

    readimagefile("add.jpg",0,0,1920,1050);

    settextstyle(6,HORIZ_DIR,6);
    outtextxy(1920/2-200,80,"NEW FOOD");

    settextstyle(6,HORIZ_DIR,4);
    setbkcolor(0);
    setcolor(15);

    outtextxy(1920/2-300,1050/2-200," Enter Your Food Name :  ");
    line(1920/2-300,1050/2-100,1920/2+300,1050/2-100);

    fflush(stdin);
    setbkcolor(15);
    setcolor(0);

    char *c=new char;
    int i=0,tw=0,width=1920/2-300+5;
    while(1)
    {
        c[i]=getch();
        if(c[i]==13)
        {
            break;
        }
        else if(c[i]==8)
        {
            i=i-1;
            char *c1=new char;
            c1[0]=c[i];
            c1[1]='\0';
            width=width-textwidth(c1);

            outtextxy(width,1050/2-135,"   ");
        }
        else
        {
            char *c1=new char;
            c1[0]=c[i];
            c1[1]='\0';

            outtextxy(width,1050/2-135,c1);
            width=width+textwidth(c1);
            i++;
        }
    }
    c[i]='\0';
    s1=c;


    int flag=0;
    d1.qstate11=d1.query_where("foodlist","name",s1);

    if(!d1.qstate11)
    {
        d1.res = mysql_store_result(d1.conn);
        while(d1.row=mysql_fetch_row(d1.res))
        {

            if(d1.row[0]==s1)
            {
                flag=1;
                s1="";
                break;
            }
            {
                flag=0;
            }
        }

    }
    else
    {
        goto foodadd;
    }


    if(flag==1)
    {
        outtextxy(1920/2-300,1050/2," Food Already Exist. Add New Food ");
        cout<<s1<<endl;
        delay(2000);
        goto foodadd;
    }
    else
    {
        setbkcolor(0);
        setcolor(15);

        outtextxy(1920/2-300,1050/2-80," Enter Food Price :  ");
        line(1920/2-300,1050/2+20,1920/2+300,1050/2+20);
        outtextxy(1920/2-300,1050/2+40," Stock  :  ");
        line(1920/2-300,1050/2+140,1920/2+300,1050/2+140);

        settextstyle(6,HORIZ_DIR,5);
        setbkcolor(4);
        setcolor(15);
        outtextxy(1920/2-300,1050/2+300,"BACK");
        rectangle(1920/2-300,1050/2+300,1920/2-300+textwidth("BACK"),1050/2+300+textheight("BACK"));
        outtextxy(1920/2+100,1050/2+300,"SUBMIT");
        rectangle(1920/2+100,1050/2+300,1920/2+100+textwidth("SUBMIT"),1050/2+300+textheight("SUBMIT"));

        settextstyle(6,HORIZ_DIR,4);
        setbkcolor(15);
        setcolor(0);
        while(1)
        {
            while (!ismouseclick(WM_LBUTTONDOWN))

            {

            }
            getmouseclick(WM_LBUTTONDOWN, mx, my);


            if(mx>=1920/2-300)
            {

                if(my>=1050/2-80 && my<=1050/2+20)
                {
                    c=new char;
                    i=0;
                    tw=0;
                    width=1920/2-300+5;
                    while(1)
                    {
                        c[i]=getch();
                        if(c[i]==13)
                        {
                            break;
                        }
                        else if(c[i]==8)
                        {
                            i=i-1;
                            char *c1=new char;
                            c1[0]=c[i];
                            c1[1]='\0';
                            width=width-textwidth(c1);

                            outtextxy(width,1050/2+20-35,"   ");
                        }
                        else
                        {
                            char *c1=new char;
                            c1[0]=c[i];
                            c1[1]='\0';

                            outtextxy(width,1050/2+20-35,c1);
                            width=width+textwidth(c1);
                            i++;
                        }
                    }
                    c[i]='\0';
                    s2=c;

                }
                else if(my>=1050/2+40 && my<=1050/2+140)
                {

                    c=new char;
                    i=0;
                    tw=0;
                    width=1920/2-300+5;
                    while(1)
                    {
                        c[i]=getch();
                        if(c[i]==13)
                        {
                            break;
                        }
                        else if(c[i]==8)
                        {
                            i=i-1;
                            char *c1=new char;
                            c1[0]=c[i];
                            c1[1]='\0';
                            width=width-textwidth(c1);

                            outtextxy(width,1050/2+140-35,"   ");
                        }
                        else
                        {
                            char *c1=new char;
                            c1[0]=c[i];
                            c1[1]='\0';

                            outtextxy(width,1050/2+140-35,c1);
                            width=width+textwidth(c1);
                            i++;
                        }
                    }
                    c[i]='\0';
                    s3=c;
                }


                else  if(my>=1050/2+300  && my<=1050/2+300+textheight("BACK"))
                {

                    if(mx>=1920/2-300  && mx<=1920/2-300+textwidth("BACK"))
                    {
                        return 1;
                    }
                    else if(my>=1050/2+300  && my<=1050/2+300+textheight("SUBMIT"))
                    {
                        if(s2!=""  && s3!="")
                        {
                            break;
                        }
                    }
                }

            }
        }


        cleardevice();

        width=1920/2-250;
        d1.qstate12=d1.insert_food(s1,s2,s3);
        if(!d1.qstate12)
        {
            settextstyle(6,HORIZ_DIR,6);
            setbkcolor(15);
            setcolor(1);
            readimagefile("success.jpg",0,0,1920,1050);
            outtextxy(1920/2-250,1050/2-100, "Submitting your data");
            for(int cs=0; cs<10; cs++)
            {
                outtextxy(width,1050/2," .");
                width=width+textwidth(" .");
                delay(500);
            }

            outtextxy(1920/2-250,1050/2+100,"Food Added Successfully......." );

            delay(3000);
            return 2;


        }
        else
        {
            outtextxy(1920/2,1050/2, "Can not Add the new food.Please insert again");
            delay(1500);
            goto foodadd;
        }
    }

}

int Manager::delete_food()
{
    view();
    d1.open_database(f1.resname);
    int flag=0,flag1=0;

    readimagefile("delete.jpg",0,0,1920,1050);
    settextstyle(6,HORIZ_DIR,6);

    setbkcolor(4);
    setcolor(15);

    outtextxy(1920/2-200,1050/2+100,"Delete");


    setbkcolor(8);
    setcolor(15);

    outtextxy(1920/2+100,1050/2+100,"Cancel");


    while(1)
    {
        while (!ismouseclick(WM_LBUTTONDOWN))

        {

        }
        getmouseclick(WM_LBUTTONDOWN, mx, my);


        if(mx>=1920/2-200  && mx<=1920/2-200+textwidth("Delete"))
        {

            if(my>=1050/2+100 && my<=1050/2+100+textheight("Delete"))
            {
                flag1=1;
                break;
            }
        }
        else if(mx>=1920/2+100  && mx<=1920/2+100+textwidth("Cancel"))
        {

            if(my>=1050/2+100 && my<=1050/2+100+textheight("Cancel"))
            {
                return 1;
            }
        }
    }
    if(flag1==1)
    {
        cout<<selected<<endl;
        for(int i=1; i<=selected; i++)
        {

            d1.qstate11=d1.delete_food(selectedfood[i]);
            if(!d1.qstate11)
            {
                flag=1;
                cout<<flag<<endl;
            }
            else
            {
                flag=0;
                break;
            }
        }

        if(flag==1)
        {
            cleardevice();
            readimagefile("delete1.jpg",0,0,1920,1050);

            delay(4000);
            return 2;
        }
        else
        {
            return -2;
        }
    }
    else
    {
        return 1;
    }


}

int Manager::update_food()
{
    update_delete=1;
    view();

    cleardevice();

    int height=1050/2-300+60,i,width,tw,flag=0;
    char *c;
    d1.open_database(f1.resname);

    settextstyle(6,HORIZ_DIR,5);
    setbkcolor(15);
    setcolor(0);
    readimagefile("mnview.jpg",0,0,1920,1050);
    outtextxy(1920/2-370,1050/2-300,"Food Name          ");
    outtextxy(1920/2-370+textwidth("Food Name          "),1050/2-300,"Stock     Price");

    int a=textwidth("Food Name          ");
    int b=textwidth("Food Name          Stock ");
    int d=textwidth("    Price");
    settextstyle(6,HORIZ_DIR,4);


    for(int i=1; i<=selected; i++)
    {
        c=new char(selectedfood[i].size()+1);

        strcpy(c,selectedfood[i].c_str());

        outtextxy(1920/2-370,height,c);

        line(1920/2-370+a,height+textheight(c),1920/2-370+b,height+textheight(c));

        line(1920/2-370+b+50,height+textheight(c),1920/2-370+b+d,height+textheight(c));

        height=height+50;

    }

    settextstyle(6,HORIZ_DIR,5);
    setbkcolor(4);
    setcolor(15);
    outtextxy(1920/2+170,930,"UPDATE");
    setbkcolor(8);
    setcolor(15);
    outtextxy(1920/2-370,930,"CANCEL");

    int m=textwidth("CANCEL");
    int n=textheight("CANCEL");
    int o=textwidth("UPDATE");
    int p=textheight("UPDATE");

    settextstyle(6,HORIZ_DIR,4);
    setbkcolor(15);
    setcolor(0);


    while(1)
    {
        while (!ismouseclick(WM_LBUTTONDOWN))

        {

        }
        getmouseclick(WM_LBUTTONDOWN, mx, my);


        if(mx>=1920/2-370+a  && mx<=1920/2-370+b)
        {
            if(my>=285  && my<=285+textheight(c)+selected*50)
            {
                for(int j=1; j<=f1.foodcount; j++)
                {
                    if(my>=285+(j-1)*50 && my<=285+textheight(c)+(j-1)*50)
                    {
                        c=new char;
                        i=0;
                        tw=0;
                        width=1920/2-370+a+5;
                        while(1)
                        {
                            c[i]=getch();
                            if(c[i]==13)
                            {
                                break;
                            }
                            else if(c[i]==8)
                            {
                                i=i-1;
                                char *c1=new char;
                                c1[0]=c[i];
                                c1[1]='\0';
                                width=width-textwidth(c1);

                                outtextxy(width,285+(j-1)*50,"   ");
                            }
                            else
                            {
                                char *c1=new char;
                                c1[0]=c[i];
                                c1[1]='\0';

                                outtextxy(width,285+(j-1)*50,c1);
                                width=width+textwidth(c1);
                                i++;
                            }
                        }
                        cout<<j<<endl;
                        c[i]='\0';
                        selectedfoodstock[j]=c;
                    }
                }
            }
        }
        else if(mx>=1920/2-370+b+50  && mx<=1920/2-370+b+d)
        {
            if(my>=285  && my<=285+textheight(c)+selected*50)
            {
                for(int j=1; j<=f1.foodcount; j++)
                {
                    if(my>=285+(j-1)*50 && my<=285+textheight(c)+(j-1)*50)
                    {
                        c=new char;
                        i=0;
                        tw=0;
                        width=1920/2-370+b+55;
                        while(1)
                        {
                            c[i]=getch();
                            if(c[i]==13)
                            {
                                break;
                            }
                            else if(c[i]==8)
                            {
                                i=i-1;
                                char *c1=new char;
                                c1[0]=c[i];
                                c1[1]='\0';
                                width=width-textwidth(c1);

                                outtextxy(width,285+(j-1)*50,"   ");
                            }
                            else
                            {
                                char *c1=new char;
                                c1[0]=c[i];
                                c1[1]='\0';

                                outtextxy(width,285+(j-1)*50,c1);
                                width=width+textwidth(c1);
                                i++;
                            }
                        }
                        cout<<j<<endl;
                        c[i]='\0';
                        selectedfoodprice[j]=c;


                    }
                }
            }
        }
        else if(mx>=1920/2-370 && mx<=1920/2-370+m)
        {
            if(my>=930 && my<=930+n)
            {
                return 1;
            }
        }
        else if(mx>=1920/2+170 && mx<=1920/2+170+m)
        {
            if(my>=930 && my<=930+p)
            {
                break;
            }
        }
    }

    for(int i=1; i<=selected; i++)
    {
        d1.qstate11=d1.update_foodlist(selectedfoodprice[i],selectedfoodstock[i],selectedfood[i]);

        if(!d1.qstate11)
        {
            flag=1;
        }
        else
        {
            flag=0;
            return -2;
        }
    }
    if(flag==1)
    {
        cleardevice();
        readimagefile("success.jpg",0,0,1920,1050);
        settextstyle(6,HORIZ_DIR,6);
        setbkcolor(15);
        setcolor(0);
        outtextxy(1920/2-175,500,"UPDATED");
        settextstyle(6,HORIZ_DIR,4);
        outtextxy(1920/2-250,650,"Food Items Has Been Updated");

        delay(4000);
        return 2;
    }
}


int Manager::backup_system()
{
    int flag;
    readimagefile("backup.jpg",0,0,1920,1050);

    settextstyle(6,HORIZ_DIR,5);
    setbkcolor(7);
    setcolor(0);
    outtextxy(1050,300,"BACK UP DATABASE");
    settextstyle(6,HORIZ_DIR,3);
    outtextxy(1000,450,"Your Back Up File Will Be Saved Based On BackUp Date");
    settextstyle(6,HORIZ_DIR,5);
    setbkcolor(4);
    setcolor(15);
    outtextxy(1000,600,"CANCEL");
    setbkcolor(2);
    setcolor(15);
    outtextxy(1400,600,"BACK UP");

    while(1)
    {
        while (!ismouseclick(WM_LBUTTONDOWN))

        {

        }
        getmouseclick(WM_LBUTTONDOWN, mx, my);


        if(mx>=1000  && mx<=1000+textwidth("CANCEL"))
        {
            if(my>=600 && my<=600+textheight("CANCEL"))
            {
                flag=0;
                return 2;
            }
        }
        else if(mx>=1400  && mx<=1400+textwidth("BACK UP"))
        {
            if(my>=600 && my<=600+textheight("BACK UP"))
            {
                flag=1;
                break;
            }
        }
    }

    if(flag==1)
    {
        string x,y,z,w;
        time_t t = time(NULL);
        tm* tPtr = localtime(&t);
        string filename=to_string(tPtr->tm_mday)+"-"+to_string(tPtr->tm_mon+1)+"-"+to_string(tPtr->tm_year+1900)+".txt";

        d1.open_database(f1.resname);
        d1.qstate11=d1.query_all("orderlist");
        if(!d1.qstate11)
        {
            ofstream outfile(filename);
            d1.res = mysql_store_result(d1.conn);
            while(d1.row=mysql_fetch_row(d1.res))
            {
                w=d1.row[0];
                x=d1.row[1];
                y=d1.row[2];
                z=d1.row[3];
                outfile<<w<<" "<<x<<" "<<y<<" "<<z<<"\n";

            }
            return 1;
        }
    }
}

