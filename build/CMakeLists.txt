PROJECT(main)


SET(SRC_LIST ../src/main.cpp
             ../src/lib/helper/Misc.cpp
             ../src/lib/helper/Time.cpp
             ../src/lib/helper/CmdlineOption.cpp
             ../src/lib/helper/Webpage.cpp
             ../src/lib/self/Fyhqy.cpp
             ../src/lib/self/Itplayer.cpp
             ../src/lib/self/Certificate.cpp)

# linux
#>>>>>>>>>>>>>>>>>>>>>>

## debug
#SET(CMAKE_CXX_COMPILER "clang++")
#SET(CMAKE_CXX_FLAGS "-std=c++11 -Werror -Weverything -Wno-documentation -Wno-disabled-macro-expansion -Wno-float-equal -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-global-constructors -Wno-exit-time-destructors -Wno-missing-prototypes -Wno-padded -Wno-old-style-cast")
#SET(CMAKE_BUILD_TYPE debug)
#ADD_EXECUTABLE(main ${SRC_LIST})
#TARGET_LINK_LIBRARIES(main curl pthread)

# release
SET(CMAKE_CXX_COMPILER "g++")
SET(CMAKE_CXX_FLAGS "-std=c++11 -O3")
SET(CMAKE_BUILD_TYPE release)
ADD_EXECUTABLE(autoshadower ${SRC_LIST})
TARGET_LINK_LIBRARIES(autoshadower curl pthread)
INSTALL(PROGRAMS autoshadower DESTINATION /usr/bin/)

#<<<<<<<<<<<<<<<<<<<<<<


## cygwin
##>>>>>>>>>>>>>>>>>>>>>>

#SET(CMAKE_CXX_COMPILER "g++")
#SET(CMAKE_CXX_FLAGS "-std=c++11 -O3 -s -DCYGWIN")
#SET(CMAKE_BUILD_TYPE release)
#ADD_EXECUTABLE(autoshadower ${SRC_LIST})
#target_link_libraries(autoshadower /bin/cygcurl-4.dll)
#target_link_libraries(autoshadower /lib/libiconv.a)

##<<<<<<<<<<<<<<<<<<<<<<


## osX
##>>>>>>>>>>>>>>>>>>>>>>

#SET(CMAKE_CXX_COMPILER "g++")
#SET(CMAKE_CXX_FLAGS "-std=c++11 -O3")
#SET(CMAKE_BUILD_TYPE release)
#ADD_EXECUTABLE(autoshadower ${SRC_LIST})
#TARGET_LINK_LIBRARIES(autoshadower curl pthread iconv)
#INSTALL(PROGRAMS autoshadower DESTINATION /usr/bin/)

##<<<<<<<<<<<<<<<<<<<<<<
