TEMPLATE = app
CONFIG -= debug_and_release qt
CONFIG += console debug
#CONFIG += console release

TARGET = pes-lib

OBJECTS_DIR = .obj
MOC_DIR = .moc

INCLUDEPATH += \

INCLUDEPATH += PesLib/

SOURCES += \
PesLib/CMExeEmb.c\
PesLib/CTTFLetter.c\
PesLib/PesLib.c\
PesLib/affine-transform.c\
PesLib/block-geometry.c\
PesLib/helpers-binary.c\
PesLib/pes-circ.c\
PesLib/pes-dtext.c\
PesLib/pes-group-object.c\
PesLib/pes-header.c\
PesLib/pes-letter.c\
PesLib/pes-line.c\
PesLib/pes-motif-data.c\
PesLib/pes-motif.c\
PesLib/pes-mtext.c\
PesLib/pes-ntext.c\
PesLib/pes-one.c\
PesLib/pes-point.c\
PesLib/pes-punch.c\
PesLib/pes-rect.c\
PesLib/pes-satin-stitch.c\
PesLib/pes-sew-fig-seg.c\
PesLib/pes-sew-seg.c\
PesLib/pes-special-shape.c\
PesLib/pes-stamp-description.c\
PesLib/pes-stitch-block.c\
PesLib/pes-thread.c\
PesLib/pes-tile-line.c\
PesLib/point.c\
PesLib/short-array.c\
PesLib/stitch-block-description.c\
    PesLib/pes_pat.c


HEADERS += \
PesLib/CMExeEmb.h\
PesLib/CTTFLetter.h\
PesLib/PesStitchBlock.h\
PesLib/affine-transform.h\
PesLib/block-geometry.h\
PesLib/helpers-binary.h\
PesLib/pes-circ.h\
PesLib/pes-dtext.h\
PesLib/pes-group-object.h\
PesLib/pes-header.h\
PesLib/pes-letter.h\
PesLib/pes-line.h\
PesLib/pes-motif-data.h\
PesLib/pes-motif.h\
PesLib/pes-mtext.h\
PesLib/pes-ntext.h\
PesLib/pes-one.h\
PesLib/pes-point.h\
PesLib/pes-punch.h\
PesLib/pes-rect.h\
PesLib/pes-satin-stitch.h\
PesLib/pes-sew-fig-seg.h\
PesLib/pes-sew-seg.h\
PesLib/pes-special-shape.h\
PesLib/pes-stamp-description.h\
PesLib/pes-stext.h\
PesLib/pes-thread.h\
PesLib/point.h\
PesLib/short-array.h\
PesLib/stitch-block-description.h\
PesLib/tile-line.h\
    PesLib/pes_pat.h

$$PWD \

QMAKE_CFLAGS += -std=c89

#Uncomment lines below to hide various warnings
#QMAKE_CFLAGS_WARN_ON += -Wno-unused-parameter 
#QMAKE_CFLAGS_WARN_ON += -Wno-unused-but-set-variable
#QMAKE_CFLAGS_WARN_ON += -Wno-unused-variable
#QMAKE_CFLAGS_WARN_ON += -Wno-unknown-pragmas



