#include<windows.h>
#define GL_SILENCE_DEPRECATION
#include <stdlib.h>
#include <stdio.h>
#include <GL/GLUT.h>

int x0, y0, xn, yn;

void display(void) {
  int x, y, dx, dy, Di, dD, k;
  glBegin(GL_POINTS);
  glVertex2i(x0, y0);
  glEnd();
  dx = xn - x0;
  dy = yn - y0;
  Di= 2 * dy - dx;  //D(initial)=pk
  dD= 2 * (dy - dx);
  x = x0;
  y = y0;
  for (k = 0; k < dx - 1; ++k) {
    if (Di < 0) {
      y=y;
      Di = Di + 2 * dy;
    } else {
      y=y+1;
      Di = Di + 2 * dy - 2 * dx;
      ++y;
    }
    ++x;
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
  }
  glFlush();
}

void myInit(void) {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int main(int argc, char** argv) {
  printf("Value of x0 : ");
  scanf("%d", &x0);
  printf("Value of y0 : ");
  scanf("%d", &y0);
  printf("Value of xn : ");
  scanf("%d", &xn);
  printf("Value of yn : ");
  scanf("%d", &yn);

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(100, 150);
  glutCreateWindow("Mid Point Line");
  myInit();
  glutDisplayFunc(display);
  glutMainLoop();
}
