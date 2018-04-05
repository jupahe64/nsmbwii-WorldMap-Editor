#ifndef GLVIEW_H
#define GLVIEW_H

#include <QMatrix4x4>
#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>
#include <qevent.h>
#include "worldmap.h"

class GLView : public QOpenGLWidget
{
    Q_OBJECT

private:
    WorldMap *m_activeMap;
    QString m_selectedPoint;

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
public:
    GLView(QWidget *parent = 0);
    ~GLView();
    void paintGL();
    void initializeGL();
    void mouseMoveEvent(QMouseEvent *e);
    void wheelEvent(QWheelEvent *e);
    void resizeGL(int w, int h);

    void setActiveMap(WorldMap *map){
        m_activeMap = map;
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
        }else if(m_activeMap->m_wayPoints[key].m_events.contains("stop")){
            if(key==m_selectedPoint)
                glColor3f(0,1,1);
            else
                glColor3f(0,0.6,1);
        }else{
            if(key==m_selectedPoint)
                glColor3f(0,0.6,1);
            else
                glColor3f(0,0,0.7);
        }
    }
};

#endif // GLVIEW_H
