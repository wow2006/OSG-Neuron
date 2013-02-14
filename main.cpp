#include <iostream>
#include <osgDB/ReadFile>
#include "matrixnode.h"
#include "viewerwidget.h"

osg::Camera* createCamera( int x, int y, int w, int h )
{
    osg::DisplaySettings* ds = osg::DisplaySettings::instance().get();
    osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
    traits->windowDecoration = false;
    traits->x = x;
    traits->y = y;
    traits->width = w;
    traits->height = h;
    traits->doubleBuffer = true;

    osg::ref_ptr<osg::Camera> camera = new osg::Camera;
    camera->setGraphicsContext( new osgQt::GraphicsWindowQt(traits.get()) );
    camera->setClearColor( osg::Vec4(0.2, 0.2, 0.6, 1.0) );
    camera->setViewport( new osg::Viewport(0, 0, traits->width, traits->height) );
    camera->setProjectionMatrixAsPerspective(
        30.0f, static_cast<double>(traits->width)/static_cast<double>(traits->height), 1.0f, 10000.0f );
    return camera.release();
}

void display()
{
    matrixNode node;
    //osg::ref_ptr<osg::MatrixTransform> node = new neuronNode;

    std::cout << "001" << std::endl;

    osg::Camera* camera = createCamera( 50, 50, 640, 480 );
    ViewerWidget* widget = new ViewerWidget(camera, node.get() );
    widget->setGeometry( 100, 100, 800, 600 );
    widget->show();
}

int main( int argc, char** argv )
{
    QApplication app( argc, argv );
    display();
    return app.exec();
}
