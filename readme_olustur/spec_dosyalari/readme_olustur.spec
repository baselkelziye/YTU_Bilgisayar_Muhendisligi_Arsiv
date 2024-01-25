# -*- mode: python ; coding: utf-8 -*-

import os

a = Analysis(
    ['../readme_olustur.py'],
    pathex=[],
    binaries=[],
    datas=[('../readme_guncelleme_arayuzu_python', 'readme_guncelleme_arayuzu_python')],
    hiddenimports=[],
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
    name='readme_olustur.exe',
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
