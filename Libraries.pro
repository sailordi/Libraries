TEMPLATE = subdirs

SUBDIRS += \
    Base \
    Message

Message.depends = Base

CONFIG += ordered
