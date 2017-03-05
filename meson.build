
project('ioc', 'cpp',  default_options : ['cpp_std=c++11'])

# Executables
executable('ioc', 'src/ioc/cpp/main.cpp', 'src/ioc/cpp/Content.cpp')

# Tests
content_test = executable('content_test', 'src/iocTest/cpp/ContentTest.cpp', 'src/ioc/cpp/Content.cpp')
test('content test', content_test)

