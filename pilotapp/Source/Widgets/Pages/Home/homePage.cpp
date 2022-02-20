#include "homePage.h"

#include "../../../MainWindow.h"
#include "../../../Utilities/utilities.h"

homePage::homePage(QWidget* parent) {

    QHBoxLayout* hBox = new QHBoxLayout(this);

    //

    QPushButton* t = new QPushButton(this);
    t->setText("Test 1");

    hBox->addWidget(t);

    connect(t, &QPushButton::released, this, &homePage::handleTest);

    //

    QPushButton* exit = new QPushButton(this);
    exit->setText("Exit");

    hBox->addWidget(exit);

    connect(exit, &QPushButton::released, utilities::findMainWindow(), &MainWindow::handleExit);

    //

}

homePage::~homePage() {

}

//

void homePage::handleTest() {
    qInfo() << "test";
}