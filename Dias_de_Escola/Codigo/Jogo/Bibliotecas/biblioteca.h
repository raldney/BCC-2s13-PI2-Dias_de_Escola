void livros()
{
    bool fechar= false;
    fundoDisplay = al_load_bitmap("Imagens/Biblioteca/livros.bmp");
    al_draw_bitmap(fundoDisplay,0,0,0);
    marcaLivro = al_create_bitmap(50,50);
    marcaLivro = al_load_bitmap("Imagens/Biblioteca/marca.bmp");
    al_convert_mask_to_alpha(marcaLivro,al_map_rgb(0,0,0));
    al_draw_bitmap(marcaLivro,matX,matY,0);
    al_flip_display();
    while (!fechar)
    {

        while (!al_is_event_queue_empty(eventosQueue))
        {

            al_wait_for_event(eventosQueue, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {

                switch(evento.keyboard.keycode)
                {
                case ALLEGRO_KEY_UP:
                    if(livro > 0 && telaLivro ==false)
                    {
                        livro--;

                        matY-=40;
                        al_draw_bitmap(fundoDisplay,0,0,0);
                        al_draw_bitmap(marcaLivro,matX,matY,0);
                        al_flip_display();
                    }




                break;
                case ALLEGRO_KEY_DOWN:
                    if(livro < 4 && telaLivro ==false)
                    {
                      matY+=40;
                      livro++;
                      al_draw_bitmap(fundoDisplay,0,0,0);
                      al_draw_bitmap(marcaLivro,matX,matY,0);
                      al_flip_display();
                    }




                break;
                case ALLEGRO_KEY_ENTER:
                mostrarLivro();

                break;
                case ALLEGRO_KEY_BACKSPACE:
                    if (!telaLivro)
                    {

                        fundoDisplay = al_load_bitmap("Imagens/Biblioteca/livros.bmp");
                        //al_draw_bimap(marcaLivro,matX,matY,0);
                        al_draw_bitmap(fundoDisplay,0,0,0);
                        al_flip_display();
                    }
                break;
                case ALLEGRO_KEY_TAB:
                fundoDisplay = al_load_bitmap(imagemMapa[mapa]);
                al_draw_bitmap(fundoDisplay, 0, 0, 0);
                al_draw_bitmap(personagemCHAR[1],x,y,0);
                al_flip_display();
                keys[UP]=false;
                keys[DOWN]=false;
                keys[RIGHT]=false;
                keys[LEFT]=false;
                keys[SELECT]=false;
                fechar = true;
                break;

                }
            }

        }
    }
}

void mostrarLivro()
{
    fundoDisplay = al_load_bitmap(livrosBiblioteca[livro]);
    al_draw_bitmap(fundoDisplay,0,0,0);
    al_flip_display();

}
