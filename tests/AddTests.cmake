cmake_minimum_required(VERSION 3.10)
include_guard(GLOBAL)

function(AddTests TestName sourceFile libLinkTargets)
	
	set(fullName "${PROJECT_NAME}_${TestName}")
	set(_runtime "${fullName}_Tests")

	add_executable(${_runtime} ${sourceFile})
	set_property(TARGET ${_runtime} PROPERTY FOLDER "Tests/")
	target_include_directories(${_runtime} PUBLIC "${vendorPath}/catch2/src/" "${PROJECT_NAME}")
	
	target_link_libraries(${_runtime} PUBLIC Catch2 Catch2WithMain ${libLinkTargets})

	add_test(NAME ${_runtime} COMMAND ${_runtime})

endfunction(AddTests)