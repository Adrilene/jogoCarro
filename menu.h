#include <GL/glut.h>
#include <iostream>

using namespace std;

int txOption = 170;
int tyOption = 100;

void DesenhaTexto(void *font, char *texto){
    // Exibe caractere a caractere
    while (*texto)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *texto++);
}

void moveMenu(int key, int x, int y){
    
    switch (key){
        case GLUT_KEY_UP:
            if (tyOption == 100)
                tyOption -= 30;
            else
                tyOption += 30;
            break;
        case GLUT_KEY_DOWN:
            if (tyOption == 70)
                tyOption += 30;
            else
                tyOption -= 30;
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

void selectOption(unsigned char key, int x, int y){

    if (key == 13)
    {
        if (tyOption == 100)
        {
            //do nothing yet
        }
        else if (tyOption == 70)
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
    glTranslated(txOption, tyOption, 0);
    glScalef(0.2, 0.2, 1);
    DesenhaTexto(GLUT_STROKE_ROMAN, "[     ]");
    glPopMatrix();

}