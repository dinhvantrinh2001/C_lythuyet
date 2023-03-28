#include<stdint.h>
#include<stdio.h>

int n=0;
int m=0;
char arr[] = {"The following lessons cover 75 topics that you will face very often in your daily life. Each lesson is designed in form of ESL conversation questions and answers"};
char arr2[100];

struct data
{
    int index;
    int size;
};

struct data infor[100];
//Show an array
void Display(const uint8_t *array, int n)
{
    printf("Array = ");
    for(uint32_t i=0;i<n;i++)
    {
        printf("%c",array[i]);
    }
    printf("\n");
}
//Find index and size of each word
void FindIndexnSize(const char *array)
{
    infor[0].index = sizeof(arr);
    infor[0].size = 0;
    for(int i = (sizeof(arr)-1);i>=0;i--)
    {
        if(arr[i] == 32 || i==0)
        {
            n++;
            infor[n].index = i;
            infor[n].size = infor[n-1].index - infor[n].index;
        }
    }
}
//
void reverse()
{
    for(int i=0;i<(n+1);i++)
    {
        
        for(int j=infor[i].index;j<(infor[i].index + infor[i].size);j++)
        {
            arr2[m] = arr[j];
            m++;
        }
    }
}

int main()
{
    FindIndexnSize(arr);
    reverse();
    Display(arr2,m);
}
