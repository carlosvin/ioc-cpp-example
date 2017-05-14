
project('ioc', 'cpp',  default_options : ['cpp_std=c++11'])

# Executables
executable('ioc', 'src/main.cpp', 'src/Content.cpp', 'src/FilesFinder.cpp')

# Tests
# when they implement https://github.com/mesonbuild/meson/issues/860 there will be a better way to copy test resources
configure_file(input : 'test/resources/example.txt', output : 'example.txt', configuration : configuration_data())

# content test
content_test = executable('content_test', 'test/ContentTest.cpp', 'src/Content.cpp')
test('content test', content_test, args : ['-r', 'compact'])

# files test
files_test = executable('files_test', 'test/FilesFinderTest.cpp', 'src/FilesFinder.cpp')
test('files test', files_test, args : ['-r', 'compact'])

# I can try to generate $ meson.py buildvs --backend vs2015 (I have to install clang on windows)