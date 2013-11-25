int colisaoMapa(int nMapa)
{
    char vMapa[] = {
        "dormitorio_feminino.txt",//0
        "dormitorio_masculino.txt",//1
        "salas.txt",//2
        "sala_diretor.txt",//3
        "biblioteca_refeitorio.txt",//4
        "",//5
        ""//7
    };
    int vMatriz_Mapa[20][25],i=0,j=0;
    FILE *fMapa = fopen(vMapa[nMapa], "r"); // Carrega o arquivo de texto da fase em questão;

    char vLe_Char;

    while((vLe_Char = getc(fMapa) ) != EOF )    // Grava Caracter enquanto não chegar ao final do arquivo;
    {
        if ( i < 25 ) // Enquanto estivar na linha;
        {
            vMatriz_Mapa[j][i] = atoi(&vLe_Char); // Carrega a matriz com os caracteres que representam as imagens;
            i++;
        }
        else // senao passa para a proxima linha;
        {
            j++;
            i=0;
        }

    }
    fclose(fMapa);
}
