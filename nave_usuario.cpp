#include<GL/gl.h>
#include<GL/glut.h>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>

void display();
void specialKeys();


// Variáveis Globais
double rotate_y=0;
double rotate_x=0;

void Inicializa(){

  // Define a janela de visualização
  glMatrixMode(GL_PROJECTION);

  // Define o sistema de coordenadas
  glOrtho(-8.0, 8.0, -8.0, 8.0, -8.0, 8.0);

  // Define a cor de fundo da janela como azul
  glClearColor(0.0, 0.0, 0.0, 0.0);
}

// Função chamada para fazer o desenho
void Desenha(){

  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();

  // Rotaciona quando o usuário muda rotate_x e rotate_y
  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );

  glBegin(GL_TRIANGLES);           // Desenha uma pirâmide com 4 triângulos
      // Front
      glColor3f(217, 8, 0.5);     // Red
      glVertex3f( 0.0, 0.2, 0.0);
      glVertex3f(-0.2, -0.2, 0.2);
      glVertex3f(0.2, -0.2, 0.2);

      // Right
      glVertex3f(0.0, 0.2, 0.0);
      glColor3f(217, 8, 0.5);     // Blue
      glVertex3f(0.2, -0.2, 0.2);
      glVertex3f(0.2, -0.2, -0.2);

      // Back
      glVertex3f(0.0, 0.2, 0.0);
      glColor3f(0.5, 8, 217);     // Green
      glVertex3f(0.2, -0.2, -0.2);
      glVertex3f(-0.2, -0.2, -0.2);

      // Left
      glColor3f(0.5, 8, 217);       // Red
      glVertex3f( 0.0, 0.2, 0.0);
      glVertex3f(-0.2,-0.2,-0.2);
      glVertex3f(-0.2,-0.2, 0.2);
  glEnd();

  glTranslatef(0.0f, -0.15f, 0.0f);
  glRotatef(180,1,0,0);

  glBegin(GL_TRIANGLES);           // Desenha uma pirâmide com 4 triângulos
      // Front
      glColor3f(80, 125, 0);     // Red
      glVertex3f( 0.0, -0.2, 0.0);
      glVertex3f(0.2, 0.2, -0.2);
      glVertex3f(-0.2, 0.2, -0.2);

      // Right
      glVertex3f(0.0, -0.2, 0.0);
      glColor3f(80, 125, 0);     // Blue
      glVertex3f(-0.2, 0.2, -0.2);
      glVertex3f(-0.2, 0.2, 0.2);

      // Back
      glVertex3f(0.0, -0.2, 0.0);
      glColor3f(0, 80, 125);     // Green
      glVertex3f(-0.2, 0.2, 0.2);
      glVertex3f(0.2, 0.2, 0.2);

      // Left
      glColor3f(0, 80, 125);       // Red
      glVertex3f( 0.0, -0.2, 0.0);
      glVertex3f(0.2,0.2,0.2);
      glVertex3f(0.2,0.2, -0.2);
  glEnd();

   //TRIANGULO VERMELHO
   glTranslatef(0.0f, -0.3f, 0.0f);

   glBegin(GL_TRIANGLES);           // Desenha uma pirâmide com 4 triângulos
      // Front
      glColor3f(1, 0, 0);     // Red
      glVertex3f( 0.0, -0.1, 0.0);
      glVertex3f(0.1, 0.1, -0.1);
      glVertex3f(-0.1, 0.1, -0.1);

      // Right
      glVertex3f(0.0, -0.1, 0.0);
      glVertex3f(-0.1, 0.1, -0.1);
      glVertex3f(-0.1, 0.1, 0.1);

      // Back
      glVertex3f(0.0, -0.1, 0.0);
      glVertex3f(-0.1, 0.1, 0.1);
      glVertex3f(0.1, 0.1, 0.1);

      // Left
      glVertex3f( 0.0, -0.1, 0.0);
      glVertex3f(0.1,0.1,0.1);
      glVertex3f(0.1,0.1, -0.1);
   glEnd();

  //CUBO
  glTranslatef(0.0f, 0.64f, 0.0f);

  glBegin(GL_POLYGON);
      glColor3f(0, 140, 0);
      glVertex3f(  0.06, -0.14, 0.06 );
      glVertex3f(  0.06,  0.14, 0.06 );
      glVertex3f( -0.06,  0.14, 0.06 );
      glVertex3f( -0.06, -0.14, 0.06 );
  glEnd();

  // Lado roxo - DIREITA
  glBegin(GL_POLYGON);
      glColor3f(140, 0, 0);
      glVertex3f( 0.06, -0.14, -0.06 );
      glVertex3f( 0.06,  0.14, -0.06 );
      glVertex3f( 0.06,  0.14,  0.06 );
      glVertex3f( 0.06, -0.14,  0.06 );
  glEnd();

  // Lado verde - ESQUERDA
  glBegin(GL_POLYGON);
      glColor3f(0, 0, 140);
      glVertex3f( -0.06, -0.14, 0.06 );
      glVertex3f( -0.06,  0.14, 0.06 );
      glVertex3f( -0.06,  0.14, -0.06 );
      glVertex3f( -0.06, -0.14, -0.06 );
  glEnd();

  // Lado azul - TOPO
  glBegin(GL_POLYGON);
      glColor3f(140, 140, 140);
      glVertex3f(  0.06,  0.14,  0.06 );
      glVertex3f(  0.06,  0.14, -0.06 );
      glVertex3f( -0.06,  0.14, -0.06 );
      glVertex3f( -0.06,  0.14,  0.06 );
  glEnd();

  // Lado vermelho - BASE
  glBegin(GL_POLYGON);
      glColor3f(0, 0, 0);
      glVertex3f(  0.06, -0.14, -0.06 );
      glVertex3f(  0.06, -0.14,  0.06 );
      glVertex3f( -0.06, -0.14,  0.06  );
      glVertex3f( -0.06, -0.14, -0.06 );
  glEnd();

  // Executa os comandos OpenGL para renderiza��o
  glFlush();
  glutSwapBuffers();
}

void specialKeys( int key, int x, int y ) {

  //  Seta direita - aumenta rotação em 5 graus
  if (key == GLUT_KEY_RIGHT)
    rotate_y += 5;

  //  Seta para esquerda - diminui a rotação por 5 graus
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 5;

  else if (key == GLUT_KEY_UP)
    rotate_x += 5;

  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;

  //  Requisitar atualização do display
  glutPostRedisplay();

}

// Programa principal
int main(int argc, char** argv){

  // Inicia GLUT e processa argumentos passados por linha de comandos
  glutInit(&argc, argv);
  glutInitWindowSize(640,580);
  // Avisa a GLUT que tipo de modo de exibi��o deve ser usado quando a janela � criada
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  // Cria uma janela GLUT que permite a execu��o de comandos OpenGL
  glutCreateWindow("Nave");

  // Define a fun��o respons�vel por redesenhar a janela OpenGL sempre que necess�rio
  glutDisplayFunc(Desenha);
  glutSpecialFunc(specialKeys);
  // Inicializa��es de OpenGL executadas antes da exibi��o do desenho
  Inicializa();

  // Inicia o processamento de eventos de GLUT. O controle do programa
  // passa a GLUT, que inicia o gerenciamento dos eventos
  glutMainLoop();

  return 0;
}
