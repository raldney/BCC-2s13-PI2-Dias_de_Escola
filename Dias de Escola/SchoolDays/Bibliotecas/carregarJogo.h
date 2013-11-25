void iniciarJogo(){
 if (sexo == 'm'){
    fundoDisplay = al_load_bitmap("Imagens/Mapas/dormitorio_masculino.bmp");
    al_draw_bitmap(fundoDisplay, 0, 0, 0);
    carregarPersonagem("Imagens/Personagens/peter.bmp");
 }else if (sexo == 'f'){
 fundoDisplay = al_load_bitmap("Imagens/Mapas/dormitorio_feminino.bmp");
    al_draw_bitmap(fundoDisplay, 0, 0, 0);
    carregarPersonagem("Imagens/Personagens/sabrina.bmp");
 }
al_flip_display();
al_rest(0.2);

}
void carregarPersonagem(char *personagem){
    ALLEGRO_BITMAP *charSET = al_load_bitmap(personagem);
    al_convert_mask_to_alpha(charSET,al_map_rgb(255,0,255));
    ALLEGRO_BITMAP *personagemCHAR[12];
    int x= LARGURA_TELA/2;
    int y= ALTURA_TELA/2;
    personagemCHAR[0] = al_create_bitmap(32,32);
    personagemCHAR[0] = al_create_sub_bitmap(charSET,  0, 0, 32, 32);
    personagemCHAR[1] = al_create_bitmap(32,32);
    personagemCHAR[1] = al_create_sub_bitmap(charSET,  32, 0, 32, 32);
    personagemCHAR[2] = al_create_bitmap(32,32);
    personagemCHAR[2] = al_create_sub_bitmap(charSET,  64, 0, 32, 32);
    personagemCHAR[3] = al_create_bitmap(32,32);
    personagemCHAR[3] = al_create_sub_bitmap(charSET,  0, 32, 32, 32);
    personagemCHAR[4] = al_create_bitmap(32,32);
    personagemCHAR[4] = al_create_sub_bitmap(charSET,  32, 32, 32, 32);
    personagemCHAR[5] = al_create_bitmap(32,32);
    personagemCHAR[5] = al_create_sub_bitmap(charSET,  64, 32, 32, 32);
    personagemCHAR[6] = al_create_bitmap(32,32);
    personagemCHAR[6] = al_create_sub_bitmap(charSET,  0, 64, 32, 32);
    personagemCHAR[7] = al_create_bitmap(32,32);
    personagemCHAR[7] = al_create_sub_bitmap(charSET,  32, 64, 32, 32);
    personagemCHAR[8] = al_create_bitmap(32,32);
    personagemCHAR[8] = al_create_sub_bitmap(charSET,  64, 64, 32, 32);
    personagemCHAR[9] = al_create_bitmap(32,32);
    personagemCHAR[9] = al_create_sub_bitmap(charSET,  0, 96, 32, 32);
    personagemCHAR[10] = al_create_bitmap(32,32);
    personagemCHAR[10] = al_create_sub_bitmap(charSET,  32, 96, 32, 32);
    personagemCHAR[11] = al_create_bitmap(32,32);
    personagemCHAR[11] = al_create_sub_bitmap(charSET,  64, 96, 32, 32);
    al_draw_bitmap(personagemCHAR[10],x,y,0);
}
