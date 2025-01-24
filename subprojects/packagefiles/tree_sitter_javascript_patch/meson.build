project('tree-sitter-javascript', 'c')

src = files(
    'src/parser.c',
    'src/scanner.c',
)

tree_sitter_javascript = library(
    'tree-sitter-javascript',
    src,
    install: not meson.is_subproject(),
)

tree_sitter_javascript_dep = declare_dependency(
    link_with: tree_sitter_javascript,
)

pkg_mod = import('pkgconfig')

pkg_mod.generate(
    tree_sitter_javascript,
    name: 'tree-sitter-javascript',
    description: 'Javascript parser',
    libraries: tree_sitter_javascript,
    version: meson.project_version(),
)
