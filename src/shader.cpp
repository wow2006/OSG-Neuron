#include "shader.h"

shader::shader(bool active)
{
    osg::ref_ptr<osg::Shader> vertShader = new osg::Shader( osg::Shader::VERTEX );
    osg::ref_ptr<osg::Shader> fragShader = new osg::Shader( osg::Shader::FRAGMENT );

    _program = new osg::Program;
    _program->addShader( vertShader.get() );
    _program->addShader( fragShader.get() );

    if (active)
    {
        vertShader->loadShaderSourceFromFile("shader/vertShader.vert");
        fragShader->loadShaderSourceFromFile("shader/fragShader.frag");
    }
    else
    {
        vertShader->loadShaderSourceFromFile("shader/vertShader.vert");
        fragShader->loadShaderSourceFromFile("shader/fragShader.frag");
    }
}

osg::Program* shader::getShader()
{
    return _program;
}
