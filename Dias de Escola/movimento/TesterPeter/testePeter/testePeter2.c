#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>



const int LARGURA_TELA = 800;
const int ALTURA_TELA = 600;

ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
ALLEGRO_BITMAP *fundo = NULL,*buffer;
ALLEGRO_FONT *fonte = NULL;
ALLEGRO_TIMER *timer;
bool keys[]={false,false,false,false,false};
enum KEYS{UP,DOWN,RIGHT,LEFT,SELECT};
void peter();
int main(void)
{


    int vMapa = 0;
    int vMatriz_Mapa[21][27],i=0,j=0;
    FILE *fMapa = fopen("dormitorio_masculino.txt", "r"); // Carrega o arquivo de texto da fase em questão;

    char vLe_Char;

    while((vLe_Char = getc(fMapa) ) != EOF )    // Grava Caracter enquanto não chegar ao final do arquivo;
    {
        if ( i < 27 ) // Enquanto estivar na linha;
        {
            vMatriz_Mapa[j][i] = atoi(&vLe_Char); // Carrega a matriz com os caracteres que representam as imagens;
            i++;
        }
        else // senao passa para a proxima linha;
        {
            j++;
            i=0;
        }

    }
    fclose(fMapa);
    for (j=0;j<19;j++){
    for (i=0;i<27;i++){

   // if(vMatriz_Mapa[j/32][i/32]==2){
        printf("%d",vMatriz_Mapa[j][i]);


    }
    printf("\n");
    }
    bool sair = false;
    int tecla = 0,top = 0, left = 0, right = 0, down=0;
    int x=192,y=64;

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

    fundo = al_load_bitmap("dormitorio_masculino.bmp");
    if (!fundo)
    {
        fprintf(stderr, "Falha ao carregar imagem de fundo.\n");
        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);
        return false;
    }

    timer = al_create_timer(6/60.0);
    al_register_event_source(fila_eventos, al_get_timer_event_source(timer));
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_draw_bitmap(fundo, 0, 0, 0);
    ALLEGRO_BITMAP *peterSET = al_load_bitmap("sabrina3.bmp");
    al_convert_mask_to_alpha(peterSET,al_map_rgb(255,0,255));
    ALLEGRO_BITMAP *peterCHAR[12];

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
al_draw_bitmap(fundo, 0, 0, 0);
al_draw_bitmap(peterCHAR[10],x,y,0);
al_flip_display();
    al_start_timer(timer);
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
            }else if (evento.type == ALLEGRO_EVENT_KEY_UP)
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
            else if (evento.type == ALLEGRO_EVENT_TIMER){

  if(keys[SELECT]){
    if(vMatriz_Mapa[y/32][(x+32)/32]==4){
            return 0;
    }
  }
  if (keys[UP]){

if(vMatriz_Mapa[(y-32)/32][x/32]==0){
                al_draw_bitmap(fundo, 0, 0, 0);
                if(top == 0)
                {   y=y-32;
                    al_draw_bitmap(peterCHAR[10],x,y,0);
                    top = 1;
                }
                else if(top == 1)
                {
                    y=y-32;
                    al_draw_bitmap(peterCHAR[9],x,y,0);
                    top=2;
                }
                else if (top == 2)
                {
                    y=y-32;
                    al_draw_bitmap(peterCHAR[11],x,y,0);
                    top =0;
                }

printf("x = %d e y = %d\n",x,y);
                al_flip_display();
  }
  }


  if (keys[DOWN]){
if(vMatriz_Mapa[(y+32)/32][x/32]==0){
                al_draw_bitmap(fundo, 0, 0, 0);
                if(down == 0)
                {   y=y+32;
                    al_draw_bitmap(peterCHAR[1],x,y,0);
                    down = 1;
                }
                else if(down == 1)
                {
                    y=y+32;
                    al_draw_bitmap(peterCHAR[0],x,y,0);
                    down = 2;
                }
                else if (down == 2)
                {
                    y=y+32;
                    al_draw_bitmap(peterCHAR[2],x,y,0);
                    down = 0;
                }
  }
  }

printf("x = %d e y = %d\n",x,y);
                al_flip_display();

                }


            if (keys[LEFT]){

if(vMatriz_Mapa[y/32][(x-32)/32]==0){
                al_draw_bitmap(fundo, 0, 0, 0);
                if(left == 0)
                {   x=x-32;
                    al_draw_bitmap(peterCHAR[4],x,y,0);
                    left = 1;
                }
                else if(left == 1)
                {
                    x=x-32;
                    al_draw_bitmap(peterCHAR[3],x,y,0);
                    left=2;
                }
                else if (left == 2)
                {
                    x=x-32;
                    al_draw_bitmap(peterCHAR[5],x,y,0);
                    left =0;
                }
                al_flip_display();
printf("x = %d e y = %d\n",x,y);
                }
            }


        if (keys[RIGHT]){

if(vMatriz_Mapa[y/32][(x+32)/32]==0){
al_draw_bitmap(fundo, 0, 0, 0);
                if(right == 0)
                {   x=x+32;
                    al_draw_bitmap(peterCHAR[7],x,y,0);
                    right = 1;
                }
                else if(right == 1)
                {
                    x=x+32;
                    al_draw_bitmap(peterCHAR[6],x,y,0);
                    right=2;
                }
                else if (right == 2)
                {
                    x=x+32;
                    al_draw_bitmap(peterCHAR[8],x,y,0);
                    right =0;
                }

printf("x = %d e y = %d\n",x,y);
                al_flip_display();
                }

        }

        }
    }

    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);

    return 0;
}
void peter()
{


}
