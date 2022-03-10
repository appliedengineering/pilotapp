#ifndef LEFT_CONTENT_SLATE_H_
#define LEFT_CONTENT_SLATE_H_

#include <QWidget>

#include <QPalette>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFrame>

class leftContentSlateWidget : public QWidget {
	Q_OBJECT

private:
	QVBoxLayout* mainVBoxLayout;

	QFrame* dividerLine;
	
	//
	QWidget* topContent;
	QVBoxLayout* topContentVBoxLayout;
	QLabel* speedometerLabel;
	//

	QWidget* bottomContent;


	void setupLayout();
	
	void renderTopContent();
	void renderBottomContent();

public:
	static const float widthRatio; // 0.45

	leftContentSlateWidget(QWidget* parent = nullptr);
	~leftContentSlateWidget();

};

#endif // !LEFT_CONTENT_SLATE_H_
