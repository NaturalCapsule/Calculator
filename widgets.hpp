#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QKeyEvent>
#include <QClipboard>

#include "tinyexpr.h"

#include <iostream>
using namespace std;

void is_nan(QString text, QLineEdit *lineinput, char char_to_replace) {
    // bool has_nan;
    string current_text = text.toStdString();
    string search_nan = "nan";
    string search_inf = "inf";

    size_t foundPos = current_text.find(search_nan);
    size_t foundPos_ = current_text.find(search_inf);


    if (foundPos != std::string::npos) {
        lineinput->setText(QChar(char_to_replace));
    }
    else if (foundPos_ != std::string::npos) {
        lineinput->setText(QChar(char_to_replace));

    }
}



class LineInput : public QLineEdit {
public:
    QClipboard *clipboard = QApplication::clipboard();

    explicit LineInput(QLineEdit *parent = nullptr) : QLineEdit(parent)
    {
        setFocusPolicy(Qt::StrongFocus); 
        setPlaceholderText("0");
        setReadOnly(true);
    }

protected:
    void keyPressEvent(QKeyEvent *event) override
    {
        if (event->key() == Qt::Key_1) {
            QString currentText = text();
            currentText += '1';
            setText(currentText);
            is_nan(currentText, this, '1');
        }

        else if (event->key() == Qt::Key_2) {
            QString currentText = text();
            currentText += '2';
            setText(currentText);
            is_nan(currentText, this, '2');
        }

        else if (event->key() == Qt::Key_3) {
            QString currentText = text();
            currentText += '3';
            setText(currentText);
            is_nan(currentText, this, '3');
        }

        else if (event->key() == Qt::Key_4) {
            QString currentText = text();
            currentText += '4';
            setText(currentText);
            is_nan(currentText, this, '4');
        }

        else if (event->key() == Qt::Key_5) {
            QString currentText = text();
            currentText += '5';
            setText(currentText);
            is_nan(currentText, this, '5');
        }

        else if (event->key() == Qt::Key_6) {
            QString currentText = text();
            currentText += '6';
            setText(currentText);
            is_nan(currentText, this, '6');
        }

        else if (event->key() == Qt::Key_7) {
            QString currentText = text();
            currentText += '7';
            setText(currentText);
            is_nan(currentText, this, '7');
        }

        else if (event->key() == Qt::Key_8) {
            QString currentText = text();
            currentText += '8';
            setText(currentText);
            is_nan(currentText, this, '8');
        }

        else if (event->key() == Qt::Key_9) {
            QString currentText = text();
            currentText += '9';
            setText(currentText);
            is_nan(currentText, this, '9');
        }

        else if (event->key() == Qt::Key_0) {
            QString currentText = text();
            currentText += '0';
            setText(currentText);
            is_nan(currentText, this, '0');
        }

        else if (event->key() == Qt::Key_Backspace) {
            QString currentText = text();
            if (!currentText.isEmpty()) {
                currentText.removeLast();
                setText(currentText);
            }
        }

        else if (event->key() == Qt::Key_Slash) {
            QString currentText = text();
            currentText += '/';
            setText(currentText);
            is_nan(currentText, this, '/');
        }

        else if (event->key() == Qt::Key_Asterisk) {
            QString currentText = text();
            currentText += '*';
            setText(currentText);
            is_nan(currentText, this, '*');
        }

        else if (event->key() == Qt::Key_Plus) {

            QString currentText = text();
            currentText += '+';
            setText(currentText);
            is_nan(currentText, this, '+');
        }

        else if (event->key() == Qt::Key_Minus) {
            QString currentText = text();
            currentText += '-';
            setText(currentText);
            is_nan(currentText, this, '-');
        }

        else if (event->key() == 67) {
            // qDebug() << "Pressed!" << " " << event->text();
            clipboard->setText(text());
        }

        else if (event->key() == Qt::Key_Equal || event->key() == Qt::Key_Return) {
            QString currentText = text();
            string expr = currentText.toStdString();

            double result = te_interp(expr.c_str(), 0);
            setText(QString::number(result));
        }

        else {
            // qDebug() << "Pressed!" << " " << event->key();

            QLineEdit::keyPressEvent(event);
        }

    }
};


void addQtWidgets(QVBoxLayout *layout, QLineEdit *lineinput ,QGridLayout *gridLayout, QPushButton *button0, QPushButton *button1, QPushButton *button2, QPushButton *button3, QPushButton *button4, QPushButton *button5, QPushButton *button6, QPushButton *button7, QPushButton *button8, QPushButton *button9, QPushButton *minusButton, QPushButton *addButton, QPushButton *multiplyButton, QPushButton *divButton, QPushButton *equalButton, QPushButton *removeElementButton) {
    layout->addWidget(lineinput);

    gridLayout->addWidget(button9, 0, 0);
    gridLayout->addWidget(button8, 0, 1);
    gridLayout->addWidget(button7, 0, 2);

    gridLayout->addWidget(button6, 2, 0);
    gridLayout->addWidget(button5, 2, 1);
    gridLayout->addWidget(button4, 2, 2);

    gridLayout->addWidget(button3, 3, 0);
    gridLayout->addWidget(button2, 3, 1);
    gridLayout->addWidget(button1, 3, 2);
    gridLayout->addWidget(button0, 4, 1);

    gridLayout->addWidget(equalButton, 4, 2);
    gridLayout->addWidget(removeElementButton, 4, 0);

    gridLayout->addWidget(addButton, 0, 3);
    gridLayout->addWidget(minusButton, 2, 3);
    gridLayout->addWidget(multiplyButton, 3, 3);
    gridLayout->addWidget(divButton, 4, 3);


    layout->addLayout(gridLayout);

}

void Qt_widgets(QWidget &window) {
    QVBoxLayout *layout = new QVBoxLayout(&window);


    QGridLayout *gridLayout = new QGridLayout();

    // QLineEdit *lineinput = new QLineEdit();
    LineInput *lineinput = new LineInput();

    // lineinput->setPlaceholderText("0");
    // lineinput->setReadOnly(true);

    // lineinput->setStyleSheet("QLineEdit {background-color: #1e1e1e; color: #ffffff; border: 2px solid #3c3c3c; border-radius: 10px; font-size: 24px; padding: 10px;} QPushButton:hover {background-color: #3c3c3c; border: 2px solid #5c5c5c;} QPushButton:pressed {background-color: #5c5c5c; border: 2px solid #7c7c7c;}");


    QPushButton *button1 = new QPushButton("1");
    QPushButton *button2 = new QPushButton("2");
    QPushButton *button3 = new QPushButton("3");

    QPushButton *button4 = new QPushButton("4");
    QPushButton *button5 = new QPushButton("5");
    QPushButton *button6 = new QPushButton("6");

    QPushButton *button7 = new QPushButton("7");
    QPushButton *button8 = new QPushButton("8");
    QPushButton *button9 = new QPushButton("9");


    QPushButton *button0 = new QPushButton("0");


    QPushButton *subButton = new QPushButton("-");
    QPushButton *addButton = new QPushButton("+");
    QPushButton *multiplyButton = new QPushButton("x");
    QPushButton *divButton = new QPushButton("÷");


    QPushButton *equalButton = new QPushButton("=");
    QPushButton *removeElementButton = new QPushButton("X");


    QObject::connect(equalButton, &QPushButton::clicked, [lineinput]() {
        QString currentText = lineinput->text();
        string expr = currentText.toStdString();

        double result = te_interp(expr.c_str(), 0);
        lineinput->setText(QString::number(result));
        lineinput->setFocus();
    });

    QObject::connect(removeElementButton, &QPushButton::clicked, [lineinput]() {
        QString currentText = lineinput->text();
        if (!currentText.isEmpty()) {
            currentText.removeLast();
            // qDebug() << currentText;
            lineinput->setText(currentText);
            lineinput->setFocus();
        }
    });

    QObject::connect(subButton, &QPushButton::clicked, [lineinput]() {
        QString currentText = lineinput->text();
        currentText += '-';
        lineinput->setFocus();
        lineinput->setText(currentText);
        is_nan(currentText, lineinput, '-');
    });

    QObject::connect(addButton, &QPushButton::clicked, [lineinput]() {
        QString currentText = lineinput->text();
        currentText += '+';
        lineinput->setFocus();
        lineinput->setText(currentText);
        is_nan(currentText, lineinput, '+');
    });

    QObject::connect(multiplyButton, &QPushButton::clicked, [lineinput]() {
        QString currentText = lineinput->text();
        currentText += '*';
        lineinput->setFocus();
        lineinput->setText(currentText);
        is_nan(currentText, lineinput, '*');
    });

    QObject::connect(divButton, &QPushButton::clicked, [lineinput]() {
        QString currentText = lineinput->text();
        currentText += '/';
        lineinput->setFocus();
        lineinput->setText(currentText);
        is_nan(currentText, lineinput, '/');
    });

    QObject::connect(button0, &QPushButton::clicked, [lineinput]() {
        QString currentText = lineinput->text();
        currentText += '0';
        lineinput->setFocus();
        lineinput->setText(currentText);
        is_nan(currentText, lineinput, '0');
    });

    QObject::connect(button1, &QPushButton::clicked, [lineinput]() {
        QString currentText = lineinput->text();
        currentText += '1';
        lineinput->setFocus();
        lineinput->setText(currentText);
        is_nan(currentText, lineinput, '1');
    });

    QObject::connect(button2, &QPushButton::clicked, [lineinput]() {
        QString currentText = lineinput->text();
        currentText += '2';
        lineinput->setFocus();
        lineinput->setText(currentText);
        is_nan(currentText, lineinput, '2');
    });

    QObject::connect(button3, &QPushButton::clicked, [lineinput]() {
        QString currentText = lineinput->text();
        currentText += '3';
        lineinput->setFocus();
        lineinput->setText(currentText);
        is_nan(currentText, lineinput, '3');
    });
    
    QObject::connect(button4, &QPushButton::clicked, [lineinput]() {
        QString currentText = lineinput->text();
        currentText += '4';
        lineinput->setFocus();
        lineinput->setText(currentText);
        is_nan(currentText, lineinput, '4');
    });

    QObject::connect(button5, &QPushButton::clicked, [lineinput]() {
        QString currentText = lineinput->text();
        currentText += '5';
        lineinput->setFocus();
        lineinput->setText(currentText);
        is_nan(currentText, lineinput, '5');
    });


    QObject::connect(button6, &QPushButton::clicked, [lineinput]() {
        QString currentText = lineinput->text();
        currentText += '6';
        lineinput->setFocus();
        lineinput->setText(currentText);
        is_nan(currentText, lineinput, '6');
    });

    QObject::connect(button7, &QPushButton::clicked, [lineinput]() {
        QString currentText = lineinput->text();
        currentText += '7';
        lineinput->setFocus();
        lineinput->setText(currentText);
        is_nan(currentText, lineinput, '7');
    });

    QObject::connect(button8, &QPushButton::clicked, [lineinput]() {
        QString currentText = lineinput->text();
        currentText += '8';
        lineinput->setFocus();
        lineinput->setText(currentText);
        is_nan(currentText, lineinput, '8');
    });

    QObject::connect(button9, &QPushButton::clicked, [lineinput]() {
        QString currentText = lineinput->text();
        currentText += '9';
        lineinput->setFocus();
        lineinput->setText(currentText);
        is_nan(currentText, lineinput, '9');
    });

    addQtWidgets(layout, lineinput, gridLayout, button0, button1, button2, button3, button4, button5, button6, button7, button8, button9, subButton, addButton, multiplyButton, divButton, equalButton, removeElementButton);
}
