#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char ch;
    FILE *fp;
    double sum=0.0;
    char number[100];
    int idx=0;

    //file open
    fp=fopen("example1.txt", "r");
    if (fp == NULL) {
        printf("File open error\n");
        return 1;
    }

    //read file content
    while((ch = fgetc(fp)) != EOF){
        if(isdigit(ch) || ch == '.') {//If it is a number or decimal point, store it in the number array.
            number[idx++] = ch;
        }else{//If the number ends, convert the string to a number and add it up
            if (idx > 0) {
                number[idx] = '\0';
                sum += atof(number);
                idx = 0;
            }
        }
    }

    //Processing if there is a number at the end of the file
    if(idx > 0){
        number[idx]='\0';
        sum += atof(number);
    }

    fclose(fp);

    //print result
    printf("The sum is %.2f\n", sum);
    return 0;
}
