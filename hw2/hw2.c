#include <stdio.h>
#include <ctype.h>

int main(){
    FILE*fp;//file pointer
    char ch;//Variable to store each character
    int alpha[26]={0};//Save alphabet count
    int digit[10]={0};//Store the number of numbers

    fp=fopen("example.txt","r");
    if(fp==NULL){
        printf("file open error\n");
        return 1;
    }

    while((ch=fgetc(fp))!=EOF){
        if(isalpha(ch)){
            ch=toupper(ch);
            alpha[ch-'A']++;//+1 to the corresponding alphabet position
        }else if(isdigit(ch)){
            digit[ch-'0']++;//+1 to that number position
        }
    }

    fclose(fp);
    //print result
    for(int i=0;i<26;i++){
        printf("%c: %d\n",'A'+i,alpha[i]);
    }

    for(int i=0;i<10;i++){
        printf("%d: %d\n",i,digit[i]);
    }

    return 0;
}