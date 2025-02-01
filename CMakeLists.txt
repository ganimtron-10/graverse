cmake_minimum_required(VERSION 3.22)

project(GraVerse)

# # file(GLOB ALGO_FILES "algos/line/*.cpp" )
# # add_library(graverse_algo STATIC ${ALGO_FILES})

# include_directories(
#     ${CMAKE_CURRENT_SOURCE_DIR}/algos
#     ${CMAKE_CURRENT_SOURCE_DIR}/interface
#     ${CMAKE_CURRENT_SOURCE_DIR}/demos
# )

# add_library(graverse_algo STATIC algos/line/ddaLine.cpp algos/utils/utils.cpp)

# add_library(graverse_interface STATIC interface/adapters/terminal_adapter.cpp)

# # target_link_libraries(graverse_algo graverse_interface)

# add_executable(line_dda demos/line_dda.cpp)

# target_link_libraries(line_dda graverse_algo graverse_interface)

# ----------------------
# add_subdirectory(algos)
# add_subdirectory(interface)
# add_subdirectory(demos)

#------------------------

include_directories(include)

set(ALGOS 
    src/algos/ddaLine.cpp 
    src/algos/scanLineFill.cpp
)

set(ADAPTERS
    src/adapter/raylib_adapter.cpp 
    src/adapter/terminal_adapter.cpp
)

add_library(${PROJECT_NAME} ${ALGOS} ${ADAPTERS} src/utils.cpp)

add_executable(line_dda demos/line_dda.cpp)
target_link_libraries(line_dda ${PROJECT_NAME} -lraylib)

add_executable(poly_scanline demos/poly_scanline.cpp)
target_link_libraries(poly_scanline ${PROJECT_NAME} -lraylib)