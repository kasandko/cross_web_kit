#include "mainwidget.h"
#include "ui_mainwidget.h"

#include "testjsobject.h"

#include <QWebFrame>

const QString MainWidget::SOURCE_PATH = HTML_SOURCE_PATH;

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget),
    test_object(new TestJsObject)
{
    ui->setupUi(this);

    QString url = "file://";
    url += SOURCE_PATH;
    url += "/test_page.htm";
    ui->webView->setUrl(QUrl(url));

    ui->webView->page()->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);

    QWebFrame * main_frame = ui->webView->page()->mainFrame();
    connect(main_frame, &QWebFrame::javaScriptWindowObjectCleared, this,
        &MainWidget::onJavaScriptWindowObjectCleared);

    connect(test_object, &TestJsObject::onRangeChanged, this, &MainWidget::changeRange);
    connect(test_object, &TestJsObject::onNumberChanged, this, &MainWidget::changeNumber);
    connect(test_object, &TestJsObject::onTextChanged, this, &MainWidget::changeText);
}

MainWidget::~MainWidget()
{
    delete ui;
    delete test_object;
}

void MainWidget::on_btnA_clicked()
{
    QWebFrame * main_frame = ui->webView->page()->mainFrame();
    main_frame->evaluateJavaScript("clickBtnA();");
}

void MainWidget::on_btnB_clicked()
{
    QWebFrame * main_frame = ui->webView->page()->mainFrame();
    main_frame->evaluateJavaScript("clickBtnB();");
}

void MainWidget::on_btnC_clicked()
{
    QWebFrame * main_frame = ui->webView->page()->mainFrame();
    main_frame->evaluateJavaScript("clickBtnC();");
}

void MainWidget::onJavaScriptWindowObjectCleared()
{
    QWebFrame * main_frame = ui->webView->page()->mainFrame();
    main_frame->addToJavaScriptWindowObject(TestJsObject::JS_OBJECT_NAME, test_object);
}

void MainWidget::changeRange(int value)
{
    ui->progress->setValue(value);
}

void MainWidget::changeNumber(int value)
{
    ui->lcd->display(value);
}

void MainWidget::changeText(const QString& value)
{
    ui->lblA->setText(value);
}
