#include <QTimer>
#include <QObject>
#include <osg/Program>
#include <osgDB/ReadFile>
#include <QDebug>

#ifndef STANDHADER_H
#define STANDHADER_H

static osg::Vec2 _change;

class updateState : public osg::Uniform::Callback
{
public:
    virtual void operator ()( osg::Uniform* node , osg::NodeVisitor* nv );
};

class standShader
{
public:
    standShader( osg::StateSet* ss );
    osg::Program* getShader();
    void setVertex( float zVertex );
    void setSpeed( int value );

protected:
    osg::ref_ptr<osg::Program> _program;
    osg::StateSet* _stateset;
    osg::ref_ptr<osg::Uniform> change;
    osg::ref_ptr<updateState> _ptrShader;

private:
    void set();
};

#endif // SHADER_H
