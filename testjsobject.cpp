#include "testjsobject.h"

#include <QDebug>

const QString TestJsObject::JS_OBJECT_NAME = "qtapi";

TestJsObject::TestJsObject(QObject *parent) : QObject(parent)
{

}

void TestJsObject::testEvent(int id, QVariant v)
{
    qDebug() << "Raise test event: " << id;


    QVariantMap m = v.toMap();
    qDebug() << "Arguments: " << m.count();
    for (const auto& key : m.keys())
    {
        qDebug() << key << ": " << m[key];
    }
}

int TestJsObject::rangeValue()
{
    return range;
}

void TestJsObject::setRangeValue(int value)
{
    range = value;
    emit onRangeChanged(range);
}

int TestJsObject::numberValue()
{
    return number;
}

void TestJsObject::setNumberValue(int value)
{
    number = value;
    emit onNumberChanged(number);
}

QString TestJsObject::textValue()
{
    return text;
}

void TestJsObject::setTextValue(const QString& value)
{
    text = value;
    emit onTextChanged(text);
}
