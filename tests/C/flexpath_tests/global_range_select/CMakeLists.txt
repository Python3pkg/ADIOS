include_directories(${PROJECT_SOURCE_DIR}/src/public)
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/test/C/flexpath_tests/include)
include_directories(${PROJECT_BINARY_DIR}/src/public)
link_directories(${PROJECT_SOURCE_DIR}/src)
link_directories(${PROJECT_BINARY_DIR}/src)


add_executable(writer writer.c)
target_link_libraries(writer adios ${ADIOSLIB_LDADD} ${MPI_C_LIBRARIES}) 

add_executable(reader reader.c)
target_link_libraries(reader adios ${ADIOSLIB_LDADD} ${MPI_C_LIBRARIES})

file(COPY arrays.xml DESTINATION ${PROJECT_BINARY_DIR}/tests/C/flexpath_tests/global_range_select)
