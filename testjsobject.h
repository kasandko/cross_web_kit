#ifndef TESTJSOBJECT_H
#define TESTJSOBJECT_H

#include <QObject>
#include <QString>

class TestJsObject : public QObject
{
    Q_OBJECT
public:
    static const QString JS_OBJECT_NAME;

public:
    explicit TestJsObject(QObject *parent = nullptr);

    Q_PROPERTY(int rangeValue READ rangeValue WRITE setRangeValue)
    Q_PROPERTY(int numberValue READ numberValue WRITE setNumberValue)
    Q_PROPERTY(QString textValue READ textValue WRITE setTextValue)

signals:
    void onRangeChanged(int value);
    void onNumberChanged(int value);
    void onTextChanged(const QString& value);

public slots:
    int rangeValue();
    void setRangeValue(int value);
    int numberValue();
    void setNumberValue(int value);
    QString textValue();
    void setTextValue(const QString& value);

private:
    int range = 0;
    int number = 0;
    QString text;
};

#endif // TESTJSOBJECT_H
