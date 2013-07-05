#ifndef GENRATESTRING_H
#define GENRATESTRING_H

#include <QFile>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QDebug>

namespace wData
{
    QString genrateobj(const QString &name,const QList<int> &coord,const QList<int> &frames)
    {
        /*
         *  genrate string which contain coordnate system " x , y , z " for one object
         *  and add to them uniform scale and rotation in z
         */
        QString objLine   =  name                               // name of object
                          + " " + QString::number(coord[0])     // represnet x
                          + " " + QString::number(coord[1])     // represnet y
                          + " " + QString::number(coord[2]);    // represnet z
//                          + " " + QString::number(coord[3])     // represnet s
//                          + " " + QString::number(coord[4]) ;   // represnet r
        QString frameline = "\nframes ";                        // represnt new line for frames
        foreach( int frame , frames )
            frameline += QString::number(frame) + " ";          // add frame then space
        frameline += "\n ";                                     // when finish add new line to seprate object
        qDebug() << "Done!";
        qDebug() << (objLine + frameline);
        return (objLine + frameline);                           // return all QString with coord and frames
    }

    QString genrateData( int totalFrames , QList<QString> grpNuron)
    {
        QString headerline = "# total " + QString::number( grpNuron.size() ) + " frames " + QString::number( totalFrames );
        foreach( QString data , grpNuron )
        {
            headerline += "\n" + data;
        }

        return headerline;
    }

    QString allData( const QStringList &nameList, const QList< QList<int> > &number )
    {
        if( ( nameList.size() == (number.size()/2)) )
        {
            QStringList myNeurons;

            int i = 0;
            foreach( QString name , nameList )
            {
                QList<int> coord,frames;
                coord = number[i++];
                frames = number[i++];
                QString newString = genrateobj(name , coord , frames );
                myNeurons.push_back( newString );
            }
            return genrateData( 10000 , myNeurons );
        }
        qDebug() << "001 not same size";
        exit (EXIT_FAILURE);
    }

    void write(const QString &fileName , const QString &text)
{
    QFile myfile(fileName);
    if ( !myfile.open(QFile::WriteOnly | QFile::Text ) )
    {
        qDebug() << "Can't open "  << fileName << " file";
        return;
    }
    QTextStream out(&myfile);
    out << text;
    myfile.flush();
    myfile.close();
}
}

namespace rData
{
    void extract(const QString &data , QList<int> &coord , QStringList& names )
    {
        if( data[0] == '#' ||  data[0] == ' ' )
            return;
        QStringList mydata = data.split(' ');
        if( mydata[0] != "frames")
        names.append( mydata[0] );
        while( !mydata.isEmpty() )
        {
            bool ok;
            QString value = mydata.takeFirst();
            int number = value.toDouble(&ok);
            if( ok )
                coord.push_back( number );
        }
    }

    bool read( const QString &fileName , QList< QList<int> > &coord , QList< QList<int> > &frames , QStringList& names )
    {
        QList< QList<int> > numbers;
        QFile myfile(fileName);
        if ( !myfile.open(QFile::ReadOnly | QFile::Text ) )
        {
            qDebug() << "Can't open "  << fileName << " file";
            return false;
        }

        QList<int> num;
        QTextStream in(&myfile);
        while( !in.atEnd() )
        {
            QString data = in.readLine();
            extract( data , num , names );
            if( !num.isEmpty() )
                numbers += num;
            num.clear();
        }

        myfile.close();
        for( int i = 0 ; i < numbers.size() ; i++ )
        {
            coord.push_back( numbers[i++] );
            frames.push_back( numbers[i] );
        }
        return true;
    }
}

#endif // GENRATESTRING_H
