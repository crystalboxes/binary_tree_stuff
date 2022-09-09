find_program(git_executable NAMES git git.exe git.cmd)

if(NOT git_executable)
  message(FATAL_ERROR "Failed to find git.")
endif()

function(UpdateExternalLib name url rev)
  set(need_checkout FALSE)
  set(external_folder "${CMAKE_CURRENT_SOURCE_DIR}/../external")
  set(external_lib_folder "${external_folder}/${name}")

  if(EXISTS ${external_lib_folder})
    message(STATUS "Updating ${name} to revision ${rev}...")
    execute_process(COMMAND "${git_executable}" "fetch" "origin" WORKING_DIRECTORY "${external_lib_folder}")
    execute_process(COMMAND "${git_executable}" "rev-parse" "HEAD" WORKING_DIRECTORY "${external_lib_folder}" OUTPUT_VARIABLE head_rev)
    string(STRIP ${head_rev} head_rev)

    if(${head_rev} STREQUAL ${rev})
      set(need_checkout FALSE)
    else()
      set(need_checkout TRUE)
    endif()
  else()
    message(STATUS "Cloning ${name} revision...")
    execute_process(COMMAND "${git_executable}" "clone" ${url} "-n" WORKING_DIRECTORY "${external_folder}")
    set(need_checkout TRUE)
  endif()

  if(need_checkout)
    message(STATUS "Checking out to revision ${rev}...")
    execute_process(COMMAND "${git_executable}" "checkout" "-q" ${rev} WORKING_DIRECTORY "${external_lib_folder}")
  endif()
endfunction()

UpdateExternalLib("cairo-cmake-static" "https://github.com/crystalboxes/cairo-cmake-static.git" "f658c250d09dfeaaabb3a12b1afb4443c87f30ea")
UpdateExternalLib("glfw" "https://github.com/glfw/glfw.git" "6b57e08bb0078c9834889eab871bac2368198c15")
# Configure glfw
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
option(GLFW_BUILD_DOCS "Build the GLFW documentation" OFF)
option(GLFW_INSTALL "Generate installation target" OFF)

add_subdirectory(glfw)
add_subdirectory(cairo-cmake-static)
