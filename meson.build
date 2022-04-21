project('st-sdl', 'c', version: '0.3.0', default_options : ['c_std=c99'])

thread_dep = dependency('threads')

SDL_dep = dependency('SDL2', version : '>=2.0.11')
SDL_ttf_dep = dependency('SDL2_ttf', version : '>=2.0.11')

cc = meson.get_compiler('c')
util_dep = cc.find_library('util', required : true)

sources = [
    'st.c'
]

executable('st', sources,
    dependencies: [ SDL_dep, SDL_ttf_dep, util_dep, thread_dep ],
    c_args : [
      '-DVERSION="0.3"',
      '-D_GNU_SOURCE=1',
      '-D_REENTRANT',
    ]
)
