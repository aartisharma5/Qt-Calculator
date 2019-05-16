#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QSignalMapper>

#include "keypad.h"

Keypad::Keypad( QWidget *parent )
{
  QGridLayout *layout = new QGridLayout( this );
  
  m_lineEdit = new QLineEdit();
  m_lineEdit->setAlignment( Qt::AlignRight );
  
  QPushButton *button0 = new QPushButton( "0" );
  QPushButton *button1 = new QPushButton( "1" );
  QPushButton *button2 = new QPushButton( "2" );
  QPushButton *button3 = new QPushButton( "3" );
  QPushButton *button4 = new QPushButton( "4" );
  QPushButton *button5 = new QPushButton( "5" );
  QPushButton *button6 = new QPushButton( "6" );
  QPushButton *button7 = new QPushButton( "7" );
  QPushButton *button8 = new QPushButton( "8" );
  QPushButton *button9 = new QPushButton( "9" );
  QPushButton *buttonpls = new QPushButton( tr("+") );
  QPushButton *buttonmin = new QPushButton( tr("-") );
  QPushButton *buttondiv = new QPushButton( tr("/") );
  QPushButton *buttonmul = new QPushButton( tr("*") );
  QPushButton *buttoneq = new QPushButton( tr("=") );
  QPushButton *buttonClear = new QPushButton( tr("C") );
  
  layout->addWidget( m_lineEdit, 0, 0, 1, 4 );
  layout->addWidget( button1, 1, 0 );
  layout->addWidget( button2, 1, 1 );
  layout->addWidget( button3, 1, 2 );
  layout->addWidget( button4, 2, 0 );
  layout->addWidget( button5, 2, 1 );
  layout->addWidget( button6, 2, 2 );
  layout->addWidget( button7, 3, 0 );
  layout->addWidget( button8, 3, 1 );
  layout->addWidget( button9, 3, 2 );
  layout->addWidget( button0, 4, 1 );
  layout->addWidget( buttonpls, 1, 3 );
  layout->addWidget( buttonmin, 2, 3 );
  layout->addWidget( buttondiv, 3, 3 );
  layout->addWidget( buttonmul, 4, 3 );
  layout->addWidget( buttoneq, 4, 0 );
  layout->addWidget( buttonClear, 4, 2 );
  
  QSignalMapper *mapper = new QSignalMapper( this );
  
  mapper->setMapping( button0, "0" );
  mapper->setMapping( button1, "1" );
  mapper->setMapping( button2, "2" );
  mapper->setMapping( button3, "3" );
  mapper->setMapping( button4, "4" );
  mapper->setMapping( button5, "5" );
  mapper->setMapping( button6, "6" );
  mapper->setMapping( button7, "7" );
  mapper->setMapping( button8, "8" );
  mapper->setMapping( button9, "9" );
  mapper->setMapping( buttonpls, "+" );
  mapper->setMapping( buttonmin, "-" );
  mapper->setMapping( buttondiv, "/" );
  mapper->setMapping( buttonmul, "*" );

  
  connect( button0, SIGNAL(clicked()), mapper, SLOT(map()) );
  connect( button0, SIGNAL(clicked()), this, SLOT(createnum()) );

  connect( button1, SIGNAL(clicked()), mapper, SLOT(map()) );
  connect( button2, SIGNAL(clicked()), mapper, SLOT(map()) );
  connect( button3, SIGNAL(clicked()), mapper, SLOT(map()) );
  connect( button4, SIGNAL(clicked()), mapper, SLOT(map()) );
  connect( button5, SIGNAL(clicked()), mapper, SLOT(map()) );
  connect( button6, SIGNAL(clicked()), mapper, SLOT(map()) );
  connect( button7, SIGNAL(clicked()), mapper, SLOT(map()) );
  connect( button8, SIGNAL(clicked()), mapper, SLOT(map()) );
  connect( button9, SIGNAL(clicked()), mapper, SLOT(map()) );
  connect( buttonpls, SIGNAL(clicked()), this, SLOT(pls()) );
  connect( buttonmin, SIGNAL(clicked()), this, SLOT(min()) );
  connect( buttondiv, SIGNAL(clicked()), this, SLOT(div()) );
  connect( buttonmul, SIGNAL(clicked()), this, SLOT(mul()) );

  connect( mapper, SIGNAL(mapped(QString)), this, SLOT(buttonClicked(QString)) );
  connect( buttonClear, SIGNAL(clicked()), m_lineEdit, SLOT(clear()) );
  connect( buttoneq, SIGNAL(clicked()), this, SLOT(operate()) );
  connect( m_lineEdit, SIGNAL(textChanged(QString)), this, SLOT(setText(QString)) );
}

const QString Keypad::text() const
{
  return m_text;
}

void Keypad::buttonClicked( const QString &newText )
{
  setText( m_text + newText );
}

void Keypad::setText( const QString &newText )
{
  if( newText == m_text )
    return;
    
  m_text = newText;
  m_lineEdit->setText( m_text );
  
  emit textChanged( m_text );
}
void Keypad::pls()
{
  sign = 0;
  ans = m_text.toInt(&check,10);
  m_lineEdit->clear();
  m_text = "";
}
void Keypad::min()
{
  sign = 1;
  ans = m_text.toInt(&check,10);
  m_lineEdit->clear();
  m_text = "";
}
void Keypad::mul()
{
  sign = 2;
  ans = m_text.toInt(&check,10);
  m_lineEdit->clear();
  m_text = "";
}
void Keypad::div()
{
  sign = 3;
  ans = m_text.toInt(&check,10);
  m_lineEdit->clear();
  m_text = "";
}

void Keypad::operate()
{
  num = m_text.toInt(&check,10);
  switch(sign){
    case 0:
      ans+=num;
      break;
    case 1:
      ans-=num;
      break;
    case 2:
      ans*=num;
      break;
    case 3:
      ans/=num;
      break;
    default:
      break;
  }   
    m_text= QString::number(ans);
    ans=0;
    num=0;
    m_lineEdit->setText( m_text );
    emit textChanged( m_text );

}