#=============================================================================
# CMake configuration file for the Chrono_Utils library
#=============================================================================

# ------------------------------------------------------------------------------
# LIST THE FILES in the ChronoEngine_Utils LIBRARY
# ------------------------------------------------------------------------------

SET(Chrono_Utils_SOURCES
    ChUtilsData.cpp
    ChUtilsCreators.cpp
    ChUtilsInputOutput.cpp
    ChUtilsValidation.cpp
    ChChaseCamera.cpp
    )

SET(Chrono_Utils_HEADERS
    ChApiUtils.h
    ChUtilsData.h
    ChUtilsGeometry.h
    ChUtilsCreators.h
    ChUtilsInputOutput.h
    ChUtilsValidation.h
    ChUtilsStringFunctions.h
    ChChaseCamera.h
    )


# ------------------------------------------------------------------------------
# ADD THE Chrono_Utils LIBRARY
# ------------------------------------------------------------------------------

ADD_LIBRARY(Chrono_Utils SHARED
    ${Chrono_Utils_HEADERS}
    ${Chrono_Utils_SOURCES})

SET_TARGET_PROPERTIES(Chrono_Utils PROPERTIES
  COMPILE_FLAGS "${CH_BUILDFLAGS}"
  LINK_FLAGS "${CH_LINKERFLAG_GPU}"
  COMPILE_DEFINITIONS "CH_API_COMPILE_UTILS")

TARGET_LINK_LIBRARIES(Chrono_Utils ChronoEngine)

INSTALL(TARGETS Chrono_Utils
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    )

