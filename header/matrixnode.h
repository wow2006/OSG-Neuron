#ifndef MATRIXNODE_H
#define MATRIXNODE_H
#include "neuronnode.h"

class matrixNode
{
public:
    matrixNode();
    inline void setLocation(osg::Vec3 &locarion);
    osg::Group *get();

private:
    osg::Vec3 _location;
    osg::Vec3 _dim;
    osg::ref_ptr<osg::MatrixTransform> _mtx;
    int num;

protected:
    void run();

};

#endif // MATRIXNODE_H
