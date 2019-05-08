#include <GL/glut.h>
#include <iostream>

void startGame(){
    	/* Especifica que as transformações irão alterar os desenhos (modelos) */
	glMatrixMode(GL_MODELVIEW);  
	/* Carrega na matriz corrente a matriz identidade */
	glLoadIdentity();

	/* Limpa a janela de visualização com a cor de fundo especificada */
	glClear(GL_COLOR_BUFFER_BIT);

    glClearColor(0.19,0.8,0.19,1.0);
    
	glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex2i(0,0);
        glVertex2i(500,0);
        glVertex2i(300,500);
        glVertex2i(200,500);
    glEnd();

	int x = 0, y = 0, z = 0, w = 0;
	//listras da pista 

	glColor3f(1.0,1.0,1.0);

    int pos = 100;

    glTranslated(0,tY,0);
    
    glBegin(GL_QUADS);

        glVertex2i(240,0);
        glVertex2i(260,0);
        glVertex2i(260,100);
        glVertex2i(240,100);

		glVertex2i(240,150);
        glVertex2i(260,150);
        glVertex2i(260,250);
        glVertex2i(240,250);

		glVertex2i(240,300);
        glVertex2i(260,300);
        glVertex2i(260,400);
        glVertex2i(240,400);

		glVertex2i(240,450);
        glVertex2i(260,450);
        glVertex2i(260,550);
        glVertex2i(240,550);
    glEnd();

    /* Executa os comandos OpenGL */
	glFlush();

}