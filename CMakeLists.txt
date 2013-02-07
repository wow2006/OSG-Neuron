cmake_minimum_required(VERSION 2.8)
project(mainLine)

find_package( OpenThreads )
find_package( osg )
find_package( osgDB )
find_package( osgGA )
find_package( osgText )
find_package( osgViewer )
find_package( osgAnimation )
find_package( osgUtil )


macro( config_project PROJNAME LIBNAME )
    include_directories( ${${LIBNAME}_INCLUDE_DIR} )
    target_link_libraries( ${PROJNAME} ${${LIBNAME}_LIBRARY} )
endmacro()


add_executable( mainLine main.cpp ${COMMON_FILES})
config_project( mainLine OPENTHREADS )
config_project( mainLine OSG )
config_project( mainLine OSGDB )
config_project( mainLine OSGGA )
config_project( mainLine OSGTEXT )
config_project( mainLine OSGVIEWER )
config_project( mainLine osgAnimation )
config_project( mainLine OSGUTIL )
