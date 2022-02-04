function(disable_project_warnings project_name)

  set(MSVC_WARNINGS
    /w
  )

  set(CLANG_WARNINGS
      -w
  )

 

  set(GCC_WARNINGS
    -w
  )

  if(MSVC)
    set(PROJECT_WARNINGS ${MSVC_WARNINGS})
  elseif(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    set(PROJECT_WARNINGS ${CLANG_WARNINGS})
  elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(PROJECT_WARNINGS ${GCC_WARNINGS})
  endif()

  target_compile_options(${project_name} PRIVATE ${PROJECT_WARNINGS})

endfunction()