# Set up project
project('shared lib', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++14']
)

# External includes
incdir_vendor = include_directories('vendor')

# Configure libarena build
subdir('libarena')
incdir_arena = include_directories('libarena/include')
lib_arena = library('arena', sources_arena, include_directories : incdir_arena)

# Configure chemlab build
subdir('Chemlab')
executable('chemlab', sources_chemlab, include_directories : [incdir_vendor, incdir_arena], link_with : lib_arena)
