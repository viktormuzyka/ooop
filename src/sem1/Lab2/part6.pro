QT += widgets
requires(qtConfig(filedialog))

SOURCES   = \
            finddialog.cpp \
            main.cpp \
            texthook.cpp
HEADERS   = \
            finddialog.h \
            texthook.h

QMAKE_PROJECT_NAME = ab_part6

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/tutorials/addressbook/part6
INSTALLS += target
