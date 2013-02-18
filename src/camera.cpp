#include "camera.h"

osg::Camera* camera::setCamera()
{
    return _camera.release();
}

void camera::run()
{
    osg::DisplaySettings* ds = osg::DisplaySettings::instance().get();
    _traits->windowDecoration = false;
    _traits->x = 50;
    _traits->y = 50;
    _traits->width = 640;
    _traits->height = 480;
    _traits->doubleBuffer = true;

    _camera = new osg::Camera;
    _camera->setGraphicsContext( new osgQt::GraphicsWindowQt(_traits.get()) );
    _camera->setClearColor( osg::Vec4(0.4, 0.2, 0.6, 1.0) );
    _camera->setViewport( new osg::Viewport(0, 0, _traits->width, _traits->height) );
    _camera->setProjectionMatrixAsPerspective(
        30.0f, static_cast<double>(_traits->width)/static_cast<double>(_traits->height), 1.0f, 10000.0f );
}
