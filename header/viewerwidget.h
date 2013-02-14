#ifndef VIEWERWIDGET_H
#define VIEWERWIDGET_H
#include <qt4/QtCore/QtCore>
#include <qt4/QtGui/QtGui>
#include <osgQt/GraphicsWindowQt>
#include <osgGA/TrackballManipulator>
#include <osgViewer/ViewerEventHandlers>
#include <osgViewer/Viewer>

class ViewerWidget : public QWidget
{
public:
    ViewerWidget( osg::Camera* camera, osg::Node* scene );

protected:
    virtual void paintEvent( QPaintEvent* event )
    { _viewer.frame(); }

    QPushButton runButton;
    osgViewer::Viewer _viewer;
    QTimer _timer;
};

#endif // VIEWERWIDGET_H
