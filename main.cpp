#include <iostream>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>
#include <osgGA/TrackballManipulator>

osg::Group* obj()
{
    osg::ref_ptr<osg::Node>objgeom = osgDB::readNodeFile("sphere.obj");
    //objgeom->setDataVariance( osg::Object::DYNAMIC );
    //objgeom->setUpdateCallback( new DynamicQuadCallback );
    osg::Group* root = new osg::Group;

    if ( objgeom.valid() )
        root->addChild( objgeom.get() );
    else
        {
            std::cout << "Can't find object" << std::endl;
            return 0;
        }
    return root;
}


void display()
{
    osgViewer::Viewer viewer;
    viewer.setSceneData( obj() );
    viewer.getCamera()->setClearColor( osg::Vec4( 0.1f, 0.1f, 0.2f, 1.0f ) );
    viewer.getCamera()->setClearMask( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT );
    viewer.setCameraManipulator(new osgGA::TrackballManipulator);
    viewer.realize();

    while( ! viewer.done() ){
        viewer.frame();
    }
}

int main()
{
    display();
    return 0;
}
