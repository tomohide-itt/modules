add_library( tensor STATIC tensor.h tensor1.cpp sym_tensor2.cpp tensor2.cpp sym_tensor4.cpp )
target_include_directories( tensor INTERFACE ${PROJECT_SOURCE_DIR}/tensor )
