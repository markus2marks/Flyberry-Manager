cmake_minimum_required(VERSION 3.10)

# Set some basic project attributes
project (flyberry-manager
	VERSION 0.1
	DESCRIPTION "A Hello World Project")

find_package(Qt6 REQUIRED COMPONENTS Core Gui OpenGL OpenGLWidgets Widgets Core5Compat)

qt_standard_project_setup()

# This project will output an executable file
qt_add_executable(${PROJECT_NAME}
shutdown.ui
flyberry-manager.cpp 
Shutdown.cpp)

# Create a simple configuration header
configure_file(config.h.in config.h)

# Include the configuration header in the build
target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}" -lwiringPi)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::OpenGL
    Qt6::OpenGLWidgets
    Qt6::Widgets
    Qt6::Core5Compat
)