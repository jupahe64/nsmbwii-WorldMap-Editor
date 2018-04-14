#ifndef GLVIEW_H
#define GLVIEW_H

#include <QMatrix4x4>
#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLFunctions_2_0>
#include <qevent.h>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include "mainwindow.h"

class GLView : public QOpenGLWidget, protected QOpenGLFunctions_2_0
{
    Q_OBJECT

private:
    WorldMap *m_activeMap = NULL;
    QString m_selectedPoint;
    int m_worldNumber;

    bool m_focusedOnTarget = true;

    QOpenGLShaderProgram *m_defaultShader;
    int m_projMatrixLoc;
    int m_mvMatrixLoc;
    int m_normalMatrixLoc;
    int m_lightPosLoc;
    QMatrix4x4 m_proj;
    float m_cameraDistance = -150;
    QMatrix4x4 m_world;

    QPoint m_lastPos;
    float m_xPos, m_yPos, m_zPos;
    float m_xRot, m_yRot;

    int m_ui_left, m_ui_top, m_ui_height;
public:
    GLView(QWidget *parent = 0);
    ~GLView();
    void paintGL();
    void initializeGL();
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void wheelEvent(QWheelEvent *e);
    void resizeGL(int w, int h);

    void zoom(int amount);

    void setActiveMap(WorldMap *map, int id){
        if(id<3)
            m_worldNumber = id+1;
        else
            m_worldNumber = id;
        m_activeMap = map;
        QString startPoint  = QString("WXS0").replace("X",QString::number(m_worldNumber));
        QString altStartPoint  = QString("WXS1").replace("X",QString::number(m_worldNumber));

        if (m_activeMap->m_wayPoints.contains(startPoint))
            setFocus(m_activeMap->m_wayPoints[startPoint]->x,
                     m_activeMap->m_wayPoints[startPoint]->y,
                     m_activeMap->m_wayPoints[startPoint]->z
                     );
        else if (m_activeMap->m_wayPoints.contains(altStartPoint))
            setFocus(m_activeMap->m_wayPoints[altStartPoint]->x,
                     m_activeMap->m_wayPoints[altStartPoint]->y,
                     m_activeMap->m_wayPoints[altStartPoint]->z
                     );
        else if (m_activeMap->m_wayPoints.contains("Fl01"))
            setFocus(m_activeMap->m_wayPoints["Fl01"]->x,
                     m_activeMap->m_wayPoints["Fl01"]->y,
                     m_activeMap->m_wayPoints["Fl01"]->z
                     );
        else
            setFocus(0,0,0);
        m_xRot = 45.0;
        m_yRot = 0;
        update();
    }
    void setSelectedPoint(QString pointName){
        m_selectedPoint = pointName;
        update();
    }
    void setFocus(float x, float y, float z){
        m_xPos = -x*0.04;
        m_yPos = -y*0.04;
        m_zPos = -z*0.04;
        if(!m_focusedOnTarget){
            m_focusedOnTarget = true;
            m_cameraDistance = -150;
        }
        update();
    }

    void colorForKey(QString key){
        if(key.startsWith('W')){
            if(key==m_selectedPoint)
                glColor3f(1,1,0);
            else
                glColor3f(0,1,0);
        }else if(m_activeMap->m_wayPoints[key]->m_events.contains("stop")){
            if(key==m_selectedPoint)
                glColor3f(0,1,1);
            else
                glColor3f(0,0.6f,1);
        }else{
            if(key==m_selectedPoint)
                glColor3f(0,0.6f,1);
            else
                glColor3f(0,0,0.7f);
        }
    }
};

#endif // GLVIEW_H
