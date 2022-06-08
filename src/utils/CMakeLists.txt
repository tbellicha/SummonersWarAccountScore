set(INCROOT ${PROJECT_SOURCE_DIR}/src/utils)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/utils)

set(SRC
    ${SRC} ${SRCROOT}/getMemberValue.cpp ${SRCROOT}/getStat.cpp
    ${SRCROOT}/removeSpaces.cpp ${SRCROOT}/maxMainStat.cpp
    PARENT_SCOPE)

set(INCDIRS
    ${INCDIRS} ${INCROOT}
    PARENT_SCOPE)
