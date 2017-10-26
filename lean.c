#include <stdio.h>
#include <stdlib.h>

void printMatrix(int **, int, int);
int ** createMatrix(int,int);
void freeMatrix(int **, int, int);

int main(void){
    int f,r;
    int ** matrix=NULL;
    printf("Cantidad de filas: ");
    scanf("%d", &f);
    printf("Cantidad de columnas: ");
    scanf("%d", &r);
    matrix= createMatrix(f,r);
    for(int i=0; i<f; i++){
        for(int j=0; j<r; j++){
            printf("Ingrese la posicion [%d][%d] de la matriz: ", i, j);
            scanf("%d", &(matrix[i][j]));
        }
    }
    printMatrix(matrix, f, r);
    freeMatrix(matrix,f,r);
    return 0;
}

int ** createMatrix(int f, int r){
    int ** aux=malloc(sizeof(*aux)*f);
    for(int i=0; i<f;i++)
        aux[i]=malloc(sizeof(int)*r);
    return aux;
}

void freeMatrix(int ** m, int f, int r){
    for(int i=0; i<f;i++)
        free(m[i]);
    free(m);
    return;
}

void printMatrix(int ** m, int f, int r){
    for(int i=0; i<f;i++){
        for(int j=0; j<r; j++)
            printf("%d ", m[i][j]);
        putchar('\n');
    }
    return;
}
