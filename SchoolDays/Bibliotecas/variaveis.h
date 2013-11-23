ALLEGRO_DISPLAY *Display;
ALLEGRO_EVENT_QUEUE *eventosQueue;
ALLEGRO_BITMAP *sairMenu,*charSET,*personagemCHAR[12], *iniciarMenu,*continuarMenu,*fundoDisplay,*historiaImagem,*personagemHistoria;
ALLEGRO_SAMPLE_INSTANCE *inicialSound;
ALLEGRO_EVENT evento;
ALLEGRO_TIMER *timer;

FILE *fMapa;
const int LARGURA_TELA = 800;
const int ALTURA_TELA = 602;
bool sair = false,escolha = false, keys[]={false,false,false,false,false};
char sexo = 'm', lerMapa;
int iniciarOption = 1,sairOption= 0,continuarOption= 0,sairClick=0,x = 64,y = 64,i,j,mapa = -1,colisao=-1,top=0,down=0,right=0,left=0;
enum KEYS{UP,DOWN,RIGHT,LEFT,SELECT};

    int tileMap[21][27];
    char *colisaoMapa[] = {
        "Imagens/Mapas/dormitorio_feminino.txt",//0
        "Imagens/Mapas/dormitorio_masculino.txt",//1
        "Imagens/Mapas/salas.txt",//2
        "Imagens/Mapas/salas_diretor.txt",//3
        "Imagens/Mapas/biblioteca_refeitorio.txt",//4
        "",//5
        "" };
        char *imagemMapa[] = {
        "Imagens/Mapas/dormitorio_feminino.bmp",//0
        "Imagens/Mapas/dormitorio_masculino.bmp",//1
        "Imagens/Mapas/salas.bmp",//2
        "Imagens/Mapas/salas_diretor.bmp",//3
        "Imagens/Mapas/biblioteca_refeitorio.bmp",//4
        "",//5
        "" };
