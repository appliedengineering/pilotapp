#ifndef TOOLBAR_H_
#define TOOLBAR_H_

#include <QWidget>

#include <QPalette>

class toolbarWidget : public QWidget{
	Q_OBJECT

private:
	const float heightRatio = 0.14;

public:
	toolbarWidget(QWidget* parent = nullptr);
	~toolbarWidget();
};

#endif // !TOOLBAR_H_
