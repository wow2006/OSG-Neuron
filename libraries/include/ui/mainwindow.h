#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDebug>
#include <QMainWindow>
#include <QWidget>
#include <QTimer>
#include <osgQt/GraphicsWindowQt>
#include <osgGA/TrackballManipulator>
#include <osgViewer/ViewerEventHandlers>
#include <osgViewer/Viewer>
#include <osg/Camera>
#include <osg/Group>
#include "ui_mainwindow.h"
#include "common/CommonFunctions"
#include "neuron/standNeuron.h"

// class for select vertex
class SelectModelHandler : public osgCookBook::PickHandler
{
public:
    SelectModelHandler( osg::Camera* camera )
        : _camera(camera) , zCoord(0){}

    virtual void doUserOperations( osgUtil::LineSegmentIntersector::Intersection& result )
    {
        osg::Geometry* geom = dynamic_cast<osg::Geometry*>( result.drawable.get() );
        if ( !geom ) return;

        osg::Vec3Array* vertices = dynamic_cast<osg::Vec3Array*>( geom->getVertexArray() );
        if ( !vertices ) return;

        osg::Vec3 point = result.getWorldIntersectPoint();
        zCoord = point.z();
    }

    float zCoord;
protected:
    osg::observer_ptr<osg::Camera> _camera;
};

class mainWindow : public QMainWindow
{
    Q_OBJECT
public:
    mainWindow( osg::Camera* camera , osg::Node* root , QWidget *parent = 0 )
        : QMainWindow( parent ) , ui( new Ui::MainWindow )
    {
        _root = root->asGroup();
        _viewer.setCamera( camera );
        ui->setupUi( this );
        setting();

        // set qt-osg wrapper
        _viewer.getCamera()->setClearMask( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT );
        _viewer.setCameraManipulator( new osgGA::TrackballManipulator );
        _viewer.setThreadingModel( osgViewer::Viewer::SingleThreaded );
        // return pointer to GraphicWindowQt from camera Context
        gw = dynamic_cast<osgQt::GraphicsWindowQt*>( _viewer.getCamera()->getGraphicsContext() );
        if ( gw )
        {
            _viewer.setSceneData( root );
            ui->GLWidget->addWidget( gw->getGLWidget() , 1000);
        }
        this->connect( &_timer , SIGNAL(timeout()) , ui->centralWidget , SLOT(update()) );
        this->connect( &_timer , SIGNAL(timeout()) , this , SLOT(selectVertex()) );
        ui->spinBox_Time->setReadOnly( true );
        _timer.start(30);

    }
    ~mainWindow()
    {
        delete ui;
        if( _one )
            delete _one;
    }
    void addToTree( QStringList& names )
    {

        foreach ( QString name , names ) {
            QTreeWidgetItem* itm = new QTreeWidgetItem( ui->treeNeuron );
            itm->setText( 0 , name );
            ui->treeNeuron->addTopLevelItem( itm );
        }
    }

private:
    void setting();
    void setSelector();
    Ui::MainWindow *ui;
    int maxSlider;
    osgViewer::Viewer _viewer;
    osgQt::GraphicsWindowQt* gw;
    QTimer _timer;
    osg::Group* _root;
    standNeuron* _one;
    osg::ref_ptr<SelectModelHandler> _selector;

public slots:
    void selectVertex();
    void updateSlider( int );

    void playSlider();
    void stopSlider();

    void runStudy();
    void resetStudy();
    void openSimFile();
    void resetSim();

    void genrateFile();
    void saveFile();

    // actions
    void reloadSys();
    void preferenceSys();
    void helpSys();
    void aboutSys();

protected:
    virtual void paintEvent( QPaintEvent* event )
    { _viewer.frame(); }

signals:
    void playSignal();
    void stopSignal();
    void dragTimeLine(int);
    void openSignal(QString&);
    void setSpeedValue(int);
    void resetMatrix();
};

#endif
