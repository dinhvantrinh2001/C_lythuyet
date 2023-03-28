/**************CALL LIBRARY******************/
#include<stdint.h>
#include<stdio.h>
const int *name[] = {"trieu","tram","muoi","nghin","tram","muoi","dong"};//Max 7 number
int value[7];//Max 7 number
/**************TAKE EACH NUMBER FUNCTION******************/
void callNumber(int n)
{
    int tg=10;
    for(int i=0;i<7;i++)
    {
        value[i] = (n%(tg)) /(tg/10);
        tg *= 10;
        
    }
}
/**************SHOW FUNCTION******************/
void show()
{
    for(int i=0;i<7;i++)
    {
        printf("%d %s ",value[6-i],name[i]);
    }
}
/**************MAIN FUNCTION******************/
int main()
{
    int n;
    printf("Enter your number : ");
    scanf("%d",&n);
    callNumber(n);
    show();
}