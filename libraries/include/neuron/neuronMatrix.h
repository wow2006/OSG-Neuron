#ifndef NEURONMATRIX_H
#define NEURONMATRIX_H
#include "base.h"
#include "shaderNeuron.h"
#include <QList>
#include <QDebug>

class neuronMatrix : public Base
{
    Q_OBJECT
public:
    neuronMatrix() : Base()
    {
    }
    neuronMatrix( QList< QList<int> >& locations,QList< QList<int> >& frames ) : Base()
    {
        _frames = frames;
        foreach( QList< int > value , locations)
        {
            osg::Vec3 locat( value[0] , value[1] , value[2] );
            shaderNeuron* obj = new shaderNeuron( locat );
            _neurons.push_back( obj );
        }
    }
    virtual QString toString();
    void setRoot( osg::Group* root );
    void deleteChild( osg::Node* );
    void deleteAll();

private:
    QList< shaderNeuron* > _neurons;
    QList< QList<int> > _frames;
    osg::Group* _root;

signals:
    void shaderUpdate();

public slots:
    void currentTimer( int );
};

#endif // NEURONMATRIX_H
