#include <GL/glut.h>
#include <iostream>

using namespace std;

#define LARGURA  500		/* Width */
#define ALTURA   500		/* Heigth */

int tX = 0;
int tY = 0;
int count = 0;
bool bateu = false;
int counter = 0;
int xOBS = 285;

/*Função para gerenciar as setas*/
void specialKey(int key, int x, int y){
    switch (key){
        case GLUT_KEY_RIGHT:
            if(tX<=300) tX+=5;
            //else tX = 0;
            break;
        case GLUT_KEY_LEFT:
            if(tX>=10) tX-=5;
            //else tX = 0;
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

void desenhaListra(int x, int y){
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
        glVertex2i(x-20,y-100);
        glVertex2i(x,y-100);
        glVertex2i(x,y);
        glVertex2i(x-20,y);
    glEnd();

}

void desenhaObstaculo(int x, int y){
    
    glColor3f(0.63, 0.32, 0.18);
    glBegin(GL_QUADS);
        glVertex2d(x-20,y-20); //
        glVertex2d(x,y-20); //
        glVertex2d(x,y);
        glVertex2d(x-20,y);
    glEnd();
}

void Timer(int value){
    count ++; 
    
    if(tY == 500) tY = 100;
    tY++; 
    // Redesenha o quadrado com as novas coordenadas 
    glutPostRedisplay();
    glutTimerFunc(20,Timer, 1);
}


void desenhaCarro(){
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_QUADS);
        glVertex2d(50,50);
        glVertex2d(150,50);
        glVertex2d(150,80);
        glVertex2d(50,80);

        glVertex2d(60,80);
        glVertex2d(140,80);
        glVertex2d(140,100); //
        glVertex2d(60,100); //
    glEnd();

    glColor3f(0.41,0.41,0.41);
    glBegin(GL_QUADS);
        glVertex2d(65,80);
        glVertex2d(135,80);
        glVertex2d(135,95);
        glVertex2d(65,95);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2d(55,55);
        glVertex2d(75,55);
        glVertex2d(75,65);
        glVertex2d(55,65);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2d(145,55);
        glVertex2d(125,55);
        glVertex2d(125,65);
        glVertex2d(145,65);
    glEnd();

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex2d(56,56);
        glVertex2d(74,56);
        glVertex2d(74,64);
        glVertex2d(56,64);

        glVertex2d(144,56);
        glVertex2d(126,56);
        glVertex2d(126,64);
        glVertex2d(144,64);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex2d(56,40);
        glVertex2d(64,40);
        glVertex2d(64,50);
        glVertex2d(56,50);

        glVertex2d(144,40);
        glVertex2d(136,40);
        glVertex2d(136,50);
        glVertex2d(144,50);
    glEnd();

}


void desenhaPista(){
  counter += 1;
  
   	glColor3f(0.51,0.54,0.54);
    glBegin(GL_QUADS);
        glVertex2i(0,0);
        glVertex2i(500,0);
        glVertex2i(300,500);
        glVertex2i(200,500);
    glEnd();

    desenhaListra(245,100-tY);
    desenhaListra(245,250-tY);
    desenhaListra(245,400-tY);
    desenhaListra(245,550-tY);
    desenhaListra(245,700-tY);
    desenhaListra(245,850-tY);
    desenhaListra(245,1000-tY);

    cout << "counter: " << counter << "\n";
    if(counter == 0) {
        int pos = rand()%2;
        if(pos == 1) {
            xOBS = 215;
        } else {
            xOBS = 285;
        } 
    }
    if(counter > 0 && counter < 1000) {
        desenhaObstaculo(xOBS, 550-tY);
    } else if(550-tY == 0) {
        counter = 0;

    }
    if(60+tX+80 >= xOBS-20 && tX+60 <= xOBS) {
        cout << "hueuhe";
    }
    
    /*if(count == 20){
        pos = rand()%2;
        if (pos == 1) x = 215;
        desenhaObstaculo(x, 550-tY);
        count = 0;
    }*/
}

/* Função callback chamada para fazer o desenho */
void Desenha(void){
	/* Especifica que as transformações irão alterar os desenhos (modelos) */
	glMatrixMode(GL_MODELVIEW);  
	/* Carrega na matriz corrente a matriz identidade */
	glLoadIdentity();

	/* Limpa a janela de visualização com a cor de fundo especificada */
	glClear(GL_COLOR_BUFFER_BIT);
    
    desenhaPista();
    glTranslated(tX,0,0);
    desenhaCarro();

  
    
    /* Executa os comandos OpenGL */
	glFlush();
}

/* Inicializa parâmetros de rendering */
void Inicializa (void){
    /* Define a cor de fundo da janela de visualização como branca */
    glClearColor(0.19f, 0.41f, 0.19f, 1.0f);

    /* Modo de projecao ortogonal */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, LARGURA, 0, ALTURA, -1 ,1);
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize (LARGURA, ALTURA);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("Transformacoes");
    glutDisplayFunc(Desenha);
	glutSpecialFunc(specialKey);
    glutTimerFunc(25,Timer,1);
    Inicializa();
	glutMainLoop();
}