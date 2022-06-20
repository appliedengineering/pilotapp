#include "settingsLogsWidget.h"

#include "../../../../../../../Backend/Utilities/utilities.h"

#include <QFont>
#include <QFrame>
#include <QFile>
#include <QInputDialog>
#include <QScroller>
#include <deque>
#include <string>

//

settingsLogsWidget::settingsLogsWidget(QWidget* parent){
    //utilities::setPaletteColor(this, QPalette::Background, Qt::blue);
    
    setupLayout();
    setupLogs();
    renderTopOptions();
    renderBottomOptions();
    renderLogs();

    connect(logManager::getInstance(), &logManager::removeFrontLogEntrySignal, this, &settingsLogsWidget::removeFrontLogEntry);
    connect(logManager::getInstance(), &logManager::appendLogEntrySignal, this, &settingsLogsWidget::appendLogEntry);
}

settingsLogsWidget::~settingsLogsWidget(){
    disconnect(logManager::getInstance(), &logManager::removeFrontLogEntrySignal, this, &settingsLogsWidget::removeFrontLogEntry);
    disconnect(logManager::getInstance(), &logManager::appendLogEntrySignal, this, &settingsLogsWidget::appendLogEntry);
}

//

void settingsLogsWidget::setupLayout(){
    const int optionsWidgetsStretchFactor = (100 - logScrollAreaStretchFactor) / 2;
    
    //

    vBoxLayout = new QVBoxLayout(this);

    vBoxLayout->setContentsMargins(0, 0, 0, 0);
    vBoxLayout->setSpacing(0);

    //

    optionsTopWidget = new QWidget(this);

    vBoxLayout->addWidget(optionsTopWidget, optionsWidgetsStretchFactor);

    //

    QFrame* topDividerLine = new QFrame(this);

    topDividerLine->setContentsMargins(0, 0, 0, 0);
    topDividerLine->setFrameShape(QFrame::HLine);
    topDividerLine->setFrameShadow(QFrame::Sunken);

    vBoxLayout->addWidget(topDividerLine);

    //

    logScrollArea = new QScrollArea(this);

    //logScrollArea->setBackgroundRole(QPalette::Dark);
    logScrollArea->setWidgetResizable(true);
    logScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    logScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QScroller::grabGesture(logScrollArea, QScroller::LeftMouseButtonGesture);

    utilities::setPaletteColor(logScrollArea, QPalette::Background, Qt::black);

    vBoxLayout->addWidget(logScrollArea, logScrollAreaStretchFactor);

    //

    QFrame* bottomDividerLine = new QFrame(this);

    bottomDividerLine->setContentsMargins(0, 0, 0, 0);
    bottomDividerLine->setFrameShape(QFrame::HLine);
    bottomDividerLine->setFrameShadow(QFrame::Sunken);

    vBoxLayout->addWidget(bottomDividerLine);

    //

    optionsBottomWidget = new QWidget(this);

    vBoxLayout->addWidget(optionsBottomWidget, optionsWidgetsStretchFactor);
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

    logScrollAreaContentLayout->setContentsMargins(logScrollAreaContentLayoutPadding, logScrollAreaContentLayoutPadding/2, logScrollAreaContentLayoutPadding + logScrollAreaContentLayoutPadding/2, logScrollAreaContentLayoutPadding/2);
    logScrollAreaContentLayout->setSpacing(logScrollAreaContentLayoutPadding);  

    //logScrollArea->setWidget(logScrollAreaContentLayout->widget());
}

void settingsLogsWidget::renderLogs(){
    while (logScrollAreaContentLayout->count() > 0){
        QLayoutItem* w = logScrollAreaContentLayout->takeAt(0);
        delete w->widget();
        delete w;
    }

    //qDebug() << "log cache size = " << QString::number(logManager::getInstance()->getLogCache().size());

    for (std::string i : logManager::getInstance()->getLogCache())
        if (isLogEntryTypeEnabled(i))
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

void settingsLogsWidget::renderTopOptions(){

    optionsTopLayout = new QHBoxLayout(optionsTopWidget);

    optionsTopLayout->setContentsMargins(optionsLayoutHoriziontalPadding, optionsLayoutHoriziontalPadding/2, optionsLayoutHoriziontalPadding, optionsLayoutHoriziontalPadding/2);
    optionsTopLayout->setSpacing(optionsLayoutHoriziontalPadding);

    //

    stopCheckBox = new QCheckBox(optionsTopWidget);

    stopCheckBox->setText("Stop");

    utilities::setPaletteColor(stopCheckBox, QPalette::WindowText, Qt::white, true);

    QFont stopCheckBoxFont = stopCheckBox->font();
    stopCheckBoxFont.setPixelSize(optionsTopWidgetFontSize);
    stopCheckBox->setFont(stopCheckBoxFont);

    connect(stopCheckBox, &QCheckBox::clicked, this, [=] { handleStopCheckBox(stopCheckBox->isChecked()); });

    optionsTopLayout->addWidget(stopCheckBox);

    //

    /*bufferSizeLineEdit = new QLineEdit(optionsTopWidget);

    bufferSizeLineEdit->setText(QString::number(logManager::getInstance()->getMaxLogSize()));
    bufferSizeLineEdit->setAlignment(Qt::AlignHCenter);

    QFont bufferSizeLineEditFont = bufferSizeLineEdit->font();
    bufferSizeLineEditFont.setPixelSize(optionsTopWidgetFontSize);
    bufferSizeLineEdit->setFont(bufferSizeLineEditFont);

    optionsTopLayout->addWidget(bufferSizeLineEdit);*/

    //

    /*bufferSizeLabel = new QLabel(optionsTopWidget);

    bufferSizeLabel->setText("Buffer Size");
    utilities::setPaletteColor(bufferSizeLabel, QPalette::Foreground, Qt::white, true);

    QFont bufferSizeLabelFont = bufferSizeLabel->font();
    bufferSizeLabelFont.setPixelSize(optionsTopWidgetFontSize);
    bufferSizeLabel->setFont(bufferSizeLabelFont);

    optionsTopLayout->addWidget(bufferSizeLabel);*/

    bufferSizeButton = new QPushButton(optionsTopWidget);

    bufferSizeButton->setText("Buffer Size");

    utilities::setPaletteColor(bufferSizeButton, QPalette::Background, Qt::gray);
    utilities::setPaletteColor(bufferSizeButton, QPalette::ButtonText, Qt::white);

    QFont bufferSizeButtonFont = bufferSizeButton->font();
    bufferSizeButtonFont.setPixelSize(optionsTopWidgetFontSize);
    bufferSizeButton->setFont(bufferSizeButtonFont);

    connect(bufferSizeButton, &QPushButton::released, this, &settingsLogsWidget::handleBufferSizeButton);

    optionsTopLayout->addWidget(bufferSizeButton);

    //

    QFrame* dividerLine = new QFrame(optionsTopWidget);

    dividerLine->setContentsMargins(0, 0, 0, 0);
    dividerLine->setFrameShape(QFrame::VLine);
    dividerLine->setFrameShadow(QFrame::Sunken);

    optionsTopLayout->addWidget(dividerLine);

    //

    saveOptionCheckBox = new QCheckBox(optionsTopWidget);

    saveOptionCheckBox->setText("Replace File");
    
    utilities::setPaletteColor(saveOptionCheckBox, QPalette::WindowText, Qt::white, true);

    QFont saveOptionCheckBoxFont = saveOptionCheckBox->font();
    saveOptionCheckBoxFont.setPixelSize(optionsTopWidgetFontSize);
    saveOptionCheckBox->setFont(saveOptionCheckBoxFont);

    optionsTopLayout->addWidget(saveOptionCheckBox);

    //

    saveButton = new QPushButton(optionsTopWidget);

    saveButton->setText("Save");

    utilities::setPaletteColor(saveButton, QPalette::Background, Qt::gray);
    utilities::setPaletteColor(saveButton, QPalette::ButtonText, Qt::white);

    QFont saveButtonFont = saveButton->font();
    saveButtonFont.setPixelSize(optionsTopWidgetFontSize);
    saveButton->setFont(saveButtonFont);

    connect(saveButton, &QPushButton::released, this, &settingsLogsWidget::handleSaveButton);

    optionsTopLayout->addWidget(saveButton);
}

void settingsLogsWidget::renderBottomOptions(){
    //

    optionsBottomLayout = new QHBoxLayout(optionsBottomWidget);

    optionsBottomLayout->setContentsMargins(optionsLayoutHoriziontalPadding, optionsLayoutHoriziontalPadding/2, optionsLayoutHoriziontalPadding, optionsLayoutHoriziontalPadding/2);
    optionsBottomLayout->setSpacing(optionsLayoutHoriziontalPadding);

    //

    infoCheckBox = new QCheckBox(optionsBottomWidget);
    filterCheckBoxes[0] = infoCheckBox;

    infoCheckBox->setText("Info");
    infoCheckBox->setChecked(logManager::getInstance()->getIsLogTypeEnabled(logManager::logType::info));

    utilities::setPaletteColor(infoCheckBox, QPalette::WindowText, Qt::white, true);

    QFont infoCheckBoxFont = infoCheckBox->font();
    infoCheckBoxFont.setPixelSize(optionsCheckBoxFontSize);
    infoCheckBox->setFont(infoCheckBoxFont);

    connect(infoCheckBox, &QCheckBox::clicked, this, [=] { handleFilterCheckBoxes(logManager::logType::info); });

    optionsBottomLayout->addWidget(infoCheckBox);

    //

    debugCheckBox = new QCheckBox(optionsBottomWidget);
    filterCheckBoxes[1] = debugCheckBox;

    debugCheckBox->setText("Debug");
    debugCheckBox->setChecked(logManager::getInstance()->getIsLogTypeEnabled(logManager::logType::debug));

    utilities::setPaletteColor(debugCheckBox, QPalette::WindowText, Qt::white, true);

    QFont debugCheckBoxFont = debugCheckBox->font();
    debugCheckBoxFont.setPixelSize(optionsCheckBoxFontSize);
    debugCheckBox->setFont(debugCheckBoxFont);

    connect(debugCheckBox, &QCheckBox::clicked, this, [=] { handleFilterCheckBoxes(logManager::logType::debug); });

    optionsBottomLayout->addWidget(debugCheckBox);

    //

    errorCheckBox = new QCheckBox(optionsBottomWidget);
    filterCheckBoxes[2] = errorCheckBox;

    errorCheckBox->setText("Error");
    errorCheckBox->setChecked(logManager::getInstance()->getIsLogTypeEnabled(logManager::logType::errors));

    utilities::setPaletteColor(errorCheckBox, QPalette::WindowText, Qt::white, true);

    QFont errorCheckBoxFont = errorCheckBox->font();
    errorCheckBoxFont.setPixelSize(optionsCheckBoxFontSize);
    errorCheckBox->setFont(errorCheckBoxFont);

    connect(errorCheckBox, &QCheckBox::clicked, this, [=] { handleFilterCheckBoxes(logManager::logType::errors); });

    optionsBottomLayout->addWidget(errorCheckBox);

    //

    telemetryCheckBox = new QCheckBox(optionsBottomWidget);
    filterCheckBoxes[3] = telemetryCheckBox;

    telemetryCheckBox->setText("Tmtry");
    telemetryCheckBox->setChecked(logManager::getInstance()->getIsLogTypeEnabled(logManager::logType::telemetry));

    utilities::setPaletteColor(telemetryCheckBox, QPalette::WindowText, Qt::white, true);

    QFont telemetryCheckBoxFont = telemetryCheckBox->font();
    telemetryCheckBoxFont.setPixelSize(optionsCheckBoxFontSize);
    telemetryCheckBox->setFont(telemetryCheckBoxFont);

    connect(telemetryCheckBox, &QCheckBox::clicked, this, [=] { handleFilterCheckBoxes(logManager::logType::telemetry); });

    optionsBottomLayout->addWidget(telemetryCheckBox);

    //

    QFrame* dividerLine = new QFrame(optionsBottomWidget);

    dividerLine->setContentsMargins(0, 0, 0, 0);
    dividerLine->setFrameShape(QFrame::VLine);
    dividerLine->setFrameShadow(QFrame::Sunken);

    optionsBottomLayout->addWidget(dividerLine);

    //

    clearLogsButton = new QPushButton(optionsBottomWidget);

    clearLogsButton->setText("Clear");

    utilities::setPaletteColor(clearLogsButton, QPalette::Background, Qt::gray);
    utilities::setPaletteColor(clearLogsButton, QPalette::ButtonText, Qt::white);

    QFont clearLogsButtonFont = clearLogsButton->font();
    clearLogsButtonFont.setPixelSize(optionsTopWidgetFontSize);
    clearLogsButton->setFont(clearLogsButtonFont);

    connect(clearLogsButton, &QPushButton::released, this, &settingsLogsWidget::handleClearButton);

    optionsBottomLayout->addWidget(clearLogsButton);
}

//

void settingsLogsWidget::handleStopCheckBox(bool shouldStop){
    //qInfo() << "should stop = " << (shouldStop ? "y" : "n");
    shouldStopLogs = shouldStop;
    if (!shouldStopLogs)
        renderLogs();
}

void settingsLogsWidget::handleSaveButton(){
    logManager::getInstance()->saveToLogFile(saveOptionCheckBox->isChecked());
    
    utilities::createStatusDialogBox("Saved Logs")->exec();
}

void settingsLogsWidget::handleFilterCheckBoxes(logManager::logType t){
    //logManager::i(std::to_string(static_cast<int>(t)) + " = " + (filterCheckBoxes[static_cast<int>(t)]->isChecked() ? "true" : "false"));
    logManager::getInstance()->setLogTypeEnabled(t, filterCheckBoxes[static_cast<int>(t)]->isChecked());
    renderLogs(); // rerender logs
}

void settingsLogsWidget::handleClearButton(){
    logManager::getInstance()->clearLogs();
    renderLogs();
}

void settingsLogsWidget::handleBufferSizeButton(){
    QInputDialog b;
    b.setLabelText("Buffer Size");

    QFont bFont = b.font();
    bFont.setPixelSize(12);
    b.setFont(bFont);

    b.setIntMinimum(1);
    b.setIntMaximum(500);
    b.setIntStep(10);
    b.setIntValue(logManager::getInstance()->getMaxLogSize());

    //connect(b, &QInputDialog::);
    
    if (b.exec())
        logManager::getInstance()->setMaxLogSize(b.intValue());
}

//

bool settingsLogsWidget::isLogEntryTypeEnabled(const std::string& entry){
    if (!entry.size()){ // invalid log..?
        logManager::e("Invalid log entry detected");
        return false;
    }
    
    logManager::logType type;

    switch (entry[0]){
    case 'I': 
        type = logManager::logType::info;
        break;
    
    case 'D':
        type = logManager::logType::debug;
        break;

    case 'E':
        type = logManager::logType::errors;
        break;

    case 'T':
        type = logManager::logType::telemetry;
        break;

    default:
        logManager::e("Invalid log entry type = " + entry[0]);
        type = logManager::logType::info;
        break;
    }

    return logManager::getInstance()->getIsLogTypeEnabled(type);
}

//

void settingsLogsWidget::removeFrontLogEntry(){
    if (!shouldStopLogs &&  logScrollAreaContentLayout->count() > 0){
        QLayoutItem* i = logScrollAreaContentLayout->takeAt(0);
        delete i->widget();
        delete i;
    }
}

void settingsLogsWidget::appendLogEntry(){
    std::string entry = logManager::getInstance()->getLogCache().back();
    if (!shouldStopLogs && isLogEntryTypeEnabled(entry)){
        logScrollAreaContentLayout->addWidget(renderLogEntry(entry));
        logScrollAreaContentLayout->update();
    }
}

