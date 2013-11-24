
#include <stdio.h>

int pode_ir_para(int x, int y)
{
    FILE *fMapa = fopen("colision_map.txt", "r");
    char vMatriz_Mapa[25][19],vLe_Char;
    int aux_x=0;
    int aux_y=0;

       while((vLe_Char = getc(fMapa) ) != EOF )    // Grava Caracter enquanto não chegar ao final do arquivo;
    {
        if ( aux_y < 19 ) // Enquanto estivar na linha;
        {
            vMatriz_Mapa[aux_x][aux_y] = vLe_Char; // Carrega a matriz com os caracteres que representam as imagens;
            aux_y++;
            aux_x=0;
        }
        else // senao passa para a proxima linha;
        {
            aux_x++;
            aux_y=0;
        }
    }
   /* for(aux_x=0;aux_x<19;aux_x++){
        for(aux_y=0;aux_y<25;aux_y++ ){
     printf("%c",vMatriz_Mapa[aux_x][aux_y]);
    }
    }
*/
printf("%c",vMatriz_Mapa[13][9]);
if (vMatriz_Mapa[x/32][y/32] = '1'){
    return 1;
}else if (vMatriz_Mapa[x/32][y/32] = '0'){
    return 0;
}
}
