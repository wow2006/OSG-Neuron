#ifndef MATRIXNODE_H
#define MATRIXNODE_H
#include "neuronnode.h"

class matrixNode
{
public:
    matrixNode();
    osg::Group* get();
    void setlocation(int x,int y,int z);

private:
    osg::Vec3 _location;
    osg::Vec3 _dim;
    osg::ref_ptr<osg::MatrixTransform> _mtx;
    int num;

protected:
    void run();

};

#endif // MATRIXNODE_H
