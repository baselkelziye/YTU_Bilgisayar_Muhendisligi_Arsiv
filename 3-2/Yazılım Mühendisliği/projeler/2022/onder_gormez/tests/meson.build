message('meson.build file find successfully in: ' + meson.current_source_dir())

exec = executable('LanguageSchoolUnitTests',
               '21011111.cpp', # SEDEN RAZİ
               '21501027.cpp', # BATUHAN HANGÜN
               '21501035.cpp', # ÖNDER GÖRMEZ
               '21501045.cpp', # BÜŞRA BASAER
               '21501081.cpp', # ENES DOĞAN ŞANLI
               'main.cpp',
               dependencies: [catch2_dep],
               install: false,
)

test('Language School Unit Tests', exec)
