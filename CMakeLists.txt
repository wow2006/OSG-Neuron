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
find_package( osgQt )
find_package( Qt4 )

# for include Qt
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

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
# include nodematrix files
SET(viewerwidget
    ${CMAKE_SOURCE_DIR}/src/viewerwidget.cpp
    ${CMAKE_SOURCE_DIR}/header/viewerwidget.h
)


macro( config_project PROJNAME LIBNAME )
    include_directories( ${${LIBNAME}_INCLUDE_DIR} )
    target_link_libraries( ${PROJNAME} ${${LIBNAME}_LIBRARY} )
endmacro()


add_executable( mainLine main.cpp ${COMMON_FILES} ${neuronNode} ${shader} ${light} ${camera} ${matrixnode} ${viewerwidget})
config_project( mainLine OPENTHREADS )
config_project( mainLine OSG )
config_project( mainLine OSGDB )
config_project( mainLine OSGGA )
config_project( mainLine OSGTEXT )
config_project( mainLine OSGVIEWER )
config_project( mainLine osgAnimation )
config_project( mainLine OSGUTIL )
config_project( mainLine OSGQT )
TARGET_LINK_LIBRARIES(mainLine ${QT_LIBRARIES})
