#include "glview.h"
#include <QtMath>
GLView::GLView(QWidget *parent)
{
    m_xRot = 135.0;
}
static const char *defaultShaderVtx =
    "attribute vec4 vertex;\n"
    "attribute vec3 normal;\n"
    "varying vec3 vert;\n"
    "varying vec3 vertNormal;\n"
    "varying vec4 v_Color;\n"
    "uniform mat4 projMatrix;\n"
    "uniform mat4 mvMatrix;\n"
    "uniform mat3 normalMatrix;\n"
    "void main() {\n"
    "   vert = vertex.xyz;\n"
    "   vertNormal = normalMatrix * normal;\n"
    "   v_Color = gl_Color;\n"
    "   gl_Position = projMatrix * mvMatrix * vertex;\n"
    "}\n";

static const char *defaultShaderFrag =
    "varying highp vec3 vert;\n"
    "varying highp vec3 vertNormal;\n"
    "uniform highp vec3 lightPos;\n"
    "varying vec4 v_Color;\n"
    "void main() {\n"
    "   //highp vec3 L = normalize(lightPos - vert);\n"
    "   //highp float NL = max(dot(normalize(vertNormal), L), 0.0);\n"
    "   //highp vec3 col = clamp(v_Color.xyz * 0.2 + v_Color.xyz * 0.8 * NL, 0.0, 1.0);\n"
    "   gl_FragColor = v_Color;\n"
    "}\n";

GLView::~GLView()
{
    if (m_defaultShader == nullptr)
        return;
    makeCurrent();
    delete m_defaultShader;
    m_defaultShader = 0;
    doneCurrent();
}

void GLView::initializeGL()
{
    glClearColor(0, 0, 0, 1);

    m_defaultShader = new QOpenGLShaderProgram;
    m_defaultShader->addShaderFromSourceCode(QOpenGLShader::Vertex, defaultShaderVtx);
    m_defaultShader->addShaderFromSourceCode(QOpenGLShader::Fragment, defaultShaderFrag);
    m_defaultShader->bindAttributeLocation("vertex", 0);
    m_defaultShader->bindAttributeLocation("normal", 1);
    m_defaultShader->link();

    m_defaultShader->bind();
    m_projMatrixLoc = m_defaultShader->uniformLocation("projMatrix");
    m_mvMatrixLoc = m_defaultShader->uniformLocation("mvMatrix");
    m_normalMatrixLoc = m_defaultShader->uniformLocation("normalMatrix");
    m_lightPosLoc = m_defaultShader->uniformLocation("lightPos");
    m_camera.setToIdentity();
    m_camera.translate(0, 0, -100);

    // Light position is fixed.
    m_defaultShader->setUniformValue(m_lightPosLoc, QVector3D(0, 0, 70));

    m_defaultShader->release();

    glEnable(GL_COLOR_MATERIAL);
}

void GLView::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->x() - m_lastPos.x();
    int dy = e->y() - m_lastPos.y();

    if(e->buttons()==Qt::RightButton){
        m_yRot +=  dx*0.5;
        m_xRot = fminf(fmaxf(0,m_xRot+dy*0.5),180);
        update();
    }else if(e->buttons()==Qt::LeftButton){
        m_xPos +=  dx*10;
        m_yPos = dy*10;
        update();
    }
    m_lastPos = e->pos();
}

void GLView::resizeGL(int w, int h)
{
    m_proj.setToIdentity();
    m_proj.perspective(45.0f, GLfloat(w) / h, 0.01f, 1000.0f);
}

void GLView::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    m_world.setToIdentity();
    m_world.translate(m_xPos, m_yPos, m_zPos);
    m_world.rotate(180.0f + m_xRot, 1, 0, 0);
    m_world.rotate(m_yRot, 0, 0, 1);


    m_world.scale(0.04);


    m_defaultShader->bind();
    m_defaultShader->setUniformValue(m_projMatrixLoc, m_proj);
    m_defaultShader->setUniformValue(m_mvMatrixLoc, m_camera * m_world);
    QMatrix3x3 normalMatrix = m_world.normalMatrix();
    m_defaultShader->setUniformValue(m_normalMatrixLoc, normalMatrix);

    /*
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
    glVertex3f(-10,-10,0);
    glVertex3f(10,-10,0);
    glVertex3f(10,10,0);
    glVertex3f(-10,10,0);
    glEnd();
    */
    if(m_activeMap!=NULL){
        glBegin(GL_QUADS);
        foreach (QString key, m_activeMap->wayPoints.keys()) {
            if(key.startsWith('W')){
                if(key==m_selectedPoint)
                    glColor3f(1,1,0);
                else
                    glColor3f(0,1,0);
            }else{
                if(key==m_selectedPoint)
                    glColor3f(0,1,1);
                else
                    glColor3f(0,0,1);
            }
            float x = m_activeMap->wayPoints[key].x;
            float y = m_activeMap->wayPoints[key].y;
            float z = m_activeMap->wayPoints[key].z;
            glVertex3f(x-10,-z-10,y);
            glVertex3f(x+10,-z-10,y);
            glVertex3f(x+10,-z+10,y);
            glVertex3f(x-10,-z+10,y);

        }
        glEnd();
    }
    m_defaultShader->release();
}
