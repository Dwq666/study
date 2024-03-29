﻿# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)
project ("study"  VERSION 0.1)


#获取所有源码
FILE(GLOB_RECURSE SRCCPP "*.cpp" "*.c" "*.h")
# 添加库源文件
SET(LIB_SOURCE ${SRCCPP} )
message("Build Type ====>${CMAKE_BUILD_TYPE}" )

set(FrameWorkLIBS
       aqScript
       jsanalyzer
       aqAnimation
       design
       AQWebView
       html5
       aqclient
       aqdb
       aqsocket
       aqgdi
       aqcore
    )

#SET(RESOURCEDIR ${PROJECT_SOURCE_DIR}/win32/winres)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  #msvc装载lib的顺序跟 mingw 相反，所以要反序  
  list(REVERSE FrameWorkLIBS) 
  #SET(RESOURCEFILE ${RESOURCEDIR}/msvc.rc)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  #链接资源文件
  SET(CMAKE_EXE_LINKER_FLAGS  " -static -mwindows ${CMAKE_EXE_LINKER_FLAGS} ${RESOURCEDIR}/win.res ") 
endif()  # "MSVC"

#SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/win32/bin)
#分别设置输出路径，避免自动增加debug 或者 release 目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG  ${PROJECT_SOURCE_DIR}/win32/bin)  
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/win32/bin)  
   

include_directories("${CMAKE_SOURCE_DIR}/FrameWork/include")
include_directories("${CMAKE_SOURCE_DIR}/../mysql6/include")


message("Default Resource File ${RESOURCEFILE}") 

add_executable(study  ${LIB_SOURCE})  #WIN32
 
  
set(LIBDIR "${CMAKE_SOURCE_DIR}/lib/${CMAKE_NAME}/${CMAKE_BUILD_TYPE}/")
set(MYSQLLIBDIR "${CMAKE_SOURCE_DIR}/../mysql6/lib")

message("study=======>${MYSQLLIBDIR}") 

target_link_directories(study PUBLIC ${LIBDIR} ${MYSQLLIBDIR})

set(LIBS
   ${FrameWorkLIBS}
   jsv8
   Tinyxml
   zlib
   jsoncpp  
   pcre 
   sqllite
   winmm 
)
message("default Libs>>>${LIBS}" ) 

#FILE(GLOB mysqllib "*.lib")
set(mysqllib
    libmysql
)

target_link_libraries(study ${LIBS} ${EXTLIBS} ${mysqllib})

add_custom_command(TARGET study 
                    POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E echo compile Finish ${PROJECT_SOURCE_DIR}/win32/bin/study.exe
                    VERBATIM
                   ) 






