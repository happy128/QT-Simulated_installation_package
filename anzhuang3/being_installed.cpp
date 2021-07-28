#include "being_installed.h"

Being_installed::Being_installed(QWidget *parent) : QWidget(parent)
{
    m_pressFlag = false;

    setWindowIcon(QIcon(":/img/softwareIcon0.png"));



    m_pWidget = new QWidget(this);
    m_pWidget->setGeometry(0, 200, 600, 420);
    m_pWidget->setStyleSheet("background-color:white;");
    m_pWidget->show();


    constructUI();
    connectSlots();
    m_backImg.load(":/img/backImg.JPG");
}
void Being_installed::constructUI()
{
    m_backImgLabel = new QLabel(this);
    m_minisizeBtn = new QPushButton(this);
    m_closeBtn = new QPushButton(this);
    progressBar = new QProgressBar(this);
    install_doing = new QLabel(this);

    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    //setStyleSheet("border-radius:5px");

    resize(600, 420);
    setFixedSize(width(), height());

    m_backImgLabel->resize(width(), 140);
    m_backImgLabel->move(0, 0);

    m_minisizeBtn->setFixedSize(24, 24);
    m_minisizeBtn->move(this->width()-48, 0);
    QString minisizeBtnStyle = "\
        QPushButton{\
            border-image:url(:/img/minisize.png);\
        }\
        QPushButton:hover{\
            border-image:url(:/img/minisizeHover.png);\
        }\
        QPushButton:pressed{\
            border-image:url(:/img/minisizePressed.png);\
        }";
    m_minisizeBtn->setStyleSheet(minisizeBtnStyle);

    m_closeBtn->setFixedSize(24, 24);
    m_closeBtn->move(this->width()-24, 0);
    QString closeBtnStyle = "\
        QPushButton{\
            border-image:url(:/img/close.png);\
        }\
        QPushButton:hover{\
            border-image:url(:/img/closeHover.png);\
        }\
        QPushButton:pressed{\
            border-image:url(:/img/closePressed.png);\
        }";
    m_closeBtn->setStyleSheet(closeBtnStyle);

    progressBar->move(50,320);
    progressBar->resize(500,20);

    install_doing->move(50,360);
    install_doing->setText("正在安装...");
}


void Being_installed::connectSlots()
{

    connect(m_minisizeBtn, SIGNAL(clicked(bool)), this, SLOT(onMinisizeBtn()));
    connect(m_closeBtn, SIGNAL(clicked(bool)), this, SLOT(onCloseBtn()));

}


void Being_installed::onMinisizeBtn()
{
    this->showMinimized();
}

void Being_installed::onCloseBtn()
{

    QMessageBox::StandardButton btn;
    btn = QMessageBox::question(this, "提示", "是否要取消安装?", QMessageBox::Yes|QMessageBox::No);
    if (btn == QMessageBox::Yes) {
         this->close();
    }
}

void Being_installed::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(m_backImgLabel->x(), m_backImgLabel->y(), m_backImgLabel->width(),
        m_backImgLabel->height(), QPixmap::fromImage(m_backImg));


    painter.setRenderHint(QPainter::Antialiasing, true);    // 让图像边缘显示平滑
}


void Being_installed::mouseMoveEvent(QMouseEvent *event)
{
    if (m_pressFlag) {
        QPoint pos = event->globalPos();
        move(this->pos() + pos - m_lastPos);
        m_lastPos = pos;
    }

    event->ignore();//表示继续向下传递事件，其他的控件还可以去获取
}

void Being_installed::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_pressFlag = true;
        m_lastPos = event->globalPos();
    }

    event->ignore();
}


void Being_installed::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_pressFlag = false;
    }

    event->ignore();
}
