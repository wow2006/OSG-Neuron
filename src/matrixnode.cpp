#include "matrixnode.h"

matrixNode::matrixNode()
{
    _location = osg::Vec3( 0 , 0 , 0 );
    _dim = osg::Vec3( 3 , 3 , 3 );
    _mtx = new osg::MatrixTransform;
    _mtx->setMatrix( osg::Matrix::translate( _location.x() , _location.y() , _location.z() ));
    num = _dim.x()*_dim.y()*_dim.z();
    run();
}

inline void matrixNode::setLocation(osg::Vec3 &locarion)
{
    _location = locarion;
    _mtx->setMatrix( osg::Matrix::translate( _location.x() , _location.y() , _location.z() ));
}

void matrixNode::run()
{
    neuronNode nMatrix[num];
    int idx = 0;
    for (int k = 0 ;  k  < _dim.z() ; k++)
        for(int j = 0 ; j < _dim.y() ; j++)
            for (int i = 0 ; i < _dim.x() ; i++)
            {
                if (idx < num)
                {
                    nMatrix[idx].setlocation( i*3 , j*3 , k*3 );
                    _mtx->addChild( nMatrix[idx].get() );
                    idx++;
                }
            }
}


osg::Group *matrixNode::get()
{
    return _mtx->asGroup();
}
