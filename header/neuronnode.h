#ifndef NEURONNODE_H
#define NEURONNODE_H

#include <osg/MatrixTransform>
#include <osgDB/ReadFile>
#include <osg/Material>
#include <iostream>

#include "shader.h"

class neuronNode : public osg::MatrixTransform
{
public:
    neuronNode();
    osg::Group *get();
    void setShader();

private:
    osg::ref_ptr<osg::Node>             _model;
    osg::StateSet*                      _stateset;
    osg::Vec3                           _location;
    osg::Vec4                           _color;


protected:
    void start();

};

#endif // NEURONNODE_H
