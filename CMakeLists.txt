cmake_minimum_required(VERSION 3.27)
project(LeeErGou)



if(MSVC)
    add_compile_options(/utf-8)
endif()

set(CMAKE_CXX_STANDARD 17)



add_executable(${PROJECT_NAME} src/App.cpp
        src/graphics/Shader.cpp
        src/graphics/Textur.cpp
        src/stb_impl.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_sources(${PROJECT_NAME} PRIVATE assets/icon/appicon.rc)

find_package(spdlog CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)

target_link_libraries(${PROJECT_NAME} PRIVATE ${LIB_HELLO})

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

#导出OpenGL函数库
find_package(glad CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glad::glad)

find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE  ${OPENGL_LIBRARY})

#加载图片库
find_package(Stb REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${Stb_INCLUDE_DIR})
#glm矩阵库
find_package(glm CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm-header-only)

find_package(Boost REQUIRED COMPONENTS filesystem)
target_link_libraries(${PROJECT_NAME} PRIVATE Boost::filesystem)


file(COPY ${PROJECT_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${PROJECT_SOURCE_DIR}/shader DESTINATION ${CMAKE_BINARY_DIR})
## install

# 指定安装目录

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(DIRECTORY assets/
        DESTINATION assets
        FILES_MATCHING
        PATTERN "*")
install(DIRECTORY shader/
        DESTINATION shader
        FILES_MATCHING
        PATTERN "*")

install(SCRIPT "InstallDependencies.cmake")

