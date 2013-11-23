void carregarMenu()
{
Display = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!Display)
    {
        fprintf(stderr, "Falha ao criar janela.\n");
    }

/*
    inicialSound = al_create_sample_instance(al_load_sample("Musicas/musicaMenu.ogg"));
    if (inicialSound)
    {
        al_set_sample_instance_playmode(inicialSound, ALLEGRO_PLAYMODE_ONCE);
        al_attach_sample_instance_to_mixer(inicialSound, al_get_default_mixer());
        al_set_sample_instance_gain(inicialSound, 0.5);
        al_play_sample_instance(inicialSound);
    }
    else fprintf(stderr, "Falha ao carregar musica do menu!\n");*/
    //Criando o Fundo
    fundoDisplay = al_load_bitmap("Imagens/Menu/sala.bmp");
    if(!fundoDisplay)
    {

        fprintf(stderr,"Falha ao carregar a imagem Sala");

    }



    // Configura o título da janela
    al_set_window_title(Display,"Scholl Days");


    // Alocamos o retângulo central da tela
    iniciarMenu = al_create_bitmap(250, 60);
    if (!iniciarMenu)
    {
        fprintf(stderr, "Falha ao criar bitmap.\n");
        al_destroy_display(Display);

    }


    // Alocamos o botão para fechar a aplicação
    sairMenu = al_create_bitmap(130, 55);
    if (!sairMenu)
    {
        fprintf(stderr, "Falha ao criar botão de saída.\n");
        al_destroy_display(Display);

    }

    //Criando fila de eventos
    eventosQueue = al_create_event_queue();
    if (!eventosQueue)
    {
        fprintf(stderr, "Falha ao inicializar o fila de eventos.\n");
        al_destroy_display(Display);

    }


    al_register_event_source(eventosQueue, al_get_keyboard_event_source());
    al_register_event_source(eventosQueue, al_get_display_event_source(Display));
        // Condição indicando se o mouse está sobre o retângulo central

    while (!sair)
    {
        // Verificamos se há eventos na fila
        while (!al_is_event_queue_empty(eventosQueue))
        {

            al_wait_for_event(eventosQueue, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {

                switch(evento.keyboard.keycode)
                {
                case ALLEGRO_KEY_UP:
                    if(continuarOption == 1){
                        iniciarOption =1;
                        continuarOption = 0;
                    }else if(sairOption==1){
                    continuarOption =1;
                    sairOption=0;
                    }

                    break;
                case ALLEGRO_KEY_DOWN:
                      if(iniciarOption == 1){
                        iniciarOption =0;
                        continuarOption = 1;
                    }else if(continuarOption==1){
                    continuarOption =0;
                    sairOption=1;
                    }
                    break;
                case ALLEGRO_KEY_ENTER:
                    if(sairOption==1){
                        fecharJogo();
                    }else
                     if(iniciarOption==1){
                    sair= true;
                    al_rest(1);
                     }
                    break;
                        }

            }


        }

    //al_set_target_bitmap(iniciarMenu);
    if (!iniciarOption)
    {
        iniciarMenu = al_load_bitmap("Imagens/Menu/iniciar.bmp");
        if(!iniciarMenu)
        {
            fprintf(stderr,"Falha ao carregar a imagem Iniciar1");

        }
    }
    else
    {
        iniciarMenu = al_load_bitmap("Imagens/Menu/iniciar2.bmp");
        if(!iniciarMenu)
        {
            fprintf(stderr,"Falha ao carregar a imagem Iniciar2");

        }
    }
     // al_set_target_bitmap(continuarMenu);
    if (!continuarOption)
    {
        continuarMenu = al_load_bitmap("Imagens/Menu/continuar1.bmp");
        if(!continuarMenu)
        {
            fprintf(stderr,"Falha ao carregar a imagem Continuar1");

        }
    }
    else
    {
        continuarMenu = al_load_bitmap("Imagens/Menu/continuar2.bmp");
        if(!continuarMenu)
        {
            fprintf(stderr,"Falha ao carregar a imagem Sair2");

        }
    }
  //  al_set_target_bitmap(sairMenu);
    if (!sairOption)
    {
        sairMenu = al_load_bitmap("Imagens/Menu/sair1.bmp");
        if(!sairMenu)
        {
            fprintf(stderr,"Falha ao carregar a imagem Sair1");

        }
    }
    else
    {
        sairMenu = al_load_bitmap("Imagens/Menu/sair2.bmp");
        if(!sairMenu)
        {
            fprintf(stderr,"Falha ao carregar a imagem Sair2");

        }

    }
    // Desenhamos os retângulos na tela
    al_set_target_bitmap(al_get_backbuffer(Display));
    al_draw_bitmap(fundoDisplay,0,0,0);
    al_draw_bitmap(iniciarMenu,300 ,170 , 0);
    al_draw_bitmap(continuarMenu, 290,250,0);
    al_draw_bitmap(sairMenu,360,320,0);
    // Atualiza a tela
    al_flip_display();

    }

}
