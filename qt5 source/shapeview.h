#ifndef SHAPEVIEW_H
#define SHAPEVIEW_H

#include "worldmap.h"

#include <QBrush>
#include <QPainter>
#include <QPen>
#include <QPixmap>
#include <QWidget>

//! [0]
class ShapeView : public QWidget, public QPainter
{
    Q_OBJECT

public:

    ShapeView(QWidget *parent = 0);

    void setActiveMap(WorldMap *map){
        m_activeMap = map;
        m_selectedPath = "";
        update();
    }

    void setSelectedPath(QString pathName){
        m_selectedPath = pathName;
        update();
    }

    WorldMap *m_activeMap;

    QString m_selectedPath;
protected:
    void paintEvent(QPaintEvent *e) override;
};
//! [0]

#endif // SHAPEVIEW_H
