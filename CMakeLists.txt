cmake_minimum_required(VERSION 3.0.2)
project(ImageManager)

find_package(OpenCV REQUIRED)

include_directories(include ${OpenCV_INCLUDE_DIRS})

set(EXCLUDE_PATHS
    "CMakeFiles"
)
file(GLOB_RECURSE CPP_FILES "*.cpp")

foreach(TMP_PATH ${CPP_FILES})
    foreach(EXCLUDE_PATH ${EXCLUDE_PATHS})
        string(FIND ${TMP_PATH} ${EXCLUDE_PATH} RESULT)

        if(NOT ${RESULT} EQUAL -1)
            list(REMOVE_ITEM CPP_FILES ${TMP_PATH})
        endif()
    endforeach(EXCLUDE_PATH)
endforeach(TMP_PATH)

add_library(${PROJECT_NAME} SHARED ${CPP_FILES})
# add_executable(${PROJECT_NAME} ${CPP_FILES})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBRARIES} pthread)