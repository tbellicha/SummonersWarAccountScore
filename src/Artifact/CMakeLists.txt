set(INCROOT ${PROJECT_SOURCE_DIR}/src/Artifact)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/Artifact)

set(SRC
    ${SRC} ${SRCROOT}/artifact.cpp
    PARENT_SCOPE)

set(INCDIRS
    ${INCDIRS} ${INCROOT}
    PARENT_SCOPE)
