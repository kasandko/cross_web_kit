#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QString>

namespace Ui {
class MainWidget;
}

class TestJsObject;

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    static const QString SOURCE_PATH;

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private slots:
    void on_btnA_clicked();
    void on_btnB_clicked();
    void on_btnC_clicked();

    void onJavaScriptWindowObjectCleared();

    void changeRange(int value);
    void changeNumber(int value);
    void changeText(const QString& value);

private:
    Ui::MainWidget *ui;
    TestJsObject* test_object;
};

#endif // MAINWIDGET_H
