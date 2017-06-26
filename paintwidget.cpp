#include "paintwidget.h"

PaintWidget::PaintWidget(QWidget *parent):
    QOpenGLWidget(parent)
{
}



void PaintWidget::initializeGL()
{
   glClearColor(1, 1, 1, 1);
   glOrtho(0,1,0,1,0,1);
   glEnableClientState(GL_VERTEX_ARRAY);
   glEnableClientState(GL_COLOR_ARRAY);
   this->update();
}


void PaintWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.82f,0.5f,0.51f);

    quad(qlX,0.0f,qW,1.0f);
    quad(qrX,0.0f,qW,1.0f);


    glColor3f(0.54f,0.0f,0.08f);
    quad(0.0f,horQY,1.0f,horQH);

    glColor3f(1.0f,1.0f,1.0f);
    circle(qrX+qW/2, horQY+horQH/2, 0.01f);

    card(num);
}

void PaintWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
}

void PaintWidget::quad(float x0, float y0, float a, float b)
{
    glBegin(GL_QUADS);

    glVertex3d(x0,y0,0);
    glVertex3d(x0+a,y0,0);
    glVertex3d(x0+a,y0+b,0);
    glVertex3d(x0,y0+b,0);

    glEnd();
}

void PaintWidget::circle(float x0, float y0, float r)
{
    glBegin(GL_POLYGON);

    for(int i=0;i<51;i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / 50.0f;//get the current angle

        float x = r * cosf(theta) + x0;//calculate the x component
        float y = r * sinf(theta) + y0;//calculate the y component

        glVertex3d(x,y,0);
    }

    glEnd();
}

void PaintWidget::sixegon(float x0, float y0,float w,float h)
{
    glBegin(GL_POLYGON);

    glVertex3d(x0-(cardW+w),y0,0);
    glVertex3d(x0-(cardW+w)/2,y0+(cardH+h)/2,0);
    glVertex3d(x0+(cardW+w)/2,y0+(cardH+h)/2,0);
    glVertex3d(x0+(cardW+w),y0,0);
    glVertex3d(x0+(cardW+w)/2,y0-(cardH+h)/2,0);
    glVertex3d(x0-(cardW+w)/2,y0-(cardH+h)/2,0);
    glVertex3d(x0-(cardW+w),y0,0);

    glEnd();
}

void PaintWidget::card(int num)
{
    int LT = num/50;
    num = num - 50*LT;

    int LD = num/10;
    num = num - 10*LD;

    int RT = num/5;
    num = num - 5*RT;

    int RD = num;

    float sX = qlX+qW/2;
    float sY = horQY+horQH + cardH/2 + 0.02f ;

    for(int i=0;i<LT;i++)
    {
        glColor3f(1.0f,1.0f,1.0f);
        sixegon(sX,sY,0.01f,0.01f);
        glColor3f(0.4f,0.0f,0.06f);
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
        sixegon(sX,sY,0,0);
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
        sixegon(sX,sY,0.01f,0.01f);
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

        sY = sY + cardH + 0.02f;
    }

    sY = horQY -cardH/2 - 0.02f;

    for(int i=0;i<LD;i++)
    {
        glColor3f(1.0f,1.0f,1.0f);
        sixegon(sX,sY,0.01f,0.01f);
        glColor3f(0.4f,0.0f,0.06f);
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
        sixegon(sX,sY,0,0);
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
        sixegon(sX,sY,0.01f,0.01f);
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);


        sY = sY -cardH - 0.02f;
    }

    sX = qrX+qW/2;
    sY = horQY + horQH + cardH/2 + 0.02f;

    for(int i=0;i<RT;i++)
    {
        glColor3f(1.0f,1.0f,1.0f);
        sixegon(sX,sY,0.01f,0.01f);
        glColor3f(0.4f,0.0f,0.06f);
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
        sixegon(sX,sY,0,0);
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
        sixegon(sX,sY,0.01f,0.01f);
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);


        sY = sY + cardH + 0.02f;
    }

    sY = horQY - cardH/2 - 0.02f;

    for(int i=0;i<RD;i++)
    {
        glColor3f(1.0f,1.0f,1.0f);
        sixegon(sX,sY,0.01f,0.01f);
        glColor3f(0.4f,0.0f,0.06f);
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
        sixegon(sX,sY,0,0);
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
        sixegon(sX,sY,0.01f,0.01f);
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);


        sY = sY - cardH - 0.02f;
    }
}

void PaintWidget::setNum(int n)
{
    this->num = n;
    this->update();
}

