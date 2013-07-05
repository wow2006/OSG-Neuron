cmake_minimum_required( VERSION 2.6 )

project( NeuronProject )
find_package( Qt4 )
include( ${QT_USE_FILE} )

add_executable( ${PROJECT_NAME}  main.cpp )
target_link_libraries( ${PROJECT_NAME} neuron )
TARGET_LINK_LIBRARIES( ${PROJECT_NAME} ${QT_LIBRARIES})

include_directories( ${neuron} )
