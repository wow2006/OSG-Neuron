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
# find qt
find_package( Qt4 4.4.3 COMPONENTS QtCore QtGui QtXml REQUIRED )

INCLUDE_DIRECTORIES(src)
INCLUDE_DIRECTORIES(header)

# include neuronNode files
SET(neuronNode
    ${CMAKE_SOURCE_DIR}/src/neuronnode.cpp
    ${CMAKE_SOURCE_DIR}/header/neuronnode.h
)
# include shader files
# include vertx and fragment shader
SET(shader
    ${CMAKE_SOURCE_DIR}/src/shader.cpp
    ${CMAKE_SOURCE_DIR}/header/shader.h
    ${CMAKE_SOURCE_DIR}/src/shader/fragShader.frag
    ${CMAKE_SOURCE_DIR}/src/shader/vertShader.vert
)
# include light files
SET(light
    ${CMAKE_SOURCE_DIR}/src/light.cpp
    ${CMAKE_SOURCE_DIR}/header/light.h
)
# include camera files
SET(camera
    ${CMAKE_SOURCE_DIR}/src/camera.cpp
    ${CMAKE_SOURCE_DIR}/header/camera.h
)
# include nodematrix files
SET(matrixnode
    ${CMAKE_SOURCE_DIR}/src/matrixnode.cpp
    ${CMAKE_SOURCE_DIR}/header/matrixnode.h
)

macro( config_project PROJNAME LIBNAME )
    include_directories( ${${LIBNAME}_INCLUDE_DIR} )
    target_link_libraries( ${PROJNAME} ${${LIBNAME}_LIBRARY} )
endmacro()


add_executable( mainLine main.cpp ${COMMON_FILES} ${neuronNode} ${shader} ${light} ${camera} ${matrixnode})
config_project( mainLine OPENTHREADS )
config_project( mainLine OSG )
config_project( mainLine OSGDB )
config_project( mainLine OSGGA )
config_project( mainLine OSGTEXT )
config_project( mainLine OSGVIEWER )
config_project( mainLine osgAnimation )
config_project( mainLine OSGUTIL )
config_project( mainLine Qt4 )
