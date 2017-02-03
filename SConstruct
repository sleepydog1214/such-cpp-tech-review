env = Environment()
env.Append(CXXFLAGS = '-Iheaders -Wall')
print env['CXXFLAGS']

cpp_sources = ['cpp/algo-review.cpp', \
               'cpp/hash-review.cpp', \
               'cpp/instance-list.cpp', \
               'cpp/io-review.cpp', \
               'cpp/list-review.cpp', \
               'cpp/main.cpp', \
               'cpp/parse-json.cpp', \
               'cpp/review.cpp', \
               'cpp/string-review.cpp', \
               'cpp/tree-review.cpp']

cpp_objects = []
for x in cpp_sources:
    tmp = x.replace('.cpp', '.o')
    tmp =  tmp.replace('cpp/', 'obj/')
    cpp_objects.append(tmp)

for index in range(len(cpp_sources)):
    env.Object(cpp_objects[index], cpp_sources[index])

env.Program('cpp-review.out', cpp_objects)
