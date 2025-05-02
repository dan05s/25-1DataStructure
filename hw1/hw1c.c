#include <stdio.h>
#include <ctype.h>


void changeCase(char str[]) {//function to change case
    int i = 0;
    while (str[i] != '\0'){//repeat until the end of the string
        if(islower(str[i])){
            str[i] = toupper(str[i]);
        }else if(isupper(str[i])){
            str[i] = tolower(str[i]);
        }
        i++;
    }
}

int main(){
    char line[100];//array of strings to store user input

    printf("Input: ");
    fgets(line, sizeof(line), stdin);//get one line of input

    changeCase(line);//function call

    printf("=> %s", line);

    return 0;
}