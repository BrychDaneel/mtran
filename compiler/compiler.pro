QT -= gui

CONFIG += c++14 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    codesource.cpp \
    lexicalanalizer.cpp \
    token.cpp \
    tokenfactory.cpp \
    tokens/endtoken.cpp \
    tokens/emptytoken.cpp \
    tokens/idtoken.cpp \
    tokens/spacetoken.cpp \
    tokens/commenttoken.cpp \
    tokens/colontoken.cpp \
    tokens/leftbracetoken.cpp \
    tokens/rightbracetoken.cpp \
    tokens/eqtoken.cpp \
    tokens/adresstoken.cpp \
    tokens/valuetoken.cpp \
    tokens/assigntoken.cpp \
    tokens/semicolontoken.cpp \
    tokens/comatoken.cpp \
    tokens/sumtoken.cpp \
    tokens/bintoken.cpp \
    tokens/ynartoken.cpp \
    tokens/facttoken.cpp \
    tokens/dotdottoken.cpp \
    tokens/dottoken.cpp \
    tokens/leftbrackettoken.cpp \
    tokens/rightbrackettoken.cpp \
    tokens/leftsquartoken.cpp \
    tokens/rightsquartoken.cpp \
    tokens/integertoken.cpp \
    tokens/realtoken.cpp \
    tokens/stringtoken.cpp \
    tokens/chartoken.cpp \
    keywordsfactory.cpp \
    tokens/keywordtoken.cpp \
    syntaxanalizer.cpp \
    node.cpp \
    basenode.cpp \
    rule.cpp \
    baserule.cpp \
    rules/terminalrule.cpp

HEADERS += \
    codesource.h \
    lexicalanalizer.h \
    token.h \
    tokenfactory.h \
    tokens/endtoken.h \
    tokens/emptytoken.h \
    tokens/idtoken.h \
    tokens/spacetoken.h \
    tokens/commenttoken.h \
    tokens/colontoken.h \
    tokens/leftbracetoken.h \
    tokens/rightbracetoken.h \
    tokens/eqtoken.h \
    tokens/adresstoken.h \
    tokens/valuetoken.h \
    tokens/assigntoken.h \
    tokens/semicolontoken.h \
    tokens/comatoken.h \
    tokens/sumtoken.h \
    tokens/bintoken.h \
    tokens/ynartoken.h \
    tokens/facttoken.h \
    tokens/dotdottoken.h \
    tokens/dottoken.h \
    tokens/leftbrackettoken.h \
    tokens/rightbrackettoken.h \
    tokens/leftsquartoken.h \
    tokens/rightsquartoken.h \
    tokens/integertoken.h \
    tokens/realtoken.h \
    tokens/stringtoken.h \
    tokens/chartoken.h \
    keywordsfactory.h \
    tokens/keywordtoken.h \
    syntaxanalizer.h \
    node.h \
    basenode.h \
    rule.h \
    baserule.h \
    rules/terminalrule.h
