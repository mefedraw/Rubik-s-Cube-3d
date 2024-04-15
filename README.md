***How to install Open-gl:***

  *download zip and extract files to your project folder*
  https://disk.yandex.ru/d/yRQBSVIuqJSFfQ
    
  *copy this lines to Cmake.txt and change project name*
  ```cmake_minimum_required(VERSION 3.27)
  project(rubik_cube)
  
  set(CMAKE_CXX_STANDARD 17)
  
  add_subdirectory(lib)
  add_executable(${PROJECT_NAME} main.cpp )
  
  target_link_libraries(${PROJECT_NAME}
          glfw ${OPENGL_glu_LIBRARY} ${GLFW_LIBRARIES}
          libglew_static
          glm::glm
  )
  target_include_directories(${PROJECT_NAME} PUBLIC ${GLEW_INCLUDES})
  ```

***WARNING: first version only work on Windows***


***Keyboard bind's:***

  wasd - moving
  
  key-up-down-right-left - cam moving

  "1" - rotation of ru

  "2" - rotation of lu

  "3" - rotation of dl

  "4" - rotation of ul

  "5" - rotation of fs

  "6" - rotation of bs

  "7" - shuffle

  "8" - solve Rubic's Cube

  ![image](https://github.com/mefedraw/Rubik-s-Cube-3d/assets/144416623/9a316e3c-1003-4a52-9037-759a80afb609)

  

  *pss visit Andrew Banach's rubik's cube implementation https://github.com/drlinggg/Rubik-Cube*
