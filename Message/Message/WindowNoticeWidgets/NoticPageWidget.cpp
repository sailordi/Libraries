#include "NoticPageWidget.h"

#include <QFont>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

#include "Base/Other/Helper.h"

//Public functions
NoticPageWidget::NoticPageWidget(QStringList btnText,QGridLayout* gL,QHBoxLayout* hL,bool tr,QWidget* parent) : SingleLayoutWidget(parent) {
    this->v_gLayout = gL;
    this->v_hLayout = hL;

    if(tr == true) {
        this->v_nextPageText = btnText.takeFirst();
        this->v_nextPageTr = btnText.takeFirst();

        this->v_nextListText = btnText.takeFirst();
        this->v_nextListTr = btnText.takeFirst();

        this->v_prevPageText = btnText.takeFirst();
        this->v_prevPageTr = btnText.takeFirst();

        this->v_prevListText = btnText.takeFirst();
        this->v_prevListTr = btnText.takeFirst();
    }
    else {
        this->v_nextPageText = btnText.takeFirst();
        this->v_nextListText = btnText.takeFirst();
        this->v_prevPageText = btnText.takeFirst();
        this->v_prevListText = btnText.takeFirst();
    }

    this->init();
}

NoticPageWidget::~NoticPageWidget() {
    this->v_pages.clear();
}

void NoticPageWidget::setFont(QFont f) {
    if(this->v_pageLabel != nullptr) {
        this->v_pageLabel->setFont(f);
    }

    if(this->v_prevPageB != nullptr) {
        this->v_prevPageB->setFont(f);
    }
    if(this->v_nextPageB != nullptr) {
        this->v_nextPageB->setFont(f);
    }

    if(this->v_prevListB != nullptr) {
        this->v_prevListB->setFont(f);
    }
    if(this->v_nextListB != nullptr) {
        this->v_nextListB->setFont(f);
    }

}

void NoticPageWidget::add(NoticePage* p) {
    if(p == nullptr) {
        return;
    }

    this->v_pages.push_back(NoticePageP(p) );
}

void NoticPageWidget::add(NoticePageP p) {
    if(p.isNull() == true) {
        return;
    }

    this->v_pages.push_back(p);
}

NoticePageP NoticPageWidget::currentPage() {
    if(this->v_pages.size() <= 0) {
        return nullptr;
    }

    return this->v_pages.at(this->v_pageIndex);
}

NoticeListP NoticPageWidget::curretList() {
    NoticePageP p = this->currentPage();

        if(p.isNull() == true) {
            return nullptr;
        }
        if(p->size() <= this->v_listIndex) {
            return nullptr;
        }

        return p->list(this->v_listIndex);
}

void NoticPageWidget::resetIndex(ResetFlag f) {
    switch(f) {
        case ResetFlag::LIST:
            this->v_listIndex = 0;
            this->hideListWidgets();
            return;
        case ResetFlag::PAGE:
            this->v_pageIndex = 0;
            this->hidePageWidgets();
            return;
        default:
            this->resetIndex(ResetFlag::LIST);
            this->resetIndex(ResetFlag::PAGE);
            return;
    }

}

void NoticPageWidget::clear() {
    this->v_pages.clear();
}

void NoticPageWidget::reTranslate() {
    if(this->v_nextPageTr.isEmpty() == false) {
        this->v_nextPageText = NoticPageWidget::tr(this->v_nextPageTr.toStdString().c_str() );
        this->v_nextPageB->setText(this->v_nextPageText);
    }
    if(this->v_prevPageTr.isEmpty() == false) {
        this->v_prevPageText = NoticPageWidget::tr(this->v_prevPageTr.toStdString().c_str() );
        this->v_prevPageB->setText(this->v_prevPageText);
    }

    if(this->v_nextListTr.isEmpty() == false) {
        this->v_nextListText = NoticPageWidget::tr(this->v_nextListTr.toStdString().c_str() );
        this->v_nextListB->setText(this->v_nextListText);
    }
        if(this->v_prevListTr.isEmpty() == false) {
        this->v_prevListText = NoticPageWidget::tr(this->v_prevListTr.toStdString().c_str() );
        this->v_prevListB->setText(this->v_prevListText);
    }

    for(int i = 0; i < this->v_pages.size(); i++) {
        this->v_pages.at(i)->reTranslate();
    }

    this->setPageLabel();
}

//Protected slots
void NoticPageWidget::nextPagePressed() {
    bool up = this->canUpdatePage(1);

        if(up == true) {
            this->v_pageIndex++;
            this->resetIndex(ResetFlag::LIST);
            this->setPageLabel();
            emit this->listChanged();
        }

        if(this->v_pageH == false) {
            this->v_nextPageB->setEnabled(this->canUpdatePage(1) );
            this->v_prevPageB->setEnabled(this->canUpdatePage(-1) );
        }
}

void NoticPageWidget::prevPagePressed() {
    bool up = this->canUpdatePage(-1);

        if(up == true) {
            this->v_pageIndex--;
            this->resetIndex(ResetFlag::LIST);
            this->setPageLabel();
            emit this->listChanged();
        }

        if(this->v_pageH == false) {
            this->v_nextPageB->setEnabled(this->canUpdatePage(1) );
            this->v_prevPageB->setEnabled(this->canUpdatePage(-1) );
        }
}

void NoticPageWidget::nextListPressed() {
    bool up = this->canUpdateList(1);

        if(up == true) {
            this->v_listIndex++;
            emit this->listChanged();
        }

        if(this->v_labelH == false) {
            this->v_nextListB->setEnabled(this->canUpdateList(1) );
            this->v_prevListB->setEnabled(this->canUpdateList(-1) );
        }
}

void NoticPageWidget::prevListPressed() {
    bool up = this->canUpdateList(-1);

        if(up == true) {
            this->v_listIndex--;
            emit this->listChanged();
        }

        if(this->v_labelH == false) {
            this->v_nextListB->setEnabled(this->canUpdateList(1) );
            this->v_prevListB->setEnabled(this->canUpdateList(-1) );
        }
}

//Protected functions
void NoticPageWidget::init() {
    this->v_pageLabel = new QLabel(this->v_p);

    this->v_nextPageB = new QPushButton(this->v_nextPageText,this->v_p);
    this->v_prevPageB = new QPushButton(this->v_prevPageText,this->v_p);
    this->v_nextListB = new QPushButton(this->v_nextListText,this->v_p);
    this->v_prevListB = new QPushButton(this->v_prevListText,this->v_p);

    connect(this->v_nextPageB,SIGNAL(clicked(bool) ),this,SLOT(nextPagePressed() ) );
    connect(this->v_prevPageB,SIGNAL(clicked(bool) ),this,SLOT(prevPagePressed() ) );
    connect(this->v_nextListB,SIGNAL(clicked(bool) ),this,SLOT(nextListPressed() ) );
    connect(this->v_prevListB,SIGNAL(clicked(bool) ),this,SLOT(prevListPressed() ) );

    this->v_gLayout->addWidget(this->v_pageLabel,0,1);

    this->v_gLayout->addWidget(this->v_prevPageB,0,0);
    this->v_gLayout->addWidget(this->v_nextPageB,0,2);

    this->v_hLayout->addItem(new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Preferred) );
    this->v_hLayout->addWidget(this->v_prevListB);
    this->v_hLayout->addItem(new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Preferred) );
    this->v_hLayout->addWidget(this->v_nextListB);
    this->v_hLayout->addItem(new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Preferred) );
}

bool NoticPageWidget::canUpdatePage(int num) {
    if(this->v_pageIndex + num < 0) {
        return false;
    }
    if(this->v_pageIndex + num >= this->v_pages.size() ) {
        return false;
    }

    return true;
}

bool NoticPageWidget::canUpdateList(int num) {
    if(this->currentPage().isNull() == true) {
        return false;
    }
    if(this->v_listIndex + num < 0) {
        return false;
    }
    if(this->v_listIndex + num >= this->currentPage()->size() ) {
        return false;
    }

    return true;
}

void NoticPageWidget::hidePageWidgets() {
    if(this->v_pages.size() <= 1) {
        this->v_pageH = true;
    }
    else {
        this->v_pageH = false;
    }

    this->v_nextPageB->setHidden(this->v_pageH);
    this->v_prevPageB->setHidden(this->v_pageH);

    this->v_pageLabel->setHidden(this->v_pageH);
}

void NoticPageWidget::hideListWidgets() {
    NoticePageP c = this->currentPage();
    int size = (c.isNull() == true) ? 0 : c->size();

        if(size <= 1) {
            this->v_labelH = true;
        }
        else {
            this->v_labelH = false;
        }

        this->v_nextListB->setHidden(this->v_labelH);
        this->v_prevListB->setHidden(this->v_labelH);
}

void NoticPageWidget::setPageLabel() {
    NoticePageP p = this->currentPage();

    if(p.isNull() == true) {
        return;
    }
    if(this->v_pageH == true) {
        return;
    }

    this->v_pageLabel->setText(p->title() );

    this->v_pageLabel->setAlignment(Qt::AlignCenter);
}
