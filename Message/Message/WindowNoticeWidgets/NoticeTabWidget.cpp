#include "NoticeTabWidget.h"

#include <QFont>
#include <QGridLayout>
#include <QLabel>
#include <QList>
#include <QTabWidget>
#include <QTextEdit>
#include <QSpinBox>

#include "Base/Other/Helper.h"
#include "Message/Notice/NoticeFlag.h"

//Public functions
NoticeTabWidget::NoticeTabWidget(int in,QGridLayout* gL,QWidget* tab,QTabWidget* tabW,QStringList& text,bool trans,NoticeFlag f,QWidget* parent) :  SingleLayoutWidget(parent) {
    this->clearLayout(gL);

    this->v_gLayout = gL;
    this->v_tab = tab;
    this->v_tabW = tabW;
    this->v_flag = f;
    this->v_index = this->v_originalIndex = in;

    if(QList<int>({4,8,12}).contains(text.size() ) == true && trans == true) {
        this->v_tabText = text.takeFirst();
        this->v_trTab = text.takeFirst();
        this->v_labelText = text.takeFirst();
        this->v_trLabel = text.takeFirst();
    }else if(QList<int>({2,4,6}).contains(text.size() ) == true && trans == false) {
        this->v_tabText = text.takeFirst();
        this->v_labelText = text.takeFirst();
    }else {
        Helper::quitProgram("Error text to few / many arguments ["+QString::number(text.size() )+"]",1);
    }

    this->init();
}

void NoticeTabWidget::setFont(QFont f) {
    if(this->v_label != nullptr) {
        this->v_label->setFont(f);
    }
    if(this->v_edit != nullptr) {
        this->v_edit->setFont(f);
    }
    if(this->v_spin != nullptr) {
        this->v_spin->setFont(f);
    }

}

void NoticeTabWidget::setChild(NoticeTabWidget* ch) {
    this->v_child = ch;
}

//Protected functions
QPalette NoticeTabWidget::textEditPalette() {
    QPalette p;

        p.setColor(QPalette::Base,Qt::black);

        switch(this->v_flag) {
            case NoticeFlag::ERROR:
                p.setColor(QPalette::Text,Qt::red);
                break;
            case NoticeFlag::WARNING:
                p.setColor(QPalette::Text,Qt::yellow);
                break;
            case NoticeFlag::MESSAGE:
                p.setColor(QPalette::Text,Qt::white);
                break;
        }

        return p;
}

void NoticeTabWidget::init() {
    this->v_label = new QLabel(this->v_p);
    this->v_spin = new QSpinBox(this->v_p);
    this->v_edit = new QTextEdit(this->v_p);

    this->v_label->setAlignment(Qt::AlignCenter);

    this->v_edit->setReadOnly(true);
    this->v_edit->setPalette(this->textEditPalette() );

    this->v_gLayout->addWidget(this->v_label,0,0);
    this->v_gLayout->addWidget(this->v_spin,0,1);
    this->v_gLayout->addWidget(this->v_edit,1,0,1,2);
}
