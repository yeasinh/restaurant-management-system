#include"Restaurant.h"


Restaurant::Restaurant()
{

}


void Restaurant::restaurant_list()
{
    Database d1;

    string x[1000],y,z;
    int i=1,height=100+60,flag=0,j,mx,my;
    setfillstyle(1,7);
    settextstyle(6,HORIZ_DIR,5);
    setbkcolor(7);
    setcolor(0);
restaurant_list:

    d1.open_database("programbasicdb");

    d1.qstate12=d1.query_all("restaurantinfo");
    if(!d1.qstate12)
    {
        outtextxy(170,100,"Restaurant Name");
        outtextxy(780,100,"Location");
        d1.res = mysql_store_result(d1.conn);
        settextstyle(6,HORIZ_DIR,4);
        while(d1.row=mysql_fetch_row(d1.res))
        {

            x[i]=d1.row[2];
            y=d1.row[3];

            char *c=new char(x[i].size()+1);
            strcpy(c,x[i].c_str());
            outtextxy(170,height,c);

            c=new char(y.size()+1);
            strcpy(c,y.c_str());
            outtextxy(600,height,c);

            height=height+50;
            i++;
        }

        int restcount=i-1;

        while(1)
        {
            while (!ismouseclick(WM_LBUTTONDOWN))

            {

            }
            getmouseclick(WM_LBUTTONDOWN, mx, my);

            if(mx>=170 )
            {
                for(j=1; j<=restcount; j++)
                {
                    if(my>=160+(j-1)*50 && my<=160+j*50)
                    {
                        flag=1;
                        break;

                    }
                }
                if(flag==1)
                {
                    break;
                }

            }
        }

        resname=x[j];
        cleardevice();
    }
    else
    {
        outtextxy(1920/2-300,1050/2-100,"Query Problem.Try again");
        delay(500);
        cleardevice();
        goto restaurant_list;
    }
}
