#include "shader.h"

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


shader::shader()
{
    osg::ref_ptr<osg::Shader> vertShader = new osg::Shader( osg::Shader::VERTEX );
    osg::ref_ptr<osg::Shader> fragShader = new osg::Shader( osg::Shader::FRAGMENT );

    _program = new osg::Program;
    _program->addShader( vertShader.get() );
    _program->addShader( fragShader.get() );

    vertShader->loadShaderSourceFromFile("shader/vertShader.vert");
    fragShader->loadShaderSourceFromFile("shader/fragShader.frag");
}

osg::Program* shader::getShader()
{
    return _program;
}
