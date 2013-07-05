#include <QTimer>
#include <QObject>
#include <osg/Program>
#include <osgDB/ReadFile>

#ifndef SHADER_H
#define SHADER_H

static osg::Vec2 _change = osg::Vec2( 0.4f , 0.6f);

class changePos : public osg::Uniform::Callback
{
public:
    virtual void operator ()( osg::Uniform* uniform , osg::NodeVisitor* nv )
    {
        float x = _change.x();
        float y = _change.y();

        x += 0.02;
        y += 0.02;

        if ( y > 1)
        {
            x = -1;
            y = -0.98;
        }

        _change.set( x , y );
        //std::cout << x << "\t" << y << std::endl;
        uniform->set( _change );
    }

};

class shader
{
public:
    shader( osg::StateSet* ss );
    osg::Program* getShader();

protected:
    osg::ref_ptr<osg::Program> _program;
    osg::StateSet* _stateset;
    osg::ref_ptr<osg::Uniform> change;

private:
    void set();
};

#endif // SHADER_H
