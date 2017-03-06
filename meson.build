
project('ioc', 'cpp',  default_options : ['cpp_std=c++11'])

# Executables
executable('ioc', 'src/ioc/cpp/main.cpp', 'src/ioc/cpp/Content.cpp')

# Tests
test_sources = ['src/iocTest/cpp/ContentTest.cpp', 'src/ioc/cpp/Content.cpp']

content_test = executable('content_test', test_sources)

# when they implement https://github.com/mesonbuild/meson/issues/860 there will be a better way to copy test resources

configure_file(input : 'src/iocTest/cpp/resources/example.txt',
  output : 'example.txt',
  configuration : configuration_data())

test('content test', content_test)
