#include "homePage.h"

#include "../../../MainWindow.h"
#include "../../../Utilities/utilities.h"

homePage::homePage(QWidget* parent) {
    setupLayout();
}

homePage::~homePage() {

}

//

void homePage::setupLayout() {
    
    vBox = new QVBoxLayout(this);

    vBox->setContentsMargins(0,0,0,0);
    vBox->setSpacing(0);

    /// 

    topContentHBox = new QHBoxLayout();
    topContentHBox->setContentsMargins(0,0,0,0);
    topContentHBox->setSpacing(0);

    vBox->addLayout(topContentHBox);

    //

    leftContentSlate = new leftContentSlateWidget(this);

    topContentHBox->addWidget(leftContentSlate);


    mainContentSlate = new mainContentSlateWidget(this);

    topContentHBox->addWidget(mainContentSlate);

    ///

    toolbar = new toolbarWidget(this);

    vBox->addWidget(toolbar);

    ///

}

