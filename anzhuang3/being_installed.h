#ifndef BEING_INSTALLED_H
#define BEING_INSTALLED_H

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
#include <QTextBrowser>
#include <QPainter>
#include <QMessageBox>
#include <QProgressBar>
class Being_installed : public QWidget
{
    Q_OBJECT

public:
    explicit Being_installed(QWidget *parent = nullptr);
private:
    bool m_pressFlag;
    QPoint m_lastPos;
    QLabel* m_backImgLabel;
    QImage m_backImg;

    QWidget* m_pWidget;
    QPushButton* m_minisizeBtn;
    QPushButton* m_closeBtn;
    QProgressBar *progressBar;

    QLabel* install_doing;
private:
    void constructUI();
    void connectSlots();

private slots:
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

#endif // BEING_INSTALLED_H
