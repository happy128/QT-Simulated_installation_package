#ifndef CUSTOM_INSTALLATION_H
#define CUSTOM_INSTALLATION_H

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
#include "being_installed.h"

class custom_installation : public QWidget
{
    Q_OBJECT
public:
    explicit custom_installation(QWidget *parent = nullptr);

private:
    bool m_pressFlag;
    QPoint m_lastPos;
    QLabel* m_backImgLabel;
    QImage m_backImg;

    QLineEdit* e_install;
    QLabel* install_location;
    QPushButton* m_browse;

    QWidget* m_pWidget;
    QCheckBox* m_readAgree;

    QPushButton* m_minisizeBtn;
    QPushButton* m_closeBtn;
    QPushButton* m_installBtn;
    QPushButton* b_softwareLicensing;
    QPushButton* b_customInstallation;


private:
    void constructUI();
    void connectSlots();

private slots :
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

signals:

public slots:
};

#endif // CUSTOM_INSTALLATION_H
