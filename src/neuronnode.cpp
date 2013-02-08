#include "neuronnode.h"

neuronNode::neuronNode()
{
    _model = osgDB::readNodeFile("sphere.obj");
    _mt =  new osg::MatrixTransform;
    _mt->addChild( _model.get() );
    _stateset = _model->getOrCreateStateSet();
    start();
}

osg::Group* neuronNode::get()
{
    return _mt->asGroup();
}

void neuronNode::start()
{
    //osg::ref_ptr<osg::Geometry> geom = dynamic_cast<osg::Geometry*>(_model.get());
    _mt->setMatrix( osg::Matrix::translate( _location.x() , _location.y() , _location.z() ) );
    setShader();
}

void neuronNode::setShader()
{
    shader _shader;
    _stateset->setAttributeAndModes( _shader.getShader() );
}

void neuronNode::setlocation(int x , int y ,int z)
{
    _location.set(x,y,z);
    _mt->setMatrix( osg::Matrix::translate( _location.x() , _location.y() ,_location.z() ) );
}
