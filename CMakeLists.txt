cmake_minimum_required(2.8.8)
  project(pm_tp1)

  # Tell CMake to run moc when necessary:
  set(CMAKE_AUTOMOC ON)
  # As moc files are generated in the binary dir, tell CMake
  # to always look for includes there:
  set(CMAKE_INCLUDE_CURRENT_DIR ON)

  # Widgets finds its own dependencies.
  find_package(Qt5Widgets REQUIRED)

  add_executable(${PROJECT_NAME} main.cpp authors.cpp BibtexArticle.cpp BibtexBook.cpp BibtexFormat.cpp BibtexInproceedings.cpp pages.cpp)

  qt5_use_modules(${PROJECT_NAME} Widgets)