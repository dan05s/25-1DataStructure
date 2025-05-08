#include <stdio.h>
#include <stdlib.h>

float** make2dArray(int rows, int cols);//Dynamic allocation of a two-dimensional array
void free2dArray(float** matrix, int rows);//Free the memory of a two-dimensional array
float** add_matrix(float** a, int ah, int aw, float** b, int bh, int bw);//Add two matrices
float** mul_matrix(float** a, int ah, int aw, float** b, int bh, int bw);//Multiply two matrices
float** transpose_matrix(float** a, int ah, int aw);//Transpose the matrix
void print_matrix(float** matrix, int rows, int cols);//Print result

int main(){
    int rows1, cols1, rows2, cols2;
    char operator;
    char filename1[50], filename2[50];

    printf("What operation do you want? (‘a’, ‘m’, ‘t’)\n");
    scanf(" %c", &operator);//Get operation type input

    float **matrix1 = NULL, **matrix2 = NULL, **result = NULL;
    int res_rows = 0, res_cols = 0;
    
    if(operator == 'a' || operator == 'm'){
        printf("Input files names:\n");
        scanf("%s %s", filename1, filename2);//Enter the file name

        FILE *file1 = fopen(filename1, "r");//First file
        if(file1 == NULL){
            printf("Can't find file: %s\n", filename1);
            return 1;
        }
        fscanf(file1, "%d %d", &rows1, &cols1);//Get the first matrix's rows and columns
        matrix1 = make2dArray(rows1, cols1);//First matrix dynamic memory allocation
        for(int i=0; i<rows1; i++){//Read a file and store the matrix in an 2d array
            for(int j=0; j<cols1; j++){
                fscanf(file1, "%f", &matrix1[i][j]);
            }
        }
        fclose(file1);
        
        FILE *file2 = fopen(filename2, "r");//Second file
        if(file2 == NULL){
            printf("Can't find file: %s\n", filename2);
            free2dArray(matrix1, rows1);
            return 1;
        }
        fscanf(file2, "%d %d", &rows2, &cols2);
        matrix2 = make2dArray(rows2, cols2);
        for(int i=0; i<rows2; i++){
            for(int j=0; j<cols2; j++){
                fscanf(file2, "%f", &matrix2[i][j]);
            }
        }
        fclose(file2);

        if(operator == 'a'){//add matrix
            result = add_matrix(matrix1, rows1, cols1, matrix2, rows2, cols2);
            res_rows = rows1;
            res_cols = cols1;
        }else{//multiply matrix
            result = mul_matrix(matrix1, rows1, cols1, matrix2, rows2, cols2);
            res_rows = rows1;
            res_cols = cols2;
        }
    }else if(operator == 't') {//transpose matrix
        printf("Input file name:\n");
        scanf("%s", filename1);
        
        FILE *file = fopen(filename1, "r");
        if(file == NULL){
            printf("Can't find file: %s\n", filename1);
            return 1;
        }
        fscanf(file, "%d %d", &rows1, &cols1);
        matrix1 = make2dArray(rows1, cols1);
        for(int i=0; i<rows1; i++){
            for(int j=0; j<cols1; j++){
                fscanf(file, "%f", &matrix1[i][j]);
            }
        }
        fclose(file);
        result = transpose_matrix(matrix1, rows1, cols1);
        res_rows = cols1;
        res_cols = rows1;
        
    } else {
        printf("Invalid operator! Use 'a', 'm', or 't'.\n");
        return 1;
    }

    print_matrix(result, res_rows, res_cols);//Print result
    free2dArray(result, res_rows);//Free result array
    

    if(matrix1) free2dArray(matrix1, rows1);//Free first matrix memory
    if(matrix2) free2dArray(matrix2, rows2);//Free second matrix memory

    return 0;
}

float** make2dArray(int rows, int cols){//Dynamic memory allocation for arrays
    float** matrix = (float**)malloc(rows * sizeof(float*));
    for(int i = 0; i < rows; i++){
        matrix[i] = (float*)malloc(cols * sizeof(float));
    }
    return matrix;
}

void free2dArray(float** matrix, int rows){//Free the memory of a two-dimensional array
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

float** add_matrix(float** a, int ah, int aw, float** b, int bh, int bw){//If the matrix size does not match, an error is output
    if (ah != bh || aw != bw){
        printf("Matrix dimensions mismatch\n");
        return NULL;
    }

    float** result = make2dArray(ah, aw);
    for(int i=0; i<ah; i++){
        for (int j=0; j<aw; j++){
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    return result;
}

float** mul_matrix(float** a, int ah, int aw, float** b, int bh, int bw){//If the matrix size does not match, an error is output
    if(aw != bh){
        printf("Matrix dimensions mismatch\n");
        return NULL;
    }

    float** result = make2dArray(ah, bw);
    for(int i=0; i<ah; i++){
        for(int j=0; j<bw; j++){
            result[i][j] = 0;
            for(int k=0; k<aw; k++){
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return result;
}

float** transpose_matrix(float** a, int ah, int aw){
    float** result = make2dArray(aw, ah);
    for (int i=0; i<ah; i++){
        for(int j=0; j<aw; j++){
            result[j][i] = a[i][j];//Swap rows and columns of a matrix
        }
    }
    return result;
}

void print_matrix(float** matrix, int rows, int cols) {
    printf("%d %d\n", rows, cols);//Output matrix size
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.1f ", matrix[i][j]);//Output matrix elements
        }
        printf("\n");
    }
}
