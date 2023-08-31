#include "Foodview.h"

Foodview::Foodview()
{

}

int Foodview::food_list()
{
    Database d1;
    string y,z,w;
    int i=1,height=1050/2-300+60,flag=0,mx,my,j;

    d1.open_database(resname);


    d1.qstate12=d1.query_all("foodlist");

    if(!d1.qstate12)
    {

       d1.res = mysql_store_result(d1.conn);
        while(d1.row=mysql_fetch_row(d1.res))
        {
            foodname[i]=d1.row[0];
            foodprice[i]=d1.row[1];
            foodstock[i]=d1.row[2];
            i++;
        }
        foodcount=i-1;
        return foodcount;
    }
    else
    {
        readimagefile("errorford.jpg",0,0,1920,1050);

        delay(2000);
        return -2;
    }
}
