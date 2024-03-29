#ifndef __ORBITCAMERA_H__
#define __ORBITCAMERA_H__

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <Ogre.h>
#include <OISMouse.h>

class OrbitCamera
{
private:
    Ogre::Camera *camera;
    Ogre::Viewport *viewport;
    Ogre::SceneNode *targetNode;
    Ogre::SceneManager *sceneMgr;

    bool orbiting;
    bool zooming;

public:
    OrbitCamera(Ogre::SceneManager *sceneMgr, Ogre::SceneNode *target);
    ~OrbitCamera();
    void updateMovement(const OIS::MouseEvent &evt);
    void updateOrbitingMovement(float x_rel,float y_rel,float z_rel);
    void updateOrbitingMovement(float rel);

    void setTarget(Ogre::SceneNode * target);

    Ogre::Camera *getCamera(void);
    bool getOrbiting(void);
    void setOrbiting(bool orbiting);
    bool getZooming(void);
    void setZooming(bool zooming);


    Ogre::Ray getRay();

};

#endif // __ORBITCAMERA_H__
