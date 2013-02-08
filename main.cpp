#include <iostream>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>
#include <osgGA/TrackballManipulator>
#include <osgViewer/ViewerEventHandlers>
#include "matrixnode.h"

void display()
{
    matrixNode node;
    osgViewer::Viewer viewer;
    viewer.setSceneData( node.get() );
    viewer.getCamera()->setClearColor( osg::Vec4( 0.1f, 0.1f, 0.2f, 1.0f ) );
    viewer.getCamera()->setClearMask( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT );
    //Stats Event Handler s key
    viewer.addEventHandler(new osgViewer::StatsHandler);
    viewer.setCameraManipulator(new osgGA::TrackballManipulator);
    viewer.realize();
    viewer.run();
}

int main()
{
    display();
    return 0;
}
