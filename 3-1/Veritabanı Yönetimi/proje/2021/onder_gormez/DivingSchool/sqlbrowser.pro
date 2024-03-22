TEMPLATE        = app
TARGET          = sqlbrowser

QT              += sql widgets
requires(qtConfig(tableview))

HEADERS         = browser.h connectionwidget.h qsqlconnectiondialog.h addstudentdialog.h
SOURCES         = main.cpp browser.cpp connectionwidget.cpp qsqlconnectiondialog.cpp addstudentdialog.cpp

FORMS           = browserwidget.ui qsqlconnectiondialog.ui addstudentdialog.ui
build_all:!build_pass {
    CONFIG -= build_all
    CONFIG += release
}

# install
target.path = $$[QT_INSTALL_EXAMPLES]/sql/sqlbrowser
INSTALLS += target
