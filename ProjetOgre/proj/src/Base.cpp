////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "Base.h"

/*****************************************************************************/
Base::Base(Scene& _scene,float _mass):scene(_scene),node(scene.sceneManager->getRootSceneNode()->createChildSceneNode()),
        box(scene.sceneManager,node),object(scene.sceneManager,node),gravityCenter(scene.sceneManager,node),mass(_mass)
{

}

/*****************************************************************************/
Base::Base(Scene& _scene,Ogre::SceneNode *parent,float _mass):scene(_scene),node(parent->createChildSceneNode()),
        box(scene.sceneManager,node),object(scene.sceneManager,node),gravityCenter(scene.sceneManager,node),mass(_mass)
{

}

/*****************************************************************************/
Base::~Base()
{
    scene.sceneManager->destroySceneNode(node);
}

/*****************************************************************************/
void Base::setPosition(float x,float y,float z)
{
    node->setPosition(x,y,z);
}

/*****************************************************************************/
void Base::setPosition(Ogre::Vector3 position)
{
    node->setPosition(position);
}

/*****************************************************************************/
Ogre::Vector3 Base::getPosition()
{
    return node->getPosition();
}

/*****************************************************************************/
Ogre::Vector3 Base::getGravityCenter()
{
    return gravityCenter.getPosition();
}

/*****************************************************************************/
Ogre::Vector3 Base::getGravityCenterMorePosition()
{
    return getGravityCenter() + getPosition();
}

/*****************************************************************************/
void Base::CreateGravityObject()
{
    gravityCenter.BecomePavet(Volume(0.5,0.5,0.5),Ogre::ColourValue::Green);
}
