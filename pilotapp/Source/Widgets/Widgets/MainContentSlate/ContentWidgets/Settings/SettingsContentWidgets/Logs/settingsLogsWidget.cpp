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

    connect(logManager::getInstance(), &logManager::removeFrontLogEntrySignal, this, &settingsLogsWidget::removeFrontLogEntry);
    connect(logManager::getInstance(), &logManager::appendLogEntrySignal, this, &settingsLogsWidget::appendLogEntry);
}

settingsLogsWidget::~settingsLogsWidget(){
    disconnect(logManager::getInstance(), &logManager::removeFrontLogEntrySignal, this, &settingsLogsWidget::removeFrontLogEntry);
    disconnect(logManager::getInstance(), &logManager::appendLogEntrySignal, this, &settingsLogsWidget::appendLogEntry);
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

    optionsWidget = new QWidget(this);

    vBoxLayout->addWidget(optionsWidget, 100 - logScrollAreaStretchFactor);
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

void settingsLogsWidget::renderLogs(){
    for (int i = 0; i < logScrollAreaContentLayout->count(); i++){
        QLayoutItem* w = logScrollAreaContentLayout->takeAt(i);
        delete w->widget();
        delete w;
    }

    //qDebug() << "log cache size = " << QString::number(logManager::getInstance()->getLogCache().size());

    for (auto i : logManager::getInstance()->getLogCache())
        logScrollAreaContentLayout->addWidget(renderLogEntry(i));
}

QLabel* settingsLogsWidget::renderLogEntry(std::string entry){
    QLabel* logEntryLabel = new QLabel(logScrollAreaContentWidget);

    logEntryLabel->setText(QString::fromStdString(entry));
    logEntryLabel->setAlignment(Qt::AlignLeft);
    logEntryLabel->setWordWrap(true);

    utilities::setPaletteColor(logEntryLabel, QPalette::Foreground, Qt::white, true);
        //utilities::setPaletteColor(logEntryLabel, QPalette::Background, Qt::white);

    QFont logEntryLabelFont = logEntryLabel->font();
    logEntryLabelFont.setPixelSize(12);
    logEntryLabel->setFont(logEntryLabelFont);

    return logEntryLabel;
}

void settingsLogsWidget::renderOptions(){
    
    optionsLayout = new QHBoxLayout(optionsWidget);

    optionsLayout->setContentsMargins(optionsLayoutHoriziontalPadding, 0, optionsLayoutHoriziontalPadding, 0);
    optionsLayout->setSpacing(optionsLayoutHoriziontalPadding);

    //

    stopCheckBox = new QCheckBox(optionsWidget);

    stopCheckBox->setText("Stop");

    QFont stopCheckBoxFont = stopCheckBox->font();
    stopCheckBoxFont.setPixelSize(optionsCheckBoxFontSize);
    stopCheckBox->setFont(stopCheckBoxFont);

    optionsLayout->addWidget(stopCheckBox);

    //

    infoCheckBox = new QCheckBox(optionsWidget);

    infoCheckBox->setText("Info");

    QFont infoCheckBoxFont = infoCheckBox->font();
    infoCheckBoxFont.setPixelSize(optionsCheckBoxFontSize);
    infoCheckBox->setFont(infoCheckBoxFont);

    optionsLayout->addWidget(infoCheckBox);

    //

    debugCheckBox = new QCheckBox(optionsWidget);

    debugCheckBox->setText("Debug");

    QFont debugCheckBoxFont = debugCheckBox->font();
    debugCheckBoxFont.setPixelSize(optionsCheckBoxFontSize);
    debugCheckBox->setFont(debugCheckBoxFont);

    optionsLayout->addWidget(debugCheckBox);

    //

    errorCheckBox = new QCheckBox(optionsWidget);

    errorCheckBox->setText("Error");

    QFont errorCheckBoxFont = errorCheckBox->font();
    errorCheckBoxFont.setPixelSize(optionsCheckBoxFontSize);
    errorCheckBox->setFont(errorCheckBoxFont);

    optionsLayout->addWidget(errorCheckBox);

    //

    telemetryCheckBox = new QCheckBox(optionsWidget);
    
    telemetryCheckBox->setText("Tmtry");

    QFont telemetryCheckBoxFont = telemetryCheckBox->font();
    telemetryCheckBoxFont.setPixelSize(optionsCheckBoxFontSize);
    telemetryCheckBox->setFont(telemetryCheckBoxFont);

    optionsLayout->addWidget(telemetryCheckBox);

    //

    saveOptionCheckBox = new QCheckBox(optionsWidget);

    saveOptionCheckBox->setText("Replace File");
    
    QFont saveOptionCheckBoxFont = saveOptionCheckBox->font();
    saveOptionCheckBoxFont.setPixelSize(optionsCheckBoxFontSize);
    saveOptionCheckBox->setFont(saveOptionCheckBoxFont);

    optionsLayout->addWidget(saveOptionCheckBox);

    //

    saveButton = new QPushButton(optionsWidget);

    saveButton->setText("Save");

    utilities::setPaletteColor(saveButton, QPalette::Background, Qt::gray);
    utilities::setPaletteColor(saveButton, QPalette::ButtonText, Qt::white);

    QFont saveButtonFont = saveButton->font();
    saveButtonFont.setPixelSize(12);
    saveButton->setFont(saveButtonFont);

    optionsLayout->addWidget(saveButton);

}

//

void settingsLogsWidget::handleSaveButton(){

}

//

void settingsLogsWidget::removeFrontLogEntry(){
    if (logScrollAreaContentLayout->count() > 0){
        QLayoutItem* i = logScrollAreaContentLayout->takeAt(0);
        delete i->widget();
        delete i;
    }
}

void settingsLogsWidget::appendLogEntry(){
    logScrollAreaContentLayout->addWidget(renderLogEntry(logManager::getInstance()->getLogCache().back()));
    logScrollAreaContentLayout->update();
}

