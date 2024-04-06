cmake_minimum_required(VERSION 3.0.0)
project(leetcode_C VERSION 0.1.0 LANGUAGES C)

set( dir_all    ${CMAKE_CURRENT_SOURCE_DIR}
                ${CMAKE_CURRENT_SOURCE_DIR}/algorithm)

foreach( dir ${dir_all} )
    aux_source_directory( ${dir} src_all )
endforeach()

add_executable(leetcode_C ${src_all}) 

target_link_libraries( leetcode_C )
target_include_directories( leetcode_C PRIVATE ${dir_all} )

# if( UNIX )
#     target_link_libraries( leetcode_C m )
# endif()

unset( dir_all )
unset( src_all )
