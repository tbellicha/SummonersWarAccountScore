set(INCROOT ${PROJECT_SOURCE_DIR}/src/Monster)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Monster)

set(SRC
    ${SRC} ${SRCROOT}/monster.cpp
    PARENT_SCOPE)

set(INCDIRS
    ${INCDIRS} ${INCROOT}
    PARENT_SCOPE)
