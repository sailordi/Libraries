TEMPLATE = subdirs

SUBDIRS += \
    Base \
    Message \
    SQL

Message.depends = Base

CONFIG += ordered
