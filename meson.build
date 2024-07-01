# Set up project
project('shared lib', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++14']
)

# External includes
incdir_vendor = include_directories('vendor')

# External dependencies
libdir = meson.source_root() + '/external_deps/rlImGui/bin/Debug'
rlimgui_header_dir = 'external_deps/rlImGui'
imgui_header_dir = 'external_deps/rlImGui/imgui-master'
raylib_header_dir = 'external_deps/rlImGui/raylib-master'

rlimgui_lib = 'rlImGui'
rlimgui_dep = declare_dependency(
  link_args : ['-L' + libdir, '-l' + rlimgui_lib],
  include_directories : [include_directories(imgui_header_dir), include_directories(rlimgui_header_dir)]
)
raylib_lib = 'raylib'
raylib_dep = declare_dependency(
  link_args : ['-L' + libdir, '-l' + raylib_lib],
  include_directories : include_directories(raylib_header_dir)
)

# Configure libarena build
subdir('libarena')
incdir_arena = include_directories('libarena/include')
lib_arena = library('arena', sources_arena, include_directories : incdir_arena)

# libarena tests
e = executable('arena_test', sources_arena_test, include_directories : incdir_arena, link_with : lib_arena)
test('Arena Test', e)

# Configure chemlab build
subdir('Chemlab')
executable('chemlab', sources_chemlab,
  include_directories : [incdir_vendor],
   dependencies : [rlimgui_dep, raylib_dep]
)

