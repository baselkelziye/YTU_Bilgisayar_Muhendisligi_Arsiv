# -*- mode: python ; coding: utf-8 -*-


a = Analysis(
    ['../readme_guncelleme_arayuzu_python/main.py'],
    pathex=[],
    binaries=[],
    datas=[
        ('../readme_guncelleme_arayuzu_python', '.'),
        ('../google_forum_islemleri', 'google_forum_islemleri'),
        ('../writers', 'writers'),
        ('../readme_olustur.py', '.'),
        ('../buffered_writer.py', '.'),
        ('../folder_cache.py', '.'),
    ],
    hiddenimports=[
        'pandas',
        'numpy',
        'requests',
        'google_forum_islemleri.ders_icerikleri_guncelle',
        'google_forum_islemleri.hoca_icerikleri_guncelle',
        'google_forum_islemleri.google_form_rutin_kontrol',
        'readme_olustur',
        'buffered_writer',
        'folder_cache',
    ],
    hookspath=[],
    hooksconfig={},
    runtime_hooks=[],
    excludes=[],
    noarchive=False,
)
pyz = PYZ(a.pure)

exe = EXE(
    pyz,
    a.scripts,
    a.binaries,
    a.datas,
    [],
    name='main',
    debug=False,
    bootloader_ignore_signals=False,
    strip=False,
    upx=True,
    upx_exclude=[],
    runtime_tmpdir=None,
    console=True,
    disable_windowed_traceback=False,
    argv_emulation=False,
    target_arch=None,
    codesign_identity=None,
    entitlements_file=None,
)

