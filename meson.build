
project('ioc', 'cpp',  default_options : ['cpp_std=c++11'])

# Executables
executable('ioc', 'src/ioc/cpp/main.cpp', 'src/ioc/cpp/Content.cpp')

# Tests
test_sources = ['src/iocTest/cpp/ContentTest.cpp', 'src/ioc/cpp/Content.cpp']

content_test = executable('content_test', test_sources)

infile = files('src/iocTest/cpp/resources/example.txt')[0]

mytarget = custom_target('example',
    input: infile,
    output : 'example.txt',
    command: ['cp', '@INPUT@', '@OUTPUT@']
)

test('content test', content_test)
