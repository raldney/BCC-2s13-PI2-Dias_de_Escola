ALLEGRO_DISPLAY *Display;
ALLEGRO_EVENT_QUEUE *eventosQueue;
ALLEGRO_BITMAP *sairMenu, *iniciarMenu,*continuarMenu,*fundoDisplay,*historiaImagem;
ALLEGRO_SAMPLE_INSTANCE *inicialSound;
ALLEGRO_EVENT evento;

bool sair = false;
char sexo;
int iniciarOption = 1,sairOption= 0,continuarOption= 0,sairClick=0;
const int LARGURA_TELA = 800;
const int ALTURA_TELA = 600;
