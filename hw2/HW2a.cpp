// ===============================================================
// Computer Graphics Homework Solutions
// Copyright (C) 2019 by George Wolberg
//
// HW2a.cpp - HW2a class
//
// Written by: George Wolberg, 2019
// ===============================================================

#include "HW2a.h"

// shader ID
enum { HW2A };

// uniform ID
enum { PROJ };

const int DrawModes[] = {
	GL_POINTS,
	GL_LINES,
	GL_LINE_STRIP,
	GL_LINE_LOOP,
	GL_TRIANGLES,
	GL_TRIANGLE_STRIP,
	GL_TRIANGLE_FAN,
	GL_QUADS,
	GL_POLYGON
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW2a::HW2a:
//
// HW2a constructor.
//
HW2a::HW2a(const QGLFormat &glf, QWidget *parent) : HW(glf, parent)
{
}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW2a::initializeGL:
//
// Initialization routine before display loop.
// Gets called once before the first time resizeGL() or paintGL() is called.
//
void
HW2a::initializeGL()
{
	// initialize GL function resolution for current context
	initializeGLFunctions();

	// init vertex and fragment shaders
	initShaders();

	// initialize vertex buffer and write positions to vertex shader
	initVertexBuffer();

	// init state variables
	glClearColor(0.0, 0.0, 0.0, 0.0);	// set background color
	glColor3f   (1.0, 1.0, 0.0);		// set foreground color
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW2a::resizeGL:
//
// Resize event handler.
// The input parameters are the window width (w) and height (h).
//
void
HW2a::resizeGL(int w, int h)
{
    // save window dimensions
    m_winW = w;
    m_winH = h;
    
    // compute aspect ratio
    float ar = (float) w / h;
    
    // set xmax, ymax;
    float xmax, ymax;
    if(ar > 1.0) {        // wide screen
        xmax = ar;
        ymax = 1.;
    } else {              // tall screen
        xmax = 1.;
        ymax = 1 / ar;
    }
    
    // set viewport to occupy full canvas
    glViewport(0, 0, w, h);
    
    // compute orthographic projection from viewing coordinates;
    // we use Qt's 4x4 matrix class in place of legacy OpenGL code:
    // glLoadIdentity();
    // glOrtho(-xmax, xmax, -ymax, ymax, -1.0, 1.0);
    m_projection.setToIdentity();
    m_projection.ortho(-xmax, xmax, -ymax, ymax, -1.0, 1.0);
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW2a::paintGL:
//
// Update GL scene.
//
void
HW2a::paintGL()
{
	// clear canvas with background color
	glClear(GL_COLOR_BUFFER_BIT);
	
	// enable vertex shader point size adjustment
	glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);

	// draw data in nine viewports after splitting canvas into 3x3 cells;
	// a different drawing mode is used in each viewport
	// ********************
	// *      *     *     *
	// *   7  *  8  *  9  *
	// *      *     *     *
	// ********************
	// *      *     *     *
	// *   4  *  5  *  6  *
	// *      *     *     *
	// ********************
	// *      *     *     *
	// *   1  *  2  *  3  *
	// *      *     *     *
	// ********************

	// viewport dimensions
	int w = m_winW / 3;
	int h = m_winH / 3;

	// use glsl program
    glUseProgram(m_program[HW2A].programId());
    
    // pass the following projection matrix to the vertex shader
    glUniformMatrix4fv(m_uniform[HW2A][PROJ ], 1, GL_FALSE, m_projection.constData ());
    
    int q = 0;                                                          // drawmodes counter
    for (int j=0; j<3; j++)                                             // y-axis viewport counter
    {
        for (int k=0; k<3; k++)                                         // x-axis viewport counter
        {
            glViewport(k*w, (j%3)*h, w, h);                             // 3x3 viewports
            
            if (q==8){                                                  //GL_QUADS, GL_POLYGON not rendering
                glDrawArrays(GL_TRIANGLE_FAN, 0, m_vertNum);            //as a workaround used GL_TF for
            }                                                           //GL_POLYGON. Could not find a
            else {                                                      //workaround for GL_QUADS
            glDrawArrays(DrawModes[q++], 0, m_vertNum);                 //Rendering Primatives, starting
            }                                                           //index = 0, count = m_vertNum
        }
    }
    
    glUseProgram(0);

	// disable vertex shader point size adjustment
	glDisable(GL_VERTEX_PROGRAM_POINT_SIZE);
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW2a::controlPanel:
//
// Create control panel groupbox.
//
QGroupBox*
HW2a::controlPanel()
{
	// init group box
	QGroupBox *groupBox = new QGroupBox("Homework 2a");
	groupBox->setStyleSheet(GroupBoxStyle);
	return(groupBox);
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW2a::reset:
//
// function to reset parameters.
//
void
HW2a::reset()
{
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW2a::initShaders:
//
// Initialize shaders.
//
void
HW2a::initShaders()
{

	// init uniforms hash table based on uniform variable names and location IDs
	UniformMap uniforms;
	uniforms["u_Projection"] = PROJ;

	// compile shader, bind attribute vars, link shader, and initialize uniform var table
	initShader(HW2A, QString(":/hw2/vshader2a.glsl"), QString(":/hw2/fshader2a.glsl"), uniforms);
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW2a::initVertexBuffer:
//
// Initialize vertex buffer.
//
void
HW2a::initVertexBuffer()
{
    float vv[] = {
        -0.5 , -0.75,
        -0.5 , -0.5 ,
        -0.5 , -0.25,
        -0.5 ,  0.0 ,
        -0.5 ,  0.25,
        -0.5 ,  0.5 ,
        -0.25,  0.75,
        0.0 ,  0.75,
        0.25,  0.75,
        0.5 ,  0.75,
        0.75 , 0.5 ,
        0.75,  0.25,
        0.5 ,  0.0 ,
        0.25,  0.0 ,
        0.0,   0.0 ,
        -0.25,  0.0
    };
    std::vector<float> v (&vv[0], &vv[0]+sizeof(vv)/sizeof(float));
    
    // init number of vertices
    m_vertNum = (int) v.size() / 2;
    
    // create a vertex buffer
    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);
    
    // bind vertex buffer to the GPU and copy the vertices from CPU to GPU
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, v.size()*sizeof(float), &v[0], GL_STATIC_DRAW);
    
    // enable vertex buffer to be accessed via the attribute vertex variable and specify data format
    glEnableVertexAttribArray(ATTRIB_VERTEX);
    glVertexAttribPointer     (ATTRIB_VERTEX, 2, GL_FLOAT, false, 0, 0);
}
