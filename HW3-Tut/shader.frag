#version 400 core

out vec4 color;

void main(void) {
     color = vec4(1.0, 1.0, 1.0, 1.0);
}


//shell code
/*
uniform sampler2D qt_Texture0;
varying vec4 qt_TexCoord0;

void main(void)
{
    gl_FragColor = texture2D(qt_Texture0, qt_TexCoord0.st);
}
*/
