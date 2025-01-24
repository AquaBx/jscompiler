project('jscompiler', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++14'])

tree_sitter_dep = dependency('tree-sitter')
tree_sitter_javascript_dep = dependency('tree-sitter-javascript')

executable('jscompiler',
           'main.cpp',
           install : true,
           dependencies: [tree_sitter_dep,tree_sitter_javascript_dep])