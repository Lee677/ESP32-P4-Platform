cmake_minimum_required(VERSION 3.16)
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(lvgl_demo_v9)
idf_build_set_property(COMPILE_OPTIONS "-Wno-stringop-truncation" APPEND)