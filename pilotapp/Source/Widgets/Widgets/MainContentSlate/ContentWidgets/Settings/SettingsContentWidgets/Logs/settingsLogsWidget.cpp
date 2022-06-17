#include "settingsLogsWidget.h"

#include "../../../../../../../Backend/Utilities/utilities.h"
#include "../../../../../../../Backend/logManager.h"

#include <QFont>
#include <deque>
#include <string>

//

settingsLogsWidget::settingsLogsWidget(QWidget* parent){
    //utilities::setPaletteColor(this, QPalette::Background, Qt::blue);
    
    setupLayout();
    setupLogs();
    renderLogs();
    renderOptions();
}

settingsLogsWidget::~settingsLogsWidget(){
}

//

void settingsLogsWidget::setupLayout(){
    vBoxLayout = new QVBoxLayout(this);

    vBoxLayout->setContentsMargins(0, 0, 0, 0);
    vBoxLayout->setSpacing(0);

    //

    logScrollArea = new QScrollArea(this);

    logScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    utilities::setPaletteColor(logScrollArea, QPalette::Background, Qt::black);

    vBoxLayout->addWidget(logScrollArea, logScrollAreaStretchFactor);

    //

    hBoxLayout = new QHBoxLayout();

    hBoxLayout->setContentsMargins(0, 0, 0, 0);
    hBoxLayout->setSpacing(10);

    vBoxLayout->addLayout(hBoxLayout, 100 - logScrollAreaStretchFactor);

}

void settingsLogsWidget::setupLogs(){
    logScrollAreaContentWidget = new QWidget(this);

    utilities::setPaletteColor(logScrollAreaContentWidget, QPalette::Background, Qt::black);

    logScrollArea->setWidget(logScrollAreaContentWidget);

    //

    logScrollAreaContentLayout = new QVBoxLayout(logScrollAreaContentWidget);

    logScrollAreaContentLayout->setContentsMargins(0, 0, 0, 0);
    logScrollAreaContentLayout->setSpacing(20);    
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

    qDebug() << "log cache size = " << QString::number(logManager::getInstance()->getLogCache().size());

    for (auto i : logManager::getInstance()->getLogCache()){
        QLabel* logEntryLabel = new QLabel(this);

        logEntryLabel->setText(QString::fromStdString(i));
        logEntryLabel->setAlignment(Qt::AlignLeft);

        utilities::setPaletteColor(logEntryLabel, QPalette::Foreground, Qt::white, true);

        QFont logEntryLabelFont = logEntryLabel->font();
        logEntryLabelFont.setPixelSize(12);
        logEntryLabel->setFont(logEntryLabelFont);

        logScrollAreaContentLayout->addWidget(logEntryLabel);
    }
}

void settingsLogsWidget::renderOptions(){

}

//

void settingsLogsWidget::handleSaveButton(){

}