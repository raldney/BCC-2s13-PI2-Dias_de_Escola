void moverChar()
{
    timer = al_create_timer(3/60.0);
    al_register_event_source(eventosQueue, al_get_timer_event_source(timer));
    al_register_event_source(eventosQueue, al_get_keyboard_event_source());
    al_register_event_source(eventosQueue, al_get_display_event_source(Display));
    al_start_timer(timer);
    while (!sair)
    {

        while(!al_is_event_queue_empty(eventosQueue))
        {
            al_wait_for_event(eventosQueue, &evento);
            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                switch(evento.keyboard.keycode)
                {
                    case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;

                    case ALLEGRO_KEY_UP:
                    keys[UP] = true;
                    break;

                    case ALLEGRO_KEY_DOWN:
                    keys[DOWN] = true;
                    break;

                    case ALLEGRO_KEY_LEFT:
                    keys[LEFT] = true;
                    break;

                    case ALLEGRO_KEY_RIGHT:
                    keys[RIGHT] = true;
                    break;

                    case ALLEGRO_KEY_SPACE:
                    keys[SELECT]=true;
                    break;
                }
            }
            else if (evento.type == ALLEGRO_EVENT_KEY_UP)
            {
                switch(evento.keyboard.keycode)
                {
                    case ALLEGRO_KEY_UP:
                    keys[UP] = false;
                    break;

                    case ALLEGRO_KEY_DOWN:
                    keys[DOWN] = false;
                    break;

                    case ALLEGRO_KEY_LEFT:
                    keys[LEFT] = false;
                    break;

                    case ALLEGRO_KEY_RIGHT:
                    keys[RIGHT] = false;
                    break;

                    case ALLEGRO_KEY_SPACE:
                    keys[SELECT]=false;
                    break;
                }
            }
            else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
            else if (evento.type == ALLEGRO_EVENT_TIMER)
            {

                if(keys[SELECT])
                {

                    if(tileMap[y/32][(x-32)/32] != 0 && tileMap[y/32][(x-32)/32] != 1 )
                    {
                        printf("%d \n",tileMap[y/32][(x-32)/32]);
                        mapa = tileMap[y/32][(x-32)/32];
                        carregarMapa(mapa);

                    }
                    else if(tileMap[(y-32)/32][(x)/32] != 0 &&   tileMap[(y-32)/32][(x)/32] != 1)
                    {
                        printf("%d \n",tileMap[(y-32)/32][x/32]);
                        mapa = tileMap[(y-32)/32][(x)/32];
                        carregarMapa(mapa);
                    }
                    else if(tileMap[(y+32)/32][(x)/32] != 0 &&   tileMap[(y+32)/32][(x)/32] != 1)
                    {
                        printf("%d \n",tileMap[(y+32)/32][x/32]);
                        mapa = tileMap[(y+32)/32][(x)/32];
                        carregarMapa(mapa);
                    }
                    else if(tileMap[y/32][(x+32)/32] != 0 && tileMap[y/32][(x+32)/32] != 1 )
                    {
                        printf("%d \n",tileMap[y/32][(x+32)/32]);
                        mapa = tileMap[y/32][(x+32)/32];
                        carregarMapa(mapa);

                    }

                }
                if (keys[UP])
                {
                    if(tileMap[(y-32)/32][x/32]==0 && (y-8) <= 600)
                    {
                        carregarMapa(mapa);
                        if(top == 0)
                        {
                            y-=8;
                            al_draw_bitmap(personagemCHAR[10],x,y,0);
                            top = 1;
                        }
                        else if(top == 1)
                        {
                            y-=8;
                            al_draw_bitmap(personagemCHAR[9],x,y,0);
                            top=2;
                        }
                        else if (top == 2)
                        {
                            y-=8;
                            al_draw_bitmap(personagemCHAR[11],x,y,0);
                            top =0;
                        }

                        printf("x = %d e y = %d\n",x,y);
                        al_flip_display();
                    }
                }

                if (keys[DOWN])
                {
                    if(tileMap[(y+32)/32][x/32]==0 && (y+8) >= 0 )
                    {

                        carregarMapa(mapa);

                        if(down == 0)
                        {
                            y+=8;
                            al_draw_bitmap(personagemCHAR[1],x,y,0);
                            down = 1;
                        }
                        else if(down == 1)
                        {
                            y+=8;
                            al_draw_bitmap(personagemCHAR[0],x,y,0);
                            down = 2;
                        }
                        else if (down == 2)
                        {
                            y+=8;
                            al_draw_bitmap(personagemCHAR[2],x,y,0);
                            down = 0;
                        }

                        printf("x = %d e y = %d\n",x,y);
                        al_flip_display();
                    }
                }

                if (keys[LEFT])
                {
                    if(tileMap[y/32][(x-32)/32]==0 && (x-8) >= 0)
                    {
                        carregarMapa(mapa);

                        if(left == 0)
                        {
                            x-=8;
                            al_draw_bitmap(personagemCHAR[4],x,y,0);
                            left = 1;
                        }
                        else if(left == 1)
                        {
                            x-=8;
                            al_draw_bitmap(personagemCHAR[3],x,y,0);
                            left=2;
                        }
                        else if (left == 2)
                        {
                            x-=8;
                            al_draw_bitmap(personagemCHAR[5],x,y,0);
                            left =0;
                        }

                        al_flip_display();
                        printf("x = %d e y = %d\n",x,y);
                    }
                }

                if (keys[RIGHT])
                {
                    if(tileMap[y/32][(x+32)/32]==0 && (x+8) <= 800 )
                    {
                        carregarMapa(mapa);

                        if(right == 0)
                        {
                            x+=8;
                            al_draw_bitmap(personagemCHAR[7],x,y,0);
                            right = 1;
                        }
                        else if(right == 1)
                        {
                            x+=8;
                            al_draw_bitmap(personagemCHAR[6],x,y,0);
                            right=2;
                        }
                        else if (right == 2)
                        {
                            x+=8;
                            al_draw_bitmap(personagemCHAR[8],x,y,0);
                            right =0;
                        }

                            printf("x = %d e y = %d\n",x,y);
                            al_flip_display();
                    }
                }
            }
        }
    }
}
