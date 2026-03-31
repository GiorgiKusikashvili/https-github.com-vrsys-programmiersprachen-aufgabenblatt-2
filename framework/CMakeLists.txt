# ---------------------------------------------------------------------------
# Framework library
#   A static library is a collection of compiled code that can be reused
#   by multiple executables. Here we bundle all the framework files
#   (shapes, math types, window handling) into one library called
#   "framework_aufgabenblatt_2".
#
#   The files listed below are the ones you will edit for this assignment.
# ---------------------------------------------------------------------------
set(FRAMEWORK_DATA_TYPE_FILES
	circle.hpp
	circle.cpp
	color.hpp
	mat2.hpp
	mat2.cpp
	rectangle.hpp
	rectangle.cpp
	vec2.hpp
	vec2.cpp
	window.hpp
	window.cpp
)

# GLEW provides resolved function pointers to OpenGL calls
set(GL_RELATED_COMPILEABLE_DEPENDENCIES
    glew.c
)

set(GLFW_VERSION_DEPENDENT_DIRECTORY glfw-3.4)
set(FULL_GLFW_INCLUDE_DIRECTORY ${CMAKE_SOURCE_DIR}/external/${GLFW_VERSION_DEPENDENT_DIRECTORY}/include)

# ---------------------------------------------------------------------------
# Build the framework as a static library
#   add_library(... STATIC ...) compiles the source files into a .lib/.a file.
#   Other targets (like "example" or "tests") can then link against it
#   using target_link_libraries().
# ---------------------------------------------------------------------------
add_library(framework_aufgabenblatt_2 STATIC ${FRAMEWORK_DATA_TYPE_FILES} ${GL_RELATED_COMPILEABLE_DEPENDENCIES})
target_include_directories(framework_aufgabenblatt_2 PRIVATE
						   ${FULL_GLFW_INCLUDE_DIRECTORY}
						   ${CMAKE_SOURCE_DIR}/external/binarized_fonts
						   ${CMAKE_SOURCE_DIR}/external/nanovg/src
						   ${CMAKE_SOURCE_DIR}/external/binarized_fonts
)

# Link the framework against the graphics libraries it depends on
target_link_libraries(framework_aufgabenblatt_2
	glfw
	${GLFW_LIBRARIES}
	nanovg
	${OPENGL_LIBRARIES}
)
