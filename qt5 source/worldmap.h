#ifndef WORLDMAPDEF_H
#define WORLDMAPDEF_H

#include <QVector3D>
#include <QtCore>

class WorldMap
{
public:
    struct Route;

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

        Representation m_representation;

        QStringList m_indirectConnections;
        QStringList m_events;
        QStringList m_exitAnims;
        QStringList m_secretExitAnims;

        QList<WorldMap::Route*> m_connectedRoutes;

        void setRepresentationFromChildBone(QString childBoneName);

        //from scratch
        WayPoint(float x, float y, float z, Representation m_representation);

        //default constructor
        WayPoint();
    };
    struct Route
    {
        Route();
        WayPoint* m_waypoint1;
        WayPoint* m_waypoint2;
        QString m_animation;
        bool *m_thornPhases = new bool[3];
    };

    struct RoutePath
    {
        RoutePath();
        QList<WayPoint*> m_nodes;
    };

    WorldMap();

    QMap<QString,WayPoint*> m_wayPoints;
    QMap<QString,Route*> m_routes;
    QMap<QString,RoutePath*> m_routePaths;
};

#endif // WORLDMAPDEF_H
