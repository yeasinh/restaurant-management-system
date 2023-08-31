#include "Person.h"

Person::Person()
{

}

int Person::access_login(string s)
{
    Database d1;
    string userid1,password1;

    int mx,my;
    char *c;
    int i=0,tw=0,width=1920/2;

login1:
    readimagefile("customersign.jpg",0,0,1920,1050);

    settextstyle(6,HORIZ_DIR,6);
    tw=textwidth("Sign In");
    setbkcolor(15);
    setcolor(1);
    outtextxy(1920/2+80,300,"Sign In");


    settextstyle(6,HORIZ_DIR,4);
    outtextxy(1920/2+80,380,"User ID");
    line(1920/2+80,450,1920/2+80+300,450);


    settextstyle(6,HORIZ_DIR,4);
    outtextxy(1920/2+80,480,"Password");
    line(1920/2+80,550,1920/2+80+300,550);




    settextstyle(6,HORIZ_DIR,6);
    setbkcolor(4);
    setcolor(15);
    outtextxy(1920/2+80,650,"Sign In");
    rectangle(1920/2+80,650,1920/2+80+textwidth("Sign In"),650+textheight("Sign In"));

    int a=textheight("Sign In");



    settextstyle(6,HORIZ_DIR,3);
    setbkcolor(15);
    setcolor(0);

    outtextxy(1920/2+375,675,"Doesn't Have an account?");

    setbkcolor(15);
    setcolor(1);


    while(1)
    {
        while (!ismouseclick(WM_LBUTTONDOWN))

        {

        }
        getmouseclick(WM_LBUTTONDOWN, mx, my);

        if(mx>=1920/2+80 && mx<=1920/2+80+300)
        {


            if(my>=380 && my<=450)
            {
                c=new char;
                i=0;
                width=1920/2+85;

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

                        outtextxy(width,420,"   ");
                    }
                    else
                    {
                        char *c1=new char;
                        c1[0]=c[i];
                        c1[1]='\0';

                        outtextxy(width,420,c1);
                        width=width+textwidth(c1);
                        i++;
                    }
                }
                c[i]='\0';
                userid=c;

            }
            else if(my>=480 && my<=550)
            {

                c=new char;
                i=0;
                width=1920/2+85;

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

                        outtextxy(width,520,"   ");
                    }
                    else
                    {
                        char *c1=new char;
                        c1[0]=c[i];
                        c1[1]='\0';

                        outtextxy(width,520,c1);
                        width=width+textwidth(c1);
                        i++;
                    }
                }
                c[i]='\0';
                password=c;
            }
            else   if(my>=650 && my<=650+a)
            {
                break;
            }
        }
        else if(mx>=1920/2+375 && mx<=1920/2+375+textwidth("Doesn't Have an account?"))
        {
            if(my>=675  &&  my<=675+textheight("Doesn't Have an account?"))
            {
                return 1;
            }
        }
    }

    cleardevice();

    d1.open_database("programbasicdb");

    if(s=="customerinfo" || s=="employeeinfo")
    {
    d1.qstate12=d1.query_where(s,"userid",userid);
    }
    else
    {
        d1.qstate12=d1.query_where(s,"name",f1.resname);
    }


    if(!d1.qstate12)
    {

        d1.res = mysql_store_result(d1.conn);
        while(d1.row=mysql_fetch_row(d1.res))
        {
            userid1=d1.row[0];
            password1=d1.row[1];
        }

        if(password.compare(password1)==0  && userid.compare(userid1)==0)
        {
            readimagefile("regdone.jpg",0,0,1920,1050);
            settextstyle(6,HORIZ_DIR,5);
            setbkcolor(9);
            setcolor(4);
            int width=1920/2-600+textwidth(" .");
            for(int cs=0; cs<15; cs++)
            {
                outtextxy(width,1050/2-200," .");
                width=width+textwidth(" .");
                delay(500);
            }

            outtextxy(1920/2-600+textwidth(" ."),1050/2, "SIGN IN SUCCESSFULLY");

            delay(1500);
        }
        else
        {

            readimagefile("errorsign.jpg",0,0,1920,1050);
            delay(1500);
            cleardevice();
            goto login1;
        }
    }
    else
    {
        outtextxy(1920/2-300,1050/2-100,"Query Problem.We are stopping the Program");
        delay(1500);
        cleardevice();
        goto login1;

    }

    return 0;
}


int Person::registration()
{
    Database d1;
    string customer_name="";
    string customer_emailid="";

    string customer_location="";
    string customer_phone_no="";

    int OTP;
    int mx,my;
    char *c2;
    int i=0,tw=0,width=1920/2;
    int b=textwidth("ABCDEFGHIJKLMNOPQRSTUVWXYZ");



registration:


    readimagefile("regis.jpg",0,0,1920,1050);




    setbkcolor(15);
    setcolor(1);

    settextstyle(6,HORIZ_DIR,6);
    tw=textwidth("Registration");
    outtextxy(1920/2-tw/2,100,"Registration");

    settextstyle(6,HORIZ_DIR,3);
    outtextxy(1920/2-500,315,"User Name");
    line(1920/2-500,315+70,1920/2-500+b+200,315+70);

    settextstyle(6,HORIZ_DIR,3);
    outtextxy(1920/2-500,400,"Email ID");
    line(1920/2-500,400+70,1920/2-500+b+200,400+70);

    settextstyle(6,HORIZ_DIR,3);
    outtextxy(1920/2-500,485,"Contact Number");
    line(1920/2-500,485+70,1920/2-500+b+200,485+70);

    settextstyle(6,HORIZ_DIR,3);
    outtextxy(1920/2-500,575,"Delivery Address Details");
    line(1920/2-500,575+70,1920/2-500+b+200,575+70);

    settextstyle(6,HORIZ_DIR,3);
    outtextxy(1920/2-500,660,"Password");
    rectangle(1920/2-500,660+70,1920/2-500+b+200,660+70);

    settextstyle(6,HORIZ_DIR,6);
    setbkcolor(4);
    setcolor(15);
    outtextxy(1920/2-150,800,"Create");
    rectangle(1920/2-150,800,1920/2-150+textwidth("Create"),800+textheight("Create"));
    int a=textheight("Create");

    settextstyle(6,HORIZ_DIR,3);
    setbkcolor(15);
    setcolor(1);
    while(1)
    {
        while (!ismouseclick(WM_LBUTTONDOWN))

        {

        }
        getmouseclick(WM_LBUTTONDOWN, mx, my);

        if(mx>=1920/2-500 && mx<=1920/2-500+b+200)
        {
            if(my>=315 && my<=385)
            {
                c2=new char;
                i=0;
                width=1920/2-495;

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

                        outtextxy(width,355,"   ");
                    }
                    else
                    {
                        char *c1=new char;
                        c1[0]=c2[i];
                        c1[1]='\0';

                        outtextxy(width,355,c1);
                        width=width+textwidth(c1);
                        i++;
                    }
                }
                c2[i]='\0';
                customer_name=c2;

            }
            else if(my>=400 && my<=470)
            {
                c2=new char;
                i=0;
                width=1920/2-495;

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

                        outtextxy(width,440,"   ");
                    }
                    else
                    {
                        char *c1=new char;
                        c1[0]=c2[i];
                        c1[1]='\0';

                        outtextxy(width,440,c1);
                        width=width+textwidth(c1);
                        i++;
                    }
                }
                c2[i]='\0';
                customer_emailid=c2;
            }
            else if(my>=485 && my<=555)
            {
                c2=new char;
                i=0;
                width=1920/2-495;

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

                        outtextxy(width,525,"   ");
                    }
                    else
                    {
                        char *c1=new char;
                        c1[0]=c2[i];
                        c1[1]='\0';

                        outtextxy(width,525,c1);
                        width=width+textwidth(c1);
                        i++;
                    }
                }
                c2[i]='\0';
                customer_location=c2;
            }
            else if(my>=575 && my<=645)
            {
                c2=new char;
                i=0;
                width=1920/2-495;

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

                        outtextxy(width,615,"   ");
                    }
                    else
                    {
                        char *c1=new char;
                        c1[0]=c2[i];
                        c1[1]='\0';

                        outtextxy(width,615,c1);
                        width=width+textwidth(c1);
                        i++;
                    }
                }
                c2[i]='\0';
                customer_phone_no=c2;
            }
            else if(my>=660 && my<=730)
            {
                c2=new char;
                i=0;
                width=1920/2-495;

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

                        outtextxy(width,700,"   ");
                    }
                    else
                    {
                        char *c1=new char;
                        c1[0]=c2[i];
                        c1[1]='\0';

                        outtextxy(width,700,c1);
                        width=width+textwidth(c1);
                        i++;
                    }
                }
                c2[i]='\0';
                password=c2;
            }

            else   if(my>=800 && my<=800+a)
            {
                if(password!="" && customer_phone_no!="" && customer_name!=""  && customer_location!="")
                {
                    break;
                }
                else
                {
                    outtextxy(1920/2-500,830,"Fill UP Every Field");
                }
            }
        }
    }

    cleardevice();

verify:
    settextstyle(6,HORIZ_DIR,5);
    setbkcolor(8);
    setcolor(0);

    srand(time(NULL));
    OTP=rand()%10000+1;
    readimagefile("otp.jpg",0,0,1920,1050);

    string x="Sent OTP  :"+to_string(OTP);
    char *m=new char(x.size()+1);
    strcpy(m,x.c_str());
    outtextxy(100,1050/2-200,m);
    outtextxy(100,1050/2-100,"Write The Given OTP  :");


    c2=new char;
    i=0;
    width=100+textwidth("Write The GiveN OTP  :");

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

            outtextxy(width,1050/2-100,"   ");
        }
        else
        {
            char *c1=new char;
            c1[0]=c2[i];
            c1[1]='\0';

            outtextxy(width,1050/2-100,c1);
            width=width+textwidth(c1);
            i++;
        }
    }
    c2[i]='\0';

    string oo=c2;

    int o=stoi(c2);
    int j=0;

    width=1920/2-500,tw=0;

    if(o==OTP)
    {
        cleardevice();
        cout<<"yes"<<endl;


        i=0;
        c2=new char;
        j=0;

        while(1)
        {
            if(customer_name[i]!=' ')
            {
                c2[j]=customer_name[i];
                j++;
            }

            i++;
            if(j==5)
            {
                break;
            }

        }
        c2[5]='\0';
        int rand1;
        srand(time(NULL));
        rand1=rand()%10000+1;


        string q=c2;

        q=q+to_string(rand1);
        userid=q;
        q="Your Auto Created User Id  :"+q;
        c2=new char(q.size()+1);
        strcpy(c2,q.c_str());

        d1.open_database("programbasicdb");

        d1.qstate12=d1.insert_customer_info(userid,password,customer_name,customer_phone_no,customer_emailid,customer_location);



        if(!d1.qstate12)
        {
            readimagefile("regdone.jpg",0,0,1920,1050);
            setbkcolor(9);
            setcolor(4);
            outtextxy(1920/2-700,1050/2-300,c2);
            width=1920/2-700;
            outtextxy(1920/2-700,1050/2-200, "Submitting your data");
            for(int cs=0; cs<10; cs++)
            {
                outtextxy(width,1050/2-100," .");
                width=width+textwidth(" .");
                delay(500);
            }
            outtextxy(1920/2-700,1050/2,"Registration Complete");
            delay(1000);
            return 1;
        }
        else
        {
            readimagefile("regfail.jpg",0,0,1920,1050);
            delay(2000);
            cleardevice();
            goto registration;
        }


    }
    else
    {
        cleardevice();
        outtextxy(1920/2-200,1050/2-100,"Wrong OTP");
        delay(1000);
        goto verify;
    }
    return 0;
}
