#include "neuronnode.h"

neuronNode::neuronNode()
{
    _model = osgDB::readNodeFile("sphere.obj");
    //this =  new osg::MatrixTransform;
    this->addChild( _model.get() );
    _stateset = _model->getOrCreateStateSet();
    start();
}

osg::Group* neuronNode::get()
{
    return this->asGroup();
}

void neuronNode::start()
{
    //osg::ref_ptr<osg::Geometry> geom = dynamic_cast<osg::Geometry*>(_model.get());
    this->setMatrix( osg::Matrix::translate( _location.x() , _location.y() , _location.z() ) );
    setShader();
}

void neuronNode::setShader()
{
    shader _shader;
    _stateset->setAttributeAndModes( _shader.getShader() );
}
