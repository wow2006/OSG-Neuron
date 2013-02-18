#include "neuronnode.h"

neuronNode::neuronNode()
{
    _model = basicNode;
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
    this->setMatrix( osg::Matrix::translate( _location.x() , _location.y() , _location.z() ) );
    setShader(true);
}

void neuronNode::setShader(bool active)
{
    shader _shader(active);
    _stateset->setAttributeAndModes( _shader.getShader() );
}
