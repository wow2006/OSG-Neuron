#ifndef SHADERNEURON_H
#define SHADERNEURON_H
#include "baseNeuron.h"
#include <osg/LOD>
#include <osg/Program>
#include <osg/StateSet>
#include <osg/Uniform>
#include <QList>
#include <QDebug>

class Example : public osg::Uniform::Callback
{
public:
    Example()
    {
        flag = true;
        counter = 0;
    }

    virtual void operator ()( osg::Uniform* uniform , osg::NodeVisitor* nv)
    {
        if( !flag )
        {
            if( counter < 50 )
            {
                uniform->set( osg::Vec4( 1.0f, 0.0f , 0.0f , 1.0f ) );
                qDebug() << "working";
                counter++;
            }
            else
            {
                flag = true;
                counter = 0;
            }
        }
        else
        {
            uniform->set( osg::Vec4( 0.0f, 0.0f , 1.0f , 1.0f ) );
        }
    }
    bool flag;
private:
    int counter;
};

class shaderNeuron : public baseNeuron
{
    Q_OBJECT
public:
    shaderNeuron() : baseNeuron()
    {
        setAttr();
    }
    shaderNeuron( osg::Vec3 location ) : baseNeuron( location )
    {
        setAttr();
    }
    virtual QString toString();
    void shaderUpdate();

private:
    void setAttr();
    osg::ref_ptr<Example>           CB ;
    osg::ref_ptr<osg::Program>      _prgm;
    osg::ref_ptr<osg::Uniform>      _color;
};

#endif // SHADERNEURON_H
