////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "Volume.h"

/*****************************************************************************/
Volume::Volume():w(0.f),h(0.f),d(0.f)
{

}

/*****************************************************************************/
Volume::Volume(float weight,float heigth,float depth):w(weight),h(heigth),d(depth)
{

}

/*****************************************************************************/
Volume::Volume(ArrayPoints& points):w(0.f),h(0.f),d(0.f)
{

    Ogre::Vector3 min,max;
    MinMaxFromPoints(points,min,max);
    w = max.x-min.x;
    h = max.y-min.y;
    d = max.z-min.z;
}

/*****************************************************************************/
Volume::~Volume()
{
    //dtor
}

/*****************************************************************************/
float Volume::getPositionFace(Relative face)
{
    return getPositionFace(Ogre::Vector3(0.f,0.f,0.f),face);
}

/*****************************************************************************/
float Volume::getPositionFace(Ogre::Vector3 pos,Relative face)
{
    switch (face)
    {
    case NONE:
        break;
    case POS_X:
        return w/2 + pos.x;
    case NEG_X:
        return -w/2 + pos.x;
    case POS_Y:
        return h/2 + pos.y;
    case NEG_Y:
        return -h/2 + pos.y;
    case POS_Z:
        return d/2 + pos.z;
    case NEG_Z:
        return -d/2 + pos.z;
    }
    return 0.f;
}

/*****************************************************************************/
void Volume::addArrayPoint(ArrayPoints& points)
{
    points.push_back(Ogre::Vector3(getPositionFace(POS_X),getPositionFace(POS_Y),getPositionFace(POS_Z)));
    points.push_back(Ogre::Vector3(getPositionFace(NEG_X),getPositionFace(POS_Y),getPositionFace(POS_Z)));
    points.push_back(Ogre::Vector3(getPositionFace(POS_X),getPositionFace(POS_Y),getPositionFace(NEG_Z)));
    points.push_back(Ogre::Vector3(getPositionFace(NEG_X),getPositionFace(POS_Y),getPositionFace(NEG_Z)));

    points.push_back(Ogre::Vector3(getPositionFace(POS_X),getPositionFace(NEG_Y),getPositionFace(POS_Z)));
    points.push_back(Ogre::Vector3(getPositionFace(POS_X),getPositionFace(NEG_Y),getPositionFace(NEG_Z)));
    points.push_back(Ogre::Vector3(getPositionFace(NEG_X),getPositionFace(NEG_Y),getPositionFace(POS_Z)));
    points.push_back(Ogre::Vector3(getPositionFace(NEG_X),getPositionFace(NEG_Y),getPositionFace(NEG_Z)));
}

/*****************************************************************************/
void Volume::MinMaxFromPoints(ArrayPoints& points,Ogre::Vector3& min,Ogre::Vector3& max)
{
    if(points.size()>0)
    {
        Ogre::Vector3 firstPoint = *(points.begin());
        max = firstPoint;
        min = firstPoint;
        for(ArrayPoints::iterator it = points.begin() ; it != points.end() ; it++ )
        {
            Ogre::Vector3 point = *it;
            if(max.x<point.x)
                max.x = point.x;
            if(max.y<point.y)
                max.y = point.y;
            if(max.z<point.z)
                max.z = point.z;
            if(min.x>point.x)
                min.x = point.x;
            if(min.y>point.y)
                min.y = point.y;
            if(min.z>point.z)
                min.z = point.z;
        }
    }
    else
    {
        min = Ogre::Vector3::ZERO;
        max = Ogre::Vector3::ZERO;
    }
}

/*****************************************************************************/
Ogre::Vector3 Volume::averagePoints(ArrayPoints points)
{
        Ogre::Vector3 bary = Ogre::Vector3::ZERO;
        if(points.size() > 0)
        {
            ArrayPoints::iterator it;
            for(it=points.begin();it!=points.end();it++)
            {
                Ogre::Vector3 point = *it;
                bary += point;
            }
            bary = bary / points.size();
        }
        return bary;
}

/*****************************************************************************/
bool Volume::getRelatif(std::string str,Relative &relative)
{
    if(str=="none")
    {
        relative = NONE;
        return true;
    }
    else if(str=="pos_x")
    {
       relative = POS_X;
       return true;
    }
    else if(str=="neg_x")
    {
        relative = NEG_X;
        return true;
    }
    else if(str=="pos_y")
    {
        relative = POS_Y;
        return true;
    }
    else if(str=="neg_y")
    {
        relative = NEG_Y;
        return true;
    }
    else if(str=="pos_z")
    {
        relative = POS_Z;
        return true;
    }
    else if(str=="neg_z")
    {
        relative = NEG_Z;
        return true;
    }
    return false;
}
