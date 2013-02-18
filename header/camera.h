#include <osg/Camera>
#include <osgQt/GraphicsWindowQt>

#ifndef CAMERA_H
#define CAMERA_H

class camera
{

public:
    camera() {
        _camera =  new osg::Camera ;
        _traits = new osg::GraphicsContext::Traits;
        run();
    }
    osg::Camera* setCamera();

protected:
    osg::ref_ptr<osg::Camera> _camera;
    osg::ref_ptr<osg::GraphicsContext::Traits> _traits;
    void run();
};

#endif // CAMERA_H
