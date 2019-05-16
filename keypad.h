#ifndef KEYPAD_H
#define KEYPAD_H

#include <QWidget>

class QLineEdit;

class Keypad : public QWidget
{
  Q_OBJECT
  public:
    Keypad(QWidget *parent = 0);
    const QString text() const;
    int num ,ans,sign;
    bool check;
  public slots:
    void setText(const QString &text);
    //void operate();
    //void setnum(int n);
    //void setsign(int si);
  signals:
    void textChanged(const QString &text);
  private slots:
    void buttonClicked(const QString &text);
    void pls();
    void min();
    void mul();
    void div();
    void operate();
  private:
    QLineEdit *m_lineEdit;
    QString m_text;
};

#endif