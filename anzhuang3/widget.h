#ifndef WIDGET_H
#define WIDGET_H
#include "custom_installation.h"
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
#include <QMessageBox>
#include <QApplication>
#include "check_agreement.h"
#include "being_installed.h"
class Widget : public QWidget
{
    Q_OBJECT
private:
    bool m_pressFlag;
    QPoint m_lastPos;
    QLabel* m_backImgLabel;
    QImage m_backImg;

    QWidget* m_pWidget;
    QCheckBox* m_autoLogin;
    QCheckBox* m_readAgree;

    QLabel* m_softwareLicensing;
    QLabel* m_customInstallation ;

    QPushButton* m_minisizeBtn;
    QPushButton* m_closeBtn;
    QPushButton* m_installBtn;
    QPushButton* b_softwareLicensing;
    QPushButton* b_customInstallation;

private:
    void constructUI();
    void connectSlots();

private slots:
    void onInstallBtn();

    void onMinisizeBtn();
    void onCloseBtn();
    void onSoftwareLicensingBtn();
    void onCustomInstallationBtn();


protected:
    void paintEvent(QPaintEvent *);

    // 鼠标支持
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
