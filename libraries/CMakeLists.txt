SET( neuron_include_dirs ${CMAKE_CURRENT_LIST_DIR}/include )
INCLUDE_DIRECTORIES( ${neuron_include_dirs} )
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
INCLUDE_DIRECTORIES( ${neuron_include_dirs}/neuron )
INCLUDE_DIRECTORIES( ${neuron_include_dirs}/neuron/shader )

find_package( OpenThreads )
find_package( osg )
find_package( osgDB )
find_package( osgGA )
find_package( osgText )
find_package( osgViewer )
find_package( osgAnimation )
find_package( osgUtil )
find_package( osgQt )
find_package( Qt4  REQUIRED)
include( ${QT_USE_FILE} )
ADD_DEFINITIONS( ${QT_DEFINITIONS} )


set( core_header
    include/core.h
    include/ui/mainwindow.h
    include/neuron/base.h
    include/neuron/baseNeuron.h
    include/neuron/neuronMatrix.h
    include/neuron/shaderNeuron.h
    include/neuron/standNeuron.h
)
QT4_WRAP_CPP( core_moc ${core_header})
# set other header
file( GLOB_RECURSE HEADERS "*.h" )
# set cpp files
file( GLOB_RECURSE SRCS "*.cpp" )

ADD_LIBRARY( neuron
        STATIC
        ${core_moc}
        ${SRCS}
        ${HEADERS}
)

# micro for include and target link
macro( config_project PROJNAME LIBNAME )
    include_directories( ${${LIBNAME}_INCLUDE_DIR} )
    target_link_libraries( ${PROJNAME} ${${LIBNAME}_LIBRARY} )
endmacro()

config_project( neuron OPENTHREADS )
config_project( neuron OSG )
config_project( neuron OSGDB )
config_project( neuron OSGGA )
config_project( neuron OSGTEXT )
config_project( neuron OSGVIEWER )
config_project( neuron osgAnimation )
config_project( neuron OSGUTIL )
config_project( neuron OSGQT )
config_project( neuron OSGFX )
TARGET_LINK_LIBRARIES(neuron ${QT_LIBRARIES})

# Export the include directory.
SET( neuron ${neuron_include_dirs} PARENT_SCOPE )
