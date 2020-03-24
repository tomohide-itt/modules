add_library( file STATIC file.h file.cpp )
target_include_directories( file INTERFACE ${PROJECT_SOURCE_DIR}/file )
