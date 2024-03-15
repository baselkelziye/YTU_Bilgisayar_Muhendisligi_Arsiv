message('meson.build file find successfully in: ' + meson.current_source_dir())

e = executable('FastLinkedListTests',
           'main.cpp',
           dependencies: [catch2_dep],
           install : false)

test('Fast Linked List Tests', e)