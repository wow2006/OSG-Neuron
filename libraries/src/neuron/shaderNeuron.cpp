#include "neuron/shaderNeuron.h"
#include "shader/shader.h"
#include <osgDB/ReadFile>

//  flag to check if to change color of neuron or not
//  bool flag = true;

QString shaderNeuron::toString()
{
    QString temp;
    temp =  " " + QString::number(_location.x()) + " " + QString::number(_location.y())
                       + " " + QString::number(_location.z()) + "\n";
//    foreach( int value , _frames )
//        temp += QString::number( value ) + " ";
    temp += "\n \n";
    return temp;
}

void shaderNeuron::setAttr()
{
    _prgm  = new osg::Program;
    _color = new osg::Uniform( osg::Uniform::FLOAT_VEC4 , "change" );
    CB = new Example;
    _color->setUpdateCallback( CB.get() );
    shader prog( _stateset );
    _stateset->addUniform( _color.get() );
    node->setStateSet( _stateset.get() );
}

void shaderNeuron::shaderUpdate()
{
    CB->flag = false;
}
