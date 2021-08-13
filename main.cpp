#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<string.h>
#include <math.h>
using namespace std;
#define WINDOW_WIDTH 1320
#define WINDOW_HEIGHT 720
float halfWidth = (float)(WINDOW_WIDTH/2.0);
float halfHeight = (float)(WINDOW_HEIGHT/2.0);
float radius = 0.5;
float inc=0.2;
float horizontal_inc=0.2;
//float x1, x2, y1, y2;
float c=0,l1=0,l2=0,s=0;
float square_inc=1.0,square_dec=1.0;
float red=1.0,green=0.0,blue=0.0;

bool backgroundwhite=true;
float window_w=500;
float window_h=500;


void display(void)
{

	glClearColor(1.0, 1.0, 1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
glMatrixMode(GL_MODELVIEW);
	glFlush();
    glutSwapBuffers();
	return;
}




void MyPaint(GLint x, GLint y)
{

	int window_width=glutGet(GLUT_WINDOW_WIDTH);
	int window_size=glutGet(GLUT_WINDOW_HEIGHT);
	float tt1=(250*window_width)/500;
	float tt2=(250*window_size)/500;
    glColor3f(red, green, blue);
    glPointSize(3.0);
    glBegin(GL_POINTS);
    glVertex2f((x - tt1) / tt1, -(y - tt2) / tt2);
    glEnd();

    glFlush();
    return;
}

void MySquare(GLint x, GLint y)
{

    glColor3f(red, green, blue);
    int window_width=glutGet(GLUT_WINDOW_WIDTH);
	int window_size=glutGet(GLUT_WINDOW_HEIGHT);
	float tt1=(250*window_width)/500;
	float tt2=(250*window_size)/500;
    float t1=(x - tt1) / tt1;
    float t2=-(y - tt2) / tt2;
    glBegin(GL_LINE_LOOP);
    glVertex2f(t1, t2);
    glVertex2f(t1+square_inc,t2);
    glVertex2f(t1+square_inc,t2-square_dec);
    glVertex2f(t1,t2-square_dec);
    glEnd();

    glFlush();
    s=1;
    return;
}
void MyEraser(GLint x, GLint y)
{

if(backgroundwhite)
{
     glColor3f(1.0, 1.0, 1.0);
    glPointSize(10.0);
    glBegin(GL_POINTS);
    glVertex2f((x - 250.0) / 250.0, -(y - 250.0) / 250.0);
    glEnd();

    glFlush();

}
else{
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(10.0);
    glBegin(GL_POINTS);
    glVertex2f((x - 250.0) / 250.0, -(y - 250.0) / 250.0);
    glEnd();

    glFlush();
}

    return;
}


void colorsmenu(int id)
{
     if(id==3)
        {
            red=1.0;
            green=0.0;
            blue=0.0;
        }
     if(id==4)
        {
            red=1.0;
            green=1.0;
            blue=0.0;
        }
     if(id==5)
        {
            red=0.0;
            green=0.0;
            blue=1.0;
        }
    if(id==6)
        {
            red=0.0;
            green=0.0;
            blue=0.0;
        }
        if(id==7)
        {
             red=0.0;
            green=1.0;
            blue=0.0;

        }



}
void MyCircle(GLint x, GLint y)
{
	glColor3f(red, green, blue);
	int window_width=glutGet(GLUT_WINDOW_WIDTH);
	int window_size=glutGet(GLUT_WINDOW_HEIGHT);
	float tt1=(250*window_width)/500;
	float tt2=(250*window_size)/500;
	float t1=(x - tt1) / tt1;
    float t2=-(y - tt2) / tt2;
	glBegin(GL_LINE_LOOP);                        // Middle circle

		float ori_x = 0.0;                         // the origin or center of circle
		float ori_y = 0.0;
		//radius-->inc
		for (int i = 0; i <= 300; i++) {
			float angle = 2 * 3.141596 * i / 300;
			float x1 = cos(angle) * radius;
			float y1 = sin(angle) * radius;
			glVertex2f(t1 + x1, t2 + y1);
	}
	glEnd();
	glFlush();
	c=1;
}

void Line(GLint x,GLint y){
	glColor3f(red, green, blue);
	int window_width=glutGet(GLUT_WINDOW_WIDTH);
	int window_size=glutGet(GLUT_WINDOW_HEIGHT);
	float tt1=(250*window_width)/500;
	float tt2=(250*window_size)/500;
	float t1=(x - tt1) / tt1;
    float t2=-(y - tt2) / tt2;
    glBegin(GL_LINES);
		glVertex2f(t1,t2);
		//inc-->0.2
		glVertex2f(t1,t2-inc);
	glEnd();
	glFlush();
	l1=1;


}
void Line2(GLint x,GLint y){
	glColor3f(red, green, blue);
	int window_width=glutGet(GLUT_WINDOW_WIDTH);
	int window_size=glutGet(GLUT_WINDOW_HEIGHT);
	float tt1=(250*window_width)/500;
	float tt2=(250*window_size)/500;
	float t1=(x - tt1) / tt1;
    float t2=-(y - tt2) / tt2;
    glBegin(GL_LINES);
		glVertex2f(t1,t2);
		//inc-->0.2
		glVertex2f(t1+horizontal_inc,t2);
	glEnd();
	glFlush();
	l2=1;


}
void triangle(GLint x,GLint y){
	glColor3f(red, green, blue);
	int window_width=glutGet(GLUT_WINDOW_WIDTH);
	int window_size=glutGet(GLUT_WINDOW_HEIGHT);
	float tt1=(250*window_width)/500;
	float tt2=(250*window_size)/500;
	float t1=(x - tt1) / tt1;
    float t2=-(y - tt2) / tt2;

    glBegin(GL_LINE_LOOP);



    glVertex2f(t1,t2);
    glVertex2f(t1-0.5,t2-0.5);
    glVertex2f(t1+0.5,t2-0.5);

    glEnd();

    glFlush();
}
void pentagon(GLint x,GLint y){
	glColor3f(red, green, blue);
	int window_width=glutGet(GLUT_WINDOW_WIDTH);
	int window_size=glutGet(GLUT_WINDOW_HEIGHT);
	float tt1=(250*window_width)/500;
	float tt2=(250*window_size)/500;
	float t1=(x - tt1) / tt1;
    float t2=-(y - tt2) / tt2;
    glBegin(GL_LINE_LOOP);
    glVertex2f(t1,t2);
    glVertex2f(t1-0.5,t2-0.5);
    glVertex2f(t1-0.3,t2-0.8);
    glVertex2f(t1+0.5,t2-0.5);
    glVertex2f(t1+0.3,t2-0.8);


    glEnd();
    glFlush();
}



void shapesmenu(int item)
{



	 if (item == 1)
	{
		glutMouseFunc(NULL);
		glutMotionFunc(MyPaint);
	}
	else if(item==2)
	{
		 glutMouseFunc(NULL);
		glutMotionFunc(MySquare);

	}
	else if(item==15)
	{
		 glutMouseFunc(NULL);
		glutMotionFunc(MyCircle);

	}

	else if(item==101){
		glutMouseFunc(NULL);
		glutMotionFunc(Line);
	}
	else if(item==201){
		glutMouseFunc(NULL);
		glutMotionFunc(Line2);
	}
	else if(item==301){
		glutMouseFunc(NULL);
		glutMotionFunc(triangle);
	}
	else if(item==401){
		glutMouseFunc(NULL);
		glutMotionFunc(pentagon);
	}
	return;
}





void MainMenu(int item)
{
	if(item==8)
	{
		if(backgroundwhite)
		{
		glClearColor(0.0, 0.0, 0.0,0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		backgroundwhite=false;
		glFlush();

		}
		else{
			glClearColor(1.0, 1.0, 1.0,1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		 backgroundwhite=true;
		glFlush();

		}

	}
	else if(item==13)
	{
		 exit(0);


	}
	else if(item=3)
	{
		if(backgroundwhite)
	{
		glClearColor(1.0, 1.0, 1.0,1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		glFlush();
		//backgroundwhite=false;

	}
	else{
		glClearColor(0.0, 0.0, 0.0,0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		glFlush();
		//backgroundwhite=true;

	}

	}
}

void MyEraser1(GLint x, GLint y)
{
    int window_width=glutGet(GLUT_WINDOW_WIDTH);
	int window_size=glutGet(GLUT_WINDOW_HEIGHT);
	float tt1=(250*window_width)/500;
	float tt2=(250*window_size)/500;
	float t1=(x - tt1) / tt1;
    float t2=-(y - tt2) / tt2;

	if(backgroundwhite)
	{

		 glColor3f(1.0, 1.0, 1.0);
		glPointSize(5.0);
		glBegin(GL_POINTS);
		glVertex2f((x - tt1) / tt1, -(y - tt2) / tt2);
		glEnd();

		glFlush();

	}
	else{
		glColor3f(0.0, 0.0, 0.0);
		glPointSize(5.0);
		glBegin(GL_POINTS);
		glVertex2f((x - tt1) / tt1, -(y - tt2) / tt2);
		glEnd();

		glFlush();
	}

    return;
}
void MyEraser2(GLint x, GLint y)
{
     int window_width=glutGet(GLUT_WINDOW_WIDTH);
	int window_size=glutGet(GLUT_WINDOW_HEIGHT);
	float tt1=(250*window_width)/500;
	float tt2=(250*window_size)/500;
	float t1=(x - tt1) / tt1;
    float t2=-(y - tt2) / tt2;

	if(backgroundwhite)
	{
		 glColor3f(1.0, 1.0, 1.0);
		glPointSize(15.0);
		glBegin(GL_POINTS);
		glVertex2f((x - tt1) / tt1, -(y - tt2) / tt2);
		glEnd();

		glFlush();

	}
	else{
		glColor3f(0.0, 0.0, 0.0);
		glPointSize(15.0);
		glBegin(GL_POINTS);
		glVertex2f((x - tt1) / tt1, -(y - tt2) / tt2);
		glEnd();

		glFlush();
	}

    return;
}
void MyEraser3(GLint x, GLint y)
{

 int window_width=glutGet(GLUT_WINDOW_WIDTH);
	int window_size=glutGet(GLUT_WINDOW_HEIGHT);
	float tt1=(250*window_width)/500;
	float tt2=(250*window_size)/500;
	float t1=(x - tt1) / tt1;
    float t2=-(y - tt2) / tt2;
	if(backgroundwhite)
	{
		 glColor3f(1.0, 1.0, 1.0);
		glPointSize(30.0);
		glBegin(GL_POINTS);
		glVertex2f((x - tt1) / tt1, -(y - tt2) / tt2);
		glEnd();

		glFlush();

	}
	else{
		glColor3f(0.0, 0.0, 0.0);
		glPointSize(30.0);
		glBegin(GL_POINTS);
		glVertex2f((x - tt1) / tt1, -(y - tt2) / tt2);
		glEnd();
		glFlush();
	}

    return;
}

void erasersmenu(int item)
{
    if(item==9)
    {
        glutMouseFunc(NULL);
    glutMotionFunc(MyEraser1);

    }
    else if(item==10)
    {
        glutMouseFunc(NULL);
    glutMotionFunc(MyEraser2);

    }
    else if(item==11)
    {
        glutMouseFunc(NULL);
    glutMotionFunc(MyEraser3);
    }

}

void reshape (int w,int h)
{
   if (h == 0)
		h = 1;

	float ratio =  w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45,ratio,1,100);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
  //<--- add

}
void key(unsigned char key, int x, int y)
{
    float frac = 0.3;
    float rotFrac = 1;
    switch(key)
    {
        case 13: // 13 is the ascii code for the ENTER key
            //START=true;
            break;
        case 'w':
             //back to start page
             if(c==1){
                radius=radius+0.5;
                c=0;
             }
             if(s==1){
                square_inc=square_inc+0.5;
                square_dec=square_dec-0.5;
                s=0;
             }
             if(l1==1){
                inc=inc+0.5;
                l1=0;
             }
             if(l2==1){
                horizontal_inc=horizontal_inc-0.5;
                l2=0;
             }
            break;
        case 's': //up
            if(c==1){
                radius=radius-0.5;
                c=0;
             }
             if(s==1){
                square_inc=square_inc-0.5;
                square_dec=square_dec+0.5;
                s=0;
             }
             if(l1==1){
                inc=inc-0.5;
                l1=0;
             }
             if(l2==1){
                horizontal_inc=horizontal_inc+0.5;
                l2=0;
             }
            break;
        case 'o':
            inc=inc+0.5;
            break;
        case 'l':
            inc=inc-0.5;
            break;

        case 27 : // 27 is the ascii code for the ESC key
            exit(0);
            break;
    }
}



int main(int argc, char **argv)
{

	glutInit(&argc, argv);
	glutInitWindowSize(1320, 720);
	glutInitWindowPosition(500, 200);
	glutCreateWindow("PAINT TOOL");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);


	int suubshapemenu_id=glutCreateMenu(shapesmenu);
		glutAddMenuEntry("Paintbrush", 1);
		glutAddMenuEntry("Square", 2);
		glutAddMenuEntry("Circle", 15);
		glutAddMenuEntry("vertical-line",101);
		glutAddMenuEntry("horizontal-line",201);
		glutAddMenuEntry("triangle",301);
		glutAddMenuEntry("Cool Shape",401);




	int subcolormenu_id = glutCreateMenu(colorsmenu);
		glutAddMenuEntry("Red", 3);
		glutAddMenuEntry("Yellow", 4);
		glutAddMenuEntry("Blue", 5);
		glutAddMenuEntry("Black", 6);
		glutAddMenuEntry("Green", 7);
	int suberasermenu_id = glutCreateMenu(erasersmenu);
		glutAddMenuEntry("Small", 9);
		glutAddMenuEntry("Medium", 10);
		glutAddMenuEntry("Large", 11);



	glutCreateMenu(MainMenu);
	glutKeyboardFunc(key);
	glutAddSubMenu("Shapes",suubshapemenu_id);
	glutAddSubMenu("Colors",subcolormenu_id);
	glutAddSubMenu("Eraser",suberasermenu_id);
	glutAddMenuEntry("Clear", 12);
	glutAddMenuEntry("Exit", 13);

	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();
}
