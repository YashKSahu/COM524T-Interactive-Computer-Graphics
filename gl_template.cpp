#include <GL/glut.h>
#include <bits/stdc++.h>

int onMouse;
float r,g,b;

void init(){
    glClearColor(0,0,0,0); //black background
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);
}

void pointPlot(int x, int y){
    glPointSize(2);
    glBegin(GL_POINTS);
        glVertex2i(x,y);
    glEnd();
}

void drawLogic(){

}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(r/10,g/10,b/10);  // random colors
    
    // Axis
    glBegin(GL_LINES);
        glVertex2d(320,480);
        glVertex2d(320, 0);

        glVertex2d(0,240);
        glVertex2d(640,240);
    glEnd();

    glFlush();
}

void mouseClicks(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        onMouse = 1;
    }
    if(onMouse == 1){
        r=rand()%9;
        g=rand()%9;
        b=rand()%9;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv){
    srand(time(0));
    r=rand()%9, g=rand()%9, b=rand()%9;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100,150);
    glutCreateWindow("Test Window");
    glutDisplayFunc(display);
    // glutMouseFunc(mouseClicks);
    init();
    glutMainLoop();
}
