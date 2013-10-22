ALLEGRO_DISPLAY *menuDisplay;
ALLEGRO_EVENT_QUEUE *eventosQueue;
ALLEGRO_BITMAP *sairMenu, *iniciarMenu,*continuarMenu,*fundoMenu,*historiaImagem;
ALLEGRO_SAMPLE_INSTANCE *inicialSound;
ALLEGRO_EVENT evento;

bool sair = false;
int iniciarOption = 1,sairOption= 0,continuarOption= 0,sairClick=0;
const int LARGURA_TELA = 800;
const int ALTURA_TELA = 600;
