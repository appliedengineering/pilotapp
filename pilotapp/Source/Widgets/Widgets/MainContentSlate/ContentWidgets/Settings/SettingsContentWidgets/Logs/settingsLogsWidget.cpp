#include "settingsLogsWidget.h"

#include "../../../../../../../Backend/Utilities/utilities.h"
#include "../../../../../../../Backend/logManager.h"

#include <QFont>
#include <QFrame>
#include <deque>
#include <string>

//

settingsLogsWidget::settingsLogsWidget(QWidget* parent){
    //utilities::setPaletteColor(this, QPalette::Background, Qt::blue);
    
    setupLayout();
    setupLogs();
    renderLogs();
    renderOptions();

    connect(logManager::getInstance(), &logManager::logUpdateSignal, this, &settingsLogsWidget::renderLogs);
}

settingsLogsWidget::~settingsLogsWidget(){
    disconnect(logManager::getInstance(), &logManager::logUpdateSignal, this, &settingsLogsWidget::renderLogs);
}

//

void settingsLogsWidget::setupLayout(){
    vBoxLayout = new QVBoxLayout(this);

    vBoxLayout->setContentsMargins(0, 0, 0, 0);
    vBoxLayout->setSpacing(0);

    //

    logScrollArea = new QScrollArea(this);

    //logScrollArea->setBackgroundRole(QPalette::Dark);
    logScrollArea->setWidgetResizable(true);
    logScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    logScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    utilities::setPaletteColor(logScrollArea, QPalette::Background, Qt::black);

    vBoxLayout->addWidget(logScrollArea, logScrollAreaStretchFactor);

    //

    QFrame* dividerLine = new QFrame(this);

    dividerLine->setContentsMargins(0, 0, 0, 0);
    dividerLine->setFrameShape(QFrame::HLine);
    dividerLine->setFrameShadow(QFrame::Sunken);

    vBoxLayout->addWidget(dividerLine);

    //

    hBoxLayout = new QHBoxLayout();

    hBoxLayout->setContentsMargins(0, 0, 0, 0);
    hBoxLayout->setSpacing(10);

    vBoxLayout->addLayout(hBoxLayout, 100 - logScrollAreaStretchFactor);

}

void settingsLogsWidget::setupLogs(){
    logScrollAreaContentWidget = new QWidget(logScrollArea);
    //logScrollAreaContentWidget->setFixedWidth(logScrollArea->width());

    utilities::setPaletteColor(logScrollAreaContentWidget, QPalette::Background, Qt::black);

    logScrollArea->setWidget(logScrollAreaContentWidget);
    //logScrollAreaContentWidget->setGeometry(0, 0, 100, 100);*/

    //

    logScrollAreaContentLayout = new QVBoxLayout(logScrollAreaContentWidget);

    logScrollAreaContentWidget->setLayout(logScrollAreaContentLayout);

    logScrollAreaContentLayout->setContentsMargins(logScrollAreaContentLayoutPadding, logScrollAreaContentLayoutPadding/2, logScrollAreaContentLayoutPadding, logScrollAreaContentLayoutPadding/2);
    logScrollAreaContentLayout->setSpacing(logScrollAreaContentLayoutPadding);  

    //logScrollArea->setWidget(logScrollAreaContentLayout->widget());
}

void settingsLogsWidget::renderOptions(){

}

void settingsLogsWidget::renderLogs(){
    for (int i = 0; i < logScrollAreaContentLayout->count(); i++){
        QLayoutItem* item = logScrollAreaContentLayout->itemAt(i);
        QWidget* w = item->widget();
        if (w){
            w->hide();
            delete w;
            w = nullptr;
        }
    }

    //qDebug() << "log cache size = " << QString::number(logManager::getInstance()->getLogCache().size());

    for (auto i : logManager::getInstance()->getLogCache()){
        QLabel* logEntryLabel = new QLabel(logScrollAreaContentWidget);

        logEntryLabel->setText(QString::fromStdString(i));
        logEntryLabel->setAlignment(Qt::AlignLeft);
        logEntryLabel->setWordWrap(true);

        utilities::setPaletteColor(logEntryLabel, QPalette::Foreground, Qt::white, true);
        //utilities::setPaletteColor(logEntryLabel, QPalette::Background, Qt::white);

        QFont logEntryLabelFont = logEntryLabel->font();
        logEntryLabelFont.setPixelSize(12);
        logEntryLabel->setFont(logEntryLabelFont);

        logScrollAreaContentLayout->addWidget(logEntryLabel);
    }
}

//

void settingsLogsWidget::handleSaveButton(){

}


