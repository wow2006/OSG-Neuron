#ifndef STANDNEURON_H
#define STANDNEURON_H
#include <osg/Vec3>
#include <osg/Program>
#include "baseNeuron.h"
#include "shader/standShader.h"

class standNeuron : public baseNeuron
{
    Q_OBJECT
public:
    standNeuron() : baseNeuron()
    {
        _prgm = new osg::Program;
        _prog = new standShader( _stateset );
        node->setStateSet( _stateset );
    }
    standNeuron( osg::Vec3 location ) : baseNeuron( location )
    {
        _prgm = new osg::Program;
        _prog = new standShader( _stateset );
        node->setStateSet( _stateset );
    }
    virtual QString toString()
    {
    }

public slots:
    void selectUpdate( float selectedVertex )
    {
        _prog->setVertex( selectedVertex );
    }
    void selectSpeed( int value )
    {
        _prog->setSpeed( value );
    }

private:
    standShader*         _prog;
    osg::ref_ptr<osg::Program>          _prgm;
};

#endif // STANDNEURON_H
