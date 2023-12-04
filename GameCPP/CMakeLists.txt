cmake_minimum_required(VERSION 3.16)

project(GameCPP VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appGameCPP
    main.cpp
)

qt_add_qml_module(appGameCPP
    URI GameCPP
    VERSION 1.0
    QML_FILES Main.qml
    SOURCES game.h game.cpp
    SOURCES player.h player.cpp
    RESOURCES images/player.png
    QML_FILES Map.qml
    QML_FILES Tile.qml
    SOURCES mapgenerator.h mapgenerator.cpp
    SOURCES tile.h tile.cpp
    QML_FILES Player.qml
    SOURCES map.h map.cpp
    RESOURCES mapFile.txt
    RESOURCES images/background/rocks.png
    RESOURCES images/background/path.png
    RESOURCES images/background/grass.png
    RESOURCES images/background/water.png
    RESOURCES images/background/sand.png
    SOURCES config.h config.cpp
    QML_FILES config.json
    QML_FILES GameMenu.qml
    SOURCES EnemyFactory/enemyfactory.h EnemyFactory/enemyfactory.cpp
    SOURCES EnemyFactory/skeleton.h EnemyFactory/skeleton.cpp
    SOURCES EnemyFactory/dragon.h EnemyFactory/dragon.cpp
    SOURCES ItemFactory/itemfactory.h ItemFactory/itemfactory.cpp
    SOURCES EnemyFactory/knight.h EnemyFactory/knight.cpp
    SOURCES ItemFactory/sword.h ItemFactory/sword.cpp
    SOURCES ItemFactory/axe.h ItemFactory/axe.cpp
    SOURCES ItemFactory/platehelmet.h ItemFactory/platehelmet.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appGameCPP PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appGameCPP
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appGameCPP
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appGameCPP
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
