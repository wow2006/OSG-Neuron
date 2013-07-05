#ifndef NUMBERGENRATOR_H
#define NUMBERGENRATOR_H

#include <qglobal.h>
#include <QTime>
#include <math.h>

#define PI 3.14159265

// Genrate random integer
inline int randInt( int low , int high )
{
    return qrand()%((high+1)-low)+low;
}

// Genrate random coordinates x , y , z
inline bool coordGen( QList<int> &coord )
{
    int x,y,z;
    z = randInt( 0 , 1000 );
    y = randInt( 0 , 500 );
    x = randInt( 0 , 500 );
    int rangMin = 125/tan(PI/6);
    int rangMax = 500 + 2*(125/tan(PI/6));

    if( !( rangMin > x && rangMax < x ) )
        y = randInt( ( 125-(x*tan( PI/6 )) ) , ( 125+(x*tan( PI/6 )) ) );

    coord.clear();
    coord.push_back( x );
    coord.push_back( y );
    coord.push_back( z );

    return true;
}

// Genrate random frames form 0 - 10000
inline bool framesGen( QList<int> &frames , int min = 0 , int max = 100 ,  int taken = 3 )
{
    frames.clear();
    for( int i = 0 ; i < taken ; i++)
    {
        int frame = randInt( min , max );
        frames.push_back( frame );
    }
    return true;
}

// Insert coordinates and frames in same QList
// num : number of object want to genrate
// all : return QList
inline bool getRandom( int num , QList< QList<int> > &all , int min = 0 , int max = 100 , int framesPneuron = 3 )
{
    if( num <= 0 )
    {
        qDebug() << "Error enter number > 0 ";
        return false;
    }
    else
    {
        all.clear();
        QList<int> coord;
        QList<int> frames;
        for( int i  = 0 ; i < num ; i++ )
        {
            coordGen( coord );
            framesGen( frames , min , max , framesPneuron );
            all.push_back( coord );
            all.push_back( frames );
        }
        return true;
    }
}

#endif // NUMBERGENRATOR_H
