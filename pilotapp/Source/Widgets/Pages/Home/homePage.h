#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include <QDebug>

//

#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

//

class homePage : public QWidget
{
	Q_OBJECT

private slots:
    void handleTest();

private:
	QLabel* tLabel;

public:
	homePage(QWidget* parent = nullptr);
	~homePage();

};
#endif // !HOMEPAGE_H
