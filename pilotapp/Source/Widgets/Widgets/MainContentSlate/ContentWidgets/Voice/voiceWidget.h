#ifndef VOICE_WIDGET_H_
#define VOICE_WIDGET_H_

#include <QWidget>

class voiceWidget : public QWidget{
    Q_OBJECT

private:

public:
    voiceWidget(QWidget* parent = nullptr);
    ~voiceWidget();

};


#endif // VOICE_WIDGET_H_