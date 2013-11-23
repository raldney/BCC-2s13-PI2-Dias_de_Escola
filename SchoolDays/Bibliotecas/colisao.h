void carregarMapa(int nMapa)
{
    printf("teste\n");
    fundoDisplay = al_load_bitmap(imagemMapa[nMapa]);
    al_draw_bitmap(fundoDisplay, 0, 0, 0);
    if (colisao != nMapa)
    {
        printf("teste\n");
        carregarColisao(nMapa);
        colisao = nMapa;
        switch (nMapa){
        case 0:
            x = 64;
            y = 64;
        break;
        case 1:
            x = 64;
            y = 64;
        break;
        case 2:
            x=416;
            y=64;
        break;
        case 3:
            x = 32;
            y = 64;
        break;
        case 4:
            x = 448;
            y = 64;
        break;
        }
        al_draw_bitmap(personagemCHAR[1],x,y,0);
    }
    al_flip_display();
}
void carregarColisao(int nMapa)
{
    i=0;
    j=0;
    fMapa = fopen(colisaoMapa[nMapa], "r"); // Carrega o arquivo de texto da fase em questão;
    printf("teste\n");

    while((lerMapa = getc(fMapa) ) != EOF )    // Grava Caracter enquanto não chegar ao final do arquivo;
    {
        if ( i < 27 ) // Enquanto estivar na linha;
        {
            tileMap[j][i] = atoi(&lerMapa); // Carrega a matriz com os caracteres que representam as imagens;
            i++;
        }
        else // senao passa para a proxima linha;
        {
            j++;
            i=0;
        }
    }
    fclose(fMapa);
    for (j=0;j<21;j++)
    {
        for (i=0;i<27;i++)
        {

            // if(vMatriz_Mapa[j/32][i/32]==2){
            printf("%d",tileMap[j][i]);


        }
        printf("\n");
    }
}
