#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
const int LARGURA_TELA = 800;
const int ALTURA_TELA = 600;

int main(void)
{
    ALLEGRO_DISPLAY *janelaDisplay;
    ALLEGRO_EVENT_QUEUE *eventosQueue;
    ALLEGRO_BITMAP *sairMenu, *iniciarMenu,*continuarMenu,*shit,*iniciarImage;
    ALLEGRO_SAMPLE_INSTANCE *inicialSound;
    // Variaveis da condição dos Loopings
    int iniciarOption = 0,sairOption= 0,continuarOption= 0,sairClick=0;

      //Inicializando o Allegro
    if (!al_init())
    {
        fprintf(stderr, "Falha ao inicializar a Allegro.\n");
        return -1;
    }

    //Inicializando addon pra inserir imagens
     if(!al_init_image_addon())
    {
        fprintf(stderr, "Falha ao iniciar o Add-ON.\n");
        return -1;
     }

     //Inicializando Codec
     if (!al_init_acodec_addon())
    {
        fprintf(stderr, "Falha ao inicializar complemento acodec!\n");
        return -1;
    }
    //Instalando recurso de audio
    if (!al_install_audio())
    {
        fprintf(stderr, "Falha ao instalar audio!\n");
        return -1;
    }
    else
        if (!al_reserve_samples(2))
        {
            fprintf(stderr, "Falha ao reservar samples!\n");
            return -1;
        }



    //Criando o Display
    janelaDisplay = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janelaDisplay)
    {
        fprintf(stderr, "Falha ao criar janela.\n");
        return -1;
    }


    inicialSound = al_create_sample_instance(al_load_sample("t.ogg"));
    if (inicialSound)
    {
        al_set_sample_instance_playmode(inicialSound, ALLEGRO_PLAYMODE_ONCE);
        al_attach_sample_instance_to_mixer(inicialSound, al_get_default_mixer());
        al_set_sample_instance_gain(inicialSound, 0.5);
        al_play_sample_instance(inicialSound);
    }
    else fprintf(stderr, "Falha ao carregar bubbles.ogg!\n");
    //Criando o Fundo
    shit = al_load_bitmap("sala.png");
    if(!shit)
    {
        fprintf(stderr,"Falha ao carregar a imagem Sala");

    }
    al_draw_bitmap(shit,0,0,0);

    // Configura o título da janela
    al_set_window_title(shit, ".::Joguinho::.");

    // Instalando o Mouse
    if (!al_install_mouse())
    {
        fprintf(stderr, "Falha ao inicializar o mouse.\n");
        al_destroy_display(janelaDisplay);
        return -1;
    }

    // Configura o ponteiro padrão do mouse
    if (!al_set_system_mouse_cursor(janelaDisplay, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT))
    {
        fprintf(stderr, "Falha ao atribuir ponteiro do mouse.\n");
        al_destroy_display(janelaDisplay);
        return -1;
    }

    // Alocamos o retângulo central da tela
    iniciarMenu = al_create_bitmap(250, 60);
    if (!iniciarMenu)
    {
        fprintf(stderr, "Falha ao criar bitmap.\n");
        al_destroy_display(shit);
        return -1;
    }


    // Alocamos o botão para fechar a aplicação
    sairMenu = al_create_bitmap(130, 55);
    if (!sairMenu)
    {
        fprintf(stderr, "Falha ao criar botão de saída.\n");
        al_destroy_display(shit);
        return -1;
    }

    //Criando fila de eventos
    eventosQueue = al_create_event_queue();
    if (!eventosQueue)
    {
        fprintf(stderr, "Falha ao inicializar o fila de eventos.\n");
        al_destroy_display(shit);
        return -1;
    }

    // Definindos os eventos vindo do mouse
    al_register_event_source(eventosQueue, al_get_mouse_event_source());

    // Condição indicando se o mouse está sobre o retângulo central

    while (true)
    {
        // Verificamos se há eventos na fila
        while (!al_is_event_queue_empty(eventosQueue))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(eventosQueue, &evento);

            // Se o evento foi de movimentação do mouse
            if (evento.type == ALLEGRO_EVENT_MOUSE_AXES)
            {
                // Verificando se esta sobre o Iniciar
                if (evento.mouse.x >= 330 &&
                    evento.mouse.x <= 510 &&
                    evento.mouse.y >= 170 &&
                    evento.mouse.y <= 230)
                {
                    iniciarOption = 1;
                }
                else
                {
                    iniciarOption = 0;
                }
                // Verificando se esta sobre o Continuar
                if (evento.mouse.x >= 290 &&
                    evento.mouse.x <= 560 &&
                    evento.mouse.y >= 250 &&
                    evento.mouse.y <= 300)
                {
                    continuarOption = 1;
                }
                else
                {
                    continuarOption = 0;
                }
                // Verificando se esta sobre o Sair
                if (evento.mouse.x >= 360 &&
                    evento.mouse.x <= 490 &&
                    evento.mouse.y >= 320 &&
                    evento.mouse.y <= 375)
                {
                    sairOption = 1;
                }
                else
                {
                    sairOption = 0;
                }
            }
            // Ou se o evento foi um clique do mouse
            else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
            {
                  if (evento.mouse.x >= 360 &&
                    evento.mouse.x <= 490 &&
                    evento.mouse.y >= 320 &&
                    evento.mouse.y <= 375)
                {
                    return 0;
                }
            }
        }

    al_set_target_bitmap(iniciarMenu);
    if (!iniciarOption)
    {
        iniciarMenu = al_load_bitmap("iniciar.png");
        if(!iniciarMenu)
        {
            fprintf(stderr,"Falha ao carregar a imagem Iniciar1");

        }
    }
    else
    {
        iniciarMenu = al_load_bitmap("iniciar2.png");
        if(!iniciarMenu)
        {
            fprintf(stderr,"Falha ao carregar a imagem Iniciar2");

        }
    }
      al_set_target_bitmap(continuarMenu);
    if (!continuarOption)
    {
        continuarMenu = al_load_bitmap("continuar1.png");
        if(!continuarMenu)
        {
            fprintf(stderr,"Falha ao carregar a imagem Continuar1");

        }
    }
    else
    {
        continuarMenu = al_load_bitmap("continuar2.png");
        if(!continuarMenu)
        {
            fprintf(stderr,"Falha ao carregar a imagem Sair2");

        }
    }
    al_set_target_bitmap(sairMenu);
    if (!sairOption)
    {
        sairMenu = al_load_bitmap("sair1.png");
        if(!sairMenu)
        {
            fprintf(stderr,"Falha ao carregar a imagem Sair1");

        }
    }
    else
    {
        sairMenu = al_load_bitmap("sair2.png");
        if(!sairMenu)
        {
            fprintf(stderr,"Falha ao carregar a imagem Sair2");

        }

    }
    // Desenhamos os retângulos na tela
    al_set_target_bitmap(al_get_backbuffer(janelaDisplay));
    al_draw_bitmap(iniciarMenu,300 ,170 , 0);
    al_draw_bitmap(continuarMenu, 290,250,0);
    al_draw_bitmap(sairMenu,360,320,0);
    // Atualiza a tela
    al_flip_display();
    al_rest(0.2);
    }


    // Desaloca os recursos utilizados na aplicação
    al_destroy_bitmap(iniciarMenu);
    al_destroy_bitmap(continuarMenu);
    al_destroy_bitmap(sairMenu);
    al_destroy_display(janelaDisplay);
    al_destroy_event_queue(eventosQueue);

    return 0;
}
