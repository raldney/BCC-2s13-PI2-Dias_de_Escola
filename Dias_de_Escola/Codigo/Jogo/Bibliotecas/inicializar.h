void iniciar(){
if (!al_init())
    {
        fprintf(stderr, "Falha ao inicializar a Allegro.\n");
    }


    if (!al_init_image_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on allegro_image.\n");

    }

    //Inicializando addon pra inserir imagens

 if (!al_install_keyboard())
    {
        fprintf(stderr, "Falha ao inicializar o teclado.\n");

    }
al_init_font_addon();


    if (!al_init_ttf_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on allegro_ttf.\n");

    }


}
