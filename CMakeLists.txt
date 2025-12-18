cmake_minimum_required(VERSION 3.19)
project(FakeWechat LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(FakeWechat
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    res.qrc
    sidebar.h sidebar.cpp sidebar.ui
    chatlist.h chatlist.cpp chatlist.ui
    chatbox.h chatbox.cpp chatbox.ui
)

target_link_libraries(FakeWechat
    PRIVATE
        Qt::Core
        Qt::Widgets
)

target_include_directories(FakeWechat PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

include(GNUInstallDirs)

install(TARGETS FakeWechat
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET FakeWechat
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
