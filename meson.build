
project('ioc', 'cpp',  default_options : ['cpp_std=c++11'])

# Executables
executable('ioc', 'src/ioc/cpp/main.cpp', 'src/ioc/cpp/Content.cpp', 'src/ioc/cpp/FilesFinder.cpp')

# Tests
content_test = executable('content_test', 'src/iocTest/cpp/ContentTest.cpp', 'src/ioc/cpp/Content.cpp')
# when they implement https://github.com/mesonbuild/meson/issues/860 there will be a better way to copy test resources
configure_file(input : 'src/iocTest/cpp/resources/example.txt', output : 'example.txt', configuration : configuration_data())
test('content test', content_test, args : ['-r', 'compact'])

# files test
files_test = executable('files_test', 'src/iocTest/cpp/FilesFinderTest.cpp', 'src/ioc/cpp/FilesFinder.cpp')
test('files test', files_test, args : ['-r', 'compact'])
