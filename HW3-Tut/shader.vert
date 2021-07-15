#version 400 core

in vec4 vPosition; //array of vertices
uniform mat4 xform; //single 4x4 matrix

void main() {
     gl_Position = xform * vPosition; //changed from gl_Position = vPosition;
}

//shell code?
/*
attribute vec4 qt_Vertex;
attribute vec4 qt_MultiTexCoord0;
uniform mat4 qt_ModelViewProjectionMatrix;
varying vec4 qt_TexCoord0;

void main(void)
{
    gl_Position = qt_ModelViewProjectionMatrix * qt_Vertex;
    qt_TexCoord0 = qt_MultiTexCoord0;
}

*/
