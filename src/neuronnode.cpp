#include "neuronnode.h"

neuronNode::neuronNode()
{
    _model = basicNode;
    _trans = new osg::MatrixTransform;
    _trans->addChild( _model.get() );
    _stateset = _model->getOrCreateStateSet();
    start();
}

void neuronNode::setTrans(int x, int y, int z)
{
   _location.set( x , y , z );
   _trans->setMatrix( osg::Matrix::translate( _location.x() , _location.y() , _location.z() ) );
}

osg::Group* neuronNode::get()
{
    return _trans->asGroup();
}

void neuronNode::start()
{
    _trans->setMatrix( osg::Matrix::translate( _location.x() , _location.y() , _location.z() ) );
    setShader();
}

void neuronNode::setShader()
{
    shader _shader;
    _stateset->setAttributeAndModes( _shader.getShader() );
    _uni = new osg::Uniform( "intensity" , float(1.0) );
    _uni->setUpdateCallback( new changePos );

    _stateset->addUniform(_uni.get());
}
