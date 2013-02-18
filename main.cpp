#include <iostream>
#include <osgDB/ReadFile>
#include "matrixnode.h"
#include "viewerwidget.h"
#include "camera.h"

void display()
{
    matrixNode node;
    camera mycamera;
    ViewerWidget* widget = new ViewerWidget( mycamera.setCamera() , node.get() );
    widget->setGeometry( 100, 100, 800, 600 );
    widget->show();
}

int main( int argc, char** argv )
{
    QApplication app( argc, argv );
    display();
    return app.exec();
}
