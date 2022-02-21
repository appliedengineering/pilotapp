#include "homePage.h"

#include "../../../MainWindow.h"
#include "../../../Utilities/utilities.h"

homePage::homePage(QWidget* parent) {

    QVBoxLayout* vBox = new QVBoxLayout(this);

    //

    QHBoxLayout* hBox = new QHBoxLayout();

    ///

    QPushButton* t = new QPushButton(this);
    t->setText("Test 1");

    hBox->addWidget(t);

    connect(t, &QPushButton::released, this, &homePage::handleTest);

    //

    QPushButton* exit = new QPushButton(this);
    exit->setText("Exit");

    hBox->addWidget(exit);

    connect(exit, &QPushButton::released, utilities::findMainWindow(), &MainWindow::closeApplication);

    ///

    tLabel = new QLabel(this);
    tLabel->setText("Before");

    utilities::changeFontSize(tLabel, 50);

    vBox->addWidget(tLabel);

    //

    vBox->addLayout(hBox);

}

homePage::~homePage() {

}

//

void homePage::handleTest() {
    //qInfo() << "test";
    tLabel->setText("Success press");
}