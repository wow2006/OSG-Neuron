#include "standShader.h"

static float z = 0;
static float value = 35;
static float inc = 0.1;

void updateState::operator ()( osg::Uniform* node , osg::NodeVisitor* nv )
{
    float x = z;
    float y = z - inc;
    x -= inc;
    y -= inc;
    if ( x < -40 )
    {
        x = value;
        y = value - inc;
    }
    z = x;
    osg::Vec2 changer(x,y);
    node->set( changer );
}

standShader::standShader( osg::StateSet* ss )
{
    change = new osg::Uniform( "change" , osg::Vec2());
    _stateset = ss;
    osg::ref_ptr<osg::Shader> vertShader = new osg::Shader( osg::Shader::VERTEX );
    osg::ref_ptr<osg::Shader> fragShader = new osg::Shader( osg::Shader::FRAGMENT );

    _program = new osg::Program;
    _program->addShader( vertShader.get() );
    _program->addShader( fragShader.get() );

    vertShader->loadShaderSourceFromFile("shader/standVert.vert");
    fragShader->loadShaderSourceFromFile("shader/standFrag.frag");
    this->set();
}

osg::Program* standShader::getShader()
{
    return _program;
}

void standShader::set()
{
    // set data uniform for shader
    _stateset->setAttribute( _program.get() );
    _stateset->addUniform( change );

    _stateset->addUniform( new osg::Uniform( "Kd" , osg::Vec3( 1.0f , 0.0f , 0.0f ) ) );
    _stateset->addUniform( new osg::Uniform( "Ka" , osg::Vec3( 0.1f , 0.0f , 0.0f ) ) );
    _stateset->addUniform( new osg::Uniform( "Ks" , osg::Vec3( 0.0f , 0.0f , 0.0f ) ) );
    _stateset->addUniform( new osg::Uniform( "shin" , 0.1f ) );
    _ptrShader = new updateState;
    change->setUpdateCallback( _ptrShader.get() );
}

void standShader::setVertex(float zVertex)
{
    if( zVertex != value )
    {
        z = zVertex;
        value = zVertex;
    }
}

void standShader::setSpeed(int value)
{
    inc = (float)value/10.0;
}
