#ifndef VOICE_WIDGET_H_
#define VOICE_WIDGET_H_

#include <QWidget>
#include "../../contentWidget.h"

class voiceWidget : public ContentWidget{
    Q_OBJECT

private:

public:
    voiceWidget(QWidget* parent = nullptr);
    ~voiceWidget();

};


#endif // VOICE_WIDGET_H_