#include <GL/glut.h>
#include <iostream>
//#include "acoes.h"

using namespace std;

void DesenhaTexto(void *font, char *texto){
    
    retornaTela(0);
    // Exibe caractere a caractere

    while (*texto)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *texto++);
}

void selectOption(unsigned char key, int x, int y){

    if (key == 13)
    {
        if (y == 100)
        {
            retornaTela(1);
            //startGame();
        }
        else if (y == 70)
        {
            //showRanking();
            cout << "oi";
        }
    }

    glutPostRedisplay();
}

void DesenhaMenu(){
    glColor3f(1.0,1.0,1.0);

    glPushMatrix();
    glTranslated(100, 200, 0);
    glScalef(0.25, 0.25, 1);
    DesenhaTexto(GLUT_STROKE_ROMAN, "Nome do Jogo.");
    glPopMatrix();

    glPushMatrix();
    glTranslated(200, 100, 0);
    glScalef(0.2, 0.2, 1);
    DesenhaTexto(GLUT_STROKE_ROMAN, "Start");
    glPopMatrix();

    glPushMatrix();
    glTranslated(185, 70, 0);
    glScalef(0.2, 0.2, 1);
    DesenhaTexto(GLUT_STROKE_ROMAN, "Ranking");
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, posMenu(), 0);
    glScalef(0.2, 0.2, 1);
    DesenhaTexto(GLUT_STROKE_ROMAN, "[     ]");
    glPopMatrix();

}