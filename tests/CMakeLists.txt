# tests config

enable_testing()

include(CTest)
include(AddTests.cmake)

AddTests("Example" "src/example/example.cpp" "")
AddTests("Console" "src/ConsoleApp/Console.cpp" "CoreLib")
