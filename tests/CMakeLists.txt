find_path(GPULITE_CUDA_RUNTIME_INCLUDE_DIR cuda_runtime_api.h
    HINTS "$ENV{CUDA_HOME}/include" "/usr/local/cuda/include"
)

add_executable(gpulite_header_compile header_compile.cpp)
target_link_libraries(gpulite_header_compile PRIVATE gpulite)

if(GPULITE_CUDA_RUNTIME_INCLUDE_DIR)
    # Exercise the nvcc-compatible path with a host compiler.  This catches
    # duplicate declarations without requiring a GPU or the CUDA compiler.
    target_include_directories(gpulite_header_compile PRIVATE
        "${GPULITE_CUDA_RUNTIME_INCLUDE_DIR}"
    )
    target_compile_definitions(gpulite_header_compile PRIVATE __CUDACC__)
endif()

add_test(NAME gpulite_header_compile COMMAND gpulite_header_compile)
