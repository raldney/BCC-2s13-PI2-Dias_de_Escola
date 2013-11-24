#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>				//Our primitive header file
#include <allegro5/allegro_image.h>
#include <stdio.h>
#define CIMA 1
#define BAIXO 2
#define DIREITA 3
#define ESQUERDA 4
void movimento();

enum KEYS{ UP, DOWN, LEFT, RIGHT};
	int width = 800;
	int height = 600;


	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
int main()
{


	al_init();


	display = al_create_display(width, height);
    al_init_primitives_addon();
	al_install_keyboard();
	al_init_image_addon();
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));


	/*****************************************************/

ALLEGRO_BITMAP *fundo;
    fundo = al_load_bitmap("biblioteca.bmp");
    al_set_target_bitmap(al_get_backbuffer(display));



al_draw_bitmap(fundo,0,0,0);
al_flip_display();
movimento();



	return 0;
}

void movimento()
 {
	bool done = false;
	bool keys[4] = {false, false, false, false};
ALLEGRO_BITMAP *sabrinaSET = al_load_bitmap("sabrina.bmp");
ALLEGRO_BITMAP *sabrinaCHAR[12];
FILE *fMapa = fopen("biblioteca_refeitorio.txt", "r");
char vLe_Char;
int vMatriz_Mapa[25][19];
int vMapa = 0;
int aux_x=0;
int aux_y=0;
int top = 0, left = 0, right = 0, down=0;
int x =width/2;
int y =height/2;
int tecla;
       // Grava Caracter enquanto não chegar ao final do arquivo;

    for(aux_x=0;aux_x<25;aux_x++){
        for(aux_y=0;aux_y<21;aux_y++ ){
    vLe_Char = getc(fMapa);
    vMatriz_Mapa[aux_x][aux_y] = atoi(&vLe_Char);
  //  printf("%d",vMatriz_Mapa[aux_x][aux_y]);
    }
    }




sabrinaCHAR[0] = al_create_bitmap(32,32);
sabrinaCHAR[0] = al_create_sub_bitmap(sabrinaSET,  0, 0, 32, 32);
sabrinaCHAR[1] = al_create_bitmap(32,32);
sabrinaCHAR[1] = al_create_sub_bitmap(sabrinaSET,  32, 0, 32, 32);
sabrinaCHAR[2] = al_create_bitmap(32,32);
sabrinaCHAR[2] = al_create_sub_bitmap(sabrinaSET,  64, 0, 32, 32);
sabrinaCHAR[3] = al_create_bitmap(32,32);
sabrinaCHAR[3] = al_create_sub_bitmap(sabrinaSET,  0, 32, 32, 32);
sabrinaCHAR[4] = al_create_bitmap(32,32);
sabrinaCHAR[4] = al_create_sub_bitmap(sabrinaSET,  32, 32, 32, 32);
sabrinaCHAR[5] = al_create_bitmap(32,32);
sabrinaCHAR[5] = al_create_sub_bitmap(sabrinaSET,  64, 32, 32, 32);
sabrinaCHAR[6] = al_create_bitmap(32,32);
sabrinaCHAR[6] = al_create_sub_bitmap(sabrinaSET,  0, 64, 32, 32);
sabrinaCHAR[7] = al_create_bitmap(32,32);
sabrinaCHAR[7] = al_create_sub_bitmap(sabrinaSET,  32, 64, 32, 32);
sabrinaCHAR[8] = al_create_bitmap(32,32);
sabrinaCHAR[8] = al_create_sub_bitmap(sabrinaSET,  64, 64, 32, 32);
sabrinaCHAR[9] = al_create_bitmap(32,32);
sabrinaCHAR[9] = al_create_sub_bitmap(sabrinaSET,  0, 96, 32, 32);
sabrinaCHAR[10] = al_create_bitmap(32,32);
sabrinaCHAR[10] = al_create_sub_bitmap(sabrinaSET,  32, 96, 32, 32);
sabrinaCHAR[11] = al_create_bitmap(32,32);
sabrinaCHAR[11] = al_create_sub_bitmap(sabrinaSET,  64, 96, 32, 32);

while(!done)
	{
	ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch(ev.keyboard.keycode)
			{
				case ALLEGRO_KEY_UP:
				tecla = CIMA;
					keys[UP] = true;
					break;
				case ALLEGRO_KEY_DOWN:
				tecla = BAIXO;
					keys[DOWN] = true;
					break;
				case ALLEGRO_KEY_RIGHT:
				tecla = DIREITA;
					keys[RIGHT] = true;
					break;
				case ALLEGRO_KEY_LEFT:
				tecla = ESQUERDA;
					keys[LEFT] = true;
					break;
			}
		}
		else if(ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch(ev.keyboard.keycode)
			{
				case ALLEGRO_KEY_UP:
					keys[UP] = false;
					break;
				case ALLEGRO_KEY_DOWN:
					keys[DOWN] = false;
					break;
				case ALLEGRO_KEY_RIGHT:
					keys[RIGHT] = false;
					break;
				case ALLEGRO_KEY_LEFT:
					keys[LEFT] = false;
					break;
				case ALLEGRO_KEY_ESCAPE:
					done = true;
					break;
			}
		}
		else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}


/*while ( vMatriz_Mapa[(y - keys[UP] * 5)][x] == 0 || vMatriz_Mapa[ (y + keys[DOWN] *5)][x] == 0 || vMatriz_Mapa[y][(x - keys[LEFT] * 5)] == 0 || vMatriz_Mapa[y][(x + keys[RIGHT] * 0)] == 1 ){
        y -= keys[UP] * 5;
        y += keys[DOWN] *5;
        x -= keys[LEFT] * 5;
        x += keys[RIGHT] * 5;
*/
        switch (tecla)
            {
            case CIMA:
                if(top == 0)
                {
                al_draw_bitmap(sabrinaCHAR[10],x,y,0);
                top = 1;
                }
                else if(top == 1)
                {

                al_draw_bitmap(sabrinaCHAR[9],x,y,0);
                top=2;
                }
                else if (top == 2)
                {
                al_draw_bitmap(sabrinaCHAR[11],x,y,0);
                top =0;
                }

                al_flip_display();

            break;
            case BAIXO:
              if(down == 0)
                {
                    al_draw_bitmap(sabrinaCHAR[1],x,y,0);
                    down = 1;
                }
                else if(down == 1)
                {
                    al_draw_bitmap(sabrinaCHAR[0],x,y,0);
                    down = 2;
                }
                else if (down == 2)
                {
                    al_draw_bitmap(sabrinaCHAR[2],x,y,0);
                    down = 0;
                }
                al_flip_display();
            break;
            case DIREITA:
               if(right == 0)
                {
                    al_draw_bitmap(sabrinaCHAR[7],x,y,0);
                    right = 1;
                }
                else if(right == 1)
                {
                    al_draw_bitmap(sabrinaCHAR[6],x,y,0);
                right=2;
                }
                else if (right == 2)
                {
                    al_draw_bitmap(sabrinaCHAR[8],x,y,0);
                    right =0;
                }
                al_flip_display();
            break;
            case ESQUERDA:
               if(left == 0)
                {
                    al_draw_bitmap(sabrinaCHAR[4],x,y,0);
                    left = 1;
                }
                else if(left == 1)
                {

                    al_draw_bitmap(sabrinaCHAR[3],x,y,0);
                    left=2;
                }
                else if (left == 2)
                {
                    al_draw_bitmap(sabrinaCHAR[5],x,y,0);
                    left =0;
                }
                al_flip_display();
            break;
            }
            al_flip_display();
}            }




