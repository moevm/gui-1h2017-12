#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QVector3D>
#include <QVector4D>

class PaintWidget: public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit PaintWidget(QWidget *parent=0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void setNum(int n);

private:
    void quad(float x0, float y0, float a, float b);
    void circle(float x0,float y0,float r);
    void sixegon(float x0, float y0,float w,float h);

    void card(int num);


    float cardW = 0.155f;
    float cardH = 0.105f;
    int num = 1;

    float qW = 0.04f;
    float qlX = 0.25f;
    float qrX = 0.65f;

    float horQY = 0.58f;
    float horQH = 0.04f;

};

#endif // PAINTWIDGET_H
