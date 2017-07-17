#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>


namespace Ui { // Implementation of new_account view.  STUPID CLASS NAME, I KNOW :).
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    QLineEdit * name;
    QLineEdit * address;
    QLineEdit * phone;
    QLineEdit * balance;
    QPushButton * submit;
    QPushButton * cancel;
    ~Widget();

public slots:
    void submit_watcher(); // Waits for submit_button clicked() SIGNAL, then emits send_values() SIGNAL.
    void cancel_watcher(); // Waits for cancel_button clicked() SIGNAL, then resets all QLineEdit in the view.


public:
    signals:
        void send_values(QString,QString,QString,QString); //Sends the signal with the new account data.

private:
    Ui::Widget *ui;
};


#endif // WIDGET_H
