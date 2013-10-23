#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include "colisao.h"


const int LARGURA_TELA = 800;
const int ALTURA_TELA = 600;

ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
ALLEGRO_BITMAP *fundo = NULL,*buffer;
ALLEGRO_FONT *fonte = NULL;



int main(void)
{
    bool sair = false;
    int tecla = 0,top = 0, left = 0, right = 0, down=0;
    int x=LARGURA_TELA/2,y=ALTURA_TELA/2;

    if (!al_init())
    {
        fprintf(stderr, "Falha ao inicializar a Allegro.\n");
        return false;
    }

    al_init_font_addon();

    if (!al_init_ttf_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on allegro_ttf.\n");
        return false;
    }

    if (!al_init_image_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on allegro_image.\n");
        return false;
    }

    if (!al_install_keyboard())
    {
        fprintf(stderr, "Falha ao inicializar o teclado.\n");
        return false;
    }

    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela)
    {
        fprintf(stderr, "Falha ao criar janela.\n");
        return false;
    }

    al_set_window_title(janela, "Utilizando o Teclado");


    fila_eventos = al_create_event_queue();
    if (!fila_eventos)
    {
        fprintf(stderr, "Falha ao criar fila de eventos.\n");
        al_destroy_display(janela);
        return false;
    }

    fundo = al_load_bitmap("salas.jpg");
    if (!fundo)
    {
        fprintf(stderr, "Falha ao carregar imagem de fundo.\n");
        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);
        return false;
    }

    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));


    al_draw_bitmap(fundo, 0, 0, 0);
 ALLEGRO_BITMAP *peterSET = al_load_bitmap("peter.png");
BITMAP *peterCHAR[12];

peterCHAR[0] = al_create_bitmap(32,32);
peterCHAR[0] = al_create_sub_bitmap(peterSET,  0, 0, 32, 32);
peterCHAR[1] = al_create_bitmap(32,32);
peterCHAR[1] = al_create_sub_bitmap(peterSET,  32, 0, 32, 32);
peterCHAR[2] = al_create_bitmap(32,32);
peterCHAR[2] = al_create_sub_bitmap(peterSET,  64, 0, 32, 32);
peterCHAR[3] = al_create_bitmap(32,32);
peterCHAR[3] = al_create_sub_bitmap(peterSET,  0, 32, 32, 32);
peterCHAR[4] = al_create_bitmap(32,32);
peterCHAR[4] = al_create_sub_bitmap(peterSET,  32, 32, 32, 32);
peterCHAR[5] = al_create_bitmap(32,32);
peterCHAR[5] = al_create_sub_bitmap(peterSET,  64, 32, 32, 32);
peterCHAR[6] = al_create_bitmap(32,32);
peterCHAR[6] = al_create_sub_bitmap(peterSET,  0, 64, 32, 32);
peterCHAR[7] = al_create_bitmap(32,32);
peterCHAR[7] = al_create_sub_bitmap(peterSET,  32, 64, 32, 32);
peterCHAR[8] = al_create_bitmap(32,32);
peterCHAR[8] = al_create_sub_bitmap(peterSET,  64, 64, 32, 32);
peterCHAR[9] = al_create_bitmap(32,32);
peterCHAR[9] = al_create_sub_bitmap(peterSET,  0, 96, 32, 32);
peterCHAR[10] = al_create_bitmap(32,32);
peterCHAR[10] = al_create_sub_bitmap(peterSET,  32, 96, 32, 32);
peterCHAR[11] = al_create_bitmap(32,32);
peterCHAR[11] = al_create_sub_bitmap(peterSET,  64, 96, 32, 32);
    while (!sair)
    {
        while(!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                switch(evento.keyboard.keycode)
                {
                case ALLEGRO_KEY_UP:
                    tecla = 1;
                    break;
                case ALLEGRO_KEY_DOWN:
                    tecla = 2;
                    break;
                case ALLEGRO_KEY_LEFT:/*
                 */tecla = 3;
                    break;
                case ALLEGRO_KEY_RIGHT:
                    tecla = 4;
                    break;
                }
            }
            else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
        }

        if (tecla)
        {
            al_draw_bitmap(fundo, 0, 0, 0);

            switch (tecla)
            {
            case 1:
                if(pode_ir_para(x,y-15) == 0 ){
                if(top == 0)
                {   y=y-15;
                    al_draw_bitmap(peterCHAR[10],x,y,0);
                    top = 1;
                }
                else if(top == 1)
                {
                y=y-15;
                    al_draw_bitmap(peterCHAR[9],x,y,0);
                top=2;
                }
                else if (top == 2)
                {
                    y=y-15;
                    al_draw_bitmap(peterCHAR[11],x,y,0);
                    top =0;
                }
                }
                al_flip_display();
                break;
            case 2:
                if(pode_ir_para(x,y+15) == 0 ){
                 if(down == 0)
                {   y=y+15;
                    al_draw_bitmap(peterCHAR[1],x,y,0);
                    down = 1;
                }
                else if(down == 1)
                {
                y=y+15;
                    al_draw_bitmap(peterCHAR[0],x,y,0);
                down = 2;
                }
                else if (down == 2)
                {
                    y=y+15;
                    al_draw_bitmap(peterCHAR[2],x,y,0);
                    down = 0;
                }
                al_flip_display();
                }break;
            case 3:
                if(pode_ir_para(x-15,y) == 0 ){
                if(left == 0)
                {   x=x-15;
                    al_draw_bitmap(peterCHAR[4],x,y,0);
                    left = 1;
                }
                else if(left == 1)
                {
                x=x-15;
                    al_draw_bitmap(peterCHAR[3],x,y,0);
                left=2;
                }
                else if (left == 2)
                {
                    x=x-15;
                    al_draw_bitmap(peterCHAR[5],x,y,0);
                    left =0;
                }
                }
                al_flip_display();



                break;
            case 4:
                if(pode_ir_para(x+15,y) == 0 ){
                if(right == 0)
                {   x=x+15;
                    al_draw_bitmap(peterCHAR[7],x,y,0);
                    right = 1;
                }
                else if(right == 1)
                {
                x=x+15;
                    al_draw_bitmap(peterCHAR[6],x,y,0);
                right=2;
                }
                else if (right == 2)
                {
                    x=x+15;
                    al_draw_bitmap(peterCHAR[8],x,y,0);
                    right =0;
                }
                }
                al_flip_display();
                break;
                }

            tecla = 0;
        }

        al_flip_display();
    }

    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);

    return 0;
}
