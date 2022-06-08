set(INCROOT ${PROJECT_SOURCE_DIR}/src/Config)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Config)

set(SRC
    ${SRC} ${SRCROOT}/config.cpp
    PARENT_SCOPE)

set(INCDIRS
    ${INCDIRS} ${INCROOT}
    PARENT_SCOPE)
