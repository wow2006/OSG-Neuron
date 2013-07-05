#include "baseNeuron.h"
#include <osgDB/ReadFile>
#include <osgUtil/Simplifier>

//static osg::Node* node01 = osgDB::readNodeFile("uvNuron.obj");
//static osg::Node* node02 = dynamic_cast<osg::Node*>(node01->clone(osg::CopyOp::DEEP_COPY_ALL));
//static osg::Node* node03 = dynamic_cast<osg::Node*>(node01->clone(osg::CopyOp::DEEP_COPY_ALL));

// [ 4 ] start return methods
QString baseNeuron::toString()
{
    QString temp;
    temp = _neuronName + " " + QString::number(_location.x()) + " " + QString::number(_location.y())
                       + " " + QString::number(_location.z()) + "\n";
//    foreach( int value , _frames )
//        temp += QString::number( value ) + " ";
    temp += "\n \n";
    return temp;
}
// [ 4 ] end return

void baseNeuron::start()
{
    // Decare
    node = osgDB::readNodeFile("uvNuron.obj");
    _lod   = new osg::LOD;
    _stateset = new osg::StateSet;

    _mt->addChild( _switch.get() );
    _switch->addChild( node.get() );

//    // Load LOD to reduce memory
//    _lod->addChild( node01 , 1000.0f , FLT_MAX );
//    _lod->addChild( node02 , 500.0f , 1000.0f );
//    _lod->addChild( node03 , 0.0f , 500.0f );

//    node01->setStateSet( _stateset.get() );
//    node02->setStateSet( _stateset.get() );
//    node03->setStateSet( _stateset.get() );
}

// [ 5 ] start destructor
baseNeuron::~baseNeuron()
{
//    free( node01 );
//    free( node02 );
//    free( node03 );
}
// [ 5 ] end destructor
