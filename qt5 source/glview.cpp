#include "glview.h"
#include <QtMath>
GLView::GLView(QWidget *parent)
{
    m_xRot = 45.0;
}

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
    initializeOpenGLFunctions();
    glClearColor(0, 0, 0, 1);
    m_defaultShader = new QOpenGLShaderProgram;

    QFile shader(":/res/Shaders/default.vsh");
    shader.open(QIODevice::ReadOnly);
    m_defaultShader->addShaderFromSourceCode(QOpenGLShader::Vertex, QString(shader.readAll()));
    shader.close();

    shader.setFileName(":/res/Shaders/default.fsh");
    shader.open(QIODevice::ReadOnly);
    m_defaultShader->addShaderFromSourceCode(QOpenGLShader::Fragment, QString(shader.readAll()));
    shader.close();

    m_defaultShader->bindAttributeLocation("vertex", 0);
    m_defaultShader->bindAttributeLocation("normal", 1);
    m_defaultShader->link();

    m_defaultShader->bind();
    m_projMatrixLoc = m_defaultShader->uniformLocation("projMatrix");
    m_mvMatrixLoc = m_defaultShader->uniformLocation("mvMatrix");
    m_normalMatrixLoc = m_defaultShader->uniformLocation("normalMatrix");
    m_lightPosLoc = m_defaultShader->uniformLocation("lightPos");

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
        m_xRot = fminf(fmaxf(-20,m_xRot+dy*0.5),90);
        update();
    }else if(e->buttons()==Qt::LeftButton){
        m_xPos += dx * 0.25 * cos(m_yRot*M_PI/180.0);
        m_zPos += dx * 0.25 * sin(m_yRot*M_PI/180.0);

        m_xPos -= dy * 0.25 * sin(m_xRot*M_PI/180.0)*sin(m_yRot*M_PI/180.0);
        m_yPos -= dy * 0.25 * cos(m_xRot*M_PI/180.0);
        m_zPos += dy * 0.25 * sin(m_xRot*M_PI/180.0)*cos(m_yRot*M_PI/180.0);
        if(m_focusedOnTarget){
            int dz = m_cameraDistance+150;
            m_xPos -= dz * cos(m_xRot*M_PI/180.0) * sin(m_yRot*M_PI/180.0);
            m_yPos += dz * sin(m_xRot*M_PI/180.0);
            m_zPos += dz * cos(m_xRot*M_PI/180.0) * cos(m_yRot*M_PI/180.0);
            m_cameraDistance = -150;
            m_focusedOnTarget = false;
        }

        update();
    }
    m_lastPos = e->pos();
}

void GLView::wheelEvent(QWheelEvent *e)
{
    if(m_focusedOnTarget){
        m_cameraDistance += e->delta() * 0.25;
    }else{
        int dz = e->delta();
        m_xPos -= dz * 0.25 * cos(m_xRot*M_PI/180.0) * sin(m_yRot*M_PI/180.0);
        m_yPos += dz * 0.25 * sin(m_xRot*M_PI/180.0);
        m_zPos += dz * 0.25 * cos(m_xRot*M_PI/180.0) * cos(m_yRot*M_PI/180.0);
    }
    update();
}

void GLView::resizeGL(int w, int h)
{
    m_proj.setToIdentity();
    m_proj.perspective(45.0f, GLfloat(w) / h, 0.01f, 1000.0f);
}

void GLView::paintGL()
{
    qDebug() << "paintGL1";
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    m_world.setToIdentity();
    m_world.translate(0, 0, m_cameraDistance);
    m_world.rotate(m_xRot, 1, 0, 0);
    m_world.rotate(m_yRot, 0, 1, 0);
    m_world.translate(m_xPos, m_yPos, m_zPos);


    m_world.scale(0.04f);

    qDebug() << "paintGL2";

    m_defaultShader->bind();
    m_defaultShader->setUniformValue(m_projMatrixLoc, m_proj);
    m_defaultShader->setUniformValue(m_mvMatrixLoc,  m_world);
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

    qDebug() << "paintGL3";

    if(m_activeMap!=NULL){
        qDebug() << "paintGL4";
        glBegin(GL_QUADS);
        foreach (QString key, m_activeMap->m_wayPoints.keys()) {
            colorForKey(key);

            float x = m_activeMap->m_wayPoints[key].x;
            float y = m_activeMap->m_wayPoints[key].y;
            float z = m_activeMap->m_wayPoints[key].z;
            glVertex3f(x-10,y,z-10);
            glVertex3f(x+10,y,z-10);
            glVertex3f(x+10,y,z+10);
            glVertex3f(x-10,y,z+10);

        }
        glEnd();

        glBegin(GL_LINES);
        foreach (QString key, m_activeMap->m_routes.keys()) {
            QString keyPoint1 = key.mid(1,4);
            colorForKey(keyPoint1);

            glVertex3f(m_activeMap->m_wayPoints[keyPoint1].x,
                       m_activeMap->m_wayPoints[keyPoint1].y,
                       m_activeMap->m_wayPoints[keyPoint1].z
                       );

            QString keyPoint2 = key.mid(5,4);
            colorForKey(keyPoint2);

            glVertex3f(m_activeMap->m_wayPoints[keyPoint2].x,
                       m_activeMap->m_wayPoints[keyPoint2].y,
                       m_activeMap->m_wayPoints[keyPoint2].z
                       );

        }
        glEnd();
    }
    qDebug() << "paintGL5";
    m_defaultShader->release();
    qDebug() << "paintGL6";
}
