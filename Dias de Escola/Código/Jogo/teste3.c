#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "Bibliotecas/variaveis.h"
#include "Bibliotecas/inicializar.h"






void lerResposta(ALLEGRO_EVENT tecla);
void mostrarResposta();

int main(void)
{
    bool sair = false;
    bool concluido = false;

    iniciar();

    Display = al_create_display(LARGURA_TELA, ALTURA_TELA);
if (!Display)
    {
        fprintf(stderr, "Falha ao criar a janela.\n");
        return false;
    }
     fundoDisplay = al_load_bitmap("Imagens/Questoes/cadeia-alimentar.bmp");
     fonte = al_load_font("Fontes/Blokletters-Potlood.ttf", 42, 0);



    strcpy(resposta, "");
    eventosQueue = al_create_event_queue();

   al_register_event_source(eventosQueue, al_get_display_event_source(Display));
    al_register_event_source(eventosQueue, al_get_keyboard_event_source());
    while (!sair)
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
                       return 0;
                        }
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



    return 0;
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
