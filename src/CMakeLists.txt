set(INCROOT ${PROJECT_SOURCE_DIR}/src)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src)

set(SRC)

add_subdirectory(File)
add_subdirectory(Rune)
add_subdirectory(Config)
add_subdirectory(Monster)
add_subdirectory(utils)

set(INCDIRS ${INCROOT})

source_group("" FILES ${SRC})

set(LIB_NAME librunes)
set(TARGET_NAME runes)

add_library(librunes ${SRC})

target_include_directories(${LIB_NAME} PRIVATE ${INCDIRS})
target_include_directories(${LIB_NAME} PUBLIC ${INCROOT})

add_executable(${TARGET_NAME} ${SRCROOT}/main.cpp)
target_link_libraries(${TARGET_NAME} PRIVATE ${LIB_NAME})

add_custom_command(
  TARGET ${TARGET_NAME}
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${TARGET_NAME}>
          ${PROJECT_SOURCE_DIR})
