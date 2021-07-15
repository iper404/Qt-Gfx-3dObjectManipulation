#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include <iostream>

#include <QOpenGLWidget>
#include <QOpenGLFunctions_4_0_Core>
#include <QSurfaceFormat>

#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>

#include <vector>

using namespace std;


class MyOpenGLWidget : public QOpenGLWidget,
        public QOpenGLFunctions_4_0_Core {
        Q_OBJECT

public:
    //fxn for determining viewport height / width?

    MyOpenGLWidget(QWidget *parent=nullptr);
    void onClearButton();
    void onVertexButton();
    void onTranslateButton(int, int, int, int, int);
    void onXAxisButton();
    void onYAxisButton();
    void onZAxisButton();

    void onVertexOne(int, int);
    void onVertexTwo(int, int);
    void onVertexThree(int, int);

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

private:
    QOpenGLVertexArrayObject *pVao;
    QOpenGLBuffer *pBuffer;
    QOpenGLShader *pVertexShader, *pFragmentShader;
    QOpenGLShaderProgram *pShaderProgram;

    QMatrix4x4 persMat; //perspective matrix
    //pers is used for setting camera focal plane and setting camera lens
    float fovy = 60.0;
    float nearclip = 1.0;
    float farclip = 20.0;

    QMatrix4x4 camMat;
    float dist = 5.0;

    QMatrix4x4 xform;
    //xform = transform matrix

    QMatrix4x4 myTrans;
    //myTrans takes in the persMat * camMat * transMat operation
    //so that we can easily call myTrans.inverted() and multiply by the vp coordinates

    QVector4D vpVert;
    //vpVert holds in the 3d coordinates for x, y, z, w
    QVector4D vWorldOne;
    //vWorld will hold the world coordinates upon final operation
    QVector4D vWorldTwo;
    QVector4D vWorldThree;

    vector<GLfloat> triVec;

    int w = 400;
    int h = 400;

    bool clearBool = false;

    int tDisty = 0;
    int tDistx = 0;
    float tDisty_3d = 0;
    float tDistx_3d = 0;
    float tDisty2_3d = 0;
    float tDistx2_3d = 0;
    float tDist = 0;

    int axisRad = 1;

    float x1_3d = 0;
    float x2_3d = 0;
    float y1_3d = 0;
    float y2_3d = 0;
    float x3_3d = 0;
    float y3_3d = 0;
    float z_3d = 0.0;
    float normVal = 1.0;

    QMatrix4x4 vertOne;

    int vertexCount = 0;

};

#endif // MYOPENGLWIDGET_H
