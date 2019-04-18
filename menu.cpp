#include <GL/glut.h>
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>


using namespace std;

#define LARGURA  500		/* Width */
#define ALTURA   500		/* Heigth */

int txOption = 170;
int tyOption = 100;

struct pontuacao {
    string player; 
    int score;
};
typedef struct pontuacao pontuacao;

void DesenhaTexto(void *font, char *texto) {  
	// Exibe caractere a caractere
	while(*texto)
		glutStrokeCharacter(GLUT_STROKE_ROMAN,*texto++); 
}

void showRanking(){
    glClear(GL_COLOR_BUFFER_BIT);
    //working on
}

void moveMenu(int key, int x, int y){
    switch (key){
        case GLUT_KEY_UP:
            if(tyOption == 100)
                tyOption-=30;
            else if(tyOption == 70)
                tyOption+=30;
            break;
        case GLUT_KEY_DOWN:
            if(tyOption == 100)
                tyOption-=30;
            if(tyOption == 70)
                tyOption+=30;
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

void selectOption(unsigned char key, int x, int y){
    
    if(key == 13){
        if (tyOption == 100){
            //do nothing yet
        }
        else if(tyOption == 70)
            showRanking();
    }
    
    glutPostRedisplay();
}


/* Função callback chamada para fazer o desenho */
void Desenha(void){
	/* Especifica que as transformações irão alterar os desenhos (modelos) */
	glMatrixMode(GL_MODELVIEW);  
	/* Carrega na matriz corrente a matriz identidade */
	glLoadIdentity();

	/* Limpa a janela de visualização com a cor de fundo especificada */
	glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslated(100,200,0);
    glScalef(0.25,0.25,1);
    DesenhaTexto(GLUT_STROKE_ROMAN,"Nome do Jogo.");
    glPopMatrix();    

    glPushMatrix();
    glTranslated(200,100,0);
    glScalef(0.2,0.2,1);
    DesenhaTexto(GLUT_STROKE_ROMAN,"Start");
    glPopMatrix();    

    glPushMatrix();
    glTranslated(185,70,0);
    glScalef(0.2,0.2,1);
    DesenhaTexto(GLUT_STROKE_ROMAN,"Ranking");
    glPopMatrix();  

    glPushMatrix();
    glTranslated(txOption,tyOption,0);
    glScalef(0.2,0.2,1);
    DesenhaTexto(GLUT_STROKE_ROMAN,"[     ]");
    glPopMatrix();      
    /* Executa os comandos OpenGL */
	glFlush();
}

/* Inicializa parâmetros de rendering */
void Inicializa (void){
    /* Define a cor de fundo da janela de visualização como branca */
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    /* Modo de projecao ortogonal */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, LARGURA, 0, ALTURA, -1 ,1);
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h){

    if(h == 0) h = 1;
            
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w <= h) 
            gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f*h/w);
    else 
            gluOrtho2D (0.0f, 250.0f*w/h, 0.0f, 250.0f);
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize (LARGURA, ALTURA);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("Transformacoes");
    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    glutSpecialFunc(moveMenu);
    glutKeyboardFunc(selectOption);
    Inicializa();
	glutMainLoop();
}