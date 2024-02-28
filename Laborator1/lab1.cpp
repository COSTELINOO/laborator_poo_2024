#include <cstdio>
#include <cstdlib>
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
    int sum=0;
    char line[100];
    FILE *fp;
    fp = fopen("input.txt", "r");
    while (fgets(line, sizeof(line), fp)) {
        int number = string_to_int(line);
        sum += number;
    }
fclose(fp);
printf("Suma este: %d",sum);
return 0;
}

