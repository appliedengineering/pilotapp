#include "homePage.h"

#include "../../../MainWindow.h"
#include "../../../Backend/Utilities/utilities.h"

homePage::homePage(QWidget* parent) {
    this->setFixedSize(utilities::findMainWindow()->size());

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

leftContentSlateWidget* homePage::getLeftContentSlateWidget(){
    return leftContentSlate;
}

mainContentSlateWidget* homePage::getMainContentSlateWidget(){
    return mainContentSlate;
}

toolbarWidget* homePage::getToolbarWidget(){
    return toolbar;
}
