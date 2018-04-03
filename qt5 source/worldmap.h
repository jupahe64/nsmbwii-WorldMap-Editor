#ifndef WORLDMAPDEF_H
#define WORLDMAPDEF_H

#include <QVector3D>
#include <QtCore>

class WorldMap
{
public:
    struct WayPoint
    {
        enum Representation{
            NONE,
            TOAD_GREEN,
            TOAD_YELLOW,
            TOAD_RED,
            TOWER,
            CASTLE,
            FINAL_CASTLE,
            GHOST,
            ANCHOR,
            WARP_CANNON,
            PEACHS_CASTLE
        };

        float x,y,z;

        Representation representation;

        QStringList indirectConnections;
        QStringList events;
        QStringList exitAnims;
        QStringList secretExitAnims;

        QList<Route*> connectedRoutes;

        void setRepresentationFromChildBone(QString childBoneName);

        //from scratch
        WayPoint(float x, float y, float z, Representation representation);

        //default constructor
        WayPoint();
    };

    struct Route
    {
        int indexWaypoint1, indexWaypoint1;
        Route();
        Route(QString waypoint1, QString waypoint2);
    }

    WorldMap();

    QMap<QString,WayPoint> wayPoints;
};

#endif // WORLDMAPDEF_H
