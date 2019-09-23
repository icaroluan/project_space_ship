//NAVEINIMIGA

// OpenGL Utility Toolkit
#include<GL/gl.h>
#include<GL/glut.h>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>


// ----------------------------------------------------------
// Declarações de Funções
// ----------------------------------------------------------
void display();
void specialKeys();
void DesenhaCUBAO();
// ----------------------------------------------------------
// Variáveis Globais
// ----------------------------------------------------------
double rotate_y=0;
double rotate_x=0;

// Apenas requerido pelas aplica��es em windows
//#include <windows.h>

// Inicializa��es de OpenGL que devem ser
// executadas antes da exibi��o do desenho
void Inicializa(){

  // Define a janela de visualiza��o
  glMatrixMode(GL_PROJECTION);

  // Define o sistema de coordenadas
  glOrtho(-8.0, 8.0, -8.0, 8.0, -8.0, 8.0);

  // Define a cor de fundo da janela como azul
  glClearColor(0.0, 0.0, 0.0, 0.0);
}

// Fun��o callback chamada para fazer o desenho
void Desenha(){

  // Limpa a janela de visualiza��o com a cor
  // de fundo especificada
  glClear(GL_COLOR_BUFFER_BIT);

  // Define a cor de desenho como vermelho
  //glColor3f(1.0, 0.0, 0.0);

  // Desenha um tri�ngulo


  // Reinicia transformações
  glLoadIdentity();

  // Outras Transformações
  // glTranslatef( 0.1, 0.0, 0.0 );      // Não está incluído
  // glRotatef( 180, 0.0, 1.0, 0.0 );    // Não está incluído

  // Rotaciona quando o usuário muda rotate_x e rotate_y
  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );

// Nave inimigo

  /*glBegin(GL_TRIANGLES);
  glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);
    glVertex3f(0.0, -0.5, 0.0);
  glEnd();

glBegin(GL_TRIANGLES);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-0.5, -0.5, 0.0);
    glVertex3f(0.5, -0.5, 0.0);
    glVertex3f(0.0, 0.5, 0.0);
  glEnd();

glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-0.25, -0.25, 0.0);
    glVertex3f(0.25, -0.25, 0.0);
    glVertex3f(0.0, 0.25, 0.0);
  glEnd();
*/

glBegin(GL_TRIANGLES);
         // Begin drawing the pyramid with 4 triangles
      // Front
      glColor3f(1.0, 0.0, 0.0);     // Red
      glVertex3f( 0.0, -0.25, 0.0);
      glVertex3f(0.50, 0.50, -0.50);
      glVertex3f(-0.50, 0.50, -0.50);

      // Right
      glVertex3f(0.0, -0.50, 0.0);
      glColor3f( 0.0, 1.0, 0.0 );
      glVertex3f(-0.50, 0.50, -0.50);
      glVertex3f(-0.50, 0.50, 0.50);

      // Back
      glVertex3f(0.0, -0.50, 0.0);
      glColor3f( 0.0, 0.0, 1.0 );
      glVertex3f(-0.50, 0.55, 0.50);
      glVertex3f(0.50, 0.50, 0.50);

      // Left
      glVertex3f( 0.0, -0.50, 0.0);
      glColor3f( 1.0, 0.0, 1.0 );
      glVertex3f(0.50,0.50,0.50);
      glVertex3f(0.50,0.50, -0.50);
   glEnd();




   glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front
      glColor3f(1.0, 0.0, 0.0);     // Red
      glVertex3f( 0.0, -0.25, 0.0);
      glVertex3f(0.25, 0.25, -0.25);
      glVertex3f(-0.25, 0.25, -0.25);

      // Right
      glVertex3f(0.0, -0.25, 0.0);
      glVertex3f(-0.25, 0.25, -0.25);
      glVertex3f(-0.25, 0.25, 0.25);

      // Back
      glVertex3f(0.0, -0.25, 0.0);
      glVertex3f(-0.25, 0.25, 0.25);
      glVertex3f(0.25, 0.25, 0.25);

      // Left
      glVertex3f( 0.0, -0.25, 0.0);
      glVertex3f(0.25,0.25,0.25);
      glVertex3f(0.25,0.25, -0.25);
   glEnd();

   ///////////////////////////////////////////aaaaaaaaaaaaaaaaaaa

 //glLoadIdentity();                  // Reset the model-view matrix
   glTranslatef(0.0f, 0.75f, 0.0f);

   glBegin(GL_POLYGON);

  glColor3f(   0.3,  0.1, 0.7 );
  glVertex3f(  0.2, -0.5, 0.2 );
  glVertex3f(  0.2,  0.5, 0.2 );
  glVertex3f( -0.2,  0.5, 0.2 );
  glVertex3f( -0.2, -0.5, 0.2 );
  glEnd();

  // Lado roxo - DIREITA
 glBegin(GL_POLYGON);
  glColor3f(  1.0,  0.0,  1.0 );
  glVertex3f( 0.2, -0.5, -0.2 );
  glVertex3f( 0.2,  0.5, -0.2 );
  glVertex3f( 0.2,  0.5,  0.2 );
  glVertex3f( 0.2, -0.5,  0.2 );
  glEnd();

  // Lado verde - ESQUERDA
 glBegin(GL_POLYGON);
  glColor3f(   0.4,  1.0,  0.0 );
  glVertex3f( -0.2, -0.5, 0.2 );
  glVertex3f( -0.2,  0.5,  0.2 );
  glVertex3f( -0.2,  0.5, -0.2 );
  glVertex3f( -0.2, -0.5, -0.2 );
  glEnd();

  // Lado azul - TOPO
 glBegin(GL_POLYGON);
  glColor3f(   0.0,  0.2,  1.0 );
  glVertex3f(  0.2,  0.5,  0.2 );
  glVertex3f(  0.2,  0.5, -0.2 );
  glVertex3f( -0.2,  0.5, -0.2 );
  glVertex3f( -0.2,  0.5,  0.2 );
  glEnd();

  // Lado vermelho - BASE
 glBegin(GL_POLYGON);
  glColor3f(   1.0,  0.0,  0.0 );
  glVertex3f(  0.2, -0.5, -0.2 );
  glVertex3f(  0.2, -0.5,  0.2 );
  glVertex3f( -0.2, -0.5, 0.2);
  glVertex3f( -0.2, -0.5, -0.2 );
  glEnd();


  // Executa os comandos OpenGL para renderiza��o
  glFlush();
  glutSwapBuffers();

}





















// ----------------------------------------------------------
// Função specialKeys()
// ----------------------------------------------------------
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

  // Avisa a GLUT que tipo de modo de exibi��o deve ser usado quando a janela � criada
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  // Cria uma janela GLUT que permite a execu��o de comandos OpenGL
  glutCreateWindow("Nave Inimiga");

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
