#include"Customer.h"

Database d1;
Foodview f1;

extern int mx,my;

Customer::Customer()
{
}

void Customer::sign_in_up()
{
    int mx,my;

    int flag=Person::access_login("customerinfo");

    if(flag==1)
    {
        Person::registration();
    }


}


void Customer::view()
{

    int k=1,j,count,i=1,height=1050/2-300+60;
    string x,y,z,w;


    readimagefile("resta.jpg",0,0,1920,1050);
    f1.restaurant_list();
    restaurant_option:
    int flag=f1.food_list();
    if(flag>=0)
    {

        char *ch=new char;

        j=0;

        while (f1.resname[j])
        {
            if(f1.resname[j]>=97)
            {
                ch[j]=f1.resname[j]-32;
            }
            else
            {
                ch[j]=f1.resname[j];
            }
            j++;
        }
        ch[j]='\0';

        settextstyle(6,HORIZ_DIR,6);
        setbkcolor(7);
        setcolor(0);
        readimagefile("menu1.jpg",0,0,1920,1050);
        outtextxy(1920/2+110,1050/2-300,"  Food Name            Price ");
        int a=textwidth("  Food Name              ");

        settextstyle(10,HORIZ_DIR,10);
        setbkcolor(0);
        setcolor(15);
        outtextxy(190,980/2+50,ch);

        settextstyle(6,HORIZ_DIR,4);
        setbkcolor(7);
        setcolor(0);

        while(i<=f1.foodcount)
        {


            char *c=new char(f1.foodname[i].size()+1);

            strcpy(c,f1.foodname[i].c_str());

            outtextxy(1920/2+130,height,c);

            c=new char(f1.foodprice[i].size()+1);

            strcpy(c,f1.foodprice[i].c_str());

            outtextxy(1920/2+110+a,height,c);
            height=height+40;
            i++;
        }


        settextstyle(6,HORIZ_DIR,6);
        setbkcolor(4);
        setcolor(15);
        outtextxy(1920/2+150,930,"BACK");

        outtextxy(1920/2+600,930,"NEXT");

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

            if(mx>=1920/2+130 )
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
                            selectedfoodquantity[k]=1;
                            setbkcolor(4);

                            cout<<selectedfood[k]<<selectedfoodprice[k]<<endl<<selectedfoodstock[k]<<endl;
                            outtextxy(1920/2+110,285+(j-1)*40,"  ");

                            order=k;
                            k++;
                        }
                    }

                }
                else if(my>=930 && my<=930+x)
                {
                    if(mx>=1920/2+150 && mx<=1920/2+150+y)
                    {
                        goto restaurant_option;
                    }
                    else if(mx>=1920/2+600 && mx<=1920/2+600+y)
                    {
                        break;
                    }
                }

            }

        }
    }
}

void Customer::set_quantity()
{
    settextstyle(6,HORIZ_DIR,4);
    setbkcolor(7);
    setcolor(0);

    int i=1,height=1050/2-300,idx,idx1,a,b;

    string x;
    char *str;


    while(1)
    {
        cleardevice();
        height=1050/2-300;
        readimagefile("quantity.jpg",0,0,1920,1050);
        for(int j=1; j<=order; j++)
        {
            x=selectedfood[j]+"    ";
            char *c=new char(x.size()+1);
            strcpy(c,x.c_str());

            outtextxy(1920/2-30,height,c);

            outtextxy(1920/2+300+150,height,"  -  ");

            rectangle(1920/2+300+150,height,1920/2+300+150+textwidth("  -  "),height+textheight("  -  "));

            str=new char;

            sprintf(str, "%d", selectedfoodquantity[j]);

            outtextxy(1920/2+450+textwidth("  -   "),height,"  ");
            outtextxy(1920/2+450+textwidth("  -     "),height,str);

            outtextxy(1920/2+450+textwidth("  -     ")+textwidth(str),height,"  ");
            outtextxy(1920/2+450+textwidth("  -        ")+textwidth(str),height,"  +  ");
            rectangle(1920/2+450+textwidth("  -        ")+textwidth(str),height,1920/2+450+textwidth("  -        ")+textwidth(str)+textwidth("  +  "),height+textheight("  +  "));


            settextstyle(6,HORIZ_DIR,6);
            setbkcolor(4);
            setcolor(15);
            outtextxy(1920/2+600,950,"NEXT");
            rectangle(1920/2+600,950,1920/2+600+textwidth("NEXT"),950+textheight("NEXT"));


            a=textheight("NEXT");
            b=textwidth("NEXT");
            height=height+50;
            settextstyle(6,HORIZ_DIR,4);
            setbkcolor(7);
            setcolor(0);

        }

        while (!ismouseclick(WM_LBUTTONDOWN))
        {

        }
        getmouseclick(WM_LBUTTONDOWN, mx, my);

        if(mx>=1920/2+450&& mx<=1920/2+450+textwidth("  -  "))
        {
            for(int j=1; j<=order; j++)
            {
                if(my>=1050/2-300+(j-1)*50 && my<=1050/2-300+(j-1)*50+textheight("  +  "))
                {
                    idx=j;
                    break;
                }
            }
            if(selectedfoodquantity[idx]>1)
            {
                selectedfoodquantity[idx]=selectedfoodquantity[idx]-1;
            }
            else
            {
                outtextxy(1920/2,900,"At least Quantity will be 1");
                delay(500);
            }
        }


        else if(mx>=1920/2+450+textwidth("")+textwidth("  -        ")  && mx<=1920/2+450+textwidth("  -          +  ")+textwidth(str))
        {
            for(int j=1; j<=order; j++)
            {
                if(my>=1050/2-300+(j-1)*50 && my<=1050/2-300+(j-1)*50+textheight("   + "))
                {
                    idx1=j;
                    break;

                }
            }
            if(selectedfoodquantity[idx1]<stoi(selectedfoodstock[idx1]))
            {
                selectedfoodquantity[idx1]=selectedfoodquantity[idx1]+1;
            }
            else
            {
                outtextxy(1920/2,900," Out of Stock");
                delay(500);
            }

        }
        else if(mx>=1920/2+600 && mx<=1920/2+600+b)
        {
            if(my>=950  && my<=950+a)
            {
                cleardevice();
                break;
            }
        }

    }

}


int Customer::order_details()
{

    settextstyle(6,HORIZ_DIR,6);
    setbkcolor(15);
    setcolor(0);

    int height=200,total_payment=0,flag=-1;
    char *c,*c1;

    readimagefile("order1.jpg",0,0,1920,1050);

    outtextxy(1920/2+350,50,"Your Cart");

    string temp1,temp;
    settextstyle(6,HORIZ_DIR,4);
    for(int i=1; i<=order; i++)
    {
        c=new char(selectedfood[i].size()+1);
        strcpy(c,selectedfood[i].c_str());

        outtextxy(1920/2+100,height,c);


        string temp6,temp5,temp7;
        temp6=selectedfoodprice[i];
        temp7=selectedfoodstock[i];

        cout<<temp6<<temp5<<temp7<<endl;

        int total=stoi(temp6)*selectedfoodquantity[i];

        total_payment=total_payment+total;

        string total_price=to_string(total);

        temp1=to_string(selectedfoodquantity[i])+" X "+selectedfoodprice[i];
        c=new char(temp1.size()+1);
        strcpy(c,temp1.c_str());

        outtextxy(1920/2+530,height,c);

        temp=" = "+ total_price+" ";
        c1=new char(temp.size()+1);
        strcpy(c1,temp.c_str());
        outtextxy(1920/2+700,height,c1);

        selectedfoodstock[i]=to_string(stoi(temp7)-selectedfoodquantity[i]);
        height=height+50;

    }

    temp="TOTAL ="+to_string(total_payment);
    c=new char(temp.size()+1);
    strcpy(c,temp.c_str());

    setcolor(0);
    height=height+30;
    line(1920/2+100,height-5,1920/2+850,height-5);
    outtextxy(1920/2+750-textwidth("TOTAL   ="),height,c);

    settextstyle(6,HORIZ_DIR,6);
    outtextxy(1920/2+100,750,"Payment :");
    settextstyle(6,HORIZ_DIR,4);
    setbkcolor(1);
    setcolor(14);
    outtextxy(1920/2+500,780,"CASH");

    outtextxy(1920/2+750,780,"CARD");
    settextstyle(6,HORIZ_DIR,6);
    setbkcolor(2);
    setcolor(15);
    outtextxy(1920/2+120,900,"          PAY ORDER       ");

    settextstyle(6,HORIZ_DIR,4);
    setbkcolor(4);
    setcolor(4);

    while(1)
    {
        while (!ismouseclick(WM_LBUTTONDOWN))

        {

        }
        getmouseclick(WM_LBUTTONDOWN, mx, my);

        if(mx>=1920/2+500 && mx<=1920/2+500+textwidth("CASH"))
        {
            if(my>=780 && my<=780+textheight("CASH"))
            {
                outtextxy(1920/2+480,780,"  ");
                flag=0;
                break;

            }

        }
        else if(mx>=1920/2+750  && mx<=1920/2+750+textwidth("CARD"))
        {
            if(my>=780  && my<=780+textheight("CARD"))
            {
                outtextxy(1920/2+720,780,"  ");
                flag=1;
                break;
            }
        }
    }

    settextstyle(6,HORIZ_DIR,4);

    setbkcolor(15);
    setcolor(0);

    if(flag==1 || flag==0)
    {
        while(1)
        {
            while (!ismouseclick(WM_LBUTTONDOWN))

            {

            }
            getmouseclick(WM_LBUTTONDOWN, mx, my);

            if(mx>=1920/2+120 && mx<=1920/2+120+textwidth("          PAY ORDER       "))
            {
                if(my>=900 && my<=900+textheight("          PAY ORDER       "))
                {
                    cleardevice();
                    break;

                }

            }
        }
        string newstock;

        d1.open_database(f1.resname);
            for(int i=1; i<=order; i++)
          {
              d1.qstate12=d1.update_foodlist(selectedfoodprice[i],selectedfoodstock[i],selectedfood[i]);

              if(!d1.qstate12)
              {

              }
              else
              {
                  return -3;
              }
          }

           d1.open_database(f1.resname);
            for(int i=1; i<=order; i++)
          {
              cout<<"KKSA"<<endl;
              d1.qstate11=d1.insert_order_list(selectedfood[i],to_string(selectedfoodquantity[i]),
                                               to_string(stoi(selectedfoodprice[i])*selectedfoodquantity[i]));

              if(!d1.qstate11)
              {

              }
              else
              {
                  return -3;
              }
          }

        d1.open_database("programbasicdb");
        int total_order,pending_order,employee_no;

        d1.qstate11=d1.query_where_date("order_employee");
        if(!d1.qstate11)
        {
            d1.res = mysql_store_result(d1.conn);
            while(d1.row=mysql_fetch_row(d1.res))
            {
                total_order=stoi(d1.row[1]);
                pending_order=stoi(d1.row[2]);
                employee_no=stoi(d1.row[3]);
            }
        }



        total_order=total_order+1;
        pending_order=pending_order+1;
        employee_no=(total_order%employee_no)+1;
        for(int i=1; i<=order; i++)
        {
            d1.qstate12=d1.insert_pendinglist(to_string(total_order),userid,to_string(employee_no),
                              selectedfood[i],f1.resname,to_string(selectedfoodquantity[i]),to_string(flag),
                                to_string(stoi(selectedfoodprice[i])*selectedfoodquantity[i]),"0");
            if(!d1.qstate12)
            {

            }
            else
            {
                return -3;
            }
        }

        for(int i=1;i<=order;i++)
        {
            d1.qstate11=d1.update_order_main_db(to_string(total_order),to_string(pending_order));
            if(!d1.qstate11)
            {

            }
            else
            {
                return -3;
            }
        }

        if(flag==1)
        {
            payment(to_string(total_payment));
        }
    }

}


int Customer::payment(string s)
{

    int mx,my,i,width;
    char *c2;
    string cardno,pin;
    d1.open_database(f1.resname);

                    readimagefile("cardpayment.jpg",0,0,1920,1050);
                    setbkcolor(7);
                    setcolor(0);
                    settextstyle(6,HORIZ_DIR,4);

                    outtextxy(1000,1050/2-100,"Enter Your Card Number  :");
                    rectangle(1000+textwidth("Enter Your Card Number  :"),
                              1050/2-100,1000+textwidth("Enter Your Card Number  :")+textwidth("123456789000123"),1050/2-100+50);
                    outtextxy(1000,1050/2,"Enter valid PIN                  :");
                    rectangle(1000+textwidth("Enter Your Card Number  :"),
                              1050/2,1000+textwidth("Enter Your Card Number  :")+textwidth("12000345"),1050/2+50);

                    setbkcolor(4);
                    setcolor(15);

                    outtextxy(1000,1050/2+300,"SUBMIT");

                    rectangle(1000,1050/2+300,1000+textwidth("SUBMIT"),1050/2+300+textheight("SUBMIT"));

                    setbkcolor(2);
                    setcolor(15);

                    outtextxy(1300,1050/2+300,"BACK");

                    rectangle(1300,1050/2+300,1300+textwidth("BACK"),1050/2+300+textheight("BACK"));
                    setbkcolor(7);
                    setcolor(0);



                    while(1)
                    {
                        while (!ismouseclick(WM_LBUTTONDOWN))

                        {

                        }
                        getmouseclick(WM_LBUTTONDOWN, mx, my);

                        if(mx>=1000+textwidth("Enter Your Card Number  :") && mx<=1000+textwidth("Enter Your Card Number  :")+textwidth("1234567890123"))
                        {


                            if(my>=1050/2-100 && my<=1050/2-100+50)
                            {
                                c2=new char;
                                i=0;
                                width=1000+textwidth("Enter Your Card Number  :")+5;

                                while(1)
                                {
                                    c2[i]=getch();
                                    if(c2[i]==13)
                                    {
                                        break;
                                    }
                                    else if(c2[i]==8)
                                    {
                                        i=i-1;
                                        char *c1=new char;
                                        c1[0]=c2[i];
                                        c1[1]='\0';
                                        width=width-textwidth(c1);

                                        outtextxy(width,1050/2-100+10,"   ");
                                    }
                                    else
                                    {
                                        char *c1=new char;
                                        c1[0]=c2[i];
                                        c1[1]='\0';

                                        outtextxy(width,1050/2-100+10,c1);
                                        width=width+textwidth(c1);
                                        i++;
                                    }
                                }
                                c2[i]='\0';
                                cardno=c2;

                            }

                            else if(my>=1050/2  && my<=1050/2+50)
                            {
                                c2=new char;
                                i=0;
                                width=1000+textwidth("Enter Your Card Number  :")+5;

                                while(1)
                                {
                                    c2[i]=getch();
                                    if(c2[i]==13)
                                    {
                                        break;
                                    }
                                    else if(c2[i]==8)
                                    {
                                        i=i-1;
                                        char *c1=new char;
                                        c1[0]=c2[i];
                                        c1[1]='\0';
                                        width=width-textwidth(c1);

                                        outtextxy(width,1050/2+10,"   ");
                                    }
                                    else
                                    {
                                        char *c1=new char;
                                        c1[0]=c2[i];
                                        c1[1]='\0';

                                        outtextxy(width,1050/2+10,c1);
                                        width=width+textwidth(c1);
                                        i++;
                                    }
                                }
                                c2[i]='\0';
                                pin=c2;
                            }


                        }
                        else if(mx>=1000  && mx<= 1000+textwidth("SUBMIT"))
                        {
                            if(my>=1050/2+300 && my<=1050/2+300+textheight("SUBMIT"))
                            {

                                if(cardno!="" && pin!="")
                                {

                                    d1.qstate11=d1.insert_card_info(cardno,s);

                                    if(!d1.qstate11)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        return -3;
                                    }
                                }
                            }
                        }
                        else if(mx>=1300  && mx<= 1300+textwidth("BACK"))
                        {
                            if(my>=1050/2+300 && my<=1050/2+300+textheight("BACK"))
                            {
                            return 0;
                            }
                        }

                }
}
