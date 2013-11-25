void carregarMapa(int nMapa)
{

    if (colisao != nMapa)
    {

        switch (nMapa){
        case 0: //Dormitorio Feminino
/*            if (x== && y==)
            {

            }*/
            x = 64;
            y = 64;

        break;
        case 1: // Dormitorio Masculino
             /*if (x== && y==)
            {

            }*/
            x = 64;
            y = 64;

        break;
        case 2: //Salas
             /*if (x== && y==)
            {

            }*/
            x=376;
            y=568;
        break;
        case 3: // Sala diretor
             /*if (x== && y==)
            {

            }*/
            x = 392;
            y = 56;
        break;
        case 4: //Biblioteca refeitorio
             /*if (x== && y==)
            {

            }*/
            x = 400;
            y = 64;
        break;
        }
        fundoDisplay = al_load_bitmap(imagemMapa[nMapa]);
        carregarColisao(nMapa);
        colisao = nMapa;
        al_draw_bitmap(fundoDisplay, 0, 0, 0);
        al_draw_bitmap(personagemCHAR[1],x,y,0);
        al_flip_display();
    }
    else
    {
        al_draw_bitmap(fundoDisplay, 0, 0, 0);
        al_flip_display();
    }
}
void carregarColisao(int nMapa)
{
    i=0;
    j=0;
    fMapa = fopen(colisaoMapa[nMapa], "r"); // Carrega o arquivo de texto da fase em questão;

    while((lerMapa = getc(fMapa) ) != EOF )    // Grava Caracter enquanto não chegar ao final do arquivo;
    {
        if ( i < 28 ) // Enquanto estivar na linha;
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
