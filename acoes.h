#include <GL/glut.h>

int posMenu(int tyOption){
    return tyOption;
}

int posCarro(int txCarro){
    return txCarro;
}

int retornaTela(int t){
    return t;
}

void gerenciaMouse(int button, int state, int x, int y){
    //do nothing
}

void gerenciaTeclado(int key, int x, int y){
    int tyOption = 100;    
    int txCarro = 0;
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
        case GLUT_KEY_LEFT:
            txCarro--;
            break;
        case GLUT_KEY_RIGHT:
            txCarro++;
            break;
        default:
            break;
    }
    posMenu(tyOption);
    posCarro(txCarro);
    glutPostRedisplay();
}