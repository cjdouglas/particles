include(FetchContent)

message(STATUS "Fetching GLFW 3.4")
FetchContent_Declare(
  glfw
  SYSTEM
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG 3.4
)
FetchContent_MakeAvailable(glfw)
