testsandboxapi_sources = [
  'main.c',
  'testsandboxapi-window.c',
  ]

testsandboxapi_deps = [
  dependency('gio-2.0', version: '>= 2.50'),
  dependency('gtk+-3.0', version: '>= 3.22'),
  dependency('libportal', version: '>= 0.3'),
]

gnome = import('gnome')

testsandboxapi_sources += gnome.compile_resources('testsandboxapi-resources',
  'testsandboxapi.gresource.xml',
  c_name: 'testsandboxapi'
)

executable('testsandboxapi', testsandboxapi_sources,
  dependencies: testsandboxapi_deps,
  install: true,
)
