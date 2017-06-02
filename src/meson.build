louder_sources = [
  'main.c',
  'louder-window.c',
  'louder-application.c',
  'louder-sidebar-row.c',
  'louder-song-list-row.c',
  'louder-avatar-widget.c',
]

louder_deps = [
  dependency('glib-2.0'),
  dependency('gtk+-3.0'),
  dependency('cairo'),
  dependency('libsoup-2.4'),
]

resources = gnome.compile_resources ('louder-resources',
                                     'ui/louder.gresource.xml',
                                     source_dir: 'ui')

							 
louder_sources += resources
executable('louder', louder_sources,
  dependencies: louder_deps,
  install: true,
)
