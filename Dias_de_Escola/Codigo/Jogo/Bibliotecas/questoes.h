void questaoCelula()
{
    concluido = false;
    responder = false;
    fundoDisplay = al_load_bitmap("Imagens/Questoes/celula.bmp");
    fonte = al_load_font("Fontes/Blokletters-Potlood.ttf", 42, 0);

    strcpy(resposta, "");

    al_register_event_source(eventosQueue, al_get_display_event_source(Display));
    al_register_event_source(eventosQueue, al_get_keyboard_event_source());

    while (!responder)
    {
        while (!al_is_event_queue_empty(eventosQueue))
        {

            al_wait_for_event(eventosQueue, &evento);

            if (!concluido)
            {
                lerResposta(evento);

                if (evento.type == ALLEGRO_EVENT_KEY_DOWN && evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {

                    if (resposta[0] == 'c' && resposta[1] == 'r' && resposta[2] == 'o' && resposta[3] == 'm' && resposta[4] == 'o' && resposta[5] == 's' && resposta[6] == 's' && resposta[7] == 'o' && resposta[8] == 'm' && resposta[9] == 'o' && resposta[10] == 's')
                        {
                            concluido = true;
                            responder = true;
                            celula = true;
                            fundoDisplay = al_load_bitmap("Imagens/Questoes/acerto.bmp");
                            al_draw_bitmap(fundoDisplay,0,0,0);
                            al_flip_display();
                            al_rest(2);
                            strcpy(resposta, "");
                        }
                        else
                        {
                            concluido = true;
                            responder = true;
                            fundoDisplay = al_load_bitmap("Imagens/Questoes/erro.bmp");
                            al_draw_bitmap(fundoDisplay,0,0,0);
                            strcpy(resposta, "");
                            al_flip_display();
                            al_rest(2);
                        }
                            fundoDisplay = al_load_bitmap(imagemMapa[mapa]);
                            keys[UP]=false;
                            keys[DOWN]=false;
                            keys[RIGHT]=false;
                            keys[LEFT]=false;
                            keys[SELECT]=false;


                }


            }

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }

        }


        al_draw_bitmap(fundoDisplay, 0, 0, 0);
        mostrarResposta();

        al_flip_display();
    }
}
void questaoCadeia()
{
concluido = false;
                            responder = false;
fundoDisplay = al_load_bitmap("Imagens/Questoes/cadeia-alimentar3.bmp");
     fonte = al_load_font("Fontes/Blokletters-Potlood.ttf", 42, 0);



    strcpy(resposta, "");


   al_register_event_source(eventosQueue, al_get_display_event_source(Display));
    al_register_event_source(eventosQueue, al_get_keyboard_event_source());
    while (!responder)
    {
        while (!al_is_event_queue_empty(eventosQueue))
        {

            al_wait_for_event(eventosQueue, &evento);

            if (!concluido)
            {
                lerResposta(evento);

                if (evento.type == ALLEGRO_EVENT_KEY_DOWN && evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {

                    if (resposta[0] == 'd' || resposta[0] == 'D')
                        {
                            concluido = true;
                            responder = true;
                            cadeia = true;
                            fundoDisplay = al_load_bitmap("Imagens/Questoes/acerto.bmp");
                            al_draw_bitmap(fundoDisplay,0,0,0);
                            strcpy(resposta, "");
                            al_flip_display();
                            al_rest(2);
                        }
                        else
                        {
                            concluido = true;
                            responder = true;
                            fundoDisplay = al_load_bitmap("Imagens/Questoes/erro.bmp");
                            al_draw_bitmap(fundoDisplay,0,0,0);
                            strcpy(resposta, "");
                            al_flip_display();
                            al_rest(2);
                        }
                            fundoDisplay = al_load_bitmap(imagemMapa[mapa]);
                            keys[UP]=false;
                            keys[DOWN]=false;
                            keys[RIGHT]=false;
                            keys[LEFT]=false;
                }
            }

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
        }


        al_draw_bitmap(fundoDisplay, 0, 0, 0);
        mostrarResposta();

        al_flip_display();
    }
}
void questaoBola()
{
concluido = false;
                            responder = false;
fundoDisplay = al_load_bitmap("Imagens/Questoes/bola-de-futebol-.bmp");
     fonte = al_load_font("Fontes/Blokletters-Potlood.ttf", 42, 0);



    strcpy(resposta, "");


   al_register_event_source(eventosQueue, al_get_display_event_source(Display));
    al_register_event_source(eventosQueue, al_get_keyboard_event_source());
    while (!responder)
    {
        while (!al_is_event_queue_empty(eventosQueue))
        {

            al_wait_for_event(eventosQueue, &evento);

            if (!concluido)
            {
                lerResposta(evento);

                if (evento.type == ALLEGRO_EVENT_KEY_DOWN && evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {

                    if (resposta[0] == '1' && resposta[1] == '0'&& resposta[2] == 'm' && resposta[3] == 's')
                        {
                            concluido = true;
                            responder = true;
                            bola = true;
                            fundoDisplay = al_load_bitmap("Imagens/Questoes/acerto.bmp");
                            al_draw_bitmap(fundoDisplay,0,0,0);
                            strcpy(resposta, "");
                            al_flip_display();
                            al_rest(2);
                        }
                        else
                        {
                            concluido = true;
                            responder = true;
                            fundoDisplay = al_load_bitmap("Imagens/Questoes/erro.bmp");
                            al_draw_bitmap(fundoDisplay,0,0,0);
                            strcpy(resposta, "");
                            al_flip_display();
                            al_rest(2);
                        }

                            fundoDisplay = al_load_bitmap(imagemMapa[mapa]);
                            keys[UP]=false;
                            keys[DOWN]=false;
                            keys[RIGHT]=false;
                            keys[LEFT]=false;
                }
            }

            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
        }


        al_draw_bitmap(fundoDisplay, 0, 0, 0);
        mostrarResposta();

        al_flip_display();
    }
}
void questaoTabela()
{
concluido = false;
                            responder = false;
fundoDisplay = al_load_bitmap("Imagens/Questoes/tabela.bmp");
     fonte = al_load_font("Fontes/Blokletters-Potlood.ttf", 42, 0);



    strcpy(resposta, "");


   al_register_event_source(eventosQueue, al_get_display_event_source(Display));
    al_register_event_source(eventosQueue, al_get_keyboard_event_source());
    while (!responder)
    {
        while (!al_is_event_queue_empty(eventosQueue))
        {

            al_wait_for_event(eventosQueue, &evento);

            if (!concluido)
            {
                lerResposta(evento);

                if (evento.type == ALLEGRO_EVENT_KEY_DOWN && evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {

                    if (resposta[0] == 'c' || resposta[0] == 'C')
                        {
                            concluido = true;
                            responder = true;
                            tabela = true;
                            fundoDisplay = al_load_bitmap("Imagens/Questoes/acerto.bmp");
                            al_draw_bitmap(fundoDisplay,0,0,0);
                            strcpy(resposta, "");
                            al_flip_display();
                            al_rest(2);
                        }
                        else
                        {
                            concluido = true;
                            responder = true;
                            fundoDisplay = al_load_bitmap("Imagens/Questoes/erro.bmp");
                            al_draw_bitmap(fundoDisplay,0,0,0);
                            strcpy(resposta, "");
                            al_flip_display();
                            al_rest(2);
                        }
                            fundoDisplay = al_load_bitmap(imagemMapa[mapa]);
                            keys[UP]=false;
                            keys[DOWN]=false;
                            keys[RIGHT]=false;
                            keys[LEFT]=false;
                }
            }


        }


        al_draw_bitmap(fundoDisplay, 0, 0, 0);
        mostrarResposta();

        al_flip_display();
}
}
void questaoEstado()
{
    concluido = false;
    responder = false;
    fundoDisplay = al_load_bitmap("Imagens/Questoes/estados.bmp");
    fonte = al_load_font("Fontes/Blokletters-Potlood.ttf", 42, 0);



    strcpy(resposta, "");


    al_register_event_source(eventosQueue, al_get_display_event_source(Display));
    al_register_event_source(eventosQueue, al_get_keyboard_event_source());
    while (!responder)
    {
        while (!al_is_event_queue_empty(eventosQueue))
        {

            al_wait_for_event(eventosQueue, &evento);

            if (!concluido)
            {
                lerResposta(evento);

                if (evento.type == ALLEGRO_EVENT_KEY_DOWN && evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {

                    if (resposta[0] == 's' && resposta[1] == 'u' && resposta[2] == 'b' && resposta[3] == 'l' && resposta[4] == 'i' && resposta[5] == 'm' && resposta[6] == 'a' && resposta[7] == 'c' && resposta[8] == 'a' && resposta[9] == 'o')
                        {
                            concluido = true;
                            responder = true;
                            estado = true;
                            fundoDisplay = al_load_bitmap("Imagens/Questoes/acerto.bmp");
                            al_draw_bitmap(fundoDisplay,0,0,0);
                            strcpy(resposta, "");
                            al_flip_display();
                            al_rest(2);
                        }
                        else
                        {
                            concluido = true;
                            responder = true;
                            fundoDisplay = al_load_bitmap("Imagens/Questoes/erro.bmp");
                            al_draw_bitmap(fundoDisplay,0,0,0);
                            strcpy(resposta, "");
                            al_flip_display();
                            al_rest(2);
                        }
                            fundoDisplay = al_load_bitmap(imagemMapa[mapa]);
                            keys[UP]=false;
                            keys[DOWN]=false;
                            keys[RIGHT]=false;
                            keys[LEFT]=false;
                }
            }


        }


        al_draw_bitmap(fundoDisplay, 0, 0, 0);
        mostrarResposta();

        al_flip_display();
}
}
void questaoCircuito()
{
        concluido = false;
        responder = false;
        fundoDisplay = al_load_bitmap("Imagens/Questoes/circuito.bmp");
        fonte = al_load_font("Fontes/Blokletters-Potlood.ttf", 42, 0);



        strcpy(resposta, "");


        al_register_event_source(eventosQueue, al_get_display_event_source(Display));
        al_register_event_source(eventosQueue, al_get_keyboard_event_source());
        while (!responder)
        {
            while (!al_is_event_queue_empty(eventosQueue))
           {

               al_wait_for_event(eventosQueue, &evento);

               if (!concluido)
               {
                    lerResposta(evento);

                    if (evento.type == ALLEGRO_EVENT_KEY_DOWN && evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                    {

                        if (resposta[0] == 'e' || resposta[0] == 'E')
                        {
                             concluido = true;
                             responder = true;
                             circuito = true;
                             fundoDisplay = al_load_bitmap("Imagens/Questoes/acerto.bmp");
                             al_draw_bitmap(fundoDisplay,0,0,0);
                             strcpy(resposta, "");
                             al_flip_display();
                             al_rest(2);
                        }
                        else
                        {
                            concluido = true;
                            responder = true;
                            fundoDisplay = al_load_bitmap("Imagens/Questoes/erro.bmp");
                            al_draw_bitmap(fundoDisplay,0,0,0);
                            strcpy(resposta, "");
                            al_flip_display();
                            al_rest(2);

                        }
                            fundoDisplay = al_load_bitmap(imagemMapa[mapa]);
                            keys[UP]=false;
                            keys[DOWN]=false;
                            keys[RIGHT]=false;
                            keys[LEFT]=false;
                }
            }


        }


        al_draw_bitmap(fundoDisplay, 0, 0, 0);
        mostrarResposta();

        al_flip_display();
}
}

void questaoPiramide()
{
   concluido = false;
   responder = false;
   fundoDisplay = al_load_bitmap("Imagens/Questoes/piramide.bmp");
   fonte = al_load_font("Fontes/Blokletters-Potlood.ttf", 42, 0);
   strcpy(resposta,"");

   al_register_event_source(eventosQueue, al_get_display_event_source(Display));
   al_register_event_source(eventosQueue, al_get_keyboard_event_source());

   while(!concluido)
   {
      while(!al_is_event_queue_empty(eventosQueue))
      {
         al_wait_for_event(eventosQueue, &evento);
         if(!concluido)
         {
             lerResposta(evento);

             if(evento.type == ALLEGRO_EVENT_KEY_DOWN && evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
             {
                if (resposta[0] == 'c' || resposta[0] == 'C')
                        {
                            concluido = true;
                            responder = true;
                            piramide=true;
                            fundoDisplay = al_load_bitmap("Imagens/Questoes/acerto.bmp");
                            al_draw_bitmap(fundoDisplay,0,0,0);
                            strcpy(resposta, "");
                            al_flip_display();
                            al_rest(2);
                        }
                        else
                        {
                            concluido = true;
                            responder = true;
                            fundoDisplay = al_load_bitmap("Imagens/Questoes/erro.bmp");
                            al_draw_bitmap(fundoDisplay,0,0,0);
                            strcpy(resposta, "");
                            al_flip_display();
                            al_rest(2);

                        }
                            fundoDisplay = al_load_bitmap(imagemMapa[mapa]);
                            keys[UP]=false;
                            keys[DOWN]=false;
                            keys[RIGHT]=false;
                            keys[LEFT]=false;

             }
         }
      }


      al_draw_bitmap(fundoDisplay, 0, 0, 0);
      mostrarResposta();

      al_flip_display();
   }

}
void questaoFotossintese()
{
concluido = false;
                            responder = false;

fundoDisplay = al_load_bitmap("Imagens/Questoes/fotossintese.bmp");
     fonte = al_load_font("Fontes/Blokletters-Potlood.ttf", 42, 0);



    strcpy(resposta, "");


   al_register_event_source(eventosQueue, al_get_display_event_source(Display));
    al_register_event_source(eventosQueue, al_get_keyboard_event_source());
    while (!concluido)
    {
        while (!al_is_event_queue_empty(eventosQueue))
        {

            al_wait_for_event(eventosQueue, &evento);

            if (!concluido)
            {
                lerResposta(evento);

                if (evento.type == ALLEGRO_EVENT_KEY_DOWN && evento.keyboard.keycode == ALLEGRO_KEY_ENTER)
                {

                    if (resposta[0] == 'e' || resposta[0] == 'E')
                        {
                            concluido = true;
                            responder = true;
                            fotossintese=true;
                            fundoDisplay = al_load_bitmap("Imagens/Questoes/acerto.bmp");
                            al_draw_bitmap(fundoDisplay,0,0,0);
                            strcpy(resposta, "");
                            al_flip_display();
                            al_rest(2);
                        }else
                        {
                            concluido = true;
                            responder = true;
                            fundoDisplay = al_load_bitmap("Imagens/Questoes/erro.bmp");
                            al_draw_bitmap(fundoDisplay,0,0,0);
                            strcpy(resposta, "");
                            al_flip_display();
                            al_rest(2);
                        }
                            fundoDisplay = al_load_bitmap(imagemMapa[mapa]);
                            keys[UP]=false;
                            keys[DOWN]=false;
                            keys[RIGHT]=false;
                            keys[LEFT]=false;
                }
            }


        }


        al_draw_bitmap(fundoDisplay, 0, 0, 0);
        mostrarResposta();

        al_flip_display();
    }
}
void lerResposta(ALLEGRO_EVENT tecla)
{
    if (tecla.type == ALLEGRO_EVENT_KEY_CHAR)
    {
        if (strlen(resposta) <= 16)
        {
            char temp[] = {tecla.keyboard.unichar, '\0'};
            if (tecla.keyboard.unichar == ' ')
            {
                strcat(resposta, temp);
            }
            else if (tecla.keyboard.unichar >= '0' &&
                     tecla.keyboard.unichar <= '9')
            {
                strcat(resposta, temp);
            }
            else if (tecla.keyboard.unichar >= 'A' &&
                     tecla.keyboard.unichar <= 'Z')
            {
                strcat(resposta, temp);
            }
            else if (tecla.keyboard.unichar >= 'a' &&
                     tecla.keyboard.unichar <= 'z')
            {
                strcat(resposta, temp);
            }
        }

        if (tecla.keyboard.keycode == ALLEGRO_KEY_BACKSPACE && strlen(resposta) != 0)
        {
            resposta[strlen(resposta) - 1] = '\0';
        }
    }
}

void mostrarResposta()
{

    if (strlen(resposta) > 0)
    {
        al_draw_text(fonte, al_map_rgb(255, 255, 255), 580,
                     (700 - al_get_font_ascent(fonte)) / 2,
                     ALLEGRO_ALIGN_CENTRE, resposta);
    }
}
