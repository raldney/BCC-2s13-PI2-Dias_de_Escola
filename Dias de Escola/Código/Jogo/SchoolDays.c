#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include <stdio.h>

#include "Bibliotecas/funcoes.h"
#include "Bibliotecas/inicializar.h"
#include "Bibliotecas/variaveis.h"
#include "Bibliotecas/menu.h"
#include "Bibliotecas/historia.h"
#include "Bibliotecas/carregarJogo.h"
#include "Bibliotecas/colisao.h"
#include "Bibliotecas/movimento.h"
#include "Bibliotecas/finalizarJogo.h"
#include "Bibliotecas/questoes.h"

int main()
{
    iniciar();
    carregarMenu();
    carregarHistoria();
    iniciarJogo();
    moverChar();


    return 0;
}



