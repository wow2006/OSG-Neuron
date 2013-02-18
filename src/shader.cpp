#include "shader.h"

shader::shader(bool active)
{
    static const char* vertSource = {
        "void main()\n"
        "{\n"
            "gl_Position = ftransform();\n"
        "}\n"
    };

    static const char* fragSource = {
        "void main()\n"
        "{\n"
            "gl_FragColor = vec4(1.);\n"
        "}\n"
    };

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
        vertShader->setShaderSource( vertSource );
        fragShader->setShaderSource( fragSource );
    }
}

osg::Program* shader::getShader()
{
    return _program;
}
