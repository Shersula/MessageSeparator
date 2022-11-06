project(MSGSeparator)

cmake_minimum_required(VERSION 2.8)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(AMXConfig)
include(AddSAMPPlugin)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/Source
  ${CMAKE_CURRENT_SOURCE_DIR}/SDK
  ${CMAKE_CURRENT_SOURCE_DIR}/SDK/amx
  ${CMAKE_CURRENT_SOURCE_DIR}/SDK/sampgdk
)

add_definitions(-DSAMPGDK_AMALGAMATION)

add_samp_plugin(MSGSeparator
  dllmain.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/SDK/amxplugin.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Source/Separator.cpp
  Source.def
  ${CMAKE_CURRENT_SOURCE_DIR}/SDK/sampgdk/sampgdk.c
  ${CMAKE_CURRENT_SOURCE_DIR}/SDK/sampgdk/sampgdk.h
)
