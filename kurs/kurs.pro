#-------------------------------------------------
#
# Project created by QtCreator 2024-01-12T21:17:39
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kurs
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Получить список всех файлов .png в папке relative/path/to/your/
IMAGES += $$files($$PWD/resources)

# Указать, что эти изображения нужно скопировать в папку сборки
# message($$IMAGES)
images.path = $$OUT_PWD
images.files += $$IMAGES
INSTALLS += images



SOURCES += \
        main.cpp \
        mainwindow.cpp \
    dbconnect.cpp \
    leaderboard.cpp

HEADERS += \
        mainwindow.h \
    dbconnect.h \
    leaderboard.h

FORMS += \
        mainwindow.ui \
    leaderboard.ui
