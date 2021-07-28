#ifndef CHECK_AGREEMENT_H
#define CHECK_AGREEMENT_H

#include <QDialog>
#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QPaintEvent>
#include <QString>
#include <QList>
#include <QImage>
#include <QLineEdit>
#include "widget.h"
#include <QTextBrowser>

class Check_agreement : public QWidget
{
    Q_OBJECT
public:
    explicit Check_agreement(QWidget *parent = nullptr);
private:
    bool m_pressFlag;
    QPoint m_lastPos;
    QLabel* m_backImgLabel;
    QImage m_backImg;

    QWidget* m_pWidget;
    QCheckBox* m_readAgree;

    QLabel* m_softwareLicensing;
    QLabel* m_customInstallation ;

    QPushButton* m_minisizeBtn;
    QPushButton* m_closeBtn;
    QPushButton* m_installBtn;
    QPushButton* b_softwareLicensing;
    QPushButton* b_customInstallation;

    QTextBrowser* b_check;
private:
    void constructUI();
    void connectSlots();

private slots:
    void onInstallBtn();

    void onMinisizeBtn();
    void onCloseBtn();


protected:
    void paintEvent(QPaintEvent *);

    // 鼠标支持
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
signals:

public slots:
};

#endif // CHECK_AGREEMENT_H
