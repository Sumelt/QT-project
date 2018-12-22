#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QWidget>

int main(int argc, char *argv[])

{

    QApplication a(argc, argv);
    QWidget *window = new QWidget;

    window->setWindowTitle("Enter Your Age");  //设置窗口的标题
    window->resize(300, 100);
    QSpinBox *spinbox = new QSpinBox;  //生成微调框
    QSlider *slider = new QSlider(Qt::Horizontal);  //生成滑动块

    spinbox->setRange(0,111); //设置范围
    slider->setRange(0,111);//设置范围

    QObject::connect(spinbox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
    QObject::connect(slider, SIGNAL(valueChanged(int)), spinbox, SLOT(setValue(int)));//信号槽

    QHBoxLayout *layout = new QHBoxLayout;  //设置布局管理器

    layout->addWidget(spinbox);
    layout->addWidget(slider);// 把目标放到管理器上
    window->setLayout(layout);  //传入管理器
    window->show();  //直接展示窗口

    return a.exec();
}
