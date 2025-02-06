cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
# cspell:disable

project(test)

set(CMAKE_BUILD_TYPE Release) # -03 -DNDEBUG

set(CMAKE_MACOSX_RPATH 0)

find_package(
  ROOT REQUIRED
  COMPONENTS Core
             RIO
             Net
             Hist
             Graf
             Graf3d
             Gpad
             Tree
             Rint
             Postscript
             Matrix
             Physics
             MathCore
             Thread
             dl)
if(NOT ROOT_FOUND)
  message(STATUS "ROOT cern not found")
endif()
include(${ROOT_USE_FILE})
add_definitions(${ROOT_CXX_FLAGS})

include_directories(${PROJECT_SOURCE_DIR}/ ${ROOT_INCLUDE_DIRS}/)

file(GLOB sources ${PROJECT_SOURCE_DIR}/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/*.hh)

set(LINK_LIBS ${ROOT_LIBRARIES})

root_generate_dictionary(G__testIO ${headers} LINKDEF ROOTLINKDef.h)
add_library(testIO SHARED ${sources} G__testIO.cxx)

target_link_libraries(testIO ${LINK_LIBS})

set(CMAKE_INSTALL_PREFIX $ENV{HOME}/software/install)
install(TARGETS testIO DESTINATION lib)

install(FILES ${CMAKE_BINARY_DIR}/libtestIO_rdict.pcm DESTINATION lib/)
install(FILES ${CMAKE_BINARY_DIR}/libtestIO.rootmap DESTINATION lib/)
install(
  TARGETS testIO
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)
