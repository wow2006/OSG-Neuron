#include "core.h"
#include "genrateString.h"

#include <QDebug>

void core::connectionSetting()
{
    connect( &_Qtimer     , SIGNAL(timeout()) , this , SLOT(incrementTimer()) );
    connect( _mainWidget , SIGNAL( playSignal() )         , this , SLOT(playSlot()) );
    connect( _mainWidget , SIGNAL( stopSignal() )         , this , SLOT(stopSlot()) );
    connect( _mainWidget , SIGNAL( dragTimeLine(int) )    , this , SLOT(setTime(int)) );
    connect( _mainWidget , SIGNAL( openSignal(QString&) ) , this , SLOT(openButton(QString&)) );

    connect( this , SIGNAL(incrementSlider(int)) , _mainWidget , SLOT(updateSlider(int)) );
    connect( _mainWidget , SIGNAL( resetMatrix() ) , this , SLOT(matrixReset()) );
//    connect( _mainWidget , SIGNAL( setSpeedValue(int) )   , this , SLOT( setTimerSpeed(int) ) );
}

// slots functions
void core::incrementTimer()
{
    if( _playFlag )
    {
        _timer += _inValue;
        emit( incrementSlider( _timer ) );
    }
}

void core::playSlot()
{
    _playFlag = true;
}

void core::stopSlot()
{
    _playFlag = false;
}

void core::setTime( int newValue )
{
    _playFlag = false;
    _timer = newValue;
}

void core::openButton( QString &fileName )
{
    rData::read( fileName , _coords , _frames , _names );
    _matrix = new neuronMatrix( _coords , _frames );
    _matrix->setRoot( _root.get() );
    _mainWidget->addToTree( _names );
    connect( this , SIGNAL(incrementSlider(int)) , _matrix , SLOT(currentTimer(int)) );
}

void core::setTimerSpeed( int inValue )
{
    _inValue = inValue;
    qDebug() << "emit speed to matrix neuron";
}

void core::matrixReset()
{
    _matrix->deleteAll();
    if( _matrix )
        delete _matrix;
}
