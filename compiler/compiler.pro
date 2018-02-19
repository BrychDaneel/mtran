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
    rules/terminalrule.cpp \
    nodes/terminalnode.cpp \
    nodes/rootnode.cpp \
    rules/rootrule.cpp \
    rules/literalrule.cpp \
    rules/ynooprule.cpp \
    rules/sumoprule.cpp \
    rules/multioprule.cpp \
    rules/varrule.cpp \
    rules/varstartrule.cpp \
    rules/varendrule.cpp \
    rules/emptyrule.cpp \
    rules/indexrule.cpp \
    rules/callrule.cpp \
    rules/paramsrule.cpp \
    rules/paramsstartrule.cpp \
    rules/paramsendrule.cpp \
    rules/operandrule.cpp \
    rules/factrule.cpp \
    rules/factstartrule.cpp \
    rules/factendrule.cpp \
    rules/sumrule.cpp \
    rules/sumstartrule.cpp \
    rules/sumendrule.cpp \
    rules/exprrule.cpp \
    rules/exprstartrule.cpp \
    rules/exprendrule.cpp \
    nodes/emptynode.cpp \
    rules/adressendrule.cpp \
    rules/assignrule.cpp \
    rules/instrrule.cpp \
    rules/instrlistrule.cpp \
    rules/blockrule.cpp \
    rules/forrule.cpp \
    rules/whilerule.cpp \
    rules/repeatrule.cpp \
    rules/ifrule.cpp \
    rules/ifendrule.cpp \
    rules/idinstrrule.cpp \
    rules/idinstrendrule.cpp \
    rules/instrlistendrule.cpp \
    rules/defsrule.cpp \
    rules/varblockrule.cpp \
    rules/functionrule.cpp \
    rules/procedurerule.cpp \
    rules/varbodyrule.cpp \
    rules/idlistrule.cpp \
    rules/idlistendrule.cpp \
    rules/sigrule.cpp \
    rules/sigendrule.cpp \
    rules/typerule.cpp \
    rules/dimrule.cpp \
    rules/dimendrule.cpp \
    rules/rangerule.cpp \
    rules/prognamerule.cpp \
    rules/programrule.cpp \
    symboltable.cpp \
    type.cpp \
    basetype.cpp \
    idinfo.cpp

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
    rules/terminalrule.h \
    nodes/terminalnode.h \
    nodes/rootnode.h \
    rules/rootrule.h \
    rules/literalrule.h \
    rules/ynooprule.h \
    rules/sumoprule.h \
    rules/multioprule.h \
    rules/varrule.h \
    rules/varstartrule.h \
    rules/varendrule.h \
    rules/emptyrule.h \
    rules/indexrule.h \
    rules/callrule.h \
    rules/paramsrule.h \
    rules/paramsstartrule.h \
    rules/paramsendrule.h \
    rules/operandrule.h \
    rules/factrule.h \
    rules/factstartrule.h \
    rules/factendrule.h \
    rules/sumrule.h \
    rules/sumstartrule.h \
    rules/sumendrule.h \
    rules/exprrule.h \
    rules/exprstartrule.h \
    rules/exprendrule.h \
    nodes/emptynode.h \
    rules/adressendrule.h \
    rules/assignrule.h \
    rules/instrrule.h \
    rules/instrlistrule.h \
    rules/blockrule.h \
    rules/forrule.h \
    rules/whilerule.h \
    rules/repeatrule.h \
    rules/ifrule.h \
    rules/ifendrule.h \
    rules/idinstrrule.h \
    rules/idinstrendrule.h \
    rules/instrlistendrule.h \
    rules/defsrule.h \
    rules/varblockrule.h \
    rules/functionrule.h \
    rules/procedurerule.h \
    rules/varbodyrule.h \
    rules/idlistrule.h \
    rules/idlistendrule.h \
    rules/sigrule.h \
    rules/sigendrule.h \
    rules/typerule.h \
    rules/dimrule.h \
    rules/dimendrule.h \
    rules/rangerule.h \
    rules/prognamerule.h \
    rules/programrule.h \
    symboltable.h \
    type.h \
    basetype.h \
    idinfo.h
