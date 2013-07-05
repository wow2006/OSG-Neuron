#include "neuronMatrix.h"

void neuronMatrix::currentTimer( int currentTime )
{
    int  i = 0;
    foreach( shaderNeuron* one , _neurons )
    {
        foreach( int frame , _frames[i] )
        {
            if( frame == currentTime )
            {
                one->shaderUpdate();
                qDebug() << "done";
            }
        }
        i++;
    }
}

QString neuronMatrix::toString()
{
}

void neuronMatrix::setRoot( osg::Group* root )
{
    _root = root;
    foreach( shaderNeuron* one , _neurons )
    {
        root->addChild( one->get() );
    }
}

void neuronMatrix::deleteChild( osg::Node * node )
{
    _root->removeChild( node );
}

void neuronMatrix::deleteAll()
{
    foreach( shaderNeuron* one , _neurons )
    {
        _root->removeChild( one->get() );
    }
}
