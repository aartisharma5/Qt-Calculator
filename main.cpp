#include <QApplication>
#include "keypad.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>

int main(int argc, char **argv)
{
  QApplication app(argc, argv);
  QWidget widget;
  QVBoxLayout layout(&widget);
  Keypad pad;
  layout.addWidget(&pad);
  QLabel label;
  QTextEdit texted;
  layout.addWidget(&label);
  QObject::connect(&pad, SIGNAL(textChanged(QString)), &label, SLOT(setText(QSring)));
  widget.show();
  return app.exec();
} 