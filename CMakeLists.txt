cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Terminio VERSION 0.1.0)

set(SQLITECPP_RUN_CPPCHECK OFF CACHE BOOL "" FORCE)
set(SQLITECPP_RUN_CPPLINT OFF CACHE BOOL "" FORCE)

add_subdirectory(lib/SQLiteCpp)
add_subdirectory(lib/FTXUI)


SET(SRC_FILES 
src/main.cpp
src/view/MainPage.cpp
src/view/NotesPage.cpp
src/view/PageTools.cpp)

add_executable(Terminio ${SRC_FILES})

target_link_libraries(Terminio
    PRIVATE SQLiteCpp
    PRIVATE sqlite3
    PRIVATE ftxui::screen
    PRIVATE ftxui::dom
    PRIVATE ftxui::component
)
