file( GLOB_RECURSE core_SOURCES "*.cpp" )

include_directories(.)
include_directories(../include)
include_directories(../include/neuron)
include_directories(../include/neuron/shader)

add_library( core ${core_SOURCES} )
target_link_libraries(core ${QT_LIBRARIES} ${OSG_LIBRARIES})

add_executable( run main.cpp )
target_link_libraries( run core )

# micro for include and target link
macro( config_project PROJNAME LIBNAME )
    include_directories( ${${LIBNAME}_INCLUDE_DIR} )
    target_link_libraries( ${PROJNAME} ${${LIBNAME}_LIBRARY} )
endmacro()

config_project( run OPENTHREADS )
config_project( run OSG )
config_project( run OSGDB )
config_project( run OSGGA )
config_project( run OSGTEXT )
config_project( run OSGVIEWER )
config_project( run osgAnimation )
config_project( run OSGUTIL )
config_project( run OSGQT )
config_project( run OSGFX )
TARGET_LINK_LIBRARIES(run ${QT_LIBRARIES})
