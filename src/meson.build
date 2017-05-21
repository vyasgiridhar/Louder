louder_sources = [
  'main.c',
  'louder-window.c',
  'louder-application.c',
]

louder_deps = [
  dependency('glib-2.0'),
  dependency('gtk+-3.0'),
]

executable('louder', louder_sources,
  dependencies: louder_deps,
  install: true,
)
