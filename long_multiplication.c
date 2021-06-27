#include <stdio.h>
#include <math.h>

int getDigit(int num, int n)
{
    int r;

    r = num / pow(10, n);

    r = r % 10;

    return r;
}

int countDigit(int n)
{
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}

void printChars(int Length, char c){

    for (int i = 0; i < Length; i++)
        printf("%c", c);

}
void multiply(int a, int b)
{
    int total = a * b;
	int totalLength = countDigit(total);
    int aLength = countDigit(a);
    int bLength = countDigit(b);
    int array[bLength][aLength];

    char space = ' ';
    char pause = '-';

    int i;
    int k;

    if (b > a)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    if(b>1){
    for(i=0; i < bLength; i++)
    {
        int d = getDigit(b, i);
        int b;
        int reserve = 0;
        for(k = 0 ; k < aLength; k++){
            b=getDigit(a, k);
            reserve = getDigit(d * b + reserve, 1);
            array[i][k] = reserve;
        }
        }


        for(i = bLength - 1; i >=0 ; i--)
        {
            if(getDigit(i, b)==1){
                continue;
            }
            printChars(totalLength - aLength + 1, space);
            for(k = aLength - 1; k >=0; k--){
            if(getDigit(i, a)==1){
                continue;
            }
                if(array[i][k]==0){
            printf(" ");
                }
            else{
                 printf("%d", array[i][k]);
            }

            }
             printf("\n");
        }
    }


    printChars(totalLength - aLength + 2, space);
    printf("%d", a);

    printf("\n*");
    printChars(totalLength - bLength + 1, space);
    printf("%d\n", b);

    printChars(totalLength + 2 < 3 ? 3 : totalLength + 2, pause);
    printf("\n");

    if (bLength > 1)
    {
        for (i = 0; i < bLength; i++)
        {
            int belowValue = getDigit(b, i) * a;

            int valLength = countDigit(belowValue);

            if (belowValue != 0)
            {
                if (i == bLength - 1){
                    printf("+");
                    }

                else
                    printf(" ");

                printChars(totalLength - valLength + 1 - i, space);
                printf("%d\n", belowValue);
            }
        }

        printChars(totalLength + 2, pause);
        printf("\n");
    }

    printf("  %d", total);
    return;
}

int main(int argc, char *argv[])
{
    int a, b;

    printf("Long multiplication \n");
    printf("a= ");
    scanf("%d", &a);

    printf("b= ");
    scanf("%d", &b);
    multiply(a, b);

}