#ifndef LAYOUT_H_INCLUDED
#define LAYOUT_H_INCLUDED
#endif // LAYOUT_H_INCLUDED
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>




      if (!al_init())
      {
        fprintf(stderr, "Falha ao inicializar allegro!\n");
        return false;
      }



      if (!al_init_image_addon())
      {
        fprintf(stderr, "Falha ao inicializar complemento image!\n");
        return false;
      }


    if (!al_install_keyboard())
    {
        fprintf(stderr, "Falha ao inicializar o teclado.\n");
        return false;
    }


    if (!al_install_mouse())
    {
        fprintf(stderr, "Falha ao inicializar o mouse.\n");
        return false;
    }



     ALLEGRO_DISPLAY *tela= NULL;
     ALLEGRO_BITMAP *fundo= NULL, *foto1= NULL,*foto2= NULL;
     ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
     ALLEGRO_EVENT evento;
       tela = al_create_display(altura,largura);
    if (!tela)
    {
        fprintf(stderr, "Falha ao criar display!\n");
        return -1;
    }
    al_set_window_title(tela,".:Joguinho:.");
    fundo = al_load_bitmap(foto);
     if (!fundo)
    {
        fprintf(stderr, "Falha ao carregar aquario.png\n");
        al_destroy_display(tela);
        return -1;
    }

     fila_eventos = al_create_event_queue();
    if (!fila_eventos)
    {
        fprintf(stderr, "Falha ao criar fila de eventos.\n");
        al_destroy_display(tela);
        return -1;
    }
      if (!al_set_system_mouse_cursor(tela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT))
    {
        fprintf(stderr, "Falha ao atribuir ponteiro do mouse.\n");
        al_destroy_display(tela);
        return -1;
    }
 al_draw_bitmap(fundo, 0, 0, 0);
 al_flip_display();

