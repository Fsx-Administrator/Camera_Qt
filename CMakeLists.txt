cmake_minimum_required(VERSION 3.16)

project(Camera VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_FLAGS             "${CMAKE_CXX_FLAGS} -Wunused-parameter -Wextra -Wreorder -Wa,-mbig-obj -O2")
set(CMAKE_CXX_STANDARD          23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC               ON)
set(CMAKE_AUTOUIC               ON)
set(CMAKE_AUTORCC               ON)
set(CMAKE_INCLUDE_CURRENT_DIR   ON)
set(WIN32_EXECUTABLE            OFF)

find_package(Qt6 REQUIRED COMPONENTS
    Multimedia
    MultimediaWidgets
    Widgets
)

############################################### Сборка исходников ###############################################

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR}/bin)
set(SOURCE_ROOT                     ${PROJECT_SOURCE_DIR}/src)
set(ICONS_ROOT                      icons)

file(GLOB HEADERS ${SOURCE_ROOT}/*.h ${SOURCE_ROOT}/*/*.h)
file(GLOB SOURCES ${SOURCE_ROOT}/*.cpp ${SOURCE_ROOT}/*/*.cpp)

qt_add_executable(${PROJECT_NAME}
    WIN32
    ${HEADERS}
    ${SOURCES}
)
qt_add_resources(${PROJECT_NAME} "icons"
    PREFIX "/"
    FILES
        ${ICONS_ROOT}/record.png
        ${ICONS_ROOT}/stop_record.png
        ${ICONS_ROOT}/take_picture.png
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${SOURCE_ROOT}
    ${SOURCE_ROOT}/camera
    ${SOURCE_ROOT}/ui
    ${SOURCE_ROOT}/wrappers
)

#################################################################################################################

############################################ Подключение бибилиотек #############################################

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Multimedia
    Qt${QT_VERSION_MAJOR}::MultimediaWidgets
    Qt${QT_VERSION_MAJOR}::Widgets
)

#################################################################################################################

############################################# Установка dll-файлов ##############################################

set(QT_DLL_PATH C:/Qt/6.7.2/mingw_64)

install(FILES
    ${QT_DLL_PATH}/bin/d3dcompiler_47.dll
    ${QT_DLL_PATH}/bin/libgcc_s_seh-1.dll
    ${QT_DLL_PATH}/bin/libstdc++-6.dll
    ${QT_DLL_PATH}/bin/libwinpthread-1.dll
    ${QT_DLL_PATH}/bin/opengl32sw.dll
    ${QT_DLL_PATH}/bin/Qt6Concurrent.dll
    ${QT_DLL_PATH}/bin/Qt6Core.dll
    ${QT_DLL_PATH}/bin/Qt6Core5Compat.dll
    ${QT_DLL_PATH}/bin/Qt6DataVisualization.dll
    ${QT_DLL_PATH}/bin/Qt6Gui.dll
    ${QT_DLL_PATH}/bin/Qt6Network.dll
    ${QT_DLL_PATH}/bin/Qt6OpenGL.dll
    ${QT_DLL_PATH}/bin/Qt6OpenGLWidgets.dll
    ${QT_DLL_PATH}/bin/Qt6PrintSupport.dll
    ${QT_DLL_PATH}/bin/Qt6Qml.dll
    ${QT_DLL_PATH}/bin/Qt6QmlModels.dll
    ${QT_DLL_PATH}/bin/Qt6Quick.dll
    ${QT_DLL_PATH}/bin/Qt6SerialPort.dll
    ${QT_DLL_PATH}/bin/Qt6Svg.dll
    ${QT_DLL_PATH}/bin/Qt6Widgets.dll
DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

install(FILES
    ${QT_DLL_PATH}/plugins/iconengines/qsvgicon.dll
DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/iconengines)

install(FILES
    ${QT_DLL_PATH}/plugins/imageformats/qgif.dll
    ${QT_DLL_PATH}/plugins/imageformats/qico.dll
    ${QT_DLL_PATH}/plugins/imageformats/qjpeg.dll
    ${QT_DLL_PATH}/plugins/imageformats/qsvg.dll
DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/imageformats)

install(FILES
    ${QT_DLL_PATH}/plugins/platforms/qwindows.dll
DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/platforms)

install(FILES
    ${QT_DLL_PATH}/plugins/styles/qmodernwindowsstyle.dll
    DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/styles)

install(FILES
    ${QT_DLL_PATH}/plugins/tls/qcertonlybackend.dll
    ${QT_DLL_PATH}/plugins/tls/qopensslbackend.dll
    ${QT_DLL_PATH}/plugins/tls/qschannelbackend.dll
DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/tls)

file(GLOB TRANSLATIONS
    ${QT_DLL_PATH}/translations/*.qm
)
install(FILES ${TRANSLATIONS} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/translations)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${PROJECT_NAME})
endif()

#################################################################################################################
