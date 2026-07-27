cmake_minimum_required(VERSION 3.8)
project(testefull)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(tutorial_interfaces)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

add_executable(teste_node src/teste_node.cpp)
add_executable(publicar src/teste_publisher.cpp)
add_executable(inscrito src/teste_subscriber.cpp)
add_executable(cliente src/teste_clientservico.cpp)
add_executable(server src/teste_serverservico.cpp)
add_executable(parametro src/teste_parameters.cpp)

ament_target_dependencies(teste_node rclcpp)
ament_target_dependencies(publicar rclcpp std_msgs)
ament_target_dependencies(inscrito rclcpp std_msgs)
ament_target_dependencies(cliente rclcpp tutorial_interfaces)
ament_target_dependencies(server rclcpp tutorial_interfaces)
ament_target_dependencies(parametro rclcpp)

target_include_directories(teste_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)
target_compile_features(teste_node PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)
install(TARGETS 
  teste_node 
  publicar 
  inscrito 
  server 
  cliente 
  parametro
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
