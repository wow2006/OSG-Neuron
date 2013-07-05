#ifndef CORE_H
#define CORE_H
#include <QTimer>
#include <QObject>

#include <osg/Group>
#include <osg/Camera>
#include <osgDB/ReadFile>

#include "common/CommonFunctions"
#include "ui/mainwindow.h"
#include "neuron/neuronMatrix.h"
#include "neuron/standNeuron.h"

class core : public QObject
{
    Q_OBJECT
public:
    explicit core(QObject *parent = 0) : QObject( parent )
    {
        _playFlag = false;
        _timer = 0;
        _inValue = 1;

        // setting base GUI and root
        _root = new osg::Group();
        _camera = osgCookBook::createCamera( 50, 50, 640, 480 );
        _mainWidget = new mainWindow( _camera.get() , _root.get() );
        _mainWidget->show();

        // setting connection
        connectionSetting();
        _Qtimer.start(1000);
    }

    ~core()
    {
        delete _mainWidget;
        if( _matrix )
            delete _matrix;
    }
protected:
    void connectionSetting();

public slots:
    void incrementTimer();
    void playSlot();
    void stopSlot();
    void setTime( int );
    void openButton( QString& );
    void setTimerSpeed( int );
    void matrixReset();

signals:
    void incrementSlider( int );

private:
    int                         _timer;
    int                         _inValue;
    bool                        _playFlag;
    neuronMatrix*               _matrix;
    QStringList                 _names;
    QList< QList< int > >       _coords;
    QList< QList< int > >       _frames;
    mainWindow*                 _mainWidget;
    QTimer                      _Qtimer;
    osg::ref_ptr<osg::Camera>   _camera;
    osg::ref_ptr<osg::Group>    _root;
};

#endif // CORE_H
