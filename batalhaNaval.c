#include <stdio.h>

void habilidade(int matriz[10][10], int pos[2], int forma[3][5]){

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 5; j++){

            int coluna = pos[0] - 1 + i;
            int posicao = pos[1] - 2 + j;

            if (forma[i][j] == 0){continue;}
            
            if (posicao >= 0 && posicao < 10 && coluna >= 0 && coluna < 10){
                if (matriz[coluna][posicao] == 3){
                    matriz[coluna][posicao] = 5;
                } else{
                    matriz[coluna][posicao] = 1;
                }
            }
        }
    }

}

int main(){

    int matriz[10][10] = {0};

    int forma_cone[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
    };

    int forma_cruz[3][5] = {
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
    };

    int forma_octaedro[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
    };

    int pos_1[2] = {2,4}, pos_2[2] = {0,1}, pos_3[2] = {9,3}, pos_4[2] = {7,5};

    int pos_cone[2] = {4,4}, pos_cruz[2] = {8,4}, pos_octaedro[2] = {2,1};

    for (int i = 0; i < 3; i++){matriz[pos_1[0]][pos_1[1] + i] = 3;} // vertical
    for (int i = 0; i < 3; i++){matriz[pos_2[0] + i][pos_2[1]] = 3;} // horizontal
    for (int i = 0; i < 3; i++){matriz[pos_3[0] - i][pos_3[1] - i] = 3;}
    for (int i = 0; i < 3; i++){matriz[pos_4[0] - i][pos_4[1] + i] = 3;}
    
    habilidade(matriz, pos_cone, forma_cone);
    habilidade(matriz, pos_cruz, forma_cruz);
    habilidade(matriz, pos_octaedro, forma_octaedro);
    
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
}