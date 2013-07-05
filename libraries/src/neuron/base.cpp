#include "base.h"
Base::Base(osg::Vec3 location  , QObject *parent) :
    QObject(parent)
{
    _mt = new osg::MatrixTransform;
    _switch = new osg::Switch;

    _location = location;
    _mt->addChild( _switch.get() );
    this->updateAtt();
}

void Base::setLocation( osg::Vec3& location )
{
    _location = location;
    this->updateAtt();
}

osg::Vec3& Base::getLocation()
{
    return _location;
}

osg::Group* Base::get()
{
    return _mt->asGroup();
}

void Base::updateAtt()
{
    _mt->setMatrix( osg::Matrix::translate( _location.x() , _location.y() , _location.z() ) );
}

// Slots methods
extern void Base::hide()
{
    _switch->setAllChildrenOff();
}

extern void Base::show()
{
    _switch->setAllChildrenOn();
}
