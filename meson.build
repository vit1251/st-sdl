project('st-sdl', 'c', version: '0.3.0')

SDL = dependency('SDL', version : '>=1.2.16')
#SDL = dependency('SDL2', version : '>=2.0.11')
SDL_ttf = dependency('SDL_ttf', version : '>=2.0.11')

sources = [
    'st.c'
]

executable('st', sources,
    dependencies: [ SDL, SDL_ttf ],
    c_args : [
      '-DVERSION="0.3"',
      '-D_GNU_SOURCE=1',
      '-D_REENTRANT',
    ]
)
