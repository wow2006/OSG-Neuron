#ifndef NEURONNODE_H
#define NEURONNODE_H

#include <math.h>
#include <QObject>
#include <osg/MatrixTransform>
#include <osgDB/ReadFile>
#include <osg/Material>
#include <osg/BlendFunc>
#include <osgGA/GUIEventAdapter>
#include <iostream>

#include "shader.h"

class changePos : public osg::Uniform::Callback
{
public:
    virtual void operator ()( osg::Uniform* uniform , osg::NodeVisitor* nv )
    {
        const osg::FrameStamp* fs = nv->getFrameStamp();
        if( !fs ) return;

            float intensity =  sin( (float)fs->getFrameNumber()  );
            uniform->set( intensity  );
    }
};


static osg::ref_ptr<osg::Node> basicNode = osgDB::readNodeFile("sphere.obj");

class neuronNode
{
public:
    neuronNode();
    osg::Group *get();
    void setTrans(int x,int y,int z);
    void setShader();

private:
    osg::ref_ptr<osg::Node>                        _model;
    osg::ref_ptr<osg::MatrixTransform>       _trans;
    osg::StateSet*                                         _stateset;
    osg::Vec3                                                _location;
    osg::ref_ptr<osg::Uniform>                    _uni;

protected:
    void start();
    void update();
};

#endif // NEURONNODE_H
