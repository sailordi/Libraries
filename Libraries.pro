TEMPLATE = subdirs

SUBDIRS += \
    Base \
    Message \
    SQL

Message.depends = Base
SQL.depends = Base

CONFIG += ordered
