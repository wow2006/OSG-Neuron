#include "matrixnode.h"

matrixNode::matrixNode()
{
    _location = osg::Vec3( 0 , 0 , 0 );
    _dim = osg::Vec3( 3 , 3 , 3 );
    _mtx =  new osg::MatrixTransform;
    _mtx->setMatrix( osg::Matrix::translate( _location.x() , _location.y() , _location.z() ));
    num = _dim.x()*_dim.y()*_dim.z();
    run();
}

matrixNode::matrixNode(int x,int y,int z,int dx,int dy,int dz)
{
    _location = osg::Vec3( x , y , z );
    _dim = osg::Vec3( dx , dy , dz );
    _mtx =  new osg::MatrixTransform;
    _mtx->setMatrix( osg::Matrix::translate( _location.x() , _location.y() , _location.z() ));
    num = _dim.x()*_dim.y()*_dim.z();
    run();
}

void matrixNode::run()
{
    osg::ref_ptr<osg::MatrixTransform> nMatrix[num];
    int idx = 0;
    for (int k = 0 ;  k  < _dim.z() ; k++)
        for(int j = 0 ; j < _dim.y() ; j++)
            for (int i = 0 ; i < _dim.x() ; i++)
            {
                if (idx < num)
                {
                    nMatrix[idx] = new neuronNode;
                    nMatrix[idx]->setMatrix(osg::Matrix::translate( i*3 , j*3 , k*3 ));
                    _mtx->addChild( nMatrix[idx].get() );
                    idx++;
                }
            }
}

void matrixNode::setlocation(int x, int y, int z)
{
    _location.set(x,y,z);
    _mtx->setMatrix(osg::Matrix::translate(_location.x(),_location.y(),_location.z()));
}

osg::Group* matrixNode::get()
{
    return _mtx->asGroup();
}


void matrixNode::pulse(int x, int y, int z)
{

}
