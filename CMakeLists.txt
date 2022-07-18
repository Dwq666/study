# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)
project ("data_structure"  VERSION 0.1)
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


message("Default Resource File ${RESOURCEFILE}") 

add_executable(data_structure  ${LIB_SOURCE})  #WIN32


set(LIBDIR "${CMAKE_SOURCE_DIR}/lib/${CMAKE_NAME}/${CMAKE_BUILD_TYPE}/")
target_link_directories(data_structure PUBLIC ${LIBDIR}/)

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

target_link_libraries(data_structure ${LIBS} ${EXTLIBS})

add_custom_command(TARGET data_structure 
                    POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E echo compile Finish ${PROJECT_SOURCE_DIR}/win32/bin/data_structure.exe 
                    VERBATIM
                   ) 






