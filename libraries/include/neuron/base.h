#ifndef BASE_H
#define BASE_H

#include <QObject>
#include <QString>
#include <osg/Switch>
#include <osg/MatrixTransform>

class Base : public QObject
{
    Q_OBJECT
public:
    explicit Base(osg::Vec3 location = osg::Vec3( 0 , 0 , 0 ) , QObject *parent = 0);
    void setLocation( osg::Vec3& location );
    osg::Vec3& getLocation();
    virtual QString toString() = 0;
    osg::Group* get();

protected:
    void updateAtt();
    osg::Vec3 _location;
    osg::ref_ptr< osg::MatrixTransform > _mt;
    osg::ref_ptr< osg::Switch > _switch;

public slots:
    void hide();
    void show();
};

#endif // BASE_H
