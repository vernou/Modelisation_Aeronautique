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
Volume::~Volume()
{
    //dtor
}

/*****************************************************************************/
float Volume::getPositionFace(Ogre::Vector3 pos,Relative face)
{
    switch (face)
    {
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
