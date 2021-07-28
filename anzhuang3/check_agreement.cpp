#include "check_agreement.h"
#include <QPainter>
Check_agreement::Check_agreement(QWidget *parent) : QWidget(parent)
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
void Check_agreement::constructUI()
{
    m_backImgLabel = new QLabel(this);
    m_readAgree = new QCheckBox(this);
    m_minisizeBtn = new QPushButton(this);;
    m_closeBtn = new QPushButton(this);;
    m_installBtn = new QPushButton(this);
    b_softwareLicensing = new QPushButton(this);
    //b_customInstallation = new QPushButton(this);
    b_check = new QTextBrowser(this);

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

    b_check->move(40,100);
    b_check->resize(520,260);
    b_check->setStyleSheet("QTextBrowser{border-width:0;border-style:outset}");
    b_check->setText("<h1><font color = blue><center>软件许可及服务协议</center></font>"
                     "<h2>首部及导言</h2> "
                     "<p>欢迎你使用密盾微云软件及服务</p>"
                     "<h4>为使用密盾微云软件（以下简称“本软件”）"
                     "应届毕业生是乐鑫未来发展的主动力,我们期待有好奇心、有想法、有创"
                     "应届毕业生是乐鑫未来发展的主动力,我们期待有好奇心、有想法、有创"
                     "应届毕业生是乐鑫未来发展的主动力,我们期待有好奇心、有想法、有创<br>"
                     "应届毕业生是乐鑫未来发展的主动力,我们期待有好奇心、有想法、有创"
                     "应届毕业生是乐鑫未来发展的主动力,我们期待有好奇心、有想法、有创");



    QString btnStyle1 = "\
        QPushButton{\
            color: rgb(38, 133, 227);\
            border:1px;\
        }\
        QPushButton:hover{\
            color: rgb(97, 179, 246);\
        }\
        QPushButton:pressed{\
            color: rgb(38, 133, 227);\
        }";


    m_readAgree->setText("我已阅读并同意密盾微云");
    m_readAgree->move(20, 390);

    b_softwareLicensing->move(170, 389);
    b_softwareLicensing->resize(130, 20);
    b_softwareLicensing->setText("《软件许可及服务协议》");
    b_softwareLicensing->setStyleSheet("QPushButton{color:black; background-color:transparent;}");
    b_softwareLicensing->setCursor(QCursor(Qt::PointingHandCursor));

    QString btnStyle2 =
        "QPushButton{\
            color: rgb(255, 255, 255);\
            background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(0, 34, 238), stop:0.3 rgb(0, 34, 238), stop:1 rgb(0, 34, 238));\
            border:1px;\
            border-radius:15px; /*border-radius控制圆角大小*/\
            padding:2px 4px;  \
        }\
        QPushButton:hover{\
            color: rgb(255, 255, 255); \
            background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(130,120,226), stop:0.3 rgb(120,130,230), stop:1 rgb(125,140,226));\
            border:1px;  \
            border-radius:15px; /*border-radius控制圆角大小*/\
            padding:2px 4px; \
        }\
        QPushButton:pressed{    \
            color: rgb(255, 255, 255); \
            background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(240,156,121), stop:0.3 rgb(220,160,140), stop:1 rgb(230,140,120));  \
            border:1px;  \
            border-radius:15px; /*border-radius控制圆角大小*/\
            padding:2px 4px; \
        }";
    m_installBtn->setStyleSheet(btnStyle2);


    m_installBtn->setText("返回");
    m_installBtn->resize(70, 30);
    m_installBtn->move(500, 380);

}


void Check_agreement::connectSlots()
{

    connect(m_installBtn, SIGNAL(clicked(bool)), this, SLOT(onInstallBtn()));
    connect(m_minisizeBtn, SIGNAL(clicked(bool)), this, SLOT(onMinisizeBtn()));
    connect(m_closeBtn, SIGNAL(clicked(bool)), this, SLOT(onCloseBtn()));
    //connect(b_softwareLicensing, SIGNAL(clicked(bool)), this, SLOT(onSoftwareLicensingBtn()));
   // connect(b_customInstallation, SIGNAL(clicked(bool)), this, SLOT(onCustomInstallationBtn()));
}


void Check_agreement::onInstallBtn()
{
    // 关闭当前界面
        Widget * pic = new Widget();
        this->close();
        pic->show();

}

//void Check_agreement::onCustomInstallationBtn()
//{
//    Widget * pic = new Widget();
//    this->close();
//    pic->show();


//}
void Check_agreement::onMinisizeBtn()
{
    this->showMinimized();
}

void Check_agreement::onCloseBtn()
{

    QMessageBox::StandardButton btn;
    btn = QMessageBox::question(this, "提示", "是否要取消安装?", QMessageBox::Yes|QMessageBox::No);
    if (btn == QMessageBox::Yes) {
         this->close();
    }
}

void Check_agreement::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(m_backImgLabel->x(), m_backImgLabel->y(), m_backImgLabel->width(),
        m_backImgLabel->height(), QPixmap::fromImage(m_backImg));


    painter.setRenderHint(QPainter::Antialiasing, true);    // 让图像边缘显示平滑
//    QPainterPath path;
//    path.addEllipse(m_headLogo->x(), m_headLogo->y(),
//                    m_headLogo->width(), m_headLogo->height());

//    painter.setClipPath(path);

//    painter.drawPixmap(m_headLogo->x(), m_headLogo->y(), m_headLogo->width(),
//        m_headLogo->height(), QPixmap::fromImage(m_headImg));
//    painter.setRenderHint(QPainter::Antialiasing, false);
}


void Check_agreement::mouseMoveEvent(QMouseEvent *event)
{
    if (m_pressFlag) {
        QPoint pos = event->globalPos();
        move(this->pos() + pos - m_lastPos);
        m_lastPos = pos;
    }

    event->ignore();//表示继续向下传递事件，其他的控件还可以去获取
}

void Check_agreement::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_pressFlag = true;
        m_lastPos = event->globalPos();
    }

    event->ignore();
}


void Check_agreement::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_pressFlag = false;
    }

    event->ignore();
}
