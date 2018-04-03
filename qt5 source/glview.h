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

    QOpenGLShaderProgram *m_defaultShader;
    int m_projMatrixLoc;
    int m_mvMatrixLoc;
    int m_normalMatrixLoc;
    int m_lightPosLoc;
    QMatrix4x4 m_proj;
    QMatrix4x4 m_camera;
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
    void resizeGL(int w, int h);

    void setActiveMap(WorldMap *map){
        m_activeMap = map;
        update();
    }
    void setSelectedPoint(QString pointName){
        m_selectedPoint = pointName;
        update();
    }
};

#endif // GLVIEW_H
