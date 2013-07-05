#ifndef BASENEURON_H
#define BASENEURON_H
#include "base.h"
#include <osg/Node>
#include <osg/Vec3>
#include <osg/LOD>

class baseNeuron : public Base
{
    Q_OBJECT
    /*
     *  base class for nueorn node
     */
public:
    // [ 1 ] start constructor
    baseNeuron() : Base()
    {
        start();
    }
    baseNeuron( osg::Vec3 location ) : Base( location )
    {
        start();
    }
    // [ 1 ] end  constructor

    // [ 4 ] stat return
    virtual QString toString();
    // [ 4 ] end  return

    // [ 5 ] start destructor
    ~baseNeuron();
    // [ 5 ] end  destructor

protected:
    void start();
    osg::Camera* textHUD();
    osg::ref_ptr<osg::StateSet>         _stateset;
    osg::ref_ptr<osg::Node> node;

private:
    osg::ref_ptr<osg::LOD>              _lod;
    QString                             _neuronName;

};

#endif // BASENEURON_H
