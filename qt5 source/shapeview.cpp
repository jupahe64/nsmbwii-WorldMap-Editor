#include "shapeview.h"

#include <QPainter>

//define Processing like functions

#define NO_FILL setBrush(QBrush(QColor(0,0,0,0)))
#define FILL(r,g,b) setBrush(QBrush(QColor(r,g,b)))
#define FILL_RGBA(r,g,b,a) setBrush(QBrush(QColor(r,g,b,a)))

#define NO_STROKE setPen(QColor(0,0,0,0))
#define STROKE(r,g,b) setPen(QColor(r,g,b))
#define STROKE_RGBA(r,g,b,a) setPen(QColor(r,g,b,a))

ShapeView::ShapeView(QWidget *parent):
    QWidget(parent)
{

}

void ShapeView::paintEvent(QPaintEvent *e)
{
    if(m_activeMap!=0){
        if(m_activeMap->m_routePaths.contains(m_selectedPath)){
            float minX = 100000;
            float maxX = -100000;
            float minZ = 100000;
            float maxZ = -100000;
            qDebug() << "paintShapes";
            foreach(WorldMap::WayPoint *point, m_activeMap->m_routePaths[m_selectedPath]->m_nodes){
                foreach(WorldMap::Route *route, point->m_connectedRoutes){
                    minX = fminf(minX,route->m_waypoint1->x);
                    maxX = fmaxf(maxX,route->m_waypoint1->x);
                    minZ = fminf(minZ,route->m_waypoint1->z);
                    maxZ = fmaxf(maxZ,route->m_waypoint1->z);

                    minX = fminf(minX,route->m_waypoint2->x);
                    maxX = fmaxf(maxX,route->m_waypoint2->x);
                    minZ = fminf(minZ,route->m_waypoint2->z);
                    maxZ = fmaxf(maxZ,route->m_waypoint2->z);
                }
            }

            qDebug() << QString::number(minX) << QString::number(maxX) << QString::number(minZ) << QString::number(maxZ);
            float boundsWidth = maxX-minX+2;
            float boundsHeight = maxZ-minZ+2;

            float boundsCenterX = (minX+maxX)*0.5;
            float boundsCenterY = (minZ+maxZ)*0.5;

            float fitScale = fminf(width()/boundsWidth,height()/boundsHeight);

            float pointSize = fmin(width(),height())/32;

            begin(this);
            setRenderHint(RenderHint::Antialiasing);

            FILL(0,255,0);
            translate(width()/2,height()/2);
            foreach(WorldMap::WayPoint *point, m_activeMap->m_routePaths[m_selectedPath]->m_nodes){
                foreach(WorldMap::Route *route, point->m_connectedRoutes){
                    qDebug() << "Route";

                    drawLine(
                                (route->m_waypoint1->x-boundsCenterX)*fitScale*0.8,
                                (route->m_waypoint1->z-boundsCenterY)*fitScale*0.8,
                                (route->m_waypoint2->x-boundsCenterX)*fitScale*0.8,
                                (route->m_waypoint2->z-boundsCenterY)*fitScale*0.8
                                );

                }
            }

            foreach(WorldMap::WayPoint *point, m_activeMap->m_routePaths[m_selectedPath]->m_nodes){
                drawEllipse(
                            (point->x-boundsCenterX)*fitScale*0.8-pointSize/2,
                            (point->z-boundsCenterY)*fitScale*0.8-pointSize/2,
                            pointSize,pointSize
                            );
            }

            end();
        }
    }
}
