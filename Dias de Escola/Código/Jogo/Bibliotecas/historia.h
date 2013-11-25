void carregarHistoria()
{
    historiaImagem = al_load_bitmap("Imagens/Historia/lousa.bmp");
    sabrinaImagem = al_load_bitmap("Imagens/Historia/sabrina1.bmp");
    peterImagem = al_load_bitmap("Imagens/Historia/peter1.bmp");
    al_set_target_bitmap(al_get_backbuffer(Display));
    al_draw_bitmap(historiaImagem,0,0,0);
    sabrinaImagem = al_load_bitmap("Imagens/Historia/sabrina1.bmp");
    peterImagem = al_load_bitmap("Imagens/Historia/peter1.bmp");
    al_draw_bitmap(sabrinaImagem,200,230,0);
    al_draw_bitmap(peterImagem,400,230,0);
    al_flip_display();

    sair = false;
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
                case ALLEGRO_KEY_SPACE:
                    if (escolha)
                        sair= true;
                break;
                case ALLEGRO_KEY_RIGHT:
                    if (!escolha)
                        if (sexo != 'm')
                        {
                            sexo ='m';
                            sabrinaImagem = al_load_bitmap("Imagens/Historia/sabrina1.bmp");
                            peterImagem = al_load_bitmap("Imagens/Historia/peter2.bmp");
                            al_draw_bitmap(sabrinaImagem,200,230,0);
                            al_draw_bitmap(peterImagem,400,230,0);
                            al_flip_display();
                        }
                break;
                case ALLEGRO_KEY_LEFT:
                    if (!escolha)
                        if (sexo != 'f')
                        {
                            sexo = 'f';
                            sabrinaImagem = al_load_bitmap("Imagens/Historia/sabrina2.bmp");
                            peterImagem = al_load_bitmap("Imagens/Historia/peter1.bmp");
                            al_draw_bitmap(sabrinaImagem,200,230,0);
                            al_draw_bitmap(peterImagem,400,230,0);
                            al_flip_display();
                        }
                break;
                case ALLEGRO_KEY_ENTER:
                    if (!escolha)
                    {
                        escolha = true;
                        if (sexo == 'f')
                        {
                            mapa = 0;
                            carregarTexto("Imagens/Historia/sabrinaHistoria.bmp");
                        }
                        else if (sexo == 'm')
                        {
                            mapa = 1;
                            carregarTexto("Imagens/Historia/peterHistoria.bmp");
                        }
                    }
                break;

                    }


            }
        }
    }
    sair=false;
}
void carregarTexto(char *historia)
{

    personagemHistoria = al_load_bitmap(historia);
    al_convert_mask_to_alpha(personagemHistoria,al_map_rgb(255,255,255));
    al_draw_bitmap(personagemHistoria,0,0,0);
    al_flip_display();

}

