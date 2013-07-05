#include "ui/mainwindow.h"
#include "random/numberGenrator.h"
#include "random/genrateString.h"
#include <QTextStream>
#include <QFileDialog>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QThread>

void mainWindow::setting()
{
    this->connect( ui->timeSlider , SIGNAL(valueChanged(int)) , this ,  SLOT(updateSlider(int)) );

    // connection to timeSlider buttons
    this->connect( ui->pushButton_Play , SIGNAL( clicked() ) , this , SLOT( playSlider() ) );
    this->connect( ui->pushButton_Stop , SIGNAL( clicked() ) , this , SLOT( stopSlider() ) );
    // run study
    this->connect( ui->pushButton_StudyLoad , SIGNAL( clicked() ) , this , SLOT( runStudy() ) );
    this->connect( ui->pushButton_StudyReset , SIGNAL( clicked() ) , this , SLOT( resetStudy()) );
    // open *.sim file
    this->connect( ui->pushButton_SimLoad , SIGNAL( clicked() ) , this , SLOT( openSimFile() ) );
    this->connect( ui->pushButton_SimReset , SIGNAL( clicked() ) , this , SLOT( resetSim() ) );
    // generator
    this->connect( ui->pushButton_Genrate , SIGNAL( clicked() ) , this , SLOT( genrateFile() ) );
    this->connect( ui->pushButton_Save , SIGNAL( clicked() ) , this , SLOT( saveFile() ) );
    // connection to actions
    this->connect( ui->actionExit , SIGNAL(triggered()) , this , SLOT( close() ) );
    this->connect( ui->actionRest , SIGNAL(triggered()) , this , SLOT( reloadSys() ) );
    this->connect( ui->actionPreference , SIGNAL(triggered()) , this , SLOT( preferenceSys() ) );
    this->connect( ui->actionHelp , SIGNAL(triggered()) , this , SLOT( helpSys() ) );
    this->connect( ui->actionAbout_Us , SIGNAL(triggered()) , this , SLOT( aboutSys() ) );
    setSelector();
}

void mainWindow::setSelector()
{
    _selector = new SelectModelHandler( _viewer.getCamera() );
    _viewer.addEventHandler( _selector.get() );
    osg::CullSettings::CullingMode mode = _viewer.getCamera()->getCullingMode();
    _viewer.getCamera()->setCullingMode( mode & ( ~osg::CullSettings::SMALL_FEATURE_CULLING) );
}

void mainWindow::selectVertex()
{
    if( _selector->zCoord != 0 )
    {
        _one->selectUpdate( _selector->zCoord );
    }
}

// public slots
void mainWindow::updateSlider( int timeValue )
{
    ui->spinBox_Time->setValue( timeValue );
    if( ui->timeSlider->isSliderDown() )
        emit( dragTimeLine( timeValue ) );
    else
        ui->timeSlider->setValue( timeValue );

}

void mainWindow::playSlider()
{
    emit( playSignal() );
}

void mainWindow::stopSlider()
{
    emit( stopSignal() );
}

void mainWindow::runStudy()
{
    _one =  new standNeuron;
    _root->addChild( _one->get() );
    ui->centralWidget->update();
    this->connect( ui->spinBox_StudySpeed , SIGNAL(valueChanged(int)) , _one , SLOT(selectSpeed(int)) );
    QStringList name( QString("Study neuron") );
    addToTree( name );
}

void mainWindow::resetStudy()
{
    if( _one )
    {
        // disconnect mainwindow from standNeuron
        _root->removeChild( _one->get() );
    }
    ui->spinBox_StudySpeed->setValue( 1 );
    ui->treeNeuron->clear();
}

void mainWindow::openSimFile()
{
    QString fileName = "/home/ahmed/Documents/MainLine/build/newFile.sim";
//    QString fileName = QFileDialog::getOpenFileName(this, tr("Open file"), "",tr("Simulation files (*.sim)"));

    if( fileName == "" )
        return;
    else
    {
        emit( openSignal( fileName ) );
    }
}

void mainWindow::resetSim()
{
    emit( resetMatrix() );
    ui->spinBox_SimSpeed->setValue( 1 );
    ui->treeNeuron->clear();
}

void mainWindow::genrateFile()
{
    QString fileName = "/home/ahmed/Documents/MainLine/build/newFile.sim";
    //    QString fileName = QFileDialog::getOpenFileName(this, tr("Open file"), "",tr("Simulation files (*.sim)"));
    QString neuronName = ui->lineEdit_preNeuron->text();
    int num = ui->lineEdit_numNeuron->text().toInt();
    int min = ui->lineEdit_Start->text().toInt();
    int max = ui->lineEdit_End->text().toInt();
    int tak = ui->lineEdit_numTime->text().toInt();

        QList< QList< int > > all;
        // return data will work at all var
        getRandom( num , all , min , max , tak );
        if( !fileName.isEmpty() )
        {
            QStringList names;
            for( int i = 0 ; i < num ; i++ )
            {
                names.push_back(neuronName+QString::number( i ));
            }
            QString finalData = wData::allData( names ,all );
            qDebug() << finalData;
            wData::write( fileName , finalData );
        }
}

void mainWindow::saveFile()
{
//    QString text("Hello World");
//    QString fileName = QFileDialog::getSaveFileName(this, tr("Save file"), "",tr("Simulation files (*.sim)"));
//    fileName += ".sim";
//    QFile outfile(fileName);

//    if( outfile.exists() )
//        qDebug() << "overide dialog";
//    else
//    {
//        qDebug() << fileName;
//        if( !outfile.open( QIODevice::WriteOnly | QIODevice::Text ) )
//        {
//        }
//        QTextStream out(&outfile);
//        out << text;
//        outfile.flush();
//        outfile.close();
//    }
}

//
void mainWindow::reloadSys()
{
    qDebug() << "Reload";
}

void mainWindow::preferenceSys()
{
    qDebug() << "preference";
}

void mainWindow::helpSys()
{
    qDebug() << "Help";
}

void mainWindow::aboutSys()
{
    qDebug() << "About";
}

/*void MainWindow::toggleWin()
//{
//    if( ui->textBrowser->height() != 0 )
//    {
//        ui->textBrowser->setGeometry( ui->textBrowser->x() , ui->textBrowser->y() , ui->textBrowser->width() , 0 );
//        ui->pushButton_toggle->setGeometry( ui->textBrowser->x() , ui->textBrowser->y()
//                                                                 , ui->pushButton_toggle->width() , ui->pushButton_toggle->height() );
//    }
//    else
//    {
//        ui->textBrowser->setGeometry( ui->textBrowser->x() , ui->textBrowser->y() , ui->textBrowser->width() , 100 );
//        ui->pushButton_toggle->setGeometry( ui->textBrowser->x() , ( ui->textBrowser->y() + ui->textBrowser->y() )
//                                                                 , ui->pushButton_toggle->width() , ui->pushButton_toggle->height() );
//    }
//}*/
