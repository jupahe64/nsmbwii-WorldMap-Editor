#include "worldmap.h"

WorldMap::WorldMap()
{

}

void WorldMap::WayPoint::setRepresentationFromChildBone(QString childBoneName)
{
    if (childBoneName.startsWith("cobKinoko1up"))
        this->m_representation = TOAD_GREEN;

    else if (childBoneName.startsWith("cobKinokoStar"))
        this->m_representation = TOAD_YELLOW;

    else if (childBoneName.startsWith("cobKinokoRed"))
        this->m_representation = TOAD_RED;

    else if (childBoneName=="cobToride")
        this->m_representation = TOWER;

    else if (childBoneName=="cobCastle")
        this->m_representation = CASTLE;

    else if (childBoneName=="cobKoopaCastle")
        this->m_representation = FINAL_CASTLE;

    else if (childBoneName=="cobGhost")
        this->m_representation = GHOST;

    else if (childBoneName=="cobAnchor")
        this->m_representation = ANCHOR;

    else if (childBoneName=="cobCannon")
        this->m_representation = WARP_CANNON;

    else if (childBoneName=="cobPeachCastle")
        this->m_representation = PEACHS_CASTLE;

    else
        this->m_representation = NONE;

}

WorldMap::WayPoint::WayPoint(float x, float y, float z, WorldMap::WayPoint::Representation representation)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->m_representation = representation;
}

WorldMap::WayPoint::WayPoint(){
    this->m_representation = NONE;
}

WorldMap::Route::Route()
{

}

WorldMap::RoutePath::RoutePath()
{

}
