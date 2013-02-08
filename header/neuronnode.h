#ifndef NEURONNODE_H
#define NEURONNODE_H

#include <osg/MatrixTransform>
#include <osgDB/ReadFile>
#include <osg/Material>
#include <iostream>

#include "shader.h"

class neuronNode
{
public:
    neuronNode();
    osg::Group *get();
    void setlocation(int x , int y , int z);

private:
    osg::ref_ptr<osg::Node>             _model;
    osg::ref_ptr<osg::MatrixTransform>  _mt ;
    osg::StateSet*                      _stateset;
    osg::Vec3                           _location;
    osg::Vec4                           _color;


protected:
    void setShader();
    void start();

};

#endif // NEURONNODE_H
