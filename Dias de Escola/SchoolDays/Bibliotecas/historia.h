void carregarHistoria()
{
historiaImagem = al_load_bitmap("Imagens/Historia/lousa.bmp");
sabrinaImagem = al_load_bitmap("Imagens/Historia/sabrina1.bmp");
peterImagem = al_load_bitmap("Imagens/Historia/peter1.bmp");
selectCHAR = al_load_bitmap("Imagens/Historia/selecao.bmp");
al_set_target_bitmap(al_get_backbuffer(Display));
al_draw_bitmap(historiaImagem,0,0,0);
sabrinaOption = al_create_bitmap(175,90);
al_draw_bitmap(sabrinaImagem,470,230,0);
peterOption = al_create_bitmap(175,90);
al_draw_bitmap(peterImagem,520,230,0);




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
                sair = true;
                break;
                case ALLEGRO_KEY_RIGHT:
                    if (sexo != 'm')
                        sexo ='m';

                break;
                case ALLEGRO_KEY_LEFT:
                    if (sexo != 'f')
                        sexo = 'f';
                break;
                case ALLEGRO_KEY_ENTER:
                    carregarTexto();
                break;

                    }


            }
        }
    }
    sair=false;
}
void carregarTexto()
{
    ALLEGRO_BITMAP *imagemhistoriaSabrina;
    imagemhistoriaSabrina = al_load_bitmap("Imagens/Historia/imagemhistoriaPeter.bmp");
    al_convert_mask_to_alpha(imagemhistoriaSabrina,al_map_rgb(255,0,255));
    al_draw_bitmap(imagemhistoriaSabrina,0,0,0);
    al_flip_display();
}
