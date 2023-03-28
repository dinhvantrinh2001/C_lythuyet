/**************CALL LIBRARY******************/
#include<stdint.h>
#include<stdio.h>
#include<stdbool.h>
/**************CHECK LEAP YEAR******************/
bool check_year(int y)
{
    if(y%4==0 && y%100!=0)
    {
        return true;
    }else if(y%400==0) 
    {
        return true;
    }
    else return false;
}
/**************DEFINE DAY OF THE MONTH******************/
int dayOfMonth(int m,int y)
{
    switch (m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;
    case 2:
        if(check_year(y)==true)
        {
            return 29;
        }else return 28;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;
    default:
    printf("Invalid month\n");
        break;
    }
}
/**************CALCULATE SUM DAY******************/
int totalDay(int d, int m, int y)
{
    int total=0;
    for(int i=1;i<y;i++)
    {
        if(check_year(i)==true)
        {
            total += 366;
        } else total += 365;
    }
    for(int i=1;i<m;i++)
    {
        total += dayOfMonth(i,y);
    }
    total += d;
    // printf("%d\n",total);
    return total;
}
/**************SHOW FUNCTION******************/
void show(int d, int m, int y)
{
    switch (totalDay(d,m,y)%7)
    {
    case 0:
        printf("Sunday\n");
        break;
    case 1:
        printf("Monday\n");
        break;
    case 2:
        printf("Tuesday\n");
        break;
    case 3:
        printf("Wednesday\n");
        break;
    case 4:
        printf("Thursday\n");
        break;
    case 5:
        printf("Friday\n");
        break;
    case 6:
        printf("Sartuday\n");
        break;
    default:
        printf("Invalid\n");
        break;
    }
}
/**************MAIN FUNCTION******************/
int main()
{
    int d,m,y;
    printf("Enter day, month, year : ");
    scanf("%d %d %d",&d,&m,&y);
    printf("Day : %d/%d/%d \n",d,m,y);
    // totalDay(d,m,y);
    show(d,m,y);
}
