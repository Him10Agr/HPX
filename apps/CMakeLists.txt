add_executable(main_example main.cpp)
target_link_libraries(main_example PRIVATE HPX_lib)

# Link MPI example if enabled
if(WITH_MPI)
    add_executable(mpi_example mpi_example.cpp)
    target_link_libraries(mpi_example MPI::MPI_CXX)
endif()

# Link HPX example if enabled
if(WITH_HPX)
    add_executable(hpx_example hpx_example.cpp)
    target_link_libraries(hpx_example HPX::hpx HPX::wrap_main 
                            HPX::iostreams_component HPX_lib)
endif()

# Link HPX SIMD example if enabled
if(WITH_HPX_SIMD)
    add_executable(hpx_simd_example hpx_simd_example.cpp)
    target_link_libraries(hpx_simd_example HPX::hpx HPX::wrap_main)
endif()

# Link HPX Coroutine example if enabled
if(WITH_HPX_COROUTINE)
    add_executable(hpx_coroutine_example hpx_coroutine_example.cpp)
    target_link_libraries(hpx_coroutine_example HPX::hpx HPX::wrap_main)
endif()