#include "worldmap.h"

WorldMap::WorldMap()
{

}

void WorldMap::WayPoint::setRepresentationFromChildBone(QString childBoneName)
{
    if (childBoneName.startsWith("cobKinoko1up"))
        this->representation = TOAD_GREEN;

    else if (childBoneName.startsWith("cobKinokoStar"))
        this->representation = TOAD_YELLOW;

    else if (childBoneName.startsWith("cobKinokoRed"))
        this->representation = TOAD_RED;

    else if (childBoneName=="cobToride")
        this->representation = TOWER;

    else if (childBoneName=="cobCastle")
        this->representation = CASTLE;

    else if (childBoneName=="cobKoopaCastle")
        this->representation = FINAL_CASTLE;

    else if (childBoneName=="cobGhost")
        this->representation = GHOST;

    else if (childBoneName=="cobAnchor")
        this->representation = ANCHOR;

    else if (childBoneName=="cobCannon")
        this->representation = WARP_CANNON;

    else if (childBoneName=="cobPeachCastle")
        this->representation = PEACHS_CASTLE;

    else
        this->representation = NONE;

}

WorldMap::WayPoint::WayPoint(float x, float y, float z, WorldMap::WayPoint::Representation representation)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->representation = representation;
}

WorldMap::WayPoint::WayPoint(){
    this->representation = NONE;
}

WorldMap::Route::Route()
{
    indexWaypoint1 = -1;
    indexWaypoint2 = -1;
}

WorldMap::Route::Route(QString waypoint1, QString waypoint2)
{

}
