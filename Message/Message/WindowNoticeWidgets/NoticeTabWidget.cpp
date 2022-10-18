#include "NoticeTabWidget.h"

#include <QFont>
#include <QGridLayout>
#include <QLabel>
#include <QList>
#include <QTabWidget>
#include <QTextBlockFormat>
#include <QTextCursor>
#include <QTextEdit>
#include <QSpinBox>

#include "Message/Notice/NoticeFlag.h"

//Public functions
NoticeTabWidget::NoticeTabWidget(int in,QGridLayout* gL,QWidget* tab,QTabWidget* tabW,QStringList& text,bool tr,NoticeFlag f,QWidget* parent) :  SingleLayoutWidget(parent) {
    this->clearLayout(gL);

    this->v_gLayout = gL;
    this->v_tab = tab;
    this->v_tabW = tabW;
    this->v_flag = f;
    this->v_index = this->v_originalIndex = in;

    if(tr == true) {
        this->v_tabText = text.takeFirst();
        this->v_trTab = text.takeFirst();
        this->v_labelText = text.takeFirst();
        this->v_trLabel = text.takeFirst();
    }else {
        this->v_tabText = text.takeFirst();
        this->v_labelText = text.takeFirst();
    }

    this->init();
}

void NoticeTabWidget::setFont(QFont f) {
    this->setFont({f,f,f});
}

void NoticeTabWidget::setFont(QList<QFont> f) {
    if(this->v_label != nullptr && f.size() > 0) {
        this->v_label->setFont(f.takeFirst() );
    }
    if(this->v_edit != nullptr && f.size() > 0) {
        this->v_edit->setFont(f.takeFirst() );
    }
    if(this->v_spin != nullptr && f.size() > 0) {
        this->v_spin->setFont(f.takeFirst() );
    }
}

void NoticeTabWidget::setChild(NoticeTabWidget* ch) {
    this->v_child = ch;
}

void NoticeTabWidget::setText(QString t,QFlags<Qt::AlignmentFlag> f) {
    this->v_edit->setText(t);

    this->alignTextEdit(f);
}

void NoticeTabWidget::setLabel(int pos) {
    QString pS = QString::number(pos);
    QString sS = QString::number(this->v_size);

    this->v_label->setText(this->v_labelText+"[ "+pS+" / "+sS+" ]");
}

void NoticeTabWidget::setData(int size,int pos) {
    this->v_size = size;

    if(this->tabUsed() == false) {
        return;
    }

    this->v_spin->setMinimum(0);
    emit this->v_spin->valueChanged(0);
    this->v_spin->setMaximum(size);

    emit this->v_spin->valueChanged(pos);
    this->v_spin->setMinimum(1);
}

void NoticeTabWidget::resetTab(bool resetChild) {
    if(this->v_originalIndex != this->v_index) {
        this->v_index = this->v_originalIndex;

        this->v_tabW->insertTab(this->v_index,this->v_tab,this->v_tabText);
    }

    if(this->v_child != nullptr && resetChild == true) {
        this->v_child->resetTab();
    }

}

bool NoticeTabWidget::inUse() {
    return (this->v_index == -1) ? false : true;
}

void NoticeTabWidget::reTranslate() {
    if(this->v_trLabel.isEmpty() == false) {
        this->v_labelText = NoticeTabWidget::tr(this->v_trLabel.toStdString().c_str() );
    }
    if(this->v_trTab.isEmpty() == false) {
        this->v_tabText = NoticeTabWidget::tr(this->v_trTab.toStdString().c_str() );
    }
    if(this->v_size > 0) {
        emit this->messageChanged(this->v_spin->value(),this->v_flag);
    }
}

//Protected slots
void NoticeTabWidget::numberChanged() {
    emit this->messageChanged(this->v_spin->value(),this->v_flag);
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

    connect(this->v_spin,SIGNAL(valueChanged(int) ),this,SLOT(numberChanged() ) );

    this->v_edit->setReadOnly(true);
    this->v_edit->setPalette(this->textEditPalette() );

    this->v_gLayout->addWidget(this->v_label,0,0);
    this->v_gLayout->addWidget(this->v_spin,0,1);
    this->v_gLayout->addWidget(this->v_edit,1,0,1,2);

    this->setLabel(0);
}

void NoticeTabWidget::alignTextEdit(QFlags<Qt::AlignmentFlag> f) {
    QTextCursor cu = this->v_edit->textCursor();

        cu.movePosition(QTextCursor::Start);

        while(cu.atEnd() == false) {
            QTextBlockFormat text = cu.blockFormat();

            text.setAlignment(f);
            cu.mergeBlockFormat(text);

            if(cu.movePosition(QTextCursor::NextBlock) == false) {
                break;
            }
        }

        this->v_edit->setTextCursor(cu);
}

bool NoticeTabWidget::tabUsed() {
    if(this->v_size > 0) {
        return true;
    }

    this->v_spin->setMinimum(0);
    this->v_spin->setValue(0);

    this->v_tabW->removeTab(this->v_index);

    this->v_index = -1;

    if(this->v_child != nullptr) {
        this->childIndexChange();
    }

    return false;
}

void NoticeTabWidget::childIndexChange() {
    this->v_index--;

    if(this->v_child != nullptr) {
        this->v_child->childIndexChange();
    }

}
