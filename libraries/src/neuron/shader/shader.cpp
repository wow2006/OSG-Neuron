#include "shader.h"

shader::shader( osg::StateSet* ss )
{
    change = new osg::Uniform( "change" , osg::Vec2());
    _stateset = ss;
    osg::ref_ptr<osg::Shader> vertShader = new osg::Shader( osg::Shader::VERTEX );
    osg::ref_ptr<osg::Shader> fragShader = new osg::Shader( osg::Shader::FRAGMENT );

    _program = new osg::Program;
    _program->addShader( vertShader.get() );
    _program->addShader( fragShader.get() );

    vertShader->loadShaderSourceFromFile("shader/active.vert");
    fragShader->loadShaderSourceFromFile("shader/active.frag");
    this->set();
}

osg::Program* shader::getShader()
{
    return _program;
}

void shader::set()
{
    // set data uniform for shader
    _stateset->setAttribute( _program.get() );
    _stateset->addUniform( change );

    _stateset->addUniform( new osg::Uniform( "Kd" , osg::Vec3( 1.0f , 0.0f , 0.0f ) ) );
    _stateset->addUniform( new osg::Uniform( "Ka" , osg::Vec3( 0.1f , 0.0f , 0.0f ) ) );
    _stateset->addUniform( new osg::Uniform( "Ks" , osg::Vec3( 0.0f , 0.0f , 0.0f ) ) );
    _stateset->addUniform( new osg::Uniform( "shin" , 0.1f ) );

    change->setUpdateCallback(  new changePos );
}
