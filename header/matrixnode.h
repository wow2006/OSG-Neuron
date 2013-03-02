#ifndef MATRIXNODE_H
#define MATRIXNODE_H
#include "neuronnode.h"

class  nodeVisitor : public osg::NodeVisitor {
public :
    nodeVisitor() : NodeVisitor( NodeVisitor::TRAVERSE_ALL_CHILDREN ) {};

    osg::Geometry *_geom;

    virtual ~nodeVisitor(){};

    virtual void apply(osg::Group &node){
        traverse(node);
    }// apply( osg::Group &node )

    virtual void apply ( osg::Node &node ){
        traverse( node );
    } // apply( osg::Node &node )

    virtual void apply( osg::Geode &geode ){
        _geom= geode.getDrawable( 0 )->asGeometry();
    }

    osg::Geometry* getGeom()
    {
        return _geom;
    }
 }; // class nodeVisitor

class matrixNode
{
public:
    matrixNode();
    matrixNode(int x,int y,int z,int dx,int dy,int dz);
    osg::Group* get();
    void setlocation(int x,int y,int z);
    void pulse(int x,int y,int z);
    ~matrixNode()
    {
    }

private:
    osg::Vec3 _location;
    osg::Vec3 _dim;
    osg::ref_ptr<osg::MatrixTransform> _mtx;
    nodeVisitor _nv;
    int num;

protected:
    void run();

};

#endif // MATRIXNODE_H
