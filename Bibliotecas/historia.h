void carregarHistoria()
{
historiaImagem = al_load_bitmap("Imagens/lousa.bmp");
al_set_target_bitmap(al_get_backbuffer(menuDisplay));
al_draw_bitmap(historiaImagem,0,0,0);
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
                    }


            }
        }
    }
}
