# ---------------------------------------------------------------------------
# Framework library
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

set(GL_RELATED_COMPILEABLE_DEPENDENCIES
		glew.c
)

set(GLFW_VERSION_DEPENDENT_DIRECTORY glfw-3.4)
set(FULL_GLFW_INCLUDE_DIRECTORY ${CMAKE_SOURCE_DIR}/external/${GLFW_VERSION_DEPENDENT_DIRECTORY}/include)

add_library(framework_aufgabenblatt_2 STATIC
		${FRAMEWORK_DATA_TYPE_FILES}
		${GL_RELATED_COMPILEABLE_DEPENDENCIES}
)

# WICHTIG: Erzwinge, dass vec2.cpp kompiliert wird
target_sources(framework_aufgabenblatt_2 PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/vec2.cpp
)

target_include_directories(framework_aufgabenblatt_2 PRIVATE
		${FULL_GLFW_INCLUDE_DIRECTORY}
		${CMAKE_SOURCE_DIR}/external/binarized_fonts
		${CMAKE_SOURCE_DIR}/external/nanovg/src
)

target_link_libraries(framework_aufgabenblatt_2
		glfw
		${GLFW_LIBRARIES}
		nanovg
		${OPENGL_LIBRARIES}
)