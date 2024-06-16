cmake_minimum_required(VERSION 3.27)
project(LeeErGou)



if(MSVC)
    add_compile_options(/utf-8)
endif()

set(LIB_HELLO Hello)

add_library(${LIB_HELLO} SHARED src/Hello.cpp
        )
target_include_directories(${LIB_HELLO} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_compile_definitions(${LIB_HELLO} PUBLIC PLATFORM_WINDOWS)
target_compile_definitions(${LIB_HELLO} PUBLIC BUILD_DLL)




add_executable(${PROJECT_NAME} src/App.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include/stb)

target_sources(${PROJECT_NAME} PRIVATE resource/appicon.rc)

find_package(spdlog CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)

target_link_libraries(${PROJECT_NAME} PRIVATE ${LIB_HELLO})

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

find_package(glad CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glad::glad)

find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE  ${OPENGL_LIBRARY})


find_package(Stb REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${Stb_INCLUDE_DIR})


## install

# 指定安装目录

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(DIRECTORY resource/
        DESTINATION resource
        FILES_MATCHING
        PATTERN "*")

install(SCRIPT "InstallDependencies.cmake")

