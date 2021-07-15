#include "myopenglwidget.h"

MyOpenGLWidget::MyOpenGLWidget(QWidget *parent) :
QOpenGLWidget(parent)
{
     static QSurfaceFormat mSurfaceFormat;
     mSurfaceFormat.setDepthBufferSize(24);
     mSurfaceFormat.setStencilBufferSize(8);
     mSurfaceFormat.setVersion(4,0);
     mSurfaceFormat.setProfile(QSurfaceFormat::CoreProfile);
     setFormat(mSurfaceFormat);

     camMat.setToIdentity();

     camMat.lookAt(QVector3D(0.0, 0.0, 0.0), /* eye point*/
                   QVector3D(0.0, 0.0, -dist), /* aiming point */
                   QVector3D(0.0, 1.0, 0.0) ); /* up vector */

     xform.setToIdentity();
}

void MyOpenGLWidget::initializeGL() {
     initializeOpenGLFunctions();

     // must run after initializeOpenGLFunctions()
     pVao = new QOpenGLVertexArrayObject();
     pVao->create();
     pVao->bind();

     //create vertex shader object
     pVertexShader = new QOpenGLShader(QOpenGLShader::Vertex);
     pVertexShader->compileSourceFile("../HW3-Tut/shader.vert");
     cout << pVertexShader->log().toLatin1().data(); //print errlog

     //create fragment shader object
     pFragmentShader = new QOpenGLShader(QOpenGLShader::Fragment);
     pFragmentShader->compileSourceFile("../HW3-Tut/shader.frag");
     cout << pFragmentShader->log().toLatin1().data(); // print errlog

     //create+assemble final Shader Program Object
     // Must occur after the vertex shader and fragment shader objects
     // are created.
     pShaderProgram = new QOpenGLShaderProgram(this);
     pShaderProgram->create();
     pShaderProgram->addShader(pVertexShader);
     pShaderProgram->addShader(pFragmentShader);
     pShaderProgram->link();

}

void MyOpenGLWidget::paintGL() {
     float col[] = { 0.0f, 0.5f, 0.8f, 1.0f };
     glClearBufferfv(GL_COLOR,0,col);

     //create Buffer Object
     static GLfloat triangles[1000];

     if(clearBool == false){
         for (unsigned int i = 0; i < triVec.size(); i++){
             triangles[i] = triVec[i];
             //cout << i << ": " << triangles[i] << " ";
         }
     }

     else{
         for (unsigned int i = 0; i < triVec.size(); i++){
             triangles[i] = 0;
             //cout << i << ": " << triangles[i] << " ";
         }
         triVec.clear();
         clearBool = false;
     }

     pBuffer = new QOpenGLBuffer(); // QOpenGLBuffer
     pBuffer->create();
     pBuffer->bind();
     pBuffer->setUsagePattern(QOpenGLBuffer::DynamicDraw);
     pBuffer->allocate(triangles,sizeof(triangles));

     //now we have created buffer & cleared screen.
     //pass buffer object to shader program:
     pShaderProgram->bind();
     pShaderProgram->enableAttributeArray("vPosition");
     pShaderProgram->setAttributeBuffer("vPosition",GL_FLOAT,0,4);

     //NEW ADDS
     int xformLoc = pShaderProgram->uniformLocation("xform");
     pShaderProgram->setUniformValue(xformLoc, xform);
     //END NEW

     //after binding Shader Program, draw triangles
     glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
     glDrawArrays(GL_TRIANGLES,0,vertexCount);

     //finished -- release Shader Program, delete Buffer object
     pShaderProgram->disableAttributeArray("vPosition");
     pShaderProgram->release(); // release program
     pBuffer->destroy(); // destroy buffer object
     delete pBuffer; // release buffer object memory
}

void MyOpenGLWidget::resizeGL(int w, int h) {
    persMat.setToIdentity(); // mat is a QMatrix4x4 object
    persMat.perspective(fovy, (GLfloat)w/(GLfloat)h, nearclip,
    farclip);
    //fovy = horiz angle
    //float w/h is aspect ratio
}

void MyOpenGLWidget::onTranslateButton(int x1, int y1, int x2, int y2, int axisRad){
    //tDisty = y2 - y1;
    //tDistx = x2 - x1;

    float(tDistx_3d) = (float((float(2)*float(x1))/float(w))) - float(1);
    float(tDisty_3d) = float(1) - (float((float(2)*float(y1))/float(h)));
    float(tDistx2_3d) = (float((float(2)*float(x2))/float(w))) - float(1);
    float(tDisty2_3d) = float(1) - (float((float(2)*float(y2))/float(h)));

    tDisty = tDisty2_3d - tDisty_3d;
    tDistx = tDistx2_3d - tDistx_3d;

    z_3d = 0;

    if(axisRad == 1){ //x-axis
        xform.translate(tDistx_3d, 0, 0);
    }

    else if(axisRad == 2){ //y-axis
        xform.translate(0, tDisty_3d, 0);
    }

    else if(axisRad == 3){ //z-axis
        xform.translate(0, 0, tDisty_3d);
    }

    update();
}


void MyOpenGLWidget::onVertexOne(int x1, int y1){
    //cout << "\n---\nx1: " << x1 << " y1: " << y1 << "\nx1/w = " << float(x1)/float(w) << "\n";

    float(x1_3d) = (float((float(2)*float(x1))/float(w))) - float(1);
    float(y1_3d) = float(1) - (float((float(2)*float(y1))/float(h)));
    z_3d = 0;
    //GL Viewport Coordinates obtained from screen coordinates
    //(x3d, y3d, 0, 1.0)

    //Next: find GL World Coordinates
    //(x3dw, y3dw z3dw, 1.0)
    //(P*C*X)^-1
    //= x^-1 * c^-1 * p ^-1
    // p = pers
    // c = cam
    // x = translate transform (x3d?)

    //cout << "Vertex 1 = " << x1_3d << ", " << y1_3d << ", " << z_3d << ", " << normVal << "\n";

    //QVector4d vpVert: vpVert holds in the 3d coordinates for x, y, z, w
    vpVert.setX(x1_3d);
    vpVert.setY(y1_3d);
    vpVert.setZ(z_3d);
    vpVert.setW(normVal);

    //QMatrix4x4 myTrans takes in P*C*X
    myTrans = persMat * camMat * xform;

    //QVector4D vWorldOne: holds the world coordinates given by inverse PCX * vpVert 3d coordinates
    vWorldOne = myTrans.inverted() * vpVert;

    //cout << "vWorld1: " << vWorldOne.x() << " " << vWorldOne.y() << " " << vWorldOne.z() <<" " << vWorldOne.w() << "\n---\n";

    //triVec is a vector<GLfloat> triVec which is holding all our 3d world coordinates.
    triVec.push_back(vWorldOne.x());
    triVec.push_back(vWorldOne.y());
    triVec.push_back(vWorldOne.z());
    triVec.push_back(normVal);

    vertexCount++;
}

void MyOpenGLWidget::onVertexTwo(int x2, int y2){
    //cout << "\nx1: " << x2 << " y1: " << y2 << "\n";

    float(x2_3d) = (float((float(2)*float(x2))/float(w))) - float(1);
    float(y2_3d) = float(1) - (float((float(2)*float(y2))/float(h)));
    z_3d = 0;

    //cout << "Vertex 2 = " << x2_3d << ", " << y2_3d << ", " << z_3d << ", " << normVal << "\n";

    vpVert.setX(x2_3d);
    vpVert.setY(y2_3d);
    vpVert.setZ(z_3d);
    vpVert.setW(normVal);

    myTrans = persMat * camMat * xform;

    vWorldTwo = myTrans.inverted() * vpVert;

    //cout << "vWorld2: " << vWorldTwo.x() << " " << vWorldTwo.y() << " " << vWorldTwo.z() <<" " << vWorldTwo.w() << "\n---\n";

    triVec.push_back(vWorldTwo.x());
    triVec.push_back(vWorldTwo.y());
    triVec.push_back(vWorldTwo.z());
    triVec.push_back(normVal);

    vertexCount++;
}

void MyOpenGLWidget::onVertexThree(int x3, int y3){
    //cout << "\nx1: " << x3 << " y1: " << y3 << "\n";

    float(x3_3d) = (float((float(2)*float(x3))/float(w))) - float(1);
    float(y3_3d) = float(1) - (float((float(2)*float(y3))/float(h)));
    z_3d = 0;

    //cout << "Vertex 3 = " << x3_3d << ", " << y3_3d << ", " << z_3d << ", " << normVal << "\n";

    vpVert.setX(x3_3d);
    vpVert.setY(y3_3d);
    vpVert.setZ(z_3d);
    vpVert.setW(normVal);

    //v1
    myTrans = persMat * camMat * xform;

    vWorldThree = myTrans.inverted() * vpVert;

    //cout << "vWorld3: " << vWorldThree.x() << " " << vWorldThree.y() << " " << vWorldThree.z() <<" " << vWorldThree.w() << "\n---\n";

    triVec.push_back(vWorldThree.x());
    triVec.push_back(vWorldThree.y());
    triVec.push_back(vWorldThree.z());
    triVec.push_back(normVal);

    vertexCount++;

    //use update to draw the triangle
    update();
}

void MyOpenGLWidget::onClearButton(){
    clearBool = true;
    xform.setToIdentity();
    update();
}

