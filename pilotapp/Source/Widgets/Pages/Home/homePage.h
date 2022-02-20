#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include <QDebug>

//

#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>

//

class homePage : public QWidget
{
	Q_OBJECT

private slots:
    void handleTest();

public:
	homePage(QWidget* parent = nullptr);
	~homePage();

};
#endif // !HOMEPAGE_H
