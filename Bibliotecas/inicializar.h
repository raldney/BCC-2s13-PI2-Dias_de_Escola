void iniciar(){
if (!al_init())
    {
        fprintf(stderr, "Falha ao inicializar a Allegro.\n");
    }

    //Inicializando addon pra inserir imagens
     if(!al_init_image_addon())
    {
        fprintf(stderr, "Falha ao iniciar o Add-ON.\n");
    }
 if (!al_install_keyboard())
    {
        fprintf(stderr, "Falha ao inicializar o teclado.\n");

    }
     //Inicializando Codec
    /* if (!al_init_acodec_addon())
    {
        fprintf(stderr, "Falha ao inicializar complemento acodec!\n");

    }
    //Instalando recurso de audio
    if (!al_install_audio())
    {
        fprintf(stderr, "Falha ao instalar audio!\n");

    }
    else
        if (!al_reserve_samples(2))
        {
            fprintf(stderr, "Falha ao reservar samples!\n");

        }*/

}
