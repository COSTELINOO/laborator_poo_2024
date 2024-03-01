#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include<iostream>
using namespace std;
int string_to_int(char s[])
{
    int p=0;
    for(int i=0;s[i+1]!=0;i++)
        p=p*10+s[i]-'0';
    printf("%d \n",p);
    return p;
}
int main() {
   char s[100];
    scanf("%[^\n]", s);
    int i=0;
    char *p=strtok(s," "),q[100][100];
    while(p!=NULL)
    {
        strcpy(q[i],p);
        p=strtok(NULL," ");
        i++;
    }
    int n=i,j;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(strlen(q[i])<strlen(q[j]))
                swap((q[i]),(q[j]));

    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(strlen(q[i])==strlen(q[j]))
                if(strcmp(q[i],q[j])>0)
                swap((q[i]),(q[j]));
    for( j=0;j<i;j++)
        printf("%s \n",q[j]);

   // printf(s);

}

