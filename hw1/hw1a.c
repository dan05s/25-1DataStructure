#include <stdio.h>
#include <limits.h>//use INT_MAX

int main() {
    FILE *fp;//file pointer
    int num;//variable that stores an integer read from a file
    int min = INT_MAX;//minimum number. Initialize to the largest value first

    //file1.txt
    fp = fopen("file1.txt", "r");
    if (fp == NULL) {
        printf("file1.txt open error\n");//file open error
        return 1;//end program
    }

    min = INT_MAX;//Initialize the minimum value to INT_MAX
    while (fscanf(fp, "%d", &num) != EOF) {//find minimum number
        if (num < min) {
            min = num;
        }
    }
    //print result
    printf("Input filename: file1.txt\n");
    printf("The smallest number is %d\n",min);
    fclose(fp);

    //file2.txt
    fp = fopen("file2.txt", "r");
    if (fp == NULL) {
        printf("file2.txt open error\n");
        return 1;
    }

    min = INT_MAX;
    while (fscanf(fp, "%d", &num) != EOF) {
        if (num < min) {
            min = num;
        }
    }
    printf("Input filename: file2.txt\n");
    printf("The smallest number is %d\n",min);
    fclose(fp);

    // file3.txt
    fp = fopen("file3.txt", "r");
    if (fp == NULL) {
        printf("file3.txt open error\n");
        return 1;
    }

    min = INT_MAX;
    while (fscanf(fp, "%d", &num) != EOF) {
        if (num < min) {
            min = num;
        }
    }
    printf("Input filename: file3.txt\n");
    printf("The smallest number is %d\n", min);
    fclose(fp);

    return 0;
}