cmake_minimum_required(VERSION 3.3)
project(ipd15a CXX)
include(.ipd/cmake/CMakeLists.txt)


add_cxx_program(data_members src/data_members.cxx)

add_cxx_test_program(member_functions_test
        test/member_functions_test.cxx
        src/member_functions.cxx)

add_cxx_test_program(constructors_test
        test/constructors_test.cxx
        src/constructors.cxx)

###
### Exercises
###

add_cxx_program(ipd15a-1
        exercise/ipd15a-1-main.cxx
        exercise/ipd15a-1.cxx)

add_cxx_test_program(ipd15a-2
        exercise/ipd15a-2.cxx
        exercise/ipd15a-1.cxx)

add_cxx_test_program(ipd15a-3
        exercise/ipd15a-3.cxx
        src/member_functions.cxx)
